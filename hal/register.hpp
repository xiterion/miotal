#pragma once

#include <cstdint>

namespace hal {

template <std::uint32_t address>
struct Register
{
    std::uint32_t read() const { return *reinterpret_cast<volatile std::uint32_t*>(address); }
    Register<address>& write(const std::uint32_t& value)
    {
        *reinterpret_cast<volatile std::uint32_t*>(address) = value;
        return *this;
    }
};

template <std::uint32_t address, std::uint32_t bit>
struct Bit : private Register<address>
{
    bool read() const { return Register<address>::read() & (1 << bit); }
    Bit<address, bit>& set()
    {
        Register<address>::write(Register<address>::read() | (1 << bit));
        return *this;
    }
    Bit<address, bit>& clear()
    {
        Register<address>::write(Register<address>::read() & ~(1 << bit));
        return *this;
    }
    Bit<address, bit>& write(const bool& value) { return value ? set() : clear(); }
};

} // namespace hal
