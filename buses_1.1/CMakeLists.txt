cmake_minimum_required(VERSION 3.15)
project(lippman)

set(CMAKE_CXX_STANDARD 14)

add_executable(lippman main.cpp query.cpp query.h responses.cpp responses.h bus_manager.cpp bus_manager.h)