cmake_minimum_required (VERSION 3.1)
project (twoway_cyclic_list)

add_executable(twoway_cyclic_list main.c imp.c)
add_executable(tests tests.c imp.c)
