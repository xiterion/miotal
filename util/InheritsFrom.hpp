#pragma once

#include <type_traits>

namespace util {

template <typename...>
class InheritsFrom;

template <typename Derived, typename First, typename... Rest>
class InheritsFrom<Derived, First, Rest...> : public InheritsFrom<Derived, Rest...>
{
    static_assert(std::is_base_of<First, Derived>::value,
    "Implementation does not satisfy all interfaces");
};

template <typename Derived>
class InheritsFrom<Derived> {};

} // namespace util
