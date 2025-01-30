cmake_minimum_required(VERSION 3.15)
project(MathFunctions)

# make cache variables for install destinations
include(GNUInstallDirs)

set(SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/file_only_in_build.hpp.in")
set(OUTPUT_FILE "${CMAKE_CURRENT_BINARY_DIR}/file_only_in_build.hpp")
configure_file(${SOURCE_FILE} ${OUTPUT_FILE} @ONLY)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(MathFunctionscbrt STATIC MathFunctionscbrt.cxx)

target_include_directories(MathFunctionscbrt
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

add_library(MathFunctions STATIC MathFunctions.cxx)

target_include_directories(MathFunctions
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)