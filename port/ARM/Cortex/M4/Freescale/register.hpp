#pragma once

#include <type_traits>

#include <port/ARM/Cortex/register.hpp>

namespace port {

template <typename T, std::uint32_t bit>
struct W1C : private port::Bit<T, bit>
{
    constexpr W1C(std::uintptr_t address) : port::Bit<T, bit>(address) {};

    using port::Bit<T, bit>::read;
    void clear() { port::Bit<T, bit>::set(); }
    using port::Bit<T, bit>::to_word;
};

} // namespace port
