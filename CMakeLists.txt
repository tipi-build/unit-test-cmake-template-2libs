cmake_minimum_required(VERSION 3.15)
project(MathFunctions)

# make cache variables for install destinations
include(GNUInstallDirs)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(MathFunctionscbrt STATIC MathFunctionscbrt.cxx)
add_library(MathFunctionscbrt::MathFunctionscbrt ALIAS MathFunctionscbrt)

target_include_directories(MathFunctionscbrt
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)



add_library(MathFunctions STATIC MathFunctions.cxx)
add_library(MathFunctions::MathFunctions ALIAS MathFunctions)

target_include_directories(MathFunctions
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)