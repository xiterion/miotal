#pragma once

#include <array>
#include <functional>

#include <boost/preprocessor/repetition/repeat.hpp>

#include <util/bit_manipulation.hpp>
#include <platform/ARM/Cortex/M4/Freescale/register.hpp>

namespace platform::gpio {

struct GPIOx_PDOR_t : public Register<GPIOx_PDOR_t> {
    using Register<GPIOx_PDOR_t>::Register;
};

struct GPIOx_PSOR_t : public Register<GPIOx_PSOR_t> {
    using Register<GPIOx_PSOR_t>::Register;

    template <typename... Pins>
    void set(const Pins... pins) const { write(util::Bitmask<std::uint32_t>{pins...}.mask); }
/*
    void set(const int pin) const {
        std::uintptr_t addr = platform::generic::get_bitband_address(address, pin);
        Register<GPIOx_PSOR_t>{addr}.write(1);
    }
    */
};

struct GPIOx_PCOR_t : public Register<GPIOx_PCOR_t> {
    using Register<GPIOx_PCOR_t>::Register;

    template <typename... Pins>
    void clear(const Pins... pins) const { write(util::Bitmask<std::uint32_t>{pins...}.mask); }
};

struct GPIOx_PTOR_t : public Register<GPIOx_PTOR_t> {
    using Register<GPIOx_PTOR_t>::Register;

    template <typename... Pins>
    void toggle(const Pins... pins) const { write(util::Bitmask<std::uint32_t>{pins...}.mask); }
};

struct GPIOx_PDIR_t : public Register<GPIOx_PDIR_t> {
    using Register<GPIOx_PDIR_t>::Register;

    template <typename... Pins>
    bool read(const Pins... pins) const { read() & util::Bitmask<std::uint32_t>{pins...}.mask; }
};

struct GPIOx_PDDR_t : public Register<GPIOx_PDDR_t> {
    using Register<GPIOx_PDDR_t>::Register;

    template <typename... Pins>
    void set_output(const Pins... pins) const {
        write(read() | util::Bitmask<std::uint32_t>{pins...}.mask); }
    template <typename... Pins>
    void set_input(const Pins... pins) const {
        write(read() & ~util::Bitmask<std::uint32_t>{pins...}.mask); }
};

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

extern const GPIOx_PDOR_t GPIOA_PDOR;
extern const GPIOx_PSOR_t GPIOA_PSOR;
extern const GPIOx_PCOR_t GPIOA_PCOR;
extern const GPIOx_PTOR_t GPIOA_PTOR;
extern const GPIOx_PDIR_t GPIOA_PDIR;
extern const GPIOx_PDDR_t GPIOA_PDDR;

extern const GPIOx_PDOR_t GPIOB_PDOR;
extern const GPIOx_PSOR_t GPIOB_PSOR;
extern const GPIOx_PCOR_t GPIOB_PCOR;
extern const GPIOx_PTOR_t GPIOB_PTOR;
extern const GPIOx_PDIR_t GPIOB_PDIR;
extern const GPIOx_PDDR_t GPIOB_PDDR;

extern const GPIOx_PDOR_t GPIOC_PDOR;
extern const GPIOx_PSOR_t GPIOC_PSOR;
extern const GPIOx_PCOR_t GPIOC_PCOR;
extern const GPIOx_PTOR_t GPIOC_PTOR;
extern const GPIOx_PDIR_t GPIOC_PDIR;
extern const GPIOx_PDDR_t GPIOC_PDDR;

extern const GPIOx_PDOR_t GPIOD_PDOR;
extern const GPIOx_PSOR_t GPIOD_PSOR;
extern const GPIOx_PCOR_t GPIOD_PCOR;
extern const GPIOx_PTOR_t GPIOD_PTOR;
extern const GPIOx_PDIR_t GPIOD_PDIR;
extern const GPIOx_PDDR_t GPIOD_PDDR;

extern const GPIOx_PDOR_t GPIOE_PDOR;
extern const GPIOx_PSOR_t GPIOE_PSOR;
extern const GPIOx_PCOR_t GPIOE_PCOR;
extern const GPIOx_PTOR_t GPIOE_PTOR;
extern const GPIOx_PDIR_t GPIOE_PDIR;
extern const GPIOx_PDDR_t GPIOE_PDDR;

} // namespace platform::gpio
