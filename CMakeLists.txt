cmake_minimum_required(VERSION 3.10)
project(PROJET C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET main.c personnage.c personnage.h)
add_executable(exemple exempleTableau.c personnage.h personnage.c)
add_executable(Test tests.c)
add_executable(Test2 test2.c personnage.h personnage.c)
