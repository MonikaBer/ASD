cmake_minimum_required (VERSION 3.1)
project (ASD-9)

add_executable(tree main.c imp.c)

add_executable(tests tests.c imp.c)

add_executable(test_simple test_simple.c imp.c)

add_executable(test_delete test_delete.c imp.c)
