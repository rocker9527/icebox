#include "os.hpp"

#define FDP_MODULE "os_nt"
#include "log.hpp"
#include "core.hpp"
#include "endian.hpp"
#include "utils.hpp"
#include "sym.hpp"
#include "utf8.hpp"
#include "core_helpers.hpp"

#include <algorithm>
#include <array>
#include <string>

#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

namespace
{
    enum member_offset_e
    {
        EPROCESS_ActiveProcessLinks,
        EPROCESS_ImageFileName,
        EPROCESS_Pcb,
        EPROCESS_Peb,
        EPROCESS_SeAuditProcessCreationInfo,
        EPROCESS_VadRoot,
        KPCR_Prcb,
        KPRCB_CurrentThread,
        KPROCESS_DirectoryTableBase,
        KTHREAD_Process,
        LDR_DATA_TABLE_ENTRY_DllBase,
        LDR_DATA_TABLE_ENTRY_FullDllName,
        LDR_DATA_TABLE_ENTRY_InLoadOrderLinks,
        LDR_DATA_TABLE_ENTRY_SizeOfImage,
        OBJECT_NAME_INFORMATION_Name,
        PEB_Ldr,
        PEB_LDR_DATA_InLoadOrderModuleList,
        PEB_ProcessParameters,
        RTL_USER_PROCESS_PARAMETERS_ImagePathName,
        SE_AUDIT_PROCESS_CREATION_INFO_ImageFileName,
        MEMBER_OFFSET_COUNT,
    };

    struct MemberOffset
    {
        member_offset_e e_id;
        const char      module[16];
        const char      struc[32];
        const char      member[32];
    };
    const MemberOffset g_member_offsets[] =
    {
        {EPROCESS_ActiveProcessLinks,                   "nt", "_EPROCESS",                        "ActiveProcessLinks"},
        {EPROCESS_ImageFileName,                        "nt", "_EPROCESS",                        "ImageFileName"},
        {EPROCESS_Pcb,                                  "nt", "_EPROCESS",                        "Pcb"},
        {EPROCESS_Peb,                                  "nt", "_EPROCESS",                        "Peb"},
        {EPROCESS_SeAuditProcessCreationInfo,           "nt", "_EPROCESS",                        "SeAuditProcessCreationInfo"},
        {EPROCESS_VadRoot,                              "nt", "_EPROCESS",                        "VadRoot"},
        {KPCR_Prcb,                                     "nt", "_KPCR",                            "Prcb"},
        {KPRCB_CurrentThread,                           "nt", "_KPRCB",                           "CurrentThread"},
        {KPROCESS_DirectoryTableBase,                   "nt", "_KPROCESS",                        "DirectoryTableBase"},
        {KTHREAD_Process,                               "nt", "_KTHREAD",                         "Process"},
        {LDR_DATA_TABLE_ENTRY_DllBase,                  "nt", "_LDR_DATA_TABLE_ENTRY",            "DllBase"},
        {LDR_DATA_TABLE_ENTRY_FullDllName,              "nt", "_LDR_DATA_TABLE_ENTRY",            "FullDllName"},
        {LDR_DATA_TABLE_ENTRY_InLoadOrderLinks,         "nt", "_LDR_DATA_TABLE_ENTRY",            "InLoadOrderLinks"},
        {LDR_DATA_TABLE_ENTRY_SizeOfImage,              "nt", "_LDR_DATA_TABLE_ENTRY",            "SizeOfImage"},
        {OBJECT_NAME_INFORMATION_Name,                  "nt", "_OBJECT_NAME_INFORMATION",         "Name"},
        {PEB_Ldr,                                       "nt", "_PEB",                             "Ldr"},
        {PEB_LDR_DATA_InLoadOrderModuleList,            "nt", "_PEB_LDR_DATA",                    "InLoadOrderModuleList"},
        {PEB_ProcessParameters,                         "nt", "_PEB",                             "ProcessParameters"},
        {RTL_USER_PROCESS_PARAMETERS_ImagePathName,     "nt", "_RTL_USER_PROCESS_PARAMETERS",     "ImagePathName"},
        {SE_AUDIT_PROCESS_CREATION_INFO_ImageFileName,  "nt", "_SE_AUDIT_PROCESS_CREATION_INFO",  "ImageFileName"},
    };
    static_assert(COUNT_OF(g_member_offsets) == MEMBER_OFFSET_COUNT, "invalid members");

