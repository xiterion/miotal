#pragma once

#include <type_traits>

#include <platform/ARM/Cortex/register.hpp>

namespace platform {

template <typename Reg, std::size_t offset>
struct W1C : private Bitfield<Reg, offset> {
    using Bitfield<Reg, offset>::Bitfield;
    using Bitfield<Reg, offset>::read;
    struct clear_flag {};
    static void clear(Reg& instance) { Bitfield<Reg, offset>::write(instance, 1); }
};

} // namespace platform
