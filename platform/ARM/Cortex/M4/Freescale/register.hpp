#pragma once

#include <type_traits>

#include <platform/ARM/Cortex/register.hpp>

namespace platform {

template <typename T, std::uint32_t bit>
struct W1C : private platform::Bit<T, bit>
{
    constexpr W1C(std::uintptr_t address) : platform::Bit<T, bit>{address} {};

    using platform::Bit<T, bit>::read;
    void clear() { platform::Bit<T, bit>::set(); }
    using platform::Bit<T, bit>::to_word;
};

} // namespace platform
