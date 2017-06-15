#pragma once

#include <port/ARM/Cortex/M4/register.hpp>

namespace port {

template <uint32_t bit>
struct W1C : private Bit<bit>
{
    constexpr W1C(hal::Register* reg) : Bit<bit>(reg) {};

    using Bit<bit>::read;
    W1C<bit>& clear()
    {
        return static_cast<W1C<bit>&>(Bit<bit>::set());
    }
};

} // namespace port
