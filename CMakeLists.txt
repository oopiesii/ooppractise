cmake_minimum_required(VERSION 4.3)
project(assignment1)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment1 main.cpp
        Shape.cpp
        Shape.h
        Circle.cpp
        Circle.h
        Canvas.cpp
        Canvas.h
        Rectangle.cpp
        Rectangle.h
        Line.cpp
        Line.h
        Triangle.cpp
        Triangle.h
        Program.cpp
        Program.h
        )
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(assignment1 ${Boost_LIBRARIES})