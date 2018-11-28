ifeq (,$(filter build,$(notdir $(CURDIR))))
include target.mk
else

.SUFFIXES:

VPATH = $(SRCDIR)

$(V).SILENT:

NAME      := test
CPU       := -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb
PLATFORM  := ARM/Cortex/M4/NXP/K2x
AS        := arm-none-eabi-as $(CPU)
CC        := arm-none-eabi-gcc $(CPU)
CXX       := arm-none-eabi-g++ $(CPU)
OBJCOPY   := arm-none-eabi-objcopy
ASFLAGS   := 
CFLAGS    := -I$(SRCDIR)/include
CFLAGS    += -I$(SRCDIR)/src
CFLAGS    += -ffreestanding -flto -ffunction-sections
CXXFLAGS  = $(CFLAGS) -std=c++17 -fno-rtti -fno-exceptions -fno-unwind-tables

CDEPEND   = arm-none-eabi-gcc $(CFLAGS) -MM
CXXDEPEND = arm-none-eabi-g++ $(CXXFLAGS) -MM

LD        := arm-none-eabi-gcc
LDFLAGS   := --specs=nano.specs $(CPU)
LDFLAGS   += -flto -T ../lib/ldscripts/ARM/Cortex/M4/NXP/K2x.ld -nostartfiles
LDFLAGS   += -Wl,--gc-sections
LDLIBS    := -lstdc++

SIZE      := arm-none-eabi-size

rwildcard = $(strip $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d)))

ASOURCES              := $(call rwildcard,$(SRCDIR),*.s)
CSOURCES              := $(call rwildcard,$(SRCDIR),*.c)
CXXSOURCES            := $(call rwildcard,$(SRCDIR),*.cpp)
OBJECTS               := $(ASOURCES:%.s=%.o) $(CSOURCES:%.c=%.o) $(CXXSOURCES:%.cpp=%.o)
OBJECTS               := $(subst $(SRCDIR)/,,$(OBJECTS))
DEPENDENCY_FILES      := $(OBJECTS:%.o=%.d)

.PHONY: default
default: debug

.PHONY: debug
debug: CFLAGS += -g -O1
debug: $(NAME).elf $(NAME).bin

.PHONY: release
release: CFLAGS += -O3
release: $(NAME).elf $(NAME).bin


$(NAME).elf: $(OBJECTS) | lib/ldscripts/ARM/Cortex/M4/NXP/K2x.ld
	@echo LD $@
	$(LD) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	$(SIZE) $@

$(NAME).bin: $(NAME).elf
	@echo OBJCOPY $@
	$(OBJCOPY) -O binary $< $@

%.o: %.cpp %.d
	@echo CXX $@
	$(CXX) -c $< -o $@ $(CXXFLAGS)

%.o: %.c %.d
	@echo CC $@
	$(CC) -c $< -o $@ $(CFLAGS)

%.o: %.s
	@echo AS $@
	$(AS) $< -o $@ $(ASFLAGS)

%.d: %.c
	@echo CDEPEND $@
	+@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	case "$(dir $*)" in                                                             \
	  "" | "." | "./")                                                                 \
	    $(CDEPEND) $< | sed -e 's@^\(.*\)\.o:@\1.d \1.o:@' > $@;                       \
	    ;;                                                                             \
	  *)                                                                               \
	    $(CDEPEND) $< | sed -e "s@^\(.*\)\.o:@$(dir $*)/\1.d $(dir $*)/\1.o:@" > $@;   \
	    ;;                                                                             \
	esac

%.d: %.cpp
	@echo CXXDEPEND $@
	+@[ -d $(dir $@) ] || mkdir -p $(dir $@)
	case "$(dir $*)" in                                                             \
	  "" | "." | "./")                                                                 \
	    $(CXXDEPEND) $< | sed -e 's@^\(.*\)\.o:@\1.d \1.o:@' > $@;                     \
	    ;;                                                                             \
	  *)                                                                               \
	    $(CXXDEPEND) $< | sed -e "s@^\(.*\)\.o:@$(dir $*)/\1.d $(dir $*)/\1.o:@" > $@; \
	    ;;                                                                             \
	esac

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPENDENCY_FILES)
endif

$(OBJECTS) $(DEPENDENCY_FILES): Makefile

endif
