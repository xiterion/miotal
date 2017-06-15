#pragma once

#include "../util/InheritsFrom.hpp"

namespace hal {

template <typename impl, typename... interfaces>
class Pin : public impl
{
public:
    Pin(impl& hw) {};
private:
    static util::InheritsFrom<impl, interfaces...> check;
};

class InterruptCapable
{
public:
    virtual bool interruptActive() const = 0;
};

class OpenDrainCapable
{
public:
    virtual bool openDrainEnabled() const = 0;
};

} // namespace hal
