# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/medrobotics/kinect

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/medrobotics/kinect

# Include any dependencies generated for this target.
include CMakeFiles/kinect_read.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kinect_read.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kinect_read.dir/flags.make

CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o: CMakeFiles/kinect_read.dir/flags.make
CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o: src/kinect_read.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/medrobotics/kinect/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o -c /home/medrobotics/kinect/src/kinect_read.cpp

CMakeFiles/kinect_read.dir/src/kinect_read.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kinect_read.dir/src/kinect_read.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/medrobotics/kinect/src/kinect_read.cpp > CMakeFiles/kinect_read.dir/src/kinect_read.cpp.i

CMakeFiles/kinect_read.dir/src/kinect_read.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kinect_read.dir/src/kinect_read.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/medrobotics/kinect/src/kinect_read.cpp -o CMakeFiles/kinect_read.dir/src/kinect_read.cpp.s

CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o.requires:

.PHONY : CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o.requires

CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o.provides: CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o.requires
	$(MAKE) -f CMakeFiles/kinect_read.dir/build.make CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o.provides.build
.PHONY : CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o.provides

CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o.provides.build: CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o


# Object files for target kinect_read
kinect_read_OBJECTS = \
"CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o"

# External object files for target kinect_read
kinect_read_EXTERNAL_OBJECTS =

kinect_read: CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o
kinect_read: CMakeFiles/kinect_read.dir/build.make
kinect_read: /home/medrobotics/freenect2/lib/libfreenect2.so
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_gapi.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_highgui.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_ml.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_objdetect.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_photo.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_stitching.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_video.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_videoio.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_dnn.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_imgcodecs.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_calib3d.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_features2d.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_flann.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_imgproc.so.4.5.2
kinect_read: /home/medrobotics/opencv/build/lib/libopencv_core.so.4.5.2
kinect_read: CMakeFiles/kinect_read.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/medrobotics/kinect/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kinect_read"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kinect_read.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kinect_read.dir/build: kinect_read

.PHONY : CMakeFiles/kinect_read.dir/build

CMakeFiles/kinect_read.dir/requires: CMakeFiles/kinect_read.dir/src/kinect_read.cpp.o.requires

.PHONY : CMakeFiles/kinect_read.dir/requires

CMakeFiles/kinect_read.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kinect_read.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kinect_read.dir/clean

CMakeFiles/kinect_read.dir/depend:
	cd /home/medrobotics/kinect && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/medrobotics/kinect /home/medrobotics/kinect /home/medrobotics/kinect /home/medrobotics/kinect /home/medrobotics/kinect/CMakeFiles/kinect_read.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kinect_read.dir/depend

