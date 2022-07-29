project(node_node_imagemagick C CXX)

cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

option(NODE_INSTALL_DIR "Node installation directory")

if(NOT DEFINED CMAKE_JS_INC)
set(CMAKE_JS_INC
    ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/nan
    ${NODE_INSTALL_DIR}/include/node
)
endif()

find_package(PkgConfig)
pkg_check_modules(ImageMagick REQUIRED ImageMagick++ MagickCore)

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
target_link_libraries(node_imagemagick PRIVATE ${ImageMagick_LINK_LIBRARIES})
target_compile_options(
    node_imagemagick PRIVATE
    -Wfatal-errors
    #-pedantic -Wall -Werror -Wextra -Wfatal-errors
    # -Wno-error=unused-parameter
    ${ImageMagick_CFLAGS_OTHER}
)
target_include_directories(
    node_imagemagick
    PRIVATE ${CMAKE_JS_INC} ${ImageMagick_INCLUDE_DIRS}
)
target_link_directories(node_imagemagick PRIVATE ${})

if(DEFINED CMAKE_JS_VERSION)
    set_target_properties(node_imagemagick PROPERTIES PREFIX "" SUFFIX ".node")
endif()
