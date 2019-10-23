#pragma once

#include "memory.hpp"
#include "registers.hpp"
#include "state.hpp"
#include "sym.hpp"
#include "types.hpp"

#include <memory>
#include <string_view>

namespace os { struct IModule; }

namespace core
{
    struct Data;

    struct Core
    {
         Core();
        ~Core();

        bool setup(const std::string& name);

        // private data
        std::unique_ptr<Data> d_;
    };

} // namespace core
