cmake_minimum_required(VERSION 3.0.0)
project(LeetCOde VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(LeetCo12de ../top-100-liked/437.cpp)

# add_executable(LeetCode ./2181.cpp)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
