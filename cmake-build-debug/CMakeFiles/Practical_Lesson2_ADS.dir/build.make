# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Programming\C++\Practical-Lesson2-ADS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Programming\C++\Practical-Lesson2-ADS\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Practical_Lesson2_ADS.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Practical_Lesson2_ADS.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Practical_Lesson2_ADS.dir\flags.make

CMakeFiles\Practical_Lesson2_ADS.dir\main.cpp.obj: CMakeFiles\Practical_Lesson2_ADS.dir\flags.make
CMakeFiles\Practical_Lesson2_ADS.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\Programming\C++\Practical-Lesson2-ADS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Practical_Lesson2_ADS.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Practical_Lesson2_ADS.dir\main.cpp.obj /FdCMakeFiles\Practical_Lesson2_ADS.dir\ /FS -c E:\Programming\C++\Practical-Lesson2-ADS\main.cpp
<<

CMakeFiles\Practical_Lesson2_ADS.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Practical_Lesson2_ADS.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe > CMakeFiles\Practical_Lesson2_ADS.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Programming\C++\Practical-Lesson2-ADS\main.cpp
<<

CMakeFiles\Practical_Lesson2_ADS.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Practical_Lesson2_ADS.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Practical_Lesson2_ADS.dir\main.cpp.s /c E:\Programming\C++\Practical-Lesson2-ADS\main.cpp
<<

# Object files for target Practical_Lesson2_ADS
Practical_Lesson2_ADS_OBJECTS = \
"CMakeFiles\Practical_Lesson2_ADS.dir\main.cpp.obj"

# External object files for target Practical_Lesson2_ADS
Practical_Lesson2_ADS_EXTERNAL_OBJECTS =

Practical_Lesson2_ADS.exe: CMakeFiles\Practical_Lesson2_ADS.dir\main.cpp.obj
Practical_Lesson2_ADS.exe: CMakeFiles\Practical_Lesson2_ADS.dir\build.make
Practical_Lesson2_ADS.exe: CMakeFiles\Practical_Lesson2_ADS.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\Programming\C++\Practical-Lesson2-ADS\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Practical_Lesson2_ADS.exe"
	"C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Practical_Lesson2_ADS.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1428~1.293\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Practical_Lesson2_ADS.dir\objects1.rsp @<<
 /out:Practical_Lesson2_ADS.exe /implib:Practical_Lesson2_ADS.lib /pdb:E:\Programming\C++\Practical-Lesson2-ADS\cmake-build-debug\Practical_Lesson2_ADS.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Practical_Lesson2_ADS.dir\build: Practical_Lesson2_ADS.exe

.PHONY : CMakeFiles\Practical_Lesson2_ADS.dir\build

CMakeFiles\Practical_Lesson2_ADS.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Practical_Lesson2_ADS.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Practical_Lesson2_ADS.dir\clean

CMakeFiles\Practical_Lesson2_ADS.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\Programming\C++\Practical-Lesson2-ADS E:\Programming\C++\Practical-Lesson2-ADS E:\Programming\C++\Practical-Lesson2-ADS\cmake-build-debug E:\Programming\C++\Practical-Lesson2-ADS\cmake-build-debug E:\Programming\C++\Practical-Lesson2-ADS\cmake-build-debug\CMakeFiles\Practical_Lesson2_ADS.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Practical_Lesson2_ADS.dir\depend