    enum symbol_offset_e
    {
        KiSystemCall64,
        PsActiveProcessHead,
        PsInitialSystemProcess,
        SYMBOL_OFFSET_COUNT,
    };

    struct SymbolOffset
    {
        symbol_offset_e e_id;
        const char      module[16];
        const char      name[32];
    };
    const SymbolOffset g_symbol_offsets[] =
    {
        {KiSystemCall64,            "nt", "KiSystemCall64"},
        {PsActiveProcessHead,       "nt", "PsActiveProcessHead"},
        {PsInitialSystemProcess,    "nt", "PsInitialSystemProcess"},
    };
    static_assert(COUNT_OF(g_symbol_offsets) == SYMBOL_OFFSET_COUNT, "invalid symbols");

    using Sym           = std::unique_ptr<sym::IModule>;
    using MemberOffsets = std::array<uint64_t, MEMBER_OFFSET_COUNT>;
    using SymbolOffsets = std::array<uint64_t, SYMBOL_OFFSET_COUNT>;

    struct OsNt
        : public os::IHandler
    {
        OsNt(ICore& core);

        // methods
        bool setup();

        // os::IHandler
        bool                list_procs(const on_proc_fn& on_process) override;
        opt<proc_t>         get_current_proc() override;
        opt<proc_t>         get_proc(const std::string& name) override;
        opt<std::string>    get_proc_name(proc_t proc) override;
        bool                list_mods(proc_t proc, const on_mod_fn& on_module) override;
        opt<std::string>    get_mod_name(proc_t proc, mod_t mod) override;
        opt<span_t>         get_mod_span(proc_t proc, mod_t mod) override;
        bool                has_virtual(proc_t proc) override;

        // members
        ICore&          core_;
        MemberOffsets   members_;
        SymbolOffsets   symbols_;
    };
}

OsNt::OsNt(ICore& core)
    : core_(core)
{
}

namespace
{
    std::optional<size_t> validate_pe_header(const uint8_t (&buf)[PAGE_SIZE])
    {
        static const auto e_lfanew_offset = 0x3C;
        int idx = e_lfanew_offset;
        if(idx + 4 > sizeof buf)
            return std::nullopt;

        const auto e_lfanew = read_le32(&buf[idx]);
        idx = e_lfanew;

        static const uint32_t image_nt_signature = 'PE' << 16;
        if(idx + sizeof image_nt_signature > sizeof buf)
            return std::nullopt;

        const auto signature = read_be32(&buf[idx]);
        if(signature != image_nt_signature)
            return std::nullopt;

        static const uint16_t image_file_machine_amd64 = 0x8664;
        idx += sizeof signature;
        if(idx + sizeof image_file_machine_amd64 > sizeof buf)
            return std::nullopt;

        const auto machine = read_le16(&buf[idx]);
        if(machine != image_file_machine_amd64)
            return std::nullopt;

        static const int image_file_header_size = 20;
        static const uint16_t image_nt_optional_hdr64_magic = 0x20B;
        idx += image_file_header_size;
        if(idx + sizeof image_nt_optional_hdr64_magic > sizeof buf)
            return std::nullopt;

        const auto magic = read_le16(&buf[idx]);
        if(magic != image_nt_optional_hdr64_magic)
            return std::nullopt;

        static const auto size_of_image_offset = 14 * 4;
        idx += size_of_image_offset;
        if(idx + 4 > sizeof buf)
            return std::nullopt;

        return read_le32(&buf[idx]);
    }

