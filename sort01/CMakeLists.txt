cmake_minimum_required (VERSION 3.1)
project (ASD-3)

add_executable(asd-3 main.cpp imp.cpp)

add_executable(tests tests.cpp imp.cpp)
