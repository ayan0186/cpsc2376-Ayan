# This CMake file is for the practice03_test folder

# Find GoogleTest (assuming you have it installed via CMake)
find_package(GTest REQUIRED)

# Include the directory where practice03.cpp is located (root directory)
include_directories(${CMAKE_SOURCE_DIR})

# Add the test executable for practice03
add_executable(test_practice03 test_practice03.cpp ${CMAKE_SOURCE_DIR}/practice03.cpp)

# Link the GoogleTest libraries
target_link_libraries(test_practice03 GTest::GTest GTest::Main)

# Register the test
add_test(NAME MathUtilsTests COMMAND test_practice03)