cmake_minimum_required(VERSION 3.7)

project(NativeBindingsImageMagick CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_subdirectory(libs)
add_subdirectory(core)
add_subdirectory(src)
