cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
project(HAWT C CXX)

# Force a build type to be declared
set(CMAKE_BUILD_TYPES "(None|Debug|Release|RelWithDebInfo|MinSizeRel)")
if(NOT CMAKE_BUILD_TYPE MATCHES "${CMAKE_BUILD_TYPES}")
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "${CMAKE_BUILD_TYPES}" FORCE)
endif(NOT CMAKE_BUILD_TYPE MATCHES "${CMAKE_BUILD_TYPES}")
# Specify some default directories
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")

# Version info
set(HAWT_VERSION_MAJOR 0)
set(HAWT_VERSION_MINOR 1)
if(NOT HAWT_VERSION_STRING)
  set(HAWT_VERSION_STRING "v${HAWT_VERSION_MAJOR}.${HAWT_VERSION_MINOR}"
    CACHE STRING "textual version information" FORCE)
endif(NOT HAWT_VERSION_STRING)

# Testing and packaging
include(CTest)
if(BUILD_TESTING)
  if(UNIX)
    find_program(MEMORYCHECK_COMMAND valgrind REQUIRED)
  endif(UNIX)
endif(BUILD_TESTING)
include(CPack)
