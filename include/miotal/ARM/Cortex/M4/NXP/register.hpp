#pragma once

#include <type_traits>

#include <miotal/ARM/Cortex/register.hpp>

namespace platform {

template <typename R, std::size_t bit>
struct W1C : public Bitfield<R, bit> {
	struct clear_flag {};
	static void clear(volatile R* reg) { Bitfield<R, bit>{true}.update(reg); }
};

} // namespace platform
