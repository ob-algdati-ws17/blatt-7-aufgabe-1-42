cmake_minimum_required(VERSION 3.3)
project(blatt_7_aufgabe_1_42)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES avltree/library.cpp avltree/library.h)
add_library(blatt_7_aufgabe_1_42 ${SOURCE_FILES})