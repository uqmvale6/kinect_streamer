# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/uqmvale6/kinect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uqmvale6/kinect

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/bin/cmake-gui -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/uqmvale6/kinect/CMakeFiles /home/uqmvale6/kinect//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/uqmvale6/kinect/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named kinect_write

# Build rule for target.
kinect_write: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 kinect_write
.PHONY : kinect_write

# fast build rule for target.
kinect_write/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/kinect_write.dir/build.make CMakeFiles/kinect_write.dir/build
.PHONY : kinect_write/fast

#=============================================================================
# Target rules for targets named kinect_read

# Build rule for target.
kinect_read: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 kinect_read
.PHONY : kinect_read

# fast build rule for target.
kinect_read/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/kinect_read.dir/build.make CMakeFiles/kinect_read.dir/build
.PHONY : kinect_read/fast

src/kinect_read.o: src/kinect_read.cpp.o
.PHONY : src/kinect_read.o

# target to build an object file
src/kinect_read.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/kinect_read.dir/build.make CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o
.PHONY : src/kinect_read.cpp.o

src/kinect_read.i: src/kinect_read.cpp.i
.PHONY : src/kinect_read.i

# target to preprocess a source file
src/kinect_read.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/kinect_read.dir/build.make CMakeFiles/kinect_read.dir/src/kinect_read.cpp.i
.PHONY : src/kinect_read.cpp.i

src/kinect_read.s: src/kinect_read.cpp.s
.PHONY : src/kinect_read.s

# target to generate assembly for a file
src/kinect_read.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/kinect_read.dir/build.make CMakeFiles/kinect_read.dir/src/kinect_read.cpp.s
.PHONY : src/kinect_read.cpp.s

src/kinect_write.o: src/kinect_write.cpp.o
.PHONY : src/kinect_write.o

# target to build an object file
src/kinect_write.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/kinect_write.dir/build.make CMakeFiles/kinect_write.dir/src/kinect_write.cpp.o
.PHONY : src/kinect_write.cpp.o

src/kinect_write.i: src/kinect_write.cpp.i
.PHONY : src/kinect_write.i

# target to preprocess a source file
src/kinect_write.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/kinect_write.dir/build.make CMakeFiles/kinect_write.dir/src/kinect_write.cpp.i
.PHONY : src/kinect_write.cpp.i

src/kinect_write.s: src/kinect_write.cpp.s
.PHONY : src/kinect_write.s

# target to generate assembly for a file
src/kinect_write.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/kinect_write.dir/build.make CMakeFiles/kinect_write.dir/src/kinect_write.cpp.s
.PHONY : src/kinect_write.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... kinect_read"
	@echo "... kinect_write"
	@echo "... src/kinect_read.o"
	@echo "... src/kinect_read.i"
	@echo "... src/kinect_read.s"
	@echo "... src/kinect_write.o"
	@echo "... src/kinect_write.i"
	@echo "... src/kinect_write.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

