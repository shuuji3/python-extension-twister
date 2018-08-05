cmake_minimum_required(VERSION 3.12)
project(python_extension C)

set(CMAKE_C_STANDARD 99)
include_directories(SYSTEM /Users/shuuji/.pyenv/versions/3.6.0/include/python3.6m/)
include_directories(./SFMT-src-1.5.1)

add_executable(python_extension twistermodule.c twister.h twister.c)