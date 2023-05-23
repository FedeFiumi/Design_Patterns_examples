cmake_minimum_required(VERSION 3.14)

# set(CMAKE_C_COMPILER "gcc")
# set(CMAKE_CXX_COMPILER "g++")

# set the project name and version
project(FCBS VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

set(PROJECT_FILES generic_example.cpp singleton.cpp singleton.h)

message("\n")
message("========================================================")
message("SRC included source files: ")
foreach(line IN LISTS PROJECT_FILES)
    message(STATUS ${line})
endforeach()
message("\n")

add_executable(${PROJECT_NAME} ${PROJECT_FILES})

include_directories(${CMAKE_CURRENT_LIST_DIR})
message(${CMAKE_CURRENT_LIST_DIR})