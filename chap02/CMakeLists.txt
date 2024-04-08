cmake_minimum_required(VERSION 3.25)
project(chap02 C)

set(CMAKE_C_STANDARD 11)

add_executable(vmtest vmtest.c)
add_executable(func_ptr func_ptr.c)
add_executable(print_address print_address.c)
add_executable(tiny_printf tiny_printf.c)
add_executable(permutation permutation.c)
add_executable(auto auto.c)
add_executable(alignment alignment.c)
add_executable(buffer_overflow buffer_overflow.c)
add_executable(byteorder byteorder.c)
add_executable(vla2 vla2.c)

