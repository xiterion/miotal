#pragma once
#include <initializer_list>
#include <cstdint>

namespace util {

namespace {

template <typename... Args>
constexpr std::uint32_t make_mask(Args... args);

template <typename First, typename... Rest>
constexpr std::uint32_t make_mask(First first, Rest... rest) {
    return (1u << first) | make_mask(rest...);
}

template <>
constexpr std::uint32_t make_mask() { return 0u; }

} // anonymous namespace

class Bitmask
{
public:
    template <typename... Args>
    constexpr Bitmask(Args... args) : mask{make_mask(args...)} {}

    const std::uint32_t mask;
};

} // namespace util
