cmake_minimum_required(VERSION 3.22.1)

project(ServerApp VERSION 1.0)

file(GLOB SRC_FILES 
    ${CMAKE_SOURCE_DIR}/src/*.cpp 
    ${CMAKE_SOURCE_DIR}/include/*.h
)

add_executable(ServerApp ${SRC_FILES})


target_include_directories(ServerApp PUBLIC 
    "${CMAKE_SOURCE_DIR}/include"
)
