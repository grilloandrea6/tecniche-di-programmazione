# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /opt/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrea/uni/tecniche-di-programmazione/count_sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrea/uni/tecniche-di-programmazione/count_sort/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/count_sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/count_sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/count_sort.dir/flags.make

CMakeFiles/count_sort.dir/main.c.o: CMakeFiles/count_sort.dir/flags.make
CMakeFiles/count_sort.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrea/uni/tecniche-di-programmazione/count_sort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/count_sort.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/count_sort.dir/main.c.o   -c /home/andrea/uni/tecniche-di-programmazione/count_sort/main.c

CMakeFiles/count_sort.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/count_sort.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrea/uni/tecniche-di-programmazione/count_sort/main.c > CMakeFiles/count_sort.dir/main.c.i

CMakeFiles/count_sort.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/count_sort.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrea/uni/tecniche-di-programmazione/count_sort/main.c -o CMakeFiles/count_sort.dir/main.c.s

# Object files for target count_sort
count_sort_OBJECTS = \
"CMakeFiles/count_sort.dir/main.c.o"

# External object files for target count_sort
count_sort_EXTERNAL_OBJECTS =

count_sort: CMakeFiles/count_sort.dir/main.c.o
count_sort: CMakeFiles/count_sort.dir/build.make
count_sort: CMakeFiles/count_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrea/uni/tecniche-di-programmazione/count_sort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable count_sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/count_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/count_sort.dir/build: count_sort

.PHONY : CMakeFiles/count_sort.dir/build

CMakeFiles/count_sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/count_sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/count_sort.dir/clean

CMakeFiles/count_sort.dir/depend:
	cd /home/andrea/uni/tecniche-di-programmazione/count_sort/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrea/uni/tecniche-di-programmazione/count_sort /home/andrea/uni/tecniche-di-programmazione/count_sort /home/andrea/uni/tecniche-di-programmazione/count_sort/cmake-build-debug /home/andrea/uni/tecniche-di-programmazione/count_sort/cmake-build-debug /home/andrea/uni/tecniche-di-programmazione/count_sort/cmake-build-debug/CMakeFiles/count_sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/count_sort.dir/depend
