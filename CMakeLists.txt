cmake_minimum_required(VERSION 3.7)

project(node_node_imagemagick C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

option(NODE_INSTALL_DIR "Node installation directory")

if(NOT DEFINED CMAKE_JS_INC)
    set(CMAKE_JS_INC
        ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/nan
        $ENV{NVM_INC}
    )
endif()

add_subdirectory(libs)

add_library(
    node_imagemagick SHARED
    ${CMAKE_JS_SRC}
    src/main.cpp
    src/Image.cpp
    src/Image.h
    src/Geometry.cpp
    src/Geometry.h
    src/TypeConverter.cpp
    src/TypeConverter.h
    src/Color.cpp
    src/Color.h
    src/Constants.cpp
    src/Constants.h
)
target_link_libraries(node_imagemagick PRIVATE Magick++)
target_compile_options(
    node_imagemagick PRIVATE
    -Wfatal-errors
    #-pedantic -Wall -Werror -Wextra -Wfatal-errors
    # -Wno-error=unused-parameter
)
target_include_directories(
    node_imagemagick
    PRIVATE ${CMAKE_JS_INC}
)

if(DEFINED CMAKE_JS_VERSION)
    set_target_properties(node_imagemagick PROPERTIES PREFIX "" SUFFIX ".node")
endif()
