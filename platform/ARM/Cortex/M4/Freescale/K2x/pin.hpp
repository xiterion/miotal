#pragma once
#include <hal/pin.hpp>

namespace hal {

class GPIO : public DriveStrengthAdjustable<GPIO>,
             public OpenDrainCapable<GPIO>
{
public:
    GPIO(platform::PORTx_PCRn pcr) : pcr{pcr} {}

    float getDriveStrength() { return 0.0f; }
    void setDriveStrengthAbove(float level) {}
    void setDriveStrengthBelow(float level) {}
    void setDriveStrengthBetween(float lower_level, float upper_level) {}

    void enableOpenDrain() { pcr.ODE.set(); }
    void disableOpenDrain() { pcr.ODE.clear(); }
    bool openDrainEnabled() { static_cast<bool>(pcr.ODE.read()); }

private:
    platform::PORTx_PCRn pcr;
};

} // namespace hal
