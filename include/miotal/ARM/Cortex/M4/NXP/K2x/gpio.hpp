#pragma once

#include <array>
#include <functional>

#include <miotal/util/bit_manipulation.hpp>
#include <miotal/ARM/Cortex/M4/NXP/register.hpp>

namespace platform::gpio {

struct GPIOx_PDOR_t : public Register<std::uint32_t> {
};

struct GPIOx_PSOR_t : public Register<std::uint32_t> {
    template <typename... Pins>
    void set(const Pins... pins) volatile { write(util::Bitmask<std::uint32_t>{pins...}.mask); }
};

struct GPIOx_PCOR_t : public Register<std::uint32_t> {
    template <typename... Pins>
    void clear(const Pins... pins) { write(util::Bitmask<std::uint32_t>{pins...}.mask); }
};

struct GPIOx_PTOR_t : public Register<std::uint32_t> {
    template <typename... Pins>
    void toggle(const Pins... pins) { write(util::Bitmask<std::uint32_t>{pins...}.mask); }
};

struct GPIOx_PDIR_t : public Register<std::uint32_t> {
    template <typename... Pins>
    bool read(const Pins... pins) { return read() & util::Bitmask<std::uint32_t>{pins...}.mask; }
};

struct GPIOx_PDDR_t : public Register<std::uint32_t> {

    template <typename... Pins>
    void set_output(const Pins... pins) {
        write(read() | util::Bitmask<std::uint32_t>{pins...}.mask); }
    template <typename... Pins>
    void set_input(const Pins... pins) {
        write(read() & ~util::Bitmask<std::uint32_t>{pins...}.mask); }
};
/*
struct GPIOx_t {
    const GPIOx_PDOR_t pdor;
    const GPIOx_PSOR_t psor;
    const GPIOx_PCOR_t pcor;
    const GPIOx_PTOR_t ptor;
    const GPIOx_PDIR_t pdir;
    const GPIOx_PDDR_t pddr;
};

extern const GPIOx_t GPIOA;
extern const GPIOx_t GPIOB;
extern const GPIOx_t GPIOC;
extern const GPIOx_t GPIOD;
extern const GPIOx_t GPIOE;
*/
extern volatile GPIOx_PDOR_t& GPIOA_PDOR;
extern volatile GPIOx_PSOR_t& GPIOA_PSOR;
extern volatile GPIOx_PCOR_t& GPIOA_PCOR;
extern volatile GPIOx_PTOR_t& GPIOA_PTOR;
extern volatile GPIOx_PDIR_t& GPIOA_PDIR;
extern volatile GPIOx_PDDR_t& GPIOA_PDDR;

extern volatile GPIOx_PDOR_t& GPIOB_PDOR;
extern volatile GPIOx_PSOR_t& GPIOB_PSOR;
extern volatile GPIOx_PCOR_t& GPIOB_PCOR;
extern volatile GPIOx_PTOR_t& GPIOB_PTOR;
extern volatile GPIOx_PDIR_t& GPIOB_PDIR;
extern volatile GPIOx_PDDR_t& GPIOB_PDDR;

extern volatile GPIOx_PDOR_t& GPIOC_PDOR;
extern volatile GPIOx_PSOR_t& GPIOC_PSOR;
extern volatile GPIOx_PCOR_t& GPIOC_PCOR;
extern volatile GPIOx_PTOR_t& GPIOC_PTOR;
extern volatile GPIOx_PDIR_t& GPIOC_PDIR;
extern volatile GPIOx_PDDR_t& GPIOC_PDDR;

extern volatile GPIOx_PDOR_t& GPIOD_PDOR;
extern volatile GPIOx_PSOR_t& GPIOD_PSOR;
extern volatile GPIOx_PCOR_t& GPIOD_PCOR;
extern volatile GPIOx_PTOR_t& GPIOD_PTOR;
extern volatile GPIOx_PDIR_t& GPIOD_PDIR;
extern volatile GPIOx_PDDR_t& GPIOD_PDDR;

extern volatile GPIOx_PDOR_t& GPIOE_PDOR;
extern volatile GPIOx_PSOR_t& GPIOE_PSOR;
extern volatile GPIOx_PCOR_t& GPIOE_PCOR;
extern volatile GPIOx_PTOR_t& GPIOE_PTOR;
extern volatile GPIOx_PDIR_t& GPIOE_PDIR;
extern volatile GPIOx_PDDR_t& GPIOE_PDDR;

} // namespace platform::gpio
