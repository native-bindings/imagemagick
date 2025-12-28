cmake_minimum_required(VERSION 3.10)

project(NativeBindingsImageMagick CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

add_subdirectory(libs)
add_subdirectory(core)
add_subdirectory(src)
