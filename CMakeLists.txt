cmake_minimum_required(VERSION 3.8)
project(Algorithm-Practice-Demo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Minimum-Span-Tree/KruskalMST/DenseGraph.h Minimum-Span-Tree/KruskalMST/SparseGraph.h Minimum-Span-Tree/KruskalMST/ReadGraph.h Minimum-Span-Tree/KruskalMST/Edge.h Minimum-Span-Tree/KruskalMST/UnionFind.h Minimum-Span-Tree/KruskalMST/KruskalMST.h)
add_executable(Algorithm-Practice-Demo ${SOURCE_FILES})