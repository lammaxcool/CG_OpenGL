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
CMAKE_COMMAND = /snap/clion/137/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/137/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/max/Documents/CG_OpenGL/CG_Lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/src/main.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/main.cpp.o -c /home/max/Documents/CG_OpenGL/CG_Lab3/src/main.cpp

CMakeFiles/project.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/Documents/CG_OpenGL/CG_Lab3/src/main.cpp > CMakeFiles/project.dir/src/main.cpp.i

CMakeFiles/project.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/Documents/CG_OpenGL/CG_Lab3/src/main.cpp -o CMakeFiles/project.dir/src/main.cpp.s

CMakeFiles/project.dir/src/glad.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/glad.c.o: ../src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/project.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/src/glad.c.o   -c /home/max/Documents/CG_OpenGL/CG_Lab3/src/glad.c

CMakeFiles/project.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/max/Documents/CG_OpenGL/CG_Lab3/src/glad.c > CMakeFiles/project.dir/src/glad.c.i

CMakeFiles/project.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/max/Documents/CG_OpenGL/CG_Lab3/src/glad.c -o CMakeFiles/project.dir/src/glad.c.s

CMakeFiles/project.dir/src/ElementBuffer.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/ElementBuffer.cpp.o: ../src/ElementBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project.dir/src/ElementBuffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/ElementBuffer.cpp.o -c /home/max/Documents/CG_OpenGL/CG_Lab3/src/ElementBuffer.cpp

CMakeFiles/project.dir/src/ElementBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/ElementBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/Documents/CG_OpenGL/CG_Lab3/src/ElementBuffer.cpp > CMakeFiles/project.dir/src/ElementBuffer.cpp.i

CMakeFiles/project.dir/src/ElementBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/ElementBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/Documents/CG_OpenGL/CG_Lab3/src/ElementBuffer.cpp -o CMakeFiles/project.dir/src/ElementBuffer.cpp.s

CMakeFiles/project.dir/src/VertexBuffer.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/VertexBuffer.cpp.o: ../src/VertexBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project.dir/src/VertexBuffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/VertexBuffer.cpp.o -c /home/max/Documents/CG_OpenGL/CG_Lab3/src/VertexBuffer.cpp

CMakeFiles/project.dir/src/VertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/VertexBuffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/Documents/CG_OpenGL/CG_Lab3/src/VertexBuffer.cpp > CMakeFiles/project.dir/src/VertexBuffer.cpp.i

CMakeFiles/project.dir/src/VertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/VertexBuffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/Documents/CG_OpenGL/CG_Lab3/src/VertexBuffer.cpp -o CMakeFiles/project.dir/src/VertexBuffer.cpp.s

CMakeFiles/project.dir/src/VertexArray.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/VertexArray.cpp.o: ../src/VertexArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project.dir/src/VertexArray.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/VertexArray.cpp.o -c /home/max/Documents/CG_OpenGL/CG_Lab3/src/VertexArray.cpp

CMakeFiles/project.dir/src/VertexArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/VertexArray.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/Documents/CG_OpenGL/CG_Lab3/src/VertexArray.cpp > CMakeFiles/project.dir/src/VertexArray.cpp.i

CMakeFiles/project.dir/src/VertexArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/VertexArray.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/Documents/CG_OpenGL/CG_Lab3/src/VertexArray.cpp -o CMakeFiles/project.dir/src/VertexArray.cpp.s

CMakeFiles/project.dir/src/stb_image.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/stb_image.cpp.o: ../src/stb_image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/project.dir/src/stb_image.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/stb_image.cpp.o -c /home/max/Documents/CG_OpenGL/CG_Lab3/src/stb_image.cpp

CMakeFiles/project.dir/src/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/stb_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/Documents/CG_OpenGL/CG_Lab3/src/stb_image.cpp > CMakeFiles/project.dir/src/stb_image.cpp.i

CMakeFiles/project.dir/src/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/stb_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/Documents/CG_OpenGL/CG_Lab3/src/stb_image.cpp -o CMakeFiles/project.dir/src/stb_image.cpp.s

CMakeFiles/project.dir/src/Sphere.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/Sphere.cpp.o: ../src/Sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/project.dir/src/Sphere.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/Sphere.cpp.o -c /home/max/Documents/CG_OpenGL/CG_Lab3/src/Sphere.cpp

CMakeFiles/project.dir/src/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/Sphere.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/Documents/CG_OpenGL/CG_Lab3/src/Sphere.cpp > CMakeFiles/project.dir/src/Sphere.cpp.i

CMakeFiles/project.dir/src/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/Sphere.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/Documents/CG_OpenGL/CG_Lab3/src/Sphere.cpp -o CMakeFiles/project.dir/src/Sphere.cpp.s

CMakeFiles/project.dir/src/Shader.cpp.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/src/Shader.cpp.o: ../src/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/project.dir/src/Shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project.dir/src/Shader.cpp.o -c /home/max/Documents/CG_OpenGL/CG_Lab3/src/Shader.cpp

CMakeFiles/project.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project.dir/src/Shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/max/Documents/CG_OpenGL/CG_Lab3/src/Shader.cpp > CMakeFiles/project.dir/src/Shader.cpp.i

CMakeFiles/project.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project.dir/src/Shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/max/Documents/CG_OpenGL/CG_Lab3/src/Shader.cpp -o CMakeFiles/project.dir/src/Shader.cpp.s

# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/src/main.cpp.o" \
"CMakeFiles/project.dir/src/glad.c.o" \
"CMakeFiles/project.dir/src/ElementBuffer.cpp.o" \
"CMakeFiles/project.dir/src/VertexBuffer.cpp.o" \
"CMakeFiles/project.dir/src/VertexArray.cpp.o" \
"CMakeFiles/project.dir/src/stb_image.cpp.o" \
"CMakeFiles/project.dir/src/Sphere.cpp.o" \
"CMakeFiles/project.dir/src/Shader.cpp.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

project: CMakeFiles/project.dir/src/main.cpp.o
project: CMakeFiles/project.dir/src/glad.c.o
project: CMakeFiles/project.dir/src/ElementBuffer.cpp.o
project: CMakeFiles/project.dir/src/VertexBuffer.cpp.o
project: CMakeFiles/project.dir/src/VertexArray.cpp.o
project: CMakeFiles/project.dir/src/stb_image.cpp.o
project: CMakeFiles/project.dir/src/Sphere.cpp.o
project: CMakeFiles/project.dir/src/Shader.cpp.o
project: CMakeFiles/project.dir/build.make
project: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: project

.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	cd /home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/max/Documents/CG_OpenGL/CG_Lab3 /home/max/Documents/CG_OpenGL/CG_Lab3 /home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug /home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug /home/max/Documents/CG_OpenGL/CG_Lab3/cmake-build-debug/CMakeFiles/project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project.dir/depend

