#include "nt_types.hpp"
#include "nt32_types.hpp"

#include "utils/utils.hpp"

namespace
{
    template <typename T>
    static std::string access_mask_str(T access_mask)
    {
        switch(access_mask)
        {
            case T::DELETE:                 return "DELETE";
            case T::FILE_READ_DATA:         return "FILE_READ_DATA";
            case T::FILE_READ_ATTRIBUTES:   return "FILE_READ_ATTRIBUTES";
            case T::FILE_READ_EA:           return "FILE_READ_EA";
            case T::READ_CONTROL:           return "READ_CONTROL";
            case T::FILE_WRITE_DATA:        return "FILE_WRITE_DATA";
            case T::FILE_WRITE_ATTRIBUTES:  return "FILE_WRITE_ATTRIBUTES";
            case T::FILE_WRITE_EA:          return "FILE_WRITE_EA";
            case T::FILE_APPEND_DATA:       return "FILE_APPEND_DATA";
            case T::WRITE_DAC:              return "WRITE_DAC";
            case T::WRITE_OWNER:            return "WRITE_OWNER";
            case T::SYNCHRONIZE:            return "SYNCHRONIZE";
            case T::FILE_EXECUTE:           return "FILE_EXECUTE";
            default:                        return "";
        }
    }

    template <typename T>
    static std::string afd_status_str(T afd_status)
    {
        switch(afd_status)
        {
            case T::AfdSend:                    return "AfdSend";
            case T::AfdReceive:                 return "AfdReceive";
            case T::AfdPoll:                    return "AfdPoll";
            case T::AfdDispatchImmediateIrp:    return "AfdDispatchImmediateIrp";
            case T::AfdBind:                    return "AfdBind";
            default:                            return "";
        }
    }

    static const nt::access_mask_e nt_access_mask[] =
    {
            nt::access_mask_e::DELETE,
            nt::access_mask_e::FILE_READ_DATA,
            nt::access_mask_e::FILE_READ_ATTRIBUTES,
            nt::access_mask_e::FILE_READ_EA,
            nt::access_mask_e::READ_CONTROL,
            nt::access_mask_e::FILE_WRITE_DATA,
            nt::access_mask_e::FILE_WRITE_ATTRIBUTES,
            nt::access_mask_e::FILE_WRITE_EA,
            nt::access_mask_e::FILE_APPEND_DATA,
            nt::access_mask_e::WRITE_DAC,
            nt::access_mask_e::WRITE_OWNER,
            nt::access_mask_e::SYNCHRONIZE,
            nt::access_mask_e::FILE_EXECUTE,
    };

    static const nt32::access_mask_e nt32_access_mask[] =
    {
            nt32::access_mask_e::DELETE,
            nt32::access_mask_e::FILE_READ_DATA,
            nt32::access_mask_e::FILE_READ_ATTRIBUTES,
            nt32::access_mask_e::FILE_READ_EA,
            nt32::access_mask_e::READ_CONTROL,
            nt32::access_mask_e::FILE_WRITE_DATA,
            nt32::access_mask_e::FILE_WRITE_ATTRIBUTES,
            nt32::access_mask_e::FILE_WRITE_EA,
            nt32::access_mask_e::FILE_APPEND_DATA,
            nt32::access_mask_e::WRITE_DAC,
            nt32::access_mask_e::WRITE_OWNER,
            nt32::access_mask_e::SYNCHRONIZE,
            nt32::access_mask_e::FILE_EXECUTE,
    };

    template <typename T, size_t N>
    static std::vector<std::string> access_mask_dump(uint32_t mask, const T (&access_masks)[N])
    {
        std::vector<std::string> access;
        for(auto it : access_masks)
            if(mask & static_cast<uint32_t>(it))
                access.emplace_back(access_mask_str(it));

        return access;
    }

    static const nt::afd_status_e nt_afd_status[] =
    {
            nt::afd_status_e::AfdSend,
            nt::afd_status_e::AfdReceive,
            nt::afd_status_e::AfdPoll,
            nt::afd_status_e::AfdDispatchImmediateIrp,
            nt::afd_status_e::AfdBind,
    };

    static const nt32::afd_status_e nt32_afd_status[] =
    {
            nt32::afd_status_e::AfdSend,
            nt32::afd_status_e::AfdReceive,
            nt32::afd_status_e::AfdPoll,
            nt32::afd_status_e::AfdDispatchImmediateIrp,
            nt32::afd_status_e::AfdBind,
    };

    template <typename T, size_t N>
    static std::string afd_status_dump(uint32_t status, const T (&afd_status_list)[N])
    {
        for(auto it : afd_status_list)
            if(status == static_cast<uint32_t>(it))
                return afd_status_str(it);

        return std::to_string(status);
    }
}

