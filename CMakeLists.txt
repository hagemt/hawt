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

# Find UI libraries
list(APPEND QT_COMPONENTS "QtCore")
list(APPEND QT_COMPONENTS "QtGui")
# Only need QtTest for testing
if(BUILD_TESTING)
  list(APPEND QT_COMPONENTS "QtTest")
endif(BUILD_TESTING)
# Load Qt >= QT_MIN_VERSION
set(QT_MIN_VERSION 4.6.0)
find_package(Qt4 ${QT_MIN_VERSION} COMPONENTS ${QT_COMPONENTS} REQUIRED)
# Use Qt >= QT_MIN_VERSION
if(BUILD_TESTING)
  set(QT_USE_QTTEST TRUE)
endif(BUILD_TESTING)
include("${QT_USE_FILE}")
# Include proper directories
include_directories("${CMAKE_BINARY_DIR}")
include_directories("${QT_INCLUDE_DIR}")
if(BUILD_TESTING)
  include_directories("${QT_QTTEST_INCLUDE_DIR}")
endif(BUILD_TESTING)
# Build the UI
set(hawt_SOURCES hawt_settings.cpp hawt.cpp)
set(hawt_HEADERS hawt_settings.h)
set(hawt_UI hawt_settings.ui)
set(hawt_QRC hawt.qrc)
qt4_wrap_cpp(hawt_MOC_SOURCES ${hawt_HEADERS})
qt4_wrap_ui(hawt_UI_SOURCES ${hawt_UI})
qt4_add_resources(hawt_QRC_SOURCES ${hawt_QRC})
add_executable(hawt
  ${hawt_SOURCES}
  ${hawt_MOC_SOURCES}
  ${hawt_UI_SOURCES}
  ${hawt_QRC_SOURCES})
target_link_libraries(hawt ${QT_LIBRARIES})

# Testing and packaging
include(CTest)
if(BUILD_TESTING)
  if(UNIX)
    find_program(MEMORYCHECK_COMMAND valgrind REQUIRED)
  endif(UNIX)
endif(BUILD_TESTING)
include(CPack)
