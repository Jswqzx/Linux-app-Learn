# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jswqzx/Linux_Study/Lession2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jswqzx/Linux_Study/Lession2

# Include any dependencies generated for this target.
include CMakeFiles/paa.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/paa.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/paa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/paa.dir/flags.make

CMakeFiles/paa.dir/Mq_Consumer.cpp.o: CMakeFiles/paa.dir/flags.make
CMakeFiles/paa.dir/Mq_Consumer.cpp.o: Mq_Consumer.cpp
CMakeFiles/paa.dir/Mq_Consumer.cpp.o: CMakeFiles/paa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jswqzx/Linux_Study/Lession2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/paa.dir/Mq_Consumer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/paa.dir/Mq_Consumer.cpp.o -MF CMakeFiles/paa.dir/Mq_Consumer.cpp.o.d -o CMakeFiles/paa.dir/Mq_Consumer.cpp.o -c /home/jswqzx/Linux_Study/Lession2/Mq_Consumer.cpp

CMakeFiles/paa.dir/Mq_Consumer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/paa.dir/Mq_Consumer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jswqzx/Linux_Study/Lession2/Mq_Consumer.cpp > CMakeFiles/paa.dir/Mq_Consumer.cpp.i

CMakeFiles/paa.dir/Mq_Consumer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/paa.dir/Mq_Consumer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jswqzx/Linux_Study/Lession2/Mq_Consumer.cpp -o CMakeFiles/paa.dir/Mq_Consumer.cpp.s

# Object files for target paa
paa_OBJECTS = \
"CMakeFiles/paa.dir/Mq_Consumer.cpp.o"

# External object files for target paa
paa_EXTERNAL_OBJECTS =

paa: CMakeFiles/paa.dir/Mq_Consumer.cpp.o
paa: CMakeFiles/paa.dir/build.make
paa: CMakeFiles/paa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jswqzx/Linux_Study/Lession2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable paa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/paa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/paa.dir/build: paa
.PHONY : CMakeFiles/paa.dir/build

CMakeFiles/paa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/paa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/paa.dir/clean

CMakeFiles/paa.dir/depend:
	cd /home/jswqzx/Linux_Study/Lession2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jswqzx/Linux_Study/Lession2 /home/jswqzx/Linux_Study/Lession2 /home/jswqzx/Linux_Study/Lession2 /home/jswqzx/Linux_Study/Lession2 /home/jswqzx/Linux_Study/Lession2/CMakeFiles/paa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/paa.dir/depend

