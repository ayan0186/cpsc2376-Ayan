cmake_minimum_required(VERSION 3.15)  # Make sure to set the minimum CMake version

project(MyProject)

# Include FetchContent module (needed for downloading libraries)
include(FetchContent)

# Try to find GoogleTest, if not found, it will be downloaded
find_package(GTest QUIET)

if (NOT GTest_FOUND)
  message(STATUS "GoogleTest not found, downloading using FetchContent")
  FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main  # or specify a specific tag/commit
  )
  FetchContent_MakeAvailable(gtest)
else()
  message(STATUS "GoogleTest found")
endif()

# Add source and test directories
add_subdirectory(src)
add_subdirectory(tests)
