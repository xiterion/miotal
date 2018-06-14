#include <cstdint>

#include <hal/pin.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/gpio.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/sim.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/wdog.hpp>

#define RED_ON    platform::gpio::GPIOA_PCOR.clear(1)
#define RED_OFF   platform::gpio::GPIOA_PSOR.set(1)
#define GREEN_ON  platform::gpio::GPIOA_PCOR.clear(2)
#define GREEN_OFF platform::gpio::GPIOA_PSOR.set(2)
#define BLUE_ON   platform::gpio::GPIOD_PCOR.clear(5)
#define BLUE_OFF  platform::gpio::GPIOD_PSOR.set(5)

extern "C" void low_level_init() {
    using namespace platform::wdog;
    WDOG_UNLOCK.unlock();
    WDOG_STCTRLH.write(WDOG_STCTRLH.disable_watchdog);

    using namespace platform::sim;
    SIM_SCGC5.enable_clock(SIM_SCGC5.PORTA,
                           SIM_SCGC5.PORTB,
                           SIM_SCGC5.PORTC,
                           SIM_SCGC5.PORTD,
                           SIM_SCGC5.PORTE);

    using namespace platform::port;
    PORTA_PCR1.MUX(PORTA_PCR1.alternative_1_GPIO);
    PORTA_PCR2.MUX(PORTA_PCR2.alternative_1_GPIO);
    PORTD_PCR5.MUX(PORTD_PCR5.alternative_1_GPIO);

    using namespace platform::gpio;
    GPIOA_PDDR.set_output(1,2);
    GPIOD_PDDR.set_output(5);

    GPIOA_PSOR.set(1,2);
    GPIOD_PSOR.set(5);
}

struct Foo {
    Foo() { BLUE_ON; }
};

Foo foo;

int main(void)
{
    while(1) {}
    /*
    *reinterpret_cast<volatile uint32_t*>(0x400F'F008) = (1 << 1);
    *reinterpret_cast<volatile uint32_t*>(0x400F'F004) = (1 << 1);
    *reinterpret_cast<volatile uint32_t*>(0x400F'F008) = (1 << 2);
    *reinterpret_cast<volatile uint32_t*>(0x400F'F004) = (1 << 2);
    *reinterpret_cast<volatile uint32_t*>(0x400F'F0C4) = (1 << 5);
    *reinterpret_cast<volatile uint32_t*>(0x400F'F0C0) = (1 << 5);
    */
}
