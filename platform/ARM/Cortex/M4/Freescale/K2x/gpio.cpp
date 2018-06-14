#include "gpio.hpp"

namespace platform::gpio {

extern const GPIOx_PDOR_t GPIOA_PDOR {0x400F'F000};
extern const GPIOx_PSOR_t GPIOA_PSOR {0x400F'F004};
extern const GPIOx_PCOR_t GPIOA_PCOR {0x400F'F008};
extern const GPIOx_PTOR_t GPIOA_PTOR {0x400F'F00C};
extern const GPIOx_PDIR_t GPIOA_PDIR {0x400F'F010};
extern const GPIOx_PDDR_t GPIOA_PDDR {0x400F'F014};

extern const GPIOx_PDOR_t GPIOB_PDOR {0x400F'F040};
extern const GPIOx_PSOR_t GPIOB_PSOR {0x400F'F044};
extern const GPIOx_PCOR_t GPIOB_PCOR {0x400F'F048};
extern const GPIOx_PTOR_t GPIOB_PTOR {0x400F'F04C};
extern const GPIOx_PDIR_t GPIOB_PDIR {0x400F'F050};
extern const GPIOx_PDDR_t GPIOB_PDDR {0x400F'F054};

extern const GPIOx_PDOR_t GPIOC_PDOR {0x400F'F080};
extern const GPIOx_PSOR_t GPIOC_PSOR {0x400F'F084};
extern const GPIOx_PCOR_t GPIOC_PCOR {0x400F'F088};
extern const GPIOx_PTOR_t GPIOC_PTOR {0x400F'F08C};
extern const GPIOx_PDIR_t GPIOC_PDIR {0x400F'F090};
extern const GPIOx_PDDR_t GPIOC_PDDR {0x400F'F094};

extern const GPIOx_PDOR_t GPIOD_PDOR {0x400F'F0C0};
extern const GPIOx_PSOR_t GPIOD_PSOR {0x400F'F0C4};
extern const GPIOx_PCOR_t GPIOD_PCOR {0x400F'F0C8};
extern const GPIOx_PTOR_t GPIOD_PTOR {0x400F'F0CC};
extern const GPIOx_PDIR_t GPIOD_PDIR {0x400F'F0D0};
extern const GPIOx_PDDR_t GPIOD_PDDR {0x400F'F0D4};

extern const GPIOx_PDOR_t GPIOE_PDOR {0x400F'F100};
extern const GPIOx_PSOR_t GPIOE_PSOR {0x400F'F104};
extern const GPIOx_PCOR_t GPIOE_PCOR {0x400F'F108};
extern const GPIOx_PTOR_t GPIOE_PTOR {0x400F'F10C};
extern const GPIOx_PDIR_t GPIOE_PDIR {0x400F'F110};
extern const GPIOx_PDDR_t GPIOE_PDDR {0x400F'F114};

} // namespace platform::gpio
