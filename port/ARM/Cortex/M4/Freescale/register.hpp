#pragma once

#include <type_traits>

#include <port/ARM/Cortex/register.hpp>

namespace port {

struct W1C : private port::Bit
{
    constexpr W1C(std::uintptr_t address, std::uint32_t bit) : port::Bit(address, bit) {};

    using port::Bit::read;
    void clear() { port::Bit::set(); }
    using port::Bit::to_word;
};

} // namespace port
