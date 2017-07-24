#include <utility>
#include "hal/pin.hpp"
#include "platform/ARM/Cortex/M4/Freescale/K2x/platform.hpp"

using namespace hal;

class GPIO : public InterruptCapable, public OpenDrainCapable {
public:
    void enableInterrupt() final {;}
    void disableInterrupt() final {;}
    bool interruptEnabled() final { return false; }

    void enableOpenDrain() final {;}
    void disableOpenDrain() final {;}
    bool openDrainEnabled() final { return false; }
};

template <typename... Args>
void foo(Args... args) { ; }

int main(void)
{
    platform::PORTA_PCR0.initialize(
            platform::Interrupt_Configuration::disabled,
            platform::Lock_Register::disabled,
            platform::Pin_Mux_Control::alternative_1_GPIO,
            platform::Drive_Strength::high,
            platform::Open_Drain::disabled,
            platform::Passive_Filter::disabled,
            platform::Slew_Rate::fast,
            platform::Internal_Pull::disabled,
            platform::Pull_Select::down);
}