    std::optional<span_t> find_kernel(ICore& core, uint64_t lstar)
    {
        uint8_t buf[PAGE_SIZE];
        for(auto ptr = align<PAGE_SIZE>(lstar); ptr < lstar; ptr -= PAGE_SIZE)
        {
            auto ok = core.read_mem(buf, ptr, sizeof buf);
            if(!ok)
                return std::nullopt;

            const auto e_magic = read_be16(buf);
            static const auto image_dos_signature = 'MZ';
            if(e_magic != image_dos_signature)
                continue;

            const auto size = validate_pe_header(buf);
            if(!size)
            {
                LOG(ERROR, "invalid PE header at 0x%llx", ptr);
                continue;
            }

            return span_t{ptr, *size};
        }

        return std::nullopt;
    }

    std::vector<uint8_t> read_buffer(ICore& core, span_t span)
    {
        uint8_t page[PAGE_SIZE];

        std::vector<uint8_t> buffer;
        buffer.reserve(span.size);
        for(size_t i = 0; i < span.size; i += sizeof page)
        {
            const auto chunk = std::min<size_t>(PAGE_SIZE, std::max<int64_t>(0, span.size - i));
            const auto ok = core.read_mem(page, span.addr + i, chunk);
            if(!ok)
            {
                buffer.clear();
                return buffer;
            }

            const auto old = buffer.size();
            buffer.resize(old + sizeof page);
            memcpy(&buffer[old], page, sizeof page);
        }

        return buffer;
    }

    struct PdbCtx
    {
        std::string guid;
        std::string name;
    };

    void binhex(char* dst, const void* vsrc, size_t size)
    {
        static const char hexchars_upper[] = "0123456789ABCDEF";
        const uint8_t* src = static_cast<const uint8_t*>(vsrc);
        for (size_t i = 0; i < size; ++i)
        {
            dst[i * 2 + 0] = hexchars_upper[src[i] >> 4];
            dst[i * 2 + 1] = hexchars_upper[src[i] & 0x0F];
        }
    }

    std::optional<PdbCtx> read_pdb(ICore& core, span_t kernel)
    {
        const auto buf = read_buffer(core, kernel);

        std::vector<uint8_t> magic = { 'R', 'S', 'D', 'S' };
        const auto it = std::search(buf.begin(), buf.end(), std::boyer_moore_horspool_searcher(magic.begin(), magic.end()));
        if(it == buf.end())
            FAIL(std::nullopt, "unable to find RSDS pattern into kernel module");

        const auto rsds = &*it;
        const auto size = std::distance(it, buf.end());
        if(size < 4 /*magic*/ + 16 /*guid*/ + 4 /*age*/ + 2 /*name*/)
            FAIL(std::nullopt, "kernel module is too small for pdb header");

        const auto end = reinterpret_cast<const uint8_t*>(memchr(&rsds[4 + 16 + 4], 0x00, size));
        if(!end)
            FAIL(std::nullopt, "missing null-terminating byte on PDB header module name");

        uint8_t guid[16];
        write_be32(&guid[0], read_le32(&rsds[4 + 0]));  // Data1
        write_be16(&guid[4], read_le16(&rsds[4 + 4]));  // Data2
        write_be16(&guid[6], read_le16(&rsds[4 + 6 ])); // Data3
        memcpy(&guid[8], &rsds[4 + 8], 8);              // Data4

        char strguid[sizeof guid * 2];
        binhex(strguid, &guid, sizeof guid);

        uint32_t age = read_le32(&rsds[4 + 16]);
        const auto name = &rsds[4 + 16 + 4];
        return PdbCtx{std::string{strguid, sizeof strguid} + std::to_string(age), {name, end}};
    }
}

