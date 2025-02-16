cmake_minimum_required(VERSION 3.10)
project(practice03_test)

include(CTest)
enable_testing()

include(FetchContent)

# Download and unpack googletest at configure time
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Set runtime library to dynamic for both your project and GoogleTest
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")

# Add subdirectory for tests
add_subdirectory(tests)