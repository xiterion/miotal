#pragma once

#include <cstdint>
#include <type_traits>
#include <util/bit_manipulation.hpp>

namespace platform {
namespace generic {

template <typename T, std::uintptr_t address>
class Generic_Register {
public:
    static T read() { return reg(); }
    
    template <typename... Args>
    static void write(Args... args) { write((read() & ~mask(args...)) | value(args...)); }

    template <typename Number>
    static typename std::enable_if<std::is_integral<Number>::value>::type
    write(Number value) { reg() = value; }

private:
    static volatile T& reg() { return *reinterpret_cast<volatile T*>(address); }

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
};

template <typename T, std::size_t offset, std::size_t width=1>
struct Generic_Bitfield {
    typedef Generic_Bitfield bits_t;
    T value;

    constexpr Generic_Bitfield(T raw) : value{raw} {}
    explicit operator T() const { return value; }

    static constexpr T mask = ((1u << width) - 1u) << offset;
    static constexpr std::size_t shift = offset;

    template <std::uintptr_t address>
    struct Bits {
        typedef Generic_Register<T, address> reg;

        Generic_Bitfield operator()() { return {reg::read()}; }
        void operator()(Generic_Bitfield value)
        { reg::write((reg::read() & ~mask) | static_cast<T>(value)); }
    };
};

} // namespace generic
} // namespace platform
