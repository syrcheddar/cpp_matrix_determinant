cmake_minimum_required(VERSION 3.16.3)
project(semestralka)

add_executable(matrix_determinant
        main.cpp
        )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(matrix_determinant Threads::Threads)
set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)
set(core-files
        logics.hpp
        logics.cpp
        )

add_executable(semestralka main.cpp)
