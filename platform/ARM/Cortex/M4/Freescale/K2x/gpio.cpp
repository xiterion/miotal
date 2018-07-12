#include "gpio.hpp"

namespace platform::gpio {

extern constexpr GPIOx_t GPIOA = {
    GPIOx_PDOR_t{0x400F'F000},
    GPIOx_PSOR_t{0x400F'F004},
    GPIOx_PCOR_t{0x400F'F008},
    GPIOx_PTOR_t{0x400F'F00C},
    GPIOx_PDIR_t{0x400F'F010},
    GPIOx_PDDR_t{0x400F'F014}};

extern constexpr GPIOx_t GPIOB = {
    GPIOx_PDOR_t{0x400F'F040},
    GPIOx_PSOR_t{0x400F'F044},
    GPIOx_PCOR_t{0x400F'F048},
    GPIOx_PTOR_t{0x400F'F04C},
    GPIOx_PDIR_t{0x400F'F050},
    GPIOx_PDDR_t{0x400F'F054}};
    
extern constexpr GPIOx_t GPIOC = {
    GPIOx_PDOR_t{0x400F'F080},
    GPIOx_PSOR_t{0x400F'F084},
    GPIOx_PCOR_t{0x400F'F088},
    GPIOx_PTOR_t{0x400F'F08C},
    GPIOx_PDIR_t{0x400F'F090},
    GPIOx_PDDR_t{0x400F'F094}};
    
extern constexpr GPIOx_t GPIOD = {
    GPIOx_PDOR_t{0x400F'F0C0},
    GPIOx_PSOR_t{0x400F'F0C4},
    GPIOx_PCOR_t{0x400F'F0C8},
    GPIOx_PTOR_t{0x400F'F0CC},
    GPIOx_PDIR_t{0x400F'F0D0},
    GPIOx_PDDR_t{0x400F'F0D4}};
    
extern constexpr GPIOx_t GPIOE = {
    GPIOx_PDOR_t{0x400F'F100},
    GPIOx_PSOR_t{0x400F'F104},
    GPIOx_PCOR_t{0x400F'F108},
    GPIOx_PTOR_t{0x400F'F10C},
    GPIOx_PDIR_t{0x400F'F110},
    GPIOx_PDDR_t{0x400F'F114}};

extern constexpr GPIOx_PDOR_t GPIOA_PDOR {0x400F'F000};
extern constexpr GPIOx_PSOR_t GPIOA_PSOR {0x400F'F004};
extern constexpr GPIOx_PCOR_t GPIOA_PCOR {0x400F'F008};
extern constexpr GPIOx_PTOR_t GPIOA_PTOR {0x400F'F00C};
extern constexpr GPIOx_PDIR_t GPIOA_PDIR {0x400F'F010};
extern constexpr GPIOx_PDDR_t GPIOA_PDDR {0x400F'F014};

extern constexpr GPIOx_PDOR_t GPIOB_PDOR {0x400F'F040};
extern constexpr GPIOx_PSOR_t GPIOB_PSOR {0x400F'F044};
extern constexpr GPIOx_PCOR_t GPIOB_PCOR {0x400F'F048};
extern constexpr GPIOx_PTOR_t GPIOB_PTOR {0x400F'F04C};
extern constexpr GPIOx_PDIR_t GPIOB_PDIR {0x400F'F050};
extern constexpr GPIOx_PDDR_t GPIOB_PDDR {0x400F'F054};

extern constexpr GPIOx_PDOR_t GPIOC_PDOR {0x400F'F080};
extern constexpr GPIOx_PSOR_t GPIOC_PSOR {0x400F'F084};
extern constexpr GPIOx_PCOR_t GPIOC_PCOR {0x400F'F088};
extern constexpr GPIOx_PTOR_t GPIOC_PTOR {0x400F'F08C};
extern constexpr GPIOx_PDIR_t GPIOC_PDIR {0x400F'F090};
extern constexpr GPIOx_PDDR_t GPIOC_PDDR {0x400F'F094};

extern constexpr GPIOx_PDOR_t GPIOD_PDOR {0x400F'F0C0};
extern constexpr GPIOx_PSOR_t GPIOD_PSOR {0x400F'F0C4};
extern constexpr GPIOx_PCOR_t GPIOD_PCOR {0x400F'F0C8};
extern constexpr GPIOx_PTOR_t GPIOD_PTOR {0x400F'F0CC};
extern constexpr GPIOx_PDIR_t GPIOD_PDIR {0x400F'F0D0};
extern constexpr GPIOx_PDDR_t GPIOD_PDDR {0x400F'F0D4};

extern constexpr GPIOx_PDOR_t GPIOE_PDOR {0x400F'F100};
extern constexpr GPIOx_PSOR_t GPIOE_PSOR {0x400F'F104};
extern constexpr GPIOx_PCOR_t GPIOE_PCOR {0x400F'F108};
extern constexpr GPIOx_PTOR_t GPIOE_PTOR {0x400F'F10C};
extern constexpr GPIOx_PDIR_t GPIOE_PDIR {0x400F'F110};
extern constexpr GPIOx_PDDR_t GPIOE_PDDR {0x400F'F114};

} // namespace platform::gpio
