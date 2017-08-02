#pragma once

#include "../util/InheritsFrom.hpp"

namespace hal {

template <typename T, template<typename> typename crtpType>
class crtp {
public:
    friend crtpType<T>;

    T& impl() { return static_cast<T&>(*this); }
    const T& impl() const { return static_cast<const T&>(*this); }
private:
    crtp() = default;
};

template <typename T>
class DriveStrengthAdjustable : crtp<T, DriveStrengthAdjustable> {
public:
    float getDriveStrength() { return this->impl().getDriveStrength(); }
    void setDriveStrengthAbove(float level) { this->impl().setDriveStrengthAbove(level); }
    void setDriveStrengthBelow(float level) { this->impl().setDriveStrengthBelow(level); }
    void setDriveStrengthBetween(float lower_level, float upper_level)
        { this->impl().setDriveStrengthBetween(lower_level, upper_level); }
};

template <typename T>
class OpenDrainCapable : crtp<T, OpenDrainCapable> {
public:
    void enableOpenDrain() { this->impl().enableOpenDrain(); }
    void disableOpenDrain() { this->impl().disableOpenDrain(); }
    bool openDrainEnabled() { this->impl().openDrainEnabled(); }
};

} // namespace hal
