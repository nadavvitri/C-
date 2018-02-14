cmake_minimum_required(VERSION 3.8)
project(ex1_cpp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES Ex1.cpp Arenstorf.cpp Arenstorf.h ArenstorfPoint.cpp ArenstorfPoint.h)
add_executable(ex1_cpp ${SOURCE_FILES})