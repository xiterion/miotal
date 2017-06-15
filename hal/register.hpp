#pragma once

#include <cstdint>

namespace hal {

class Register
{
public:
    constexpr Register(std::uint32_t address) : address(address) {};

    std::uint32_t read() const { return *reinterpret_cast<volatile std::uint32_t*>(address); }
    Register& write(const std::uint32_t& value)
    {
        *reinterpret_cast<volatile std::uint32_t*>(address) = value;
        return *this;
    }

    const std::uint32_t address;
};

template <std::uint32_t bit>
class Bit : private Register
{
public:
    constexpr Bit(Register* reg) : reg(*reg) {};

    bool read() const { return reg.read() & (1 << bit); }
    Bit<bit>& set()
    {
        reg.write(reg.read() | (1 << bit));
        return *this;
    }
    Bit<bit>& clear()
    {
        reg.write(reg.read() & ~(1 << bit));
        return *this;
    }
    Bit<bit>& write(const bool& value) { return value ? set() : clear(); }
private:
    Register& reg;
};

} // namespace hal
