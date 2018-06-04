cmake_minimum_required (VERSION 3.1)
project (ASD-7)

add_executable(queue main.c imp.c)
add_executable(tests tests.c imp.c)
