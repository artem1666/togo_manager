# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 4.0

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\Desktop\project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Desktop\project\build

# Include any dependencies generated for this target.
include CMakeFiles/todo_manager.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/todo_manager.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/todo_manager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/todo_manager.dir/flags.make

CMakeFiles/todo_manager.dir/codegen:
.PHONY : CMakeFiles/todo_manager.dir/codegen

CMakeFiles/todo_manager.dir/src/main.cpp.obj: CMakeFiles/todo_manager.dir/flags.make
CMakeFiles/todo_manager.dir/src/main.cpp.obj: C:/Users/User/Desktop/project/src/main.cpp
CMakeFiles/todo_manager.dir/src/main.cpp.obj: CMakeFiles/todo_manager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\User\Desktop\project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/todo_manager.dir/src/main.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/todo_manager.dir/src/main.cpp.obj -MF CMakeFiles\todo_manager.dir\src\main.cpp.obj.d -o CMakeFiles\todo_manager.dir\src\main.cpp.obj -c C:\Users\User\Desktop\project\src\main.cpp

CMakeFiles/todo_manager.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/todo_manager.dir/src/main.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Desktop\project\src\main.cpp > CMakeFiles\todo_manager.dir\src\main.cpp.i

CMakeFiles/todo_manager.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/todo_manager.dir/src/main.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Desktop\project\src\main.cpp -o CMakeFiles\todo_manager.dir\src\main.cpp.s

CMakeFiles/todo_manager.dir/src/task_manager.cpp.obj: CMakeFiles/todo_manager.dir/flags.make
CMakeFiles/todo_manager.dir/src/task_manager.cpp.obj: C:/Users/User/Desktop/project/src/task_manager.cpp
CMakeFiles/todo_manager.dir/src/task_manager.cpp.obj: CMakeFiles/todo_manager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\User\Desktop\project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/todo_manager.dir/src/task_manager.cpp.obj"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/todo_manager.dir/src/task_manager.cpp.obj -MF CMakeFiles\todo_manager.dir\src\task_manager.cpp.obj.d -o CMakeFiles\todo_manager.dir\src\task_manager.cpp.obj -c C:\Users\User\Desktop\project\src\task_manager.cpp

CMakeFiles/todo_manager.dir/src/task_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/todo_manager.dir/src/task_manager.cpp.i"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Desktop\project\src\task_manager.cpp > CMakeFiles\todo_manager.dir\src\task_manager.cpp.i

CMakeFiles/todo_manager.dir/src/task_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/todo_manager.dir/src/task_manager.cpp.s"
	C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Desktop\project\src\task_manager.cpp -o CMakeFiles\todo_manager.dir\src\task_manager.cpp.s

# Object files for target todo_manager
todo_manager_OBJECTS = \
"CMakeFiles/todo_manager.dir/src/main.cpp.obj" \
"CMakeFiles/todo_manager.dir/src/task_manager.cpp.obj"

# External object files for target todo_manager
todo_manager_EXTERNAL_OBJECTS =

todo_manager.exe: CMakeFiles/todo_manager.dir/src/main.cpp.obj
todo_manager.exe: CMakeFiles/todo_manager.dir/src/task_manager.cpp.obj
todo_manager.exe: CMakeFiles/todo_manager.dir/build.make
todo_manager.exe: CMakeFiles/todo_manager.dir/linkLibs.rsp
todo_manager.exe: CMakeFiles/todo_manager.dir/objects1.rsp
todo_manager.exe: CMakeFiles/todo_manager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\User\Desktop\project\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable todo_manager.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\todo_manager.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/todo_manager.dir/build: todo_manager.exe
.PHONY : CMakeFiles/todo_manager.dir/build

CMakeFiles/todo_manager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\todo_manager.dir\cmake_clean.cmake
.PHONY : CMakeFiles/todo_manager.dir/clean

CMakeFiles/todo_manager.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Desktop\project C:\Users\User\Desktop\project C:\Users\User\Desktop\project\build C:\Users\User\Desktop\project\build C:\Users\User\Desktop\project\build\CMakeFiles\todo_manager.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/todo_manager.dir/depend

