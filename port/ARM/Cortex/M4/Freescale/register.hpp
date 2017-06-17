#pragma once

#include <port/ARM/Cortex/M4/register.hpp>

namespace port {

struct W1C : private Bit
{
    inline constexpr W1C(Register* reg, std::uint32_t bit);

    using Bit::read;
    inline void clear();
};

constexpr W1C::W1C(Register* reg, std::uint32_t bit) :
    Bit(reg, bit) {};

void W1C::clear()
{
    Bit::set();
}

} // namespace port
