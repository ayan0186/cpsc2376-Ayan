cmake_minimum_required(VERSION 3.10)

# Add the test executable
add_executable(practice03_test practice03_test.cpp)

# Link the test executable with GoogleTest
target_link_libraries(practice03_test gtest_main)

# Register the test
include(GoogleTest)
gtest_discover_tests(practice03_test)