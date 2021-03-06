#pragma once

#include <climits>
#include <cstdint>
#include <type_traits>

namespace platform {
namespace generic {

template <typename R, std::size_t msb, std::size_t lsb=msb>
struct Bitfield {
	static_assert(msb < sizeof(typename R::reg_t)*CHAR_BIT, "Bitfield not inside parent type");

	const typename R::reg_t value;
	static constexpr std::size_t offset = lsb;
	static constexpr std::size_t width = msb-lsb+1;
	static constexpr typename R::reg_t mask = ((1u << width) - 1u) << offset;

	constexpr Bitfield(typename R::reg_t raw) : value{raw} {}

	static Bitfield decode(const volatile R* reg) {
		return Bitfield{static_cast<typename R::reg_t>((reg->read() & mask) >> offset)};
	}
	void update(volatile R* reg) { reg->write((reg->read() & ~mask) | (value << offset)); }

	Bitfield operator~() const { 
		return Bitfield<R, msb, lsb>{static_cast<typename R::reg_t>(~value & (mask >> offset))};
	}

	bool operator==(const Bitfield<R, msb, lsb>& other) {
		return value == other.value;
	}
};

template <typename T, typename... Args>
inline constexpr T mask(Args... args);

template <typename T, typename First, typename... Rest>
inline constexpr T mask(First first, Rest... rest) { return mask<T>(first) | mask<T>(rest...); }

template <typename T, typename Last>
inline constexpr T mask(Last last) { return last.mask; }

template <typename T, typename... Args>
inline constexpr T value(Args... args);

template <typename T, typename First, typename... Rest>
inline constexpr T value(First first, Rest... rest) { return value<T>(first) | value<T>(rest...); }

template <typename T, typename Last>
inline constexpr T value(Last last) { return last.value << last.offset; }

template <typename T>
class Generic_Register {
public:
	const std::uintptr_t addr;

	typedef T reg_t;

	T read() const volatile { return raw(); }
	
	template <typename Number>
	typename std::enable_if_t<std::is_integral<Number>::value>
	write(Number value) volatile { raw() = value; }

	template <typename... Args>
	void write(Args... args) volatile { write((read() & ~mask<T>(args...)) | value<T>(args...)); }

//	Generic_Register(std::uintptr_t addr) : addr{addr} {};

private:
	auto& raw() volatile { return *reinterpret_cast<volatile T*>(addr); }
	auto& raw() const volatile { return *reinterpret_cast<const volatile T*>(addr); }
};

} // namespace generic
} // namespace platform
