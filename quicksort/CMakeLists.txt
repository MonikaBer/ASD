set (CMAKE_CXX_STANDARD 11)

cmake_minimum_required (VERSION 3.1)
project (ASD-5)

add_executable(asd-5 main.cpp imp.cpp)

add_executable(tests tests.cpp imp.cpp)
