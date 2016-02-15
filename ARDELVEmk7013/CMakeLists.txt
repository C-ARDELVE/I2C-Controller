cmake_minimum_required(VERSION 2.8.11)

project(ARDELVEmk7013)



include_directories(
    /Users/Calum/Documents/Ardelve Test/ARDELVEmk7013/
    /Users/Calum/Documents/Ardelve Test/ARDELVEmk7013/

)

add_definitions(
    -DNDEBUG
)

# Linker options
set(CMAKE_LDFLAGS "${CMAKE_LDFLAGS}  ")

# Library path
set(CMAKE_LDFLAGS "${CMAKE_LDFLAGS} -L\".\" ")

# Define the CXX sources
set ( CXX_SRCS
    ../ARDELVEgusto/MK7013Scripts.cpp
    ../ARDELVEgusto/OTPCommands.cpp
    ../ARDELVEgusto/RESET.cpp
    ../ARDELVEgusto/I2Ccommands.cpp
    ../ARDELVEgusto/GENERALcommands.cpp
    ../ARDELVEgusto/PADcommands.cpp
    ../ARDELVEgusto/GPIOsetup.cpp
    ../ARDELVEgusto/TEN.cpp
    ../ARDELVEgusto/TAO.cpp
    ../ARDELVEgusto/TDO.cpp
    ../ARDELVEgusto/SUBcommands.cpp
)

set_source_files_properties(
    ${CXX_SRCS} PROPERTIES COMPILE_FLAGS 
    " -O2 -Wall")

add_executable(ARDELVEmk7013 ${CXX_SRCS} ${C_SRCS})

