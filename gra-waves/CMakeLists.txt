cmake_minimum_required(VERSION 3.15)

project(graWaves)

add_compile_options(-g -Wfatal-errors)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(/usr/include/SDL)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/*.cpp)

add_executable(graw ${SOURCES})
target_link_libraries(graw config GL SDL)

