cmake_minimum_required(VERSION 3.5)
project(Dominion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp cards.c)
add_executable(Dominion ${SOURCE_FILES})