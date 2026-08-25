module;

#include <algorithm>
#include <cstdint>
#include <limits>

export module miotal.util;

export namespace miotal::util {

template <typename T, typename... Args>
constexpr auto make_mask(Args... args) {
	return ((static_cast<T>(1u) << args) | ...);
}

template <typename T>
class Bitmask
{
public:
	template <typename... Args>
	constexpr Bitmask(const Args... args) : mask{make_mask<T>(args...)} {}

	const T mask;
};

} // namespace miotal::util
