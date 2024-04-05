cmake_minimum_required(VERSION 3.25)
project(chap01 C)

set(CMAKE_C_STANDARD 11)

add_executable(array array.c)
add_executable(array2.c array2.c)
add_executable(vla vla.c)
add_executable(get_word get_word.c)
add_executable(pointer pointer.c)
add_executable(pointer_calc pointer_calc.c)
add_executable(sizeof sizeof.c)
add_executable(get_xy get_xy.c)
add_executable(get_xy_bad get_xy_bad.c)
