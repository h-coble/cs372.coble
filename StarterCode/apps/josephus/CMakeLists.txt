cmake_minimum_required(VERSION 3.1)

#set the project name
project(jospehus)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../../include)

#add the executable
add_executable(josephusSTL josephusSTL.cpp "josephusSTL.cpp")

add_executable(josephus josephus.cpp "josephus.cpp")


