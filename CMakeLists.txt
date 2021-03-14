cmake_minimum_required(VERSION 3.16)
project(Enrollment_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(Enrollment_System
        src/degree.h
        src/Main.cpp
        src/roster.cpp
        src/roster.h
        src/student.cpp
        src/student.h)
