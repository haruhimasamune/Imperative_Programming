# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = D:\ImperativeProgramming\cmake-3.27.4-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = D:\ImperativeProgramming\cmake-3.27.4-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\haruhimasamune\OneDrive\Desktop\Radboud\2023_S2\2324_Imperative_Programming_(KW1V)\git_repository_WIN\Imperative_Programming\assignment-06-mandatory-files

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\haruhimasamune\OneDrive\Desktop\Radboud\2023_S2\2324_Imperative_Programming_(KW1V)\git_repository_WIN\Imperative_Programming\build

# Utility rule file for NightlyCoverage.

# Include any custom commands dependencies for this target.
include CMakeFiles/NightlyCoverage.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NightlyCoverage.dir/progress.make

CMakeFiles/NightlyCoverage:
	D:\ImperativeProgramming\cmake-3.27.4-windows-x86_64\bin\ctest.exe -D NightlyCoverage

NightlyCoverage: CMakeFiles/NightlyCoverage
NightlyCoverage: CMakeFiles/NightlyCoverage.dir/build.make
.PHONY : NightlyCoverage

# Rule to build all files generated by this target.
CMakeFiles/NightlyCoverage.dir/build: NightlyCoverage
.PHONY : CMakeFiles/NightlyCoverage.dir/build

CMakeFiles/NightlyCoverage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NightlyCoverage.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NightlyCoverage.dir/clean

CMakeFiles/NightlyCoverage.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\haruhimasamune\OneDrive\Desktop\Radboud\2023_S2\2324_Imperative_Programming_(KW1V)\git_repository_WIN\Imperative_Programming\assignment-06-mandatory-files D:\haruhimasamune\OneDrive\Desktop\Radboud\2023_S2\2324_Imperative_Programming_(KW1V)\git_repository_WIN\Imperative_Programming\assignment-06-mandatory-files D:\haruhimasamune\OneDrive\Desktop\Radboud\2023_S2\2324_Imperative_Programming_(KW1V)\git_repository_WIN\Imperative_Programming\build D:\haruhimasamune\OneDrive\Desktop\Radboud\2023_S2\2324_Imperative_Programming_(KW1V)\git_repository_WIN\Imperative_Programming\build D:\haruhimasamune\OneDrive\Desktop\Radboud\2023_S2\2324_Imperative_Programming_(KW1V)\git_repository_WIN\Imperative_Programming\build\CMakeFiles\NightlyCoverage.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/NightlyCoverage.dir/depend

