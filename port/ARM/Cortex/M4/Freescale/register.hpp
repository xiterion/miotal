#pragma once

#include <type_traits>

#include <port/ARM/Cortex/register.hpp>

namespace port {

template <typename T>
struct W1C : private port::Bit<T>
{
    constexpr W1C(std::uintptr_t address, std::uint32_t bit) : port::Bit<T>(address, bit) {};

    using port::Bit<T>::read;
    void clear() { port::Bit<T>::set(); }
    using port::Bit<T>::to_word;
};

} // namespace port
