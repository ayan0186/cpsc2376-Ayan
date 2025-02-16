# Code Citations

## License: unknown
https://github.com/dqduy/alib/tree/ded68c678634ab7005c62597402d48b9b7ed1f24/problems/problem5/googletest/googletest/README.md

```
.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result
```


## License: MIT
https://github.com/MengLing-L/HashRsaCircuit/tree/7f5647830b964922122e4b7f61b2aea3320f7509/libsnark/depends/gtest/googletest/README.md

```
googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "
```


## License: unknown
https://github.com/rpesl/stk-code/tree/1b3b607e901c6d92ed43b970da225f94e4e90d3c/cmake/FindGoogleTest.cmake

```
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Add googletest directly to our
```

