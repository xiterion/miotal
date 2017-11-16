#pragma once

#include <cstdint>
#include <type_traits>
#include <util/bit_manipulation.hpp>

namespace platform {
namespace generic {

template <typename T, typename Derived>
class Generic_Register {
public:
    const std::uintptr_t address;

    constexpr Generic_Register(std::uintptr_t address) : address{address} {}

    T read() const { return reg(); }
    
    template <typename... Args>
    std::enable_if_t<std::conjunction<
        std::is_same<typename Args::register_t, Derived>...>::value>
    write(Args... args) const { write((read() & ~mask(args...)) | value(args...)); }

    template <typename Number>
    typename std::enable_if_t<std::is_integral<Number>::value>
    write(Number value) const { reg() = value; }

    template <typename... Args>
    static constexpr T mask(Args... args);

    template <typename First, typename... Rest>
    static constexpr T mask(First first, Rest... rest) { return mask(first) | mask(rest...); }

    template <typename Last>
    static constexpr T mask(Last last) { return last.mask; }

    template <typename... Args>
    static constexpr T value(Args... args);

    template <typename First, typename... Rest>
    static constexpr T value(First first, Rest... rest) { return value(first) | value(rest...); }

    template <typename Last>
    static constexpr T value(Last last) { return last.value << last.shift; }

private:
    volatile T& reg() const { return *reinterpret_cast<volatile T*>(address); }
};

template <typename T, typename Reg, std::size_t offset, std::size_t width=1>
struct Generic_Bitfield {
    typedef Reg register_t;

    const T value;

    static constexpr T mask = ((1u << width) - 1u) << offset;
    static constexpr std::size_t shift = offset;

    constexpr Generic_Bitfield(T raw) : value{raw} {}
    constexpr Generic_Bitfield(Reg r) : value{(r & mask) >> shift} {}

    static Generic_Bitfield read(const Reg& instance) { return {instance.read()}; }
    static void write(const Reg& instance, Generic_Bitfield val) {
        instance.write((instance.read() & ~val.mask) | (val.value << val.shift));
    }
};

} // namespace generic
} // namespace platform
