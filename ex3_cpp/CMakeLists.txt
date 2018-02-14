cmake_minimum_required(VERSION 3.8)
project(ex3_cpp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES ParallelChecker.cpp Matrix.hpp Complex.h Complex.cpp timeChecker.cpp)
add_executable(ex3_cpp ${SOURCE_FILES})