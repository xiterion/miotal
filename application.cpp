#include <cstdint>

#include <hal/pin.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/gpio.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/sim.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/wdog.hpp>

class led {
public:
    led(const platform::gpio::GPIOx_t& gpio, const platform::port::PORTx_PCRn& pcr, const int pin) :
        gpio{gpio}, pcr{pcr}, pin{pin} {
            pcr.MUX(pcr.alternative_1_GPIO);
        };

    void on() const { gpio.pcor.clear(pin); }
    void off() const { gpio.psor.set(pin); }

private:
    const platform::gpio::GPIOx_t& gpio;
    const platform::port::PORTx_PCRn& pcr;
    const int pin;
};

int main(void)
{
    led   red{platform::gpio::GPIOA, platform::port::PORTA_PCR1, 1};
    led green{platform::gpio::GPIOA, platform::port::PORTA_PCR2, 2};
    led  blue{platform::gpio::GPIOD, platform::port::PORTD_PCR5, 5};

    using namespace platform::sim;
    SIM_SCGC5.enable_clock(SIM_SCGC5.PORTA,
                           SIM_SCGC5.PORTB,
                           SIM_SCGC5.PORTC,
                           SIM_SCGC5.PORTD,
                           SIM_SCGC5.PORTE);

    using namespace platform::port;

    using namespace platform::gpio;
    GPIOA_PDDR.set_output(1,2);
    GPIOD_PDDR.set_output(5);
    GPIOA_PSOR.set(1,2);
    GPIOD_PSOR.set(5);

    red.on();
    green.on();
    blue.on();

    while(1) {}
}
