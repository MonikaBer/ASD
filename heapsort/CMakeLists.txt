cmake_minimum_required (VERSION 3.1)
project (ASD-10)

add_executable(heap main.c imp.c)
add_executable(tests tests.c imp.c)
