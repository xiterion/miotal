.SUFFIXES:

ifeq (,$(filter build,$(notdir $(CURDIR))))

OBJDIR := build

MAKETARGET = $(MAKE) --no-print-directory -C $@ -f $(CURDIR)/Makefile \
             SRCDIR=$(CURDIR) $(MAKECMDGOALS)

.PHONY: $(OBJDIR)
$(OBJDIR):
	+@[ -d $@ ] || mkdir -p $@
	+@$(MAKETARGET)

# Prevent remaking this file or any other .mk file with the build directory creation rule
Makefile : ;
%.mk :: ;

# Make everything depend on the existence of the output directory
% :: $(OBJDIR) ;

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

else

PLATFORM  := ARM/Cortex/M4/NXP/K2x
AR        := $(TARGET)gcc-ar
AS        := $(TARGET)as $(CPU)
CC        := $(TARGET)gcc $(CPU)
CXX       := $(TARGET)g++ $(CPU)
LD        := $(TARGET)gcc
NM        := $(TARGET)gcc-nm
OBJCOPY   := $(TARGET)objcopy
OBJDUMP   := $(TARGET)objdump
SIZE      := $(TARGET)size

DIRS :=
$(foreach D,$(subst /, ,$(PLATFORM)),$(eval DIRS += $(if $(DIRS),$(lastword $(DIRS)$(D)/),$(D)/)))
PLATFORM_MAKEFILES = $(DIRS:%=$(SRCDIR)/src/%Platform.mk)

.PHONY: default
default: debug

VPATH = $(SRCDIR)

$(V).SILENT:

NAME      := miotal
CFLAGS    := -I$(SRCDIR)/include
CFLAGS    += -ffreestanding -flto -ffunction-sections
CXXFLAGS  = $(CFLAGS) -std=c++17 -fno-rtti -fno-exceptions -fno-unwind-tables

CDEPEND   = $(CC) $(CFLAGS) -MM
CXXDEPEND = $(CXX) $(CXXFLAGS) -MM

LDSCRIPT  = $(SRCDIR)/src/$(PLATFORM)/platform.ld
LDFLAGS   = --specs=nano.specs --specs=nosys.specs $(CPU)
LDFLAGS   += -flto -T $(LDSCRIPT) -nostartfiles
LDFLAGS   += -Wl,--gc-sections
LDLIBS    := -lstdc++

ASOURCES              := $(foreach D,$(DIRS),$(wildcard $(SRCDIR)/src/$(D)*.s))
CSOURCES              := $(foreach D,$(DIRS),$(wildcard $(SRCDIR)/src/$(D)*.c))
CXXSOURCES            := $(foreach D,$(DIRS),$(wildcard $(SRCDIR)/src/$(D)*.cpp))
OBJECTS               := $(ASOURCES:%.s=%.o) $(CSOURCES:%.c=%.o) $(CXXSOURCES:%.cpp=%.o)
OBJECTS               := $(subst $(SRCDIR)/,,$(OBJECTS))
DEPENDENCY_FILES      := $(OBJECTS:%.o=%.d)

.PHONY: debug
debug: CFLAGS += -g -O1
debug: $(NAME).a

.PHONY: release
release: CFLAGS += -O3
release: $(NAME).a

.PHONY: test
test: CFLAGS = -I$(SRCDIR)/include
test: CXXFLAGS = $(CFLAGS) -std=c++17
test: LDFLAGS = 
test: test.exe
	./test.exe

test.exe: $(OBJECTS)
	$(info $(DIRS))
	@echo LD $@
	$(LD) -o $@ $^ $(LDFLAGS) $(LDLIBS)

$(NAME).a: $(OBJECTS)
	@echo AR $@
	$(AR) rcs --plugin=`$(CC) --print-file-name=liblto_plugin.so` $@ $^

$(NAME).elf: main.o $(NAME).a | $(LDSCRIPT)
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
	    $(CDEPEND) $< | sed -e "s@^\(.*\)\.o:@$(dir $*)\1.d $(dir $*)\1.o:@" > $@;   \
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
	    $(CXXDEPEND) $< | sed -e "s@^\(.*\)\.o:@$(dir $*)\1.d $(dir $*)\1.o:@" > $@; \
	    ;;                                                                             \
	esac

include $(PLATFORM_MAKEFILES)

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPENDENCY_FILES)
endif

$(OBJECTS) $(DEPENDENCY_FILES): Makefile

endif
