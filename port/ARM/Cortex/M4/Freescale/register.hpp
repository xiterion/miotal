#pragma once

#include <port/ARM/Cortex/M4/register.hpp>

namespace port {

template <uint32_t address, uint32_t bit>
struct W1C : private Bit<address, bit>
{
    using Bit<address, bit>::read;
    W1C<address, bit>& clear()
    {
        return static_cast<W1C<address, bit>&>(Bit<address, bit>::set());
    }
};

} // namespace port
