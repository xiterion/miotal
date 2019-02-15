#pragma once

namespace hal {

template <typename... Capabilities>
class Pin : public Capabilities... {
public:
	Pin() {
	}
};

class Open_drain {
public:
	virtual void configure_hardware() = 0;
};

class Passive_filter {
public:
	virtual void configure_hardware() = 0;
};

class Variable_slew_rate {
public:
	virtual void configure_hardware() = 0;
};

class Pull_up {
public:
	virtual void configure_hardware() = 0;
};

class Pull_down {
public:
	virtual void configure_hardware() = 0;
};


} // namespace hal
