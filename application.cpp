#include <cstdint>
#include <stdexcept>

#include <hal/pin.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/gpio.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/sim.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/wdog.hpp>

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
}

class Pin {
public:
    virtual bool read()          const = 0;
    virtual void write(bool val) const = 0;
    virtual void set()           const = 0;
    virtual void clear()         const = 0;
    virtual void toggle()        const = 0;
};

class k22_gpio : public Pin {
public:
    k22_gpio(const platform::gpio::GPIOx_t& gpio,
             const platform::port::PORTx_PCRn& pcr,
             const int pin) :
        gpio{gpio}, pcr{pcr}, pin{pin} {
            pcr.MUX(pcr.alternative_1_GPIO);
            gpio.pddr.set_output(pin);
        };

    bool read() const final { return gpio.pdir.read(pin); }
    void write(bool val) const final { gpio.pdor.write(pin); }
    void set() const final { gpio.psor.set(pin); }
    void clear() const final { gpio.pcor.clear(pin); }
    void toggle() const final { gpio.ptor.toggle(pin); }

private:
    const platform::gpio::GPIOx_t& gpio;
    const platform::port::PORTx_PCRn& pcr;
    const int pin;
};

typedef k22_gpio Pin2;

class led {
public:
    led(const Pin2& pin) : pin{pin} {
        pin.set();
    };

    void on() const { pin.clear(); }
    void off() const { pin.set(); }

private:
    const Pin2& pin;
};

int main(void)
{
    k22_gpio pa1{platform::gpio::GPIOA, platform::port::PORTA_PCR1, 1};
    k22_gpio pa2{platform::gpio::GPIOA, platform::port::PORTA_PCR2, 2};
    k22_gpio pd5{platform::gpio::GPIOD, platform::port::PORTD_PCR5, 5};

    led   red{pa1};
    led green{pa2};
    led  blue{pd5};

    red.on();

    while(1) {}
}
