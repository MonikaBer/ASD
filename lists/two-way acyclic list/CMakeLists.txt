cmake_minimum_required (VERSION 3.1)
project (twoway_acyclic_list)

add_executable(twoway_acyclic_list main.c imp.c)
add_executable(tests tests.c imp.c)
