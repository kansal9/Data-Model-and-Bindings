CMAKE_MINIMUM_REQUIRED(VERSION 2.8.5)

#===============================================================================
# Load elements_subdir macro here
# Examples:
#   For declaring a project module:
#         elements_subdir(ElementsExamples)
#===============================================================================
elements_subdir(DmModule)

#===============================================================================
# Load elements_depends_on_subdirs macro here
#   For creating a dependency onto an other accessible module
#         elements_depends_on_subdirs(ElementsKernel)
#===============================================================================
elements_depends_on_subdirs(ElementsKernel)
elements_depends_on_subdirs(ST_DM_HeaderProvider)

#===============================================================================
# Add the find_package macro (a pure CMake command) here to locate the
# libraries.
# Examples:
#          find_package(CppUnit)
#===============================================================================

#===============================================================================
# Declare the library dependencies here
# Example:
#         elements_add_library(ElementsExamples src/Lib/*.cpp
#                     INCLUDE_DIRS Boost ElementsKernel
#                     LINK_LIBRARIES Boost ElementsKernel
#                     PUBLIC_HEADERS ElementsExamples)
#===============================================================================
elements_add_library(DmModule src/lib/*.cpp
                     INCLUDE_DIRS ElementsKernel
                     LINK_LIBRARIES ElementsKernel ST_DM_HeaderProvider
                     PUBLIC_HEADERS DmModule)

#===============================================================================
# Declare the executables here
# Example:
# elements_add_executable(ElementsProgramExample src/Program/ProgramExample.cpp
#                        INCLUDE_DIRS Boost ElementsExamples
#                        LINK_LIBRARIES Boost ElementsExamples)
#===============================================================================
elements_add_executable(DmProgram src/program/DmProgram.cpp
                     INCLUDE_DIRS ElementsKernel DmModule
                     LINK_LIBRARIES ElementsKernel DmModule)

#===============================================================================
# Declare the Boost tests here
# Example:
# elements_add_unit_test(BoostClassExample tests/src/Boost/ClassExample_test.cpp
#                       EXECUTABLE BoostClassExample_test
#                       INCLUDE_DIRS ElementsExamples
#                       LINK_LIBRARIES ElementsExamples TYPE Boost)
#===============================================================================
elements_add_unit_test(DmInput tests/src/DmInput_test.cpp 
                     EXECUTABLE DmModule_DmInput_test
                     LINK_LIBRARIES DmModule
                     TYPE Boost)
elements_add_unit_test(DmOutput tests/src/DmOutput_test.cpp 
                     EXECUTABLE DmModule_DmOutput_test
                     LINK_LIBRARIES DmModule
                     TYPE Boost)
elements_add_unit_test(Parameters tests/src/Parameters_test.cpp 
                     EXECUTABLE DmModule_Parameters_test
                     LINK_LIBRARIES DmModule
                     TYPE Boost)

#===============================================================================
# Use the following macro for python modules, scripts and aux files:
#  elements_install_python_modules()
#  elements_install_scripts()
#===============================================================================
elements_install_python_modules()

#===============================================================================
# Declare the Python programs here
# Examples :
# elements_add_python_program(PythonProgramExample
#                             ElementsExamples.PythonProgramExample)
#===============================================================================
elements_add_python_program(DmInput DmModule.DmInput)
elements_add_python_program(DmOutput DmModule.DmOutput)
elements_add_python_program(DmProgram DmModule.DmProgram)
elements_add_python_program(Parameters DmModule.Parameters)

#===============================================================================
# Add the elements_install_conf_files macro
# Examples:
#          elements_install_conf_files()
#===============================================================================
elements_install_conf_files()
