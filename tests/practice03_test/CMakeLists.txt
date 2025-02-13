cmake_minimum_required(VERSION 3.5.0)
project(practice03_test VERSION 0.1.0 LANGUAGES C CXX)

add_executable(practice03_test practice03_test.cpp)

include(FetchContent)
    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG        v1.14.0 # Use the desired tag/version
    )
    FetchContent_MakeAvailable(googletest)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
