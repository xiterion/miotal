#pragma once

#include <port/ARM/Cortex/M4/register.hpp>

namespace port {

struct W1C : private Bit
{
    constexpr W1C(hal::Register* reg, std::uint32_t bit) : Bit(reg, bit) {};

    using Bit::read;
    W1C& clear()
    {
        return static_cast<W1C&>(Bit::set());
    }
};

} // namespace port
