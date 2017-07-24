#pragma once

#include "platform.hpp"

#if defined(DEFINE_SYMBOLS)
#define SYMBOL(type, name, ...) type name(__VA_ARGS__)
#else // !defined(DEFINE_SYMBOLS)
#define SYMBOL(type, name, ...) extern type name
#endif

namespace platform {

SYMBOL(PORTx_PCRn, PORTA_PCR0, 0x4004'9000);

} // namespace platform

#undef SYMBOL
