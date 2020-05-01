cmake_minimum_required(VERSION 3.15)
project(buses)

set(CMAKE_CXX_STANDARD 14)

add_executable(buses main.cpp query.cpp query.h responses.cpp responses.h bus_manager.cpp bus_manager.h)