std::string nt::access_mask_str(nt::access_mask_e access_mask)
{
    return ::access_mask_str(access_mask);
}

std::string nt::afd_status_str(afd_status_e afd_status)
{
    return ::afd_status_str(afd_status);
}

std::string nt32::access_mask_str(nt32::access_mask_e access_mask)
{
    return ::access_mask_str(access_mask);
}

std::string nt32::afd_status_str(afd_status_e afd_status)
{
    return ::afd_status_str(afd_status);
}

std::vector<std::string> nt::access_mask_dump(uint32_t mask)
{
    return ::access_mask_dump(mask, nt_access_mask);
}

std::vector<std::string> nt32::access_mask_dump(uint32_t mask)
{
    return ::access_mask_dump(mask, nt32_access_mask);
}

std::string nt::afd_status_dump(uint32_t afd_status)
{
    return ::afd_status_dump(afd_status, nt_afd_status);
}

std::string nt32::afd_status_dump(uint32_t afd_status)
{
    return ::afd_status_dump(afd_status, nt32_afd_status);
}

namespace
{
    template <typename T>
    static const char* win32_protection_mask_str(T arg)
    {
        switch(arg)
        {
            case T::PAGE_NOACCESS:                  return "PAGE_NOACCESS";
            case T::PAGE_READONLY:                  return "PAGE_READONLY";
            case T::PAGE_READWRITE:                 return "PAGE_READWRITE";
            case T::PAGE_WRITECOPY:                 return "PAGE_WRITECOPY";
            case T::PAGE_EXECUTE:                   return "PAGE_EXECUTE";
            case T::PAGE_EXECUTE_READ:              return "PAGE_EXECUTE_READ";
            case T::PAGE_EXECUTE_READWRITE:         return "PAGE_EXECUTE_READWRITE";
            case T::PAGE_EXECUTE_WRITECOPY:         return "PAGE_EXECUTE_WRITECOPY";
            case T::PAGE_GUARD:                     return "PAGE_GUARD";
            case T::PAGE_NOCACHE:                   return "PAGE_NOCACHE";
            case T::PAGE_WRITECOMBINE:              return "PAGE_WRITECOMBINE";
            case T::PAGE_ENCLAVE_THREAD_CONTROL:    return "PAGE_ENCLAVE_THREAD_CONTROL";
            case T::PAGE_TARGETS_INVALID:           return "PAGE_TARGETS_INVALID";
            case T::PAGE_ENCLAVE_UNVALIDATED:       return "PAGE_ENCLAVE_UNVALIDATED";
            case T::PAGE_ENCLAVE_DECOMMIT:          return "PAGE_ENCLAVE_DECOMMIT";
            default:                                return "";
        }
    }

    static const nt32::win32_protection_mask_e nt32_win32_protection_masks[] =
    {
            nt32::win32_protection_mask_e::PAGE_NOACCESS,
            nt32::win32_protection_mask_e::PAGE_READONLY,
            nt32::win32_protection_mask_e::PAGE_READWRITE,
            nt32::win32_protection_mask_e::PAGE_WRITECOPY,
            nt32::win32_protection_mask_e::PAGE_EXECUTE,
            nt32::win32_protection_mask_e::PAGE_EXECUTE_READ,
            nt32::win32_protection_mask_e::PAGE_EXECUTE_READWRITE,
            nt32::win32_protection_mask_e::PAGE_EXECUTE_WRITECOPY,
            nt32::win32_protection_mask_e::PAGE_GUARD,
            nt32::win32_protection_mask_e::PAGE_NOCACHE,
            nt32::win32_protection_mask_e::PAGE_WRITECOMBINE,
            nt32::win32_protection_mask_e::PAGE_ENCLAVE_THREAD_CONTROL,
            nt32::win32_protection_mask_e::PAGE_TARGETS_INVALID,
            nt32::win32_protection_mask_e::PAGE_ENCLAVE_UNVALIDATED,
            nt32::win32_protection_mask_e::PAGE_ENCLAVE_DECOMMIT,
    };

    template <typename T, size_t N>
    static std::vector<const char*> win32_protection_mask_dump(uint32_t arg, const T (&masks)[N])
    {
        std::vector<const char*> values;
        for(auto it : masks)
            if(arg & static_cast<uint32_t>(it))
                values.emplace_back(win32_protection_mask_str(it));
        return values;
    }
}

const char* nt32::win32_protection_mask(win32_protection_mask_e arg)
{
    return win32_protection_mask_str(arg);
}

std::vector<const char*> nt32::win32_protection_mask_dump(uint32_t arg)
{
    return ::win32_protection_mask_dump(arg, nt32_win32_protection_masks);
}