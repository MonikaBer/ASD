cmake_minimum_required (VERSION 3.1)
project (oneway_cyclic_list)

add_executable(oneway_cyclic_list main.c imp.c)
add_executable(tests tests.c imp.c)
