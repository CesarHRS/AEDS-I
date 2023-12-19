cmake_minimum_required(VERSION 3.26)
project(T2)

set(CMAKE_CXX_STANDARD 23)

add_executable(T2 src/main.cpp
        src/fileOperator.cpp
        src/fileOperator.h
        src/heap.cpp
        src/heap.h
        src/AVL.cpp
        src/AVL.h
        src/bynaryTree.cpp
        src/bynaryTree.h
        src/huffman.cpp
        src/huffman.h)
