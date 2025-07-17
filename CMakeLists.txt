cmake_minimum_required(VERSION 3.31)
project(Project-Hafen-Sevilla-Port)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project-Hafen-Sevilla-Port main.cpp
        Port.cpp
        Port.h
        Ship.cpp
        Ship.h)
