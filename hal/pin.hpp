#pragma once

#include "../util/InheritsFrom.hpp"

namespace hal {

class DriveStrengthAdjustable {
public:
    virtual float getDriveStrength() = 0;
    virtual void setDriveStrengthAbove(float level) = 0;
    virtual void setDriveStrengthBelow(float level) = 0;
    virtual void setDriveStrengthBetween(float lower_level, float upper_level) = 0;
};

class OpenDrainCapable {
public:
    virtual void enableOpenDrain() = 0;
    virtual void disableOpenDrain() = 0;
    virtual bool openDrainEnabled() = 0;
};

} // namespace hal
