cmake_minimum_required(VERSION 3.10)
project(GoogleTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(FetchContent)
FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
    TLS_VERIFY false
)
FetchContent_MakeAvailable(gtest)


add_library(
    figures
    Hexagon.cpp 
    Pentagon.cpp 
    Rhombus.cpp 
    Figure.cpp
    Array.cpp
    Point.cpp
)
add_executable(Figure main.cpp)
add_executable(tests tests.cc)

target_link_libraries(tests figures gtest gtest_main)
target_link_libraries(Figure PRIVATE figures)
enable_testing()


add_test(NAME run_tests COMMAND tests)

