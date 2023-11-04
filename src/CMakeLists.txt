add_library(
    node_imagemagick SHARED
    main.cpp
    Image.cpp
    Image.h
    Geometry.cpp
    Geometry.h
    Color.cpp
    Color.h
    Constants.cpp
    Constants.h
)
target_link_libraries(node_imagemagick PRIVATE NodeNativeBindingsCore Magick++)
target_compile_options(
    node_imagemagick PRIVATE
    -Wfatal-errors
    #-pedantic -Wall -Werror -Wextra -Wfatal-errors
    # -Wno-error=unused-parameter
)

if(DEFINED CMAKE_JS_VERSION)
    set_target_properties(node_imagemagick PROPERTIES PREFIX "" SUFFIX ".node")
endif()
