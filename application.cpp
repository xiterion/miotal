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

int main(void)
{
    GPIO foo;
    InterruptCapable& bar = foo;
    bar.enableInterrupt();
    platform::PORTA_PCR0.ISF.clear();
}
