.SUFFIXES:

ifeq (,$(filter build,$(notdir $(CURDIR))))

OBJDIR := build

.PHONY: $(OBJDIR)
$(OBJDIR):
	+@[ -d $@ ] || mkdir -p $@
	+@$(MAKE) --no-print-directory -C $@ -f $(CURDIR)/Makefile SRCDIR=$(CURDIR)/src $(MAKECMDGOALS)

# Prevent remaking this file or any other .mk file with the build directory creation rule
Makefile : ;
%.mk :: ;

# Make everything depend on the existence of the output directory
% :: $(OBJDIR) ;

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

else

.SECONDEXPANSION:

VPATH = $(SRCDIR)

ifeq (,$(filter test,$(MAKECMDGOALS)))
PLATFORM := miotal/ARM/Cortex/M4/NXP/K2x
else
PLATFORM := test
endif

AR        = $(TARGET)gcc-ar
AS        = $(TARGET)as $(CPU)
CC        = $(TARGET)gcc $(CPU)
CXX       = $(TARGET)g++ $(CPU)
LD        = $(TARGET)gcc
NM        = $(TARGET)gcc-nm
OBJCOPY   = $(TARGET)objcopy
OBJDUMP   = $(TARGET)objdump
SIZE      = $(TARGET)size

DIRS :=
$(foreach D,$(subst /, ,$(PLATFORM)),$(eval DIRS += $(if $(DIRS),$(lastword $(DIRS)$(D)/),$(D)/)))
PLATFORM_MAKEFILES = $(DIRS:%=$(SRCDIR)/%Platform.mk)
DIRS += ./ miotal/util/

.PHONY: default
default: debug

$(V).SILENT:

NAME      := miotal
CFLAGS    := -I$(SRCDIR)/../include
CFLAGS    += -ffreestanding -flto -ffunction-sections
CXXFLAGS  = $(CFLAGS) -std=c++23 -fmodules-ts -fno-rtti -fno-exceptions -fno-unwind-tables

CDEPEND   := $(CC) $(CFLAGS) -MM
CXXDEPEND := $(CXX) $(CXXFLAGS) -MMD -E

LDSCRIPT  = $(SRCDIR)/$(PLATFORM)/platform.ld
LDFLAGS   = --specs=nano.specs --specs=nosys.specs $(CPU)
LDFLAGS   += -flto -T $(LDSCRIPT) -nostartfiles
LDFLAGS   += -Wl,--gc-sections
LDLIBS    := -lstdc++

ASOURCES              := $(foreach D,$(DIRS),$(wildcard $(SRCDIR)/$(D)*.s))
CSOURCES              := $(foreach D,$(DIRS),$(wildcard $(SRCDIR)/$(D)*.c))
CXXSOURCES            := $(foreach D,$(DIRS),$(wildcard $(SRCDIR)/$(D)*.cpp))
OBJECTS               := $(ASOURCES:%.s=%.o) $(CSOURCES:%.c=%.o) $(CXXSOURCES:%.cpp=%.o)
OBJECTS               := $(subst $(SRCDIR)/,,$(OBJECTS))
DEPENDENCY_FILES      := $(OBJECTS:%.o=%.d)

.PHONY: debug
debug: CFLAGS += -g -O1
debug: $(NAME).elf

.PHONY: release
release: CFLAGS += -O3
release: $(NAME).elf

.PHONY: test
test: CFLAGS   = -I$(SRCDIR)/../include
test: CXXFLAGS = $(CFLAGS) -std=c++23 -fmodules-ts
test: LDFLAGS  = 
test: test.exe
	./test.exe

test.exe: $(OBJECTS)
	@echo LD $@
	$(LD) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(NAME).elf: $(OBJECTS) | $(LDSCRIPT)
	@echo LD $@
	$(LD) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	$(SIZE) $@

$(NAME).bin: $(NAME).elf
	@echo OBJCOPY $@
	$(OBJCOPY) -O binary $< $@

%.o: %.cpp
	@echo CXX $@
	$(CXX) -c $< -o $@ $(CXXFLAGS)

%.o: %.c
	@echo CC $@
	$(CC) -c $< -o $@ $(CFLAGS)

%.o: %.s
	@echo AS $@
	$(AS) $< -o $@ $(ASFLAGS)

%.d: %.c
	@echo CDEPEND $@
	+@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	$(CDEPEND) $< -MT $*.o -MF $@ 1> /dev/null

%.d: %.cpp
	@echo CXXDEPEND $@
	+@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	$(CXXDEPEND) $< -MT $*.o -MF $@ 1> /dev/null
	# The following script is terrible. I'm sorry. This will likely change
	# as support for c++ modules grows in gcc. The result of this script
	# makes object files dependent on the compiled module interface of all
	# imported modules. The compiled module interface is dependent on the
	# object file of the interface, and that object is dependent on the
	# respective source file. Finally, object file names are modified to
	# have a path corresponding to the path to the source, so names of
	# source files within the OS and HAL directories do not accidentally
	# collide with user source names. Module names can still collide, due
	# to the way C++ modules work.
	sed -i $@\
	    -e :a -e'/\\$$/N; s/\\\n//; ta' \
	    -e '/^.PHONY/d' \
	    -e '/^CXX_IMPORTS/d' \
	    -e '/.*\.c++m: /d' \
	    -e 's@\(.*\.gcm:\)|\( .*\)@\1 $*\.o@' \
	    -e 's@\(\S\+\):\(\S\+\)@\1-\2@g' \
	    -e 's@: \(.*\).c++m@: gcm.cache/\1.gcm@'
	#    -e 's@$(notdir $*)\.o.*: \(.*\)\.c++m\$$@$*.o: gcm.cache\/\1.gcm@'

$(OBJECTS) $(DEPENDENCY_FILES): ../Makefile $(wildcard $(PLATFORM_MAKEFILES))

-include $(PLATFORM_MAKEFILES)

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPENDENCY_FILES)

endif

endif
