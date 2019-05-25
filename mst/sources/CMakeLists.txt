cmake_minimum_required(VERSION 3.13)
project(sources)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

add_executable(sources
        inc/filter_kruskal.h
        inc/grafo.h
        inc/heap_binary.h
        inc/kruskal.h
        inc/prim.h
        inc/soluction.h
        inc/union_find.h
        src/filter_kruskal.cpp
        src/grafo.cpp
        src/heap_binary.cpp
        src/kruskal.cpp
        src/main.cpp
        src/prim.cpp
        src/union_find.cpp
        src/union_find_2.cpp
        src/union_find_3.cpp
        src/union_find_4.cpp src/bucket_sort.cpp inc/bucket_sort.h)
