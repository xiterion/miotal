#include <cstdint>

#include <hal/pin.hpp>
#include <platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp>

/*
class Pin : public hal::GPIO {
public:
    Pin(const platform::port::PORTx_PCRn& pcr) : pcr{pcr} {}

    bool read() final {};
    void write() final {};
    bool toggle() final {};
private:
    const platform::port::PORTx_PCRn& pcr;
};
*/

class Foo {
public:
    Foo() {
        using namespace platform::port;
        PORTA_PCR1.MUX(PORTA_PCR1.alternative_1_GPIO);
        PORTA_PCR2.MUX(PORTA_PCR2.alternative_1_GPIO);
        PORTD_PCR5.MUX(PORTD_PCR5.alternative_1_GPIO);
        // PDOR
        *reinterpret_cast<volatile uint32_t*>(0x400F'F014) = (1 << 1) | (1 << 2);
        *reinterpret_cast<volatile uint32_t*>(0x400F'F0D4) = (1 << 5);

        // PSOR
        *reinterpret_cast<volatile uint32_t*>(0x400F'F004) = (1 << 1) | (1 << 2);
        *reinterpret_cast<volatile uint32_t*>(0x400F'F0C4) = (1 << 5);

        *reinterpret_cast<volatile uint32_t*>(0x400F'F0C4) = (1 << 5);
    }
};

static Foo foo;

extern "C" void low_level_init() {
    *reinterpret_cast<volatile std::uint16_t*>(0x4005'200E) = 0xC520;
    *reinterpret_cast<volatile std::uint16_t*>(0x4005'200E) = 0xD928;
    asm("nop");
    *reinterpret_cast<volatile std::uint16_t*>(0x4005'2000) = 0b0000'0001'0000'0000;

    *reinterpret_cast<volatile std::uint32_t*>(0x4004'8038) = 
        0b0000'0000'0000'0100'0011'1111'1000'0010;
}

int main(void)
{
    /*
    *reinterpret_cast<volatile uint32_t*>(0x400F'F008) = (1 << 1);
    *reinterpret_cast<volatile uint32_t*>(0x400F'F004) = (1 << 1);
    *reinterpret_cast<volatile uint32_t*>(0x400F'F008) = (1 << 2);
    *reinterpret_cast<volatile uint32_t*>(0x400F'F004) = (1 << 2);
    *reinterpret_cast<volatile uint32_t*>(0x400F'F0C4) = (1 << 5);
    *reinterpret_cast<volatile uint32_t*>(0x400F'F0C0) = (1 << 5);
    */
}
