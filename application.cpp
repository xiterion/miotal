#include <cstdint>
#include <stdexcept>

#include <hal/pin.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/gpio.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/sim.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/wdog.hpp>

extern "C" void low_level_init() {
//    using namespace platform::wdog;
//    WDOG_UNLOCK.unlock();
//    WDOG_STCTRLH.write(WDOG_STCTRLH.disable_watchdog);

    using namespace platform::sim;
    SIM_SCGC5.enable_clock(SIM_SCGC5.PORTA,
                           SIM_SCGC5.PORTB,
                           SIM_SCGC5.PORTC,
                           SIM_SCGC5.PORTD,
                           SIM_SCGC5.PORTE);
}

template <typename base, template<typename> typename type>
class crtp {
public:
    base& impl() { return static_cast<base&>(*this); }
    const base& impl() const { return static_cast<const base&>(*this); }
private:
    crtp() = default;
    friend type<base>;
};

template <typename base>
class pin_interface : public crtp<base, pin_interface> {
public:
    bool read()          const { return this->impl()._read(); }
    void write(bool val) const { this->impl()._write(val); }
    void set()           const { this->impl()._set(); }
    void clear()         const { this->impl()._clear(); }
    void toggle()        const { this->impl()._toggle(); }
};

class Pin {
public:
    bool read()          const { return _read(); }
    void write(bool val) const { _write(val); }
    void set()           const { _set(); }
    void clear()         const { _clear(); }
    void toggle()        const { _toggle(); }
private:
    virtual bool _read() const = 0;
    virtual void _write(bool val) const = 0;
    virtual void _set() const = 0;
    virtual void _clear() const = 0;
    virtual void _toggle() const = 0;
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

private:
    const platform::gpio::GPIOx_t& gpio;
    const platform::port::PORTx_PCRn& pcr;
    const int pin;

    bool _read() const final { return gpio.pdir.read(pin); }
    void _write(bool val) const final { gpio.pdor.write(pin); }
    void _set() const final { gpio.psor.set(pin); }
    void _clear() const final { gpio.pcor.clear(pin); }
    void _toggle() const final { gpio.ptor.toggle(pin); }
};

class led {
public:
    led(const Pin& pin) : pin{pin} {
        pin.set();
    };

    void on() const { pin.clear(); }
    void off() const { pin.set(); }

private:
    const Pin& pin;
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
