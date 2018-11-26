#include "gpio.hpp"

namespace platform::gpio {
/*
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
*/
volatile GPIOx_PDOR_t& GPIOA_PDOR = *reinterpret_cast<volatile GPIOx_PDOR_t*> (0x400F'F000);
volatile GPIOx_PSOR_t& GPIOA_PSOR = *reinterpret_cast<volatile GPIOx_PSOR_t*> (0x400F'F004);
volatile GPIOx_PCOR_t& GPIOA_PCOR = *reinterpret_cast<volatile GPIOx_PCOR_t*> (0x400F'F008);
volatile GPIOx_PTOR_t& GPIOA_PTOR = *reinterpret_cast<volatile GPIOx_PTOR_t*> (0x400F'F00C);
volatile GPIOx_PDIR_t& GPIOA_PDIR = *reinterpret_cast<volatile GPIOx_PDIR_t*> (0x400F'F010);
volatile GPIOx_PDDR_t& GPIOA_PDDR = *reinterpret_cast<volatile GPIOx_PDDR_t*> (0x400F'F014);

volatile GPIOx_PDOR_t& GPIOB_PDOR = *reinterpret_cast<volatile GPIOx_PDOR_t*> (0x400F'F040);
volatile GPIOx_PSOR_t& GPIOB_PSOR = *reinterpret_cast<volatile GPIOx_PSOR_t*> (0x400F'F044);
volatile GPIOx_PCOR_t& GPIOB_PCOR = *reinterpret_cast<volatile GPIOx_PCOR_t*> (0x400F'F048);
volatile GPIOx_PTOR_t& GPIOB_PTOR = *reinterpret_cast<volatile GPIOx_PTOR_t*> (0x400F'F04C);
volatile GPIOx_PDIR_t& GPIOB_PDIR = *reinterpret_cast<volatile GPIOx_PDIR_t*> (0x400F'F050);
volatile GPIOx_PDDR_t& GPIOB_PDDR = *reinterpret_cast<volatile GPIOx_PDDR_t*> (0x400F'F054);

volatile GPIOx_PDOR_t& GPIOC_PDOR = *reinterpret_cast<volatile GPIOx_PDOR_t*> (0x400F'F080);
volatile GPIOx_PSOR_t& GPIOC_PSOR = *reinterpret_cast<volatile GPIOx_PSOR_t*> (0x400F'F084);
volatile GPIOx_PCOR_t& GPIOC_PCOR = *reinterpret_cast<volatile GPIOx_PCOR_t*> (0x400F'F088);
volatile GPIOx_PTOR_t& GPIOC_PTOR = *reinterpret_cast<volatile GPIOx_PTOR_t*> (0x400F'F08C);
volatile GPIOx_PDIR_t& GPIOC_PDIR = *reinterpret_cast<volatile GPIOx_PDIR_t*> (0x400F'F090);
volatile GPIOx_PDDR_t& GPIOC_PDDR = *reinterpret_cast<volatile GPIOx_PDDR_t*> (0x400F'F094);

volatile GPIOx_PDOR_t& GPIOD_PDOR = *reinterpret_cast<volatile GPIOx_PDOR_t*> (0x400F'F0C0);
volatile GPIOx_PSOR_t& GPIOD_PSOR = *reinterpret_cast<volatile GPIOx_PSOR_t*> (0x400F'F0C4);
volatile GPIOx_PCOR_t& GPIOD_PCOR = *reinterpret_cast<volatile GPIOx_PCOR_t*> (0x400F'F0C8);
volatile GPIOx_PTOR_t& GPIOD_PTOR = *reinterpret_cast<volatile GPIOx_PTOR_t*> (0x400F'F0CC);
volatile GPIOx_PDIR_t& GPIOD_PDIR = *reinterpret_cast<volatile GPIOx_PDIR_t*> (0x400F'F0D0);
volatile GPIOx_PDDR_t& GPIOD_PDDR = *reinterpret_cast<volatile GPIOx_PDDR_t*> (0x400F'F0D4);

volatile GPIOx_PDOR_t& GPIOE_PDOR = *reinterpret_cast<volatile GPIOx_PDOR_t*> (0x400F'F100);
volatile GPIOx_PSOR_t& GPIOE_PSOR = *reinterpret_cast<volatile GPIOx_PSOR_t*> (0x400F'F104);
volatile GPIOx_PCOR_t& GPIOE_PCOR = *reinterpret_cast<volatile GPIOx_PCOR_t*> (0x400F'F108);
volatile GPIOx_PTOR_t& GPIOE_PTOR = *reinterpret_cast<volatile GPIOx_PTOR_t*> (0x400F'F10C);
volatile GPIOx_PDIR_t& GPIOE_PDIR = *reinterpret_cast<volatile GPIOx_PDIR_t*> (0x400F'F110);
volatile GPIOx_PDDR_t& GPIOE_PDDR = *reinterpret_cast<volatile GPIOx_PDDR_t*> (0x400F'F114);

} // namespace platform::gpio
