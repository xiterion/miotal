# miotal
Embedded microprocessor bare metal framework

# Build system
The build system starts with a makefile named Makefile in the root directory.
Invoking make with no arguments will look for a directory named "build" and if
not found, will create it. This directory contains all generated outputs and
compiler intermediate files used in the build process, as well as the outputs.
The primary output is "miotal.elf" which contains the entire executable image
linked for flashing to your target program.

The build system is intended to be effective for projects that use the miotal
operating system and hardware abstraction library for relatively self contained
embedded projects. The build system follows this order of operations:

1. Check for existance of a build directory and create it if missing.
2. Reinvoke make inside the new output directory, using VPATH to point at the
   original source directory.
2. Build a list of all source containing directories in DIRS.
3. Create a dependency file foo.d for every source file foo.cpp.
4. Include the dependency definitions in the created dependency files to the
   current set of makefile rules.
5. Definitions for how to build a .o from a .cpp are included in the base
   Makefile.
6. This newly created set of dependency rules now defines the build order,
   finding files that are out of date and performing incremental builds
   automatically.
