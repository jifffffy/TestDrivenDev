# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/f/learn/samples/TestDrivenDev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/f/learn/samples/TestDrivenDev/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/RunAllTests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/RunAllTests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/RunAllTests.dir/flags.make

tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o: tests/CMakeFiles/RunAllTests.dir/flags.make
tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o: ../tests/RunAllTests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/f/learn/samples/TestDrivenDev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o"
	cd /cygdrive/f/learn/samples/TestDrivenDev/build/tests && /usr/bin/c++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o -c /cygdrive/f/learn/samples/TestDrivenDev/tests/RunAllTests.cpp

tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RunAllTests.dir/RunAllTests.cpp.i"
	cd /cygdrive/f/learn/samples/TestDrivenDev/build/tests && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E /cygdrive/f/learn/samples/TestDrivenDev/tests/RunAllTests.cpp > CMakeFiles/RunAllTests.dir/RunAllTests.cpp.i

tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RunAllTests.dir/RunAllTests.cpp.s"
	cd /cygdrive/f/learn/samples/TestDrivenDev/build/tests && /usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S /cygdrive/f/learn/samples/TestDrivenDev/tests/RunAllTests.cpp -o CMakeFiles/RunAllTests.dir/RunAllTests.cpp.s

tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o.requires:

.PHONY : tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o.requires

tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o.provides: tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o.requires
	$(MAKE) -f tests/CMakeFiles/RunAllTests.dir/build.make tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o.provides.build
.PHONY : tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o.provides

tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o.provides.build: tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o


# Object files for target RunAllTests
RunAllTests_OBJECTS = \
"CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o"

# External object files for target RunAllTests
RunAllTests_EXTERNAL_OBJECTS =

bin/RunAllTests.exe: tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o
bin/RunAllTests.exe: tests/CMakeFiles/RunAllTests.dir/build.make
bin/RunAllTests.exe: F:\learn\samples\clion\cpputest/src/CppUTest/libCppUTest.a
bin/RunAllTests.exe: lib/libLedDriverTest.a
bin/RunAllTests.exe: lib/libLedDriver.a
bin/RunAllTests.exe: lib/libRuntimeErrorStub.a
bin/RunAllTests.exe: tests/CMakeFiles/RunAllTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/f/learn/samples/TestDrivenDev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/RunAllTests.exe"
	cd /cygdrive/f/learn/samples/TestDrivenDev/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RunAllTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/RunAllTests.dir/build: bin/RunAllTests.exe

.PHONY : tests/CMakeFiles/RunAllTests.dir/build

tests/CMakeFiles/RunAllTests.dir/requires: tests/CMakeFiles/RunAllTests.dir/RunAllTests.cpp.o.requires

.PHONY : tests/CMakeFiles/RunAllTests.dir/requires

tests/CMakeFiles/RunAllTests.dir/clean:
	cd /cygdrive/f/learn/samples/TestDrivenDev/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/RunAllTests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/RunAllTests.dir/clean

tests/CMakeFiles/RunAllTests.dir/depend:
	cd /cygdrive/f/learn/samples/TestDrivenDev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/f/learn/samples/TestDrivenDev /cygdrive/f/learn/samples/TestDrivenDev/tests /cygdrive/f/learn/samples/TestDrivenDev/build /cygdrive/f/learn/samples/TestDrivenDev/build/tests /cygdrive/f/learn/samples/TestDrivenDev/build/tests/CMakeFiles/RunAllTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/RunAllTests.dir/depend

