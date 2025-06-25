cmake_minimum_required(VERSION 3.14)
project(MemoryLeakTest)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -O1")

add_executable(memory_leak main.cpp)
