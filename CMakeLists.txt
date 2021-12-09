project(node_imagemagick CXX)

cmake_minimum_required(VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

option(NODE_INSTALL_DIR "Node installation directory")

if(NOT DEFINED CMAKE_JS_INC)
set(CMAKE_JS_INC
    ${CMAKE_CURRENT_SOURCE_DIR}/node_modules/nan
    ${NODE_INSTALL_DIR}/include/node
)
endif()

find_package(PkgConfig)
pkg_check_modules(ImageMagick REQUIRED ImageMagick++)

set(IMAGEMAGICK_COMPILE_OPTIONS ${IMAGEMAGICK_COMPILE_OPTIONS} ${ImageMagick_CFLAGS_OTHER})

add_library(
    imagemagick SHARED
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
        src/Constants.cpp src/Constants.h)
target_link_libraries(imagemagick PRIVATE ${ImageMagick_LIBRARIES})
target_compile_options(
    imagemagick PRIVATE
    -Wfatal-errors -Werror ${ImageMagick_CFLAGS_OTHER}
    #-pedantic -Wall -Werror -Wextra -Wfatal-errors
    #-Wno-error=unused-parameter
)
target_include_directories(
    imagemagick PRIVATE
    ${ImageMagick_INCLUDE_DIRS} ${CMAKE_JS_INC}
)

if(DEFINED CMAKE_JS_VERSION)
    set_target_properties(imagemagick PROPERTIES PREFIX "" SUFFIX ".node")
endif()
