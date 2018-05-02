cmake_minimum_required (VERSION 3.1)
project (ASD-4)

add_executable(asd-4 main.cpp imp.cpp)

add_executable(tests tests.cpp imp.cpp)
