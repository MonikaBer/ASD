cmake_minimum_required (VERSION 3.1)
project (ASD-1)

add_executable(asd_1 main.cpp imp.cpp)

add_executable(tests tests.cpp imp.cpp)
