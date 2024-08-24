message("Starting build...")

# Setup Project
cmake_minimum_required(VERSION "3.28")
project(PioneerLib LANGUAGES CXX VERSION 0.1 )

# Set standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Set variables
set(PIONEER_LIB pioneerLib)
set(TEST_EXE test)

# Include headers
include_directories(./include)

# Include cmake files
include(./CMakeSources.cmake)

# Build source library
add_library(${PIONEER_LIB} SHARED ${SRC_FILES})

# Add Testing Libraries
find_package(Catch2 3 REQUIRED)

add_executable(${TEST_EXE} ${TEST_SRC_FILES})
target_link_libraries(${TEST_EXE} PRIVATE 
  Catch2::Catch2WithMain
  ${PIONEER_LIB})