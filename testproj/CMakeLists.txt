cmake_minimum_required(VERSION 3.3)
project(testproj)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES insertion.cc)
add_executable(testproj ${SOURCE_FILES})