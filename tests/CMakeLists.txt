# tests/CMakeLists.txt

enable_testing()

# Create your test executable
add_executable(test_my_program tests/test_main.cpp)

# Link GoogleTest and your source code
target_link_libraries(test_my_program gtest gtest_main my_library)

# Add tests to the CMake test suite
add_test(NAME MathUtilsTests COMMAND test_my_program)