bool OsNt::setup()
{
    const auto lstar = core_.read_msr(MSR_LSTAR);
    if(!lstar)
        return false;

    const auto kernel = find_kernel(core_, *lstar);
    if(!kernel)
        FAIL(false, "unable to find kernel");

    LOG(INFO, "kernel: 0x%016llx - 0x%016llx (%lld 0x%llx)", kernel->addr, kernel->addr + kernel->size, kernel->size, kernel->size);
    const auto pdb = read_pdb(core_, *kernel);
    if(!pdb)
        FAIL(false, "unable to read pdb in kernel module");

    LOG(INFO, "kernel: pdb: %s %s", pdb->guid.data(), pdb->name.data());
    auto sym_pdb = sym::make_pdb(*kernel, pdb->name.data(), pdb->guid.data());
    if(!sym_pdb)
        FAIL(false, "unable to read pdb from %s %s", pdb->name.data(), pdb->guid.data());

    auto& sym = core_.sym();
    sym.register_module("nt", sym_pdb);

    bool fail = false;
    for(size_t i = 0; i < SYMBOL_OFFSET_COUNT; ++i)
    {
        const auto addr = sym.get_symbol(g_symbol_offsets[i].module, g_symbol_offsets[i].name);
        if(!addr)
        {
            fail = true;
            LOG(ERROR, "unable to read %s!%s symbol offset", g_symbol_offsets[i].module, g_symbol_offsets[i].name);
            continue;
        }

        symbols_[i] = *addr;
    }
    for(size_t i = 0; i < MEMBER_OFFSET_COUNT; ++i)
    {
        const auto offset = sym.get_struc_offset(g_member_offsets[i].module, g_member_offsets[i].struc, g_member_offsets[i].member);
        if(!offset)
        {
            fail = true;
            LOG(ERROR, "unable to read %s!%s.%s member offset", g_member_offsets[i].module, g_member_offsets[i].struc, g_member_offsets[i].member);
            continue;
        }

        members_[i] = *offset;
    }
    if(fail)
        return false;

    const auto KiSystemCall64 = symbols_[::KiSystemCall64];
    if(*lstar != KiSystemCall64)
        FAIL(false, "PDB mismatch lstar: 0x%llx pdb: 0x%llx\n", *lstar, KiSystemCall64);

    return true;
}

std::unique_ptr<os::IHandler> os::make_nt(ICore& core)
{
    auto nt = std::make_unique<OsNt>(core);
    if(!nt)
        return std::nullptr_t();

    const auto ok = nt->setup();
    if(!ok)
        return std::nullptr_t();

    return nt;
}

bool OsNt::list_procs(const on_proc_fn& on_process)
{
    const auto head = symbols_[PsActiveProcessHead];
    for(auto link = core::read_ptr(core_, head); link != head; link = core::read_ptr(core_, *link))
    {
        const auto eproc = *link - members_[EPROCESS_ActiveProcessLinks];
        const auto dtb = core::read_ptr(core_, eproc + members_[EPROCESS_Pcb] + members_[KPROCESS_DirectoryTableBase]);
        if(!dtb)
        {
            LOG(ERROR, "unable to read KPROCESS.DirectoryTableBase from 0x%llx", eproc);
            continue;
        }

        const auto err = on_process({eproc, *dtb});
        if(err == WALK_STOP)
            break;
    }
    return true;
}

namespace
{
    std::optional<uint64_t> read_gs_base(ICore& core)
    {
        auto gs = core.read_msr(MSR_GS_BASE);
        if(!gs)
            return std::nullopt;

        if(*gs & 0xFFF0000000000000)
            return gs;

        gs = core.read_msr(MSR_KERNEL_GS_BASE);
        if(!gs)
            return std::nullopt;

        return gs;
    }
}

opt<proc_t> OsNt::get_current_proc()
{
    const auto gs = read_gs_base(core_);
    if(!gs)
        return std::nullopt;

    const auto current_thread = core::read_ptr(core_, *gs + members_[KPCR_Prcb] + members_[KPRCB_CurrentThread]);
    if(!current_thread)
        FAIL(std::nullopt, "unable to read KPCR.Prcb.CurrentThread");

    const auto kproc = core::read_ptr(core_, *current_thread + members_[KTHREAD_Process]);
    if(!kproc)
        FAIL(std::nullopt, "unable to read KTHREAD.Process");

    const auto dtb = core::read_ptr(core_, *kproc + members_[KPROCESS_DirectoryTableBase]);
    if(!dtb)
        FAIL(std::nullopt, "unable to read KPROCESS.DirectoryTableBase");

    const auto eproc = *kproc - members_[EPROCESS_Pcb];
    return proc_t{eproc, *dtb};
}

