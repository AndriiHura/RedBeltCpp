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
CMAKE_COMMAND = /snap/clion/124/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/124/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/W2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/W2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/W2.dir/flags.make

CMakeFiles/W2.dir/CLionTestProject.cpp.o: CMakeFiles/W2.dir/flags.make
CMakeFiles/W2.dir/CLionTestProject.cpp.o: ../CLionTestProject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/W2.dir/CLionTestProject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/W2.dir/CLionTestProject.cpp.o -c /home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2/CLionTestProject.cpp

CMakeFiles/W2.dir/CLionTestProject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/W2.dir/CLionTestProject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2/CLionTestProject.cpp > CMakeFiles/W2.dir/CLionTestProject.cpp.i

CMakeFiles/W2.dir/CLionTestProject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/W2.dir/CLionTestProject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2/CLionTestProject.cpp -o CMakeFiles/W2.dir/CLionTestProject.cpp.s

# Object files for target W2
W2_OBJECTS = \
"CMakeFiles/W2.dir/CLionTestProject.cpp.o"

# External object files for target W2
W2_EXTERNAL_OBJECTS =

W2: CMakeFiles/W2.dir/CLionTestProject.cpp.o
W2: CMakeFiles/W2.dir/build.make
W2: CMakeFiles/W2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable W2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/W2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/W2.dir/build: W2

.PHONY : CMakeFiles/W2.dir/build

CMakeFiles/W2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/W2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/W2.dir/clean

CMakeFiles/W2.dir/depend:
	cd /home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2 /home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2 /home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2/cmake-build-debug /home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2/cmake-build-debug /home/andriihura/CLionProjects/CppBelts/RedBeltCpp/W2/cmake-build-debug/CMakeFiles/W2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/W2.dir/depend

