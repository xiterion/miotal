#pragma once

#include <cstdint>

namespace port {
namespace internal {

#if defined(DEFINE_REGISTERS)
#define extern
#endif

extern volatile std::uint32_t  PORTA_PCR0;
extern volatile std::uint32_t  PORTA_PCR1;
extern volatile std::uint32_t  PORTA_PCR2;
extern volatile std::uint32_t  PORTA_PCR3;
extern volatile std::uint32_t  PORTA_PCR4;
extern volatile std::uint32_t  PORTA_PCR5;
extern volatile std::uint32_t  PORTA_PCR6;
extern volatile std::uint32_t  PORTA_PCR7;
extern volatile std::uint32_t  PORTA_PCR8;
extern volatile std::uint32_t  PORTA_PCR9;
extern volatile std::uint32_t PORTA_PCR10;
extern volatile std::uint32_t PORTA_PCR11;
extern volatile std::uint32_t PORTA_PCR12;
extern volatile std::uint32_t PORTA_PCR13;
extern volatile std::uint32_t PORTA_PCR14;
extern volatile std::uint32_t PORTA_PCR15;
extern volatile std::uint32_t PORTA_PCR16;
extern volatile std::uint32_t PORTA_PCR17;
extern volatile std::uint32_t PORTA_PCR18;
extern volatile std::uint32_t PORTA_PCR19;
extern volatile std::uint32_t PORTA_PCR20;
extern volatile std::uint32_t PORTA_PCR21;
extern volatile std::uint32_t PORTA_PCR22;
extern volatile std::uint32_t PORTA_PCR23;
extern volatile std::uint32_t PORTA_PCR24;
extern volatile std::uint32_t PORTA_PCR25;
extern volatile std::uint32_t PORTA_PCR26;
extern volatile std::uint32_t PORTA_PCR27;
extern volatile std::uint32_t PORTA_PCR28;
extern volatile std::uint32_t PORTA_PCR29;
extern volatile std::uint32_t PORTA_PCR30;
extern volatile std::uint32_t PORTA_PCR31;

} // namespace internal

} // namespace port

#include "port.hpp"
