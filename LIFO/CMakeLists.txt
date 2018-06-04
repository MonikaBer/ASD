cmake_minimum_required (VERSION 3.1)
project (ASD-8)

add_executable(stack main.c imp.c)
add_executable(tests tests.c imp.c)
