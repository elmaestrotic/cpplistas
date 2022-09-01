cmake_minimum_required(VERSION 3.20)
project(listicas)

set(CMAKE_CXX_STANDARD 23)

add_executable(listicas main.cpp Lista.cpp Lista.h Nodo.cpp Nodo.h)
