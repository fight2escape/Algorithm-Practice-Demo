cmake_minimum_required(VERSION 3.8)
project(Algorithm-Practice-Demo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h ReadGraph.h Edge.h)
add_executable(Algorithm-Practice-Demo ${SOURCE_FILES})