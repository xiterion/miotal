.SUFFIXES:

.PHONY: default
default: debug

V         := @

NAME      := test
CPU       += -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb
PLATFORM  := platform/ARM/Cortex/M4/Freescale/K2x
AS        := arm-none-eabi-as $(CPU)
CC        := arm-none-eabi-gcc $(CPU) -c
CXX       := arm-none-eabi-g++ $(CPU) -c
OBJCOPY   := arm-none-eabi-objcopy
ASFLAGS   := 
CFLAGS    := -I.
CFLAGS    += -ffreestanding
CFLAGS    += -flto
CFLAGS    += -ffunction-sections
CXXFLAGS  := -std=c++17
CXXFLAGS  += -fno-rtti -fno-exceptions -fno-unwind-tables

CDEPEND   := arm-none-eabi-gcc $(CFLAGS) -MM
CXXDEPEND := arm-none-eabi-g++ $(CFLAGS) $(CXXFLAGS) -MM

LD        := arm-none-eabi-gcc --specs=nano.specs --specs=nosys.specs $(CPU)
LDFLAGS   := -flto -T $(PLATFORM)/platform.ld -nostartfiles
LDFLAGS   += -Wl,--gc-sections
LDLIBS    := -lstdc++

SIZE      := arm-none-eabi-size

rwildcard = $(strip $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d)))

ASOURCES              := $(call rwildcard,./,*.s)
CSOURCES              := $(call rwildcard,./,*.c)
CXXSOURCES            := $(call rwildcard,./,*.cpp)
OBJECTS               := $(ASOURCES:%.s=%.o) $(CSOURCES:%.c=%.o) $(CXXSOURCES:%.cpp=%.o)
DEPENDENCY_FILES      := $(OBJECTS:%.o=%.d)
OBJECT_BUILD_TREE     := $(sort $(filter-out ./,$(dir $(OBJECTS))))

.PHONY: test
test: CFLAGS += -g
test: $(NAME).elf

.PHONY: debug
debug: CFLAGS += -g -O1
debug: $(NAME).elf $(NAME).bin

.PHONY: release
release: CFLAGS += -O3
release: $(NAME).elf $(NAME).bin

.PHONY: list
list: debug
	arm-none-eabi-objdump -C -S $(NAME).elf | less

.PHONY: nm
nm: debug
	arm-none-eabi-gcc-nm -n $(NAME).elf

$(NAME).elf: $(OBJECTS)
	@echo LD $@
	$V $(LD) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	$V $(SIZE) $@

$(NAME).bin: $(NAME).elf
	@echo OBJCOPY $@
	$V $(OBJCOPY) -O binary $< $@

%.o: %.cpp %.d
	@echo CXX $@
	$V $(CXX) $< -o $@ $(CFLAGS) $(CXXFLAGS)

%.o: %.c %.d
	@echo CC $@
	$V $(CC) $< -o $@ $(CFLAGS)

%.o: %.s
	@echo AS $@
	$V $(AS) $< -o $@ $(ASFLAGS)

%.d: %.c
	@echo CDEPEND $@
	$V case "$(dir $*)" in                                                             \
	  "" | "." | "./")                                                                 \
	    $(CDEPEND) $< | sed -e 's@^\(.*\)\.o:@\1.d \1.o:@' > $@;                       \
	    ;;                                                                             \
	  *)                                                                               \
	    $(CDEPEND) $< | sed -e "s@^\(.*\)\.o:@$(dir $*)/\1.d $(dir $*)/\1.o:@" > $@;   \
	    ;;                                                                             \
	esac

%.d: %.cpp
	@echo CXXDEPEND $@
	$V case "$(dir $*)" in                                                             \
	  "" | "." | "./")                                                                 \
	    $(CXXDEPEND) $< | sed -e 's@^\(.*\)\.o:@\1.d \1.o:@' > $@;                     \
	    ;;                                                                             \
	  *)                                                                               \
	    $(CXXDEPEND) $< | sed -e "s@^\(.*\)\.o:@$(dir $*)/\1.d $(dir $*)/\1.o:@" > $@; \
	    ;;                                                                             \
	esac


-include $(DEPENDENCY_FILES)

$(OBJECTS) $(DEPENDENCY_FILES): Makefile $(PLATFORM)/platform.ld

.PHONY: clean
clean:
	rm -f $(NAME).elf $(OBJECTS)

.PHONY: cleandeps
cleandeps:
	rm -f $(DEPENDENCY_FILES)

.PHONY: cleanall
cleanall: clean cleandeps
