cmake_minimum_required(VERSION 3.15)
project(MacMemoryChanger C)

set(CMAKE_C_STANDARD 99)

add_executable(MacMemoryChanger main.c lib/darwin/xnumem.c lib/darwin/xnumem.h)