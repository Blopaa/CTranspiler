# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = C:\Users\pablo\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\pablo\AppData\Local\Programs\CLion\bin\cmake\win\x64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pablo\CLionProjects\CTranspiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pablo\CLionProjects\CTranspiler\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled14.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/untitled14.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled14.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled14.dir/flags.make

CMakeFiles/untitled14.dir/src/main.c.obj: CMakeFiles/untitled14.dir/flags.make
CMakeFiles/untitled14.dir/src/main.c.obj: C:/Users/pablo/CLionProjects/CTranspiler/src/main.c
CMakeFiles/untitled14.dir/src/main.c.obj: CMakeFiles/untitled14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\pablo\CLionProjects\CTranspiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/untitled14.dir/src/main.c.obj"
	C:\Users\pablo\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled14.dir/src/main.c.obj -MF CMakeFiles\untitled14.dir\src\main.c.obj.d -o CMakeFiles\untitled14.dir\src\main.c.obj -c C:\Users\pablo\CLionProjects\CTranspiler\src\main.c

CMakeFiles/untitled14.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/untitled14.dir/src/main.c.i"
	C:\Users\pablo\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pablo\CLionProjects\CTranspiler\src\main.c > CMakeFiles\untitled14.dir\src\main.c.i

CMakeFiles/untitled14.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/untitled14.dir/src/main.c.s"
	C:\Users\pablo\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pablo\CLionProjects\CTranspiler\src\main.c -o CMakeFiles\untitled14.dir\src\main.c.s

CMakeFiles/untitled14.dir/src/lexer/lexer.c.obj: CMakeFiles/untitled14.dir/flags.make
CMakeFiles/untitled14.dir/src/lexer/lexer.c.obj: C:/Users/pablo/CLionProjects/CTranspiler/src/lexer/lexer.c
CMakeFiles/untitled14.dir/src/lexer/lexer.c.obj: CMakeFiles/untitled14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\pablo\CLionProjects\CTranspiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/untitled14.dir/src/lexer/lexer.c.obj"
	C:\Users\pablo\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled14.dir/src/lexer/lexer.c.obj -MF CMakeFiles\untitled14.dir\src\lexer\lexer.c.obj.d -o CMakeFiles\untitled14.dir\src\lexer\lexer.c.obj -c C:\Users\pablo\CLionProjects\CTranspiler\src\lexer\lexer.c

CMakeFiles/untitled14.dir/src/lexer/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/untitled14.dir/src/lexer/lexer.c.i"
	C:\Users\pablo\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pablo\CLionProjects\CTranspiler\src\lexer\lexer.c > CMakeFiles\untitled14.dir\src\lexer\lexer.c.i

CMakeFiles/untitled14.dir/src/lexer/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/untitled14.dir/src/lexer/lexer.c.s"
	C:\Users\pablo\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pablo\CLionProjects\CTranspiler\src\lexer\lexer.c -o CMakeFiles\untitled14.dir\src\lexer\lexer.c.s

CMakeFiles/untitled14.dir/src/parser/parser.c.obj: CMakeFiles/untitled14.dir/flags.make
CMakeFiles/untitled14.dir/src/parser/parser.c.obj: C:/Users/pablo/CLionProjects/CTranspiler/src/parser/parser.c
CMakeFiles/untitled14.dir/src/parser/parser.c.obj: CMakeFiles/untitled14.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\pablo\CLionProjects\CTranspiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/untitled14.dir/src/parser/parser.c.obj"
	C:\Users\pablo\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/untitled14.dir/src/parser/parser.c.obj -MF CMakeFiles\untitled14.dir\src\parser\parser.c.obj.d -o CMakeFiles\untitled14.dir\src\parser\parser.c.obj -c C:\Users\pablo\CLionProjects\CTranspiler\src\parser\parser.c

CMakeFiles/untitled14.dir/src/parser/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/untitled14.dir/src/parser/parser.c.i"
	C:\Users\pablo\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\pablo\CLionProjects\CTranspiler\src\parser\parser.c > CMakeFiles\untitled14.dir\src\parser\parser.c.i

CMakeFiles/untitled14.dir/src/parser/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/untitled14.dir/src/parser/parser.c.s"
	C:\Users\pablo\AppData\Local\Programs\CLion\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\pablo\CLionProjects\CTranspiler\src\parser\parser.c -o CMakeFiles\untitled14.dir\src\parser\parser.c.s

# Object files for target untitled14
untitled14_OBJECTS = \
"CMakeFiles/untitled14.dir/src/main.c.obj" \
"CMakeFiles/untitled14.dir/src/lexer/lexer.c.obj" \
"CMakeFiles/untitled14.dir/src/parser/parser.c.obj"

# External object files for target untitled14
untitled14_EXTERNAL_OBJECTS =

untitled14.exe: CMakeFiles/untitled14.dir/src/main.c.obj
untitled14.exe: CMakeFiles/untitled14.dir/src/lexer/lexer.c.obj
untitled14.exe: CMakeFiles/untitled14.dir/src/parser/parser.c.obj
untitled14.exe: CMakeFiles/untitled14.dir/build.make
untitled14.exe: CMakeFiles/untitled14.dir/linkLibs.rsp
untitled14.exe: CMakeFiles/untitled14.dir/objects1.rsp
untitled14.exe: CMakeFiles/untitled14.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\pablo\CLionProjects\CTranspiler\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable untitled14.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled14.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled14.dir/build: untitled14.exe
.PHONY : CMakeFiles/untitled14.dir/build

CMakeFiles/untitled14.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled14.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled14.dir/clean

CMakeFiles/untitled14.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pablo\CLionProjects\CTranspiler C:\Users\pablo\CLionProjects\CTranspiler C:\Users\pablo\CLionProjects\CTranspiler\cmake-build-debug C:\Users\pablo\CLionProjects\CTranspiler\cmake-build-debug C:\Users\pablo\CLionProjects\CTranspiler\cmake-build-debug\CMakeFiles\untitled14.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/untitled14.dir/depend

