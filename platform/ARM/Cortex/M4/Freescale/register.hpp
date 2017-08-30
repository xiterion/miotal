#pragma once

#include <type_traits>

#include <platform/ARM/Cortex/register.hpp>

namespace platform {

template <std::size_t offset>
class W1C : private Bitfield<offset> {
};

} // namespace platform
