cmake_minimum_required(VERSION 3.15)

project(solarSim)

add_compile_options(-g -Wfatal-errors -fopenmp)

include_directories(/usr/include/opencv4)

file(GLOB SOURCES *.cpp)

add_executable(solar ${SOURCES})
target_link_libraries(solar gomp GL glfw opencv_videoio opencv_core)
