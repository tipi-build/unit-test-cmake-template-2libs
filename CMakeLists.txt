cmake_minimum_required(VERSION 3.15)
project(HfcNoExportFallback CXX)

# HFC regression fixture (no-target-cache add_subdirectory() fallback).
#
# This project intentionally performs NO install(EXPORT)/export() and produces
# no *Targets.cmake. HFC therefore cannot build a targets cache for it and must
# take the add_subdirectory() fallback in hfc_cmake_restore_or_configure.
#
# The consuming project passes a HERMETIC_TOOLCHAIN_EXTENSION that defines
# HFC_TOOLCHAIN_EXTENSION_APPLIED. On the fallback path that extension can only
# reach this CMakeLists via the generated wrapper CMakeLists.txt; if HFC drops
# it, the variable is undefined here and configuration fails loudly - which is
# exactly the regression the test wants to catch.
if(NOT DEFINED HFC_TOOLCHAIN_EXTENSION_APPLIED)
  message(FATAL_ERROR
    "HERMETIC_TOOLCHAIN_EXTENSION was not applied on the add_subdirectory() "
    "fallback path (HFC_TOOLCHAIN_EXTENSION_APPLIED is not defined)")
endif()

add_library(hfc_fallback_lib STATIC fallback_lib.cpp)
target_include_directories(hfc_fallback_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
