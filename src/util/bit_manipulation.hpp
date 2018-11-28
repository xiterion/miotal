#pragma once
#include <cstdint>
#include <limits>

namespace util {

namespace {

template <typename... Args>
constexpr auto make_mask(Args... args);

template <typename First, typename... Rest>
constexpr auto make_mask(First first, Rest... rest) {
    return (1u << first) | make_mask(rest...);
}

template <>
constexpr auto make_mask() { return 0u; }

} // anonymous namespace

template <typename T>
class Bitmask
{
public:
    template <typename... Args>
    constexpr Bitmask(const Args... args) : mask{make_mask(args...)} {}

    const T mask;
private:
};

} // namespace util