opt<proc_t> OsNt::get_proc(const std::string& name)
{
    opt<proc_t> found;
    list_procs([&](proc_t proc)
    {
        const auto got = get_proc_name(proc);
        if(got != name)
            return WALK_NEXT;

        found = proc;
        return WALK_STOP;
    });
    return found;
}

namespace
{
    opt<std::string> read_unicode_string(ICore& core, uint64_t unicode_string)
    {
        using UnicodeString = struct
        {
            uint16_t length;
            uint16_t max_length;
            uint32_t _; // padding
            uint64_t buffer;
        };
        UnicodeString us;
        auto ok = core.read_mem(&us, unicode_string, sizeof us);
        if(!ok)
            FAIL(std::nullopt, "unable to read UNICODE_STRING");

        us.length = read_le16(&us.length);
        us.max_length = read_le16(&us.max_length);
        us.buffer = read_le64(&us.buffer);

        if(us.length > us.max_length)
            FAIL(std::nullopt, "corrupted UNICODE_STRING");

        std::wstring wname;
        wname.resize(us.length);
        ok = core.read_mem(wname.data(), us.buffer, us.length);
        if(!ok)
            FAIL(std::nullopt, "unable to read UNICODE_STRING.buffer");

        return utf8::convert(wname);
    }
}

opt<std::string> OsNt::get_proc_name(proc_t proc)
{
    // EPROCESS.ImageFileName is 16 bytes, but only 14 are actually used
    char buffer[14+1];
    const auto ok = core_.read_mem(buffer, proc.id + members_[EPROCESS_ImageFileName], sizeof buffer);
    buffer[sizeof buffer - 1] = 0;
    if(!ok)
        return std::nullopt;

    const auto name = std::string{buffer};
    if(name.size() < sizeof buffer - 1)
        return name;

    const auto image_file_name = core::read_ptr(core_, proc.id + members_[EPROCESS_SeAuditProcessCreationInfo] + members_[SE_AUDIT_PROCESS_CREATION_INFO_ImageFileName]);
    if(!image_file_name)
        return name;

    const auto path = read_unicode_string(core_, *image_file_name + members_[OBJECT_NAME_INFORMATION_Name]);
    if(!path)
        return name;

    return fs::path(*path).filename().generic_string();
}

bool OsNt::list_mods(proc_t proc, const on_mod_fn& on_mod)
{
    const auto peb = core::read_ptr(core_, proc.id + members_[EPROCESS_Peb]);
    if(!peb)
        FAIL(false, "unable to read EPROCESS.Peb");

    // no PEB on system process
    if(!*peb)
        return true;

    const auto ctx = core_.switch_context(proc);
    const auto ldr = core::read_ptr(core_, *peb + members_[PEB_Ldr]);
    if(!ldr)
        FAIL(false, "unable to read PEB.Ldr");

    const auto head = *ldr + members_[PEB_LDR_DATA_InLoadOrderModuleList];
    for(auto link = core::read_ptr(core_, head); link && link != head; link = core::read_ptr(core_, *link))
        if(on_mod({*link - members_[LDR_DATA_TABLE_ENTRY_InLoadOrderLinks]}) == WALK_STOP)
            break;

    return true;
}

opt<std::string> OsNt::get_mod_name(proc_t proc, mod_t mod)
{
    const auto ctx = core_.switch_context(proc);
    return read_unicode_string(core_, mod + members_[LDR_DATA_TABLE_ENTRY_FullDllName]);
}

bool OsNt::has_virtual(proc_t proc)
{
    const auto vad_root = core::read_ptr(core_, proc.id + members_[EPROCESS_VadRoot]);
    return vad_root && *vad_root;
}

opt<span_t> OsNt::get_mod_span(proc_t proc, mod_t mod)
{
    const auto ctx = core_.switch_context(proc);
    const auto base = core::read_ptr(core_, mod + members_[LDR_DATA_TABLE_ENTRY_DllBase]);
    if(!base)
        return std::nullopt;

    const auto size = core::read_ptr(core_, mod + members_[LDR_DATA_TABLE_ENTRY_SizeOfImage]);
    if(!size)
        return std::nullopt;

    return span_t{*base, *size};
}