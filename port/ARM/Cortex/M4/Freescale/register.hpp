#pragma once

#include <type_traits>

#include <port/ARM/Cortex/register.hpp>

namespace port {
/*
struct W1C : private port::Bit
{
    constexpr W1C(Register* reg, std::uint32_t bit) : port::Bit(reg, bit) {};

    using port::Bit::read;
    void clear() { port::Bit::set(); }
};
*/
} // namespace port
