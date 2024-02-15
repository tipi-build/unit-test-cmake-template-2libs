cmake_minimum_required(VERSION 3.15)
project(MathFunctions)

# make cache variables for install destinations
include(GNUInstallDirs)
include(CheckLibraryExists)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(MathFunctionscbrt STATIC MathFunctionscbrt.cxx)

target_include_directories(MathFunctionscbrt
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)


target_link_libraries(MathFunctionscbrt OpenSSL::SSL OpenSSL::Crypto )
check_library_exists("OpenSSL::SSL" check_ssl "${CMAKE_LIBRARY_PATH}" output_var_ssl)
check_library_exists("OpenSSL::SSL" check_crypto "${CMAKE_LIBRARY_PATH}" output_var_crypto)

install(TARGETS MathFunctionscbrt
        EXPORT MathFunctionscbrtTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES MathFunctionscbrt.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT MathFunctionscbrtTargets
        FILE MathFunctionscbrtTargets.cmake
        NAMESPACE MathFunctionscbrt::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathFunctionscbrt
)
add_library(MathFunctions STATIC MathFunctions.cxx)

target_include_directories(MathFunctions
                           PUBLIC
                           "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
                           "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)


install(TARGETS MathFunctions
        EXPORT MathFunctionsTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES MathFunctions.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT MathFunctionsTargets
        FILE MathFunctionsTargets.cmake
        NAMESPACE MathFunctions::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/MathFunctions
)