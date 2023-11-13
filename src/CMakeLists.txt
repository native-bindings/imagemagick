add_library(
    NativeBindingsImageMagick SHARED
    main.cpp
    Image.cpp
    Image.h
    Geometry.cpp
    Geometry.h
    Color.cpp
    Color.h
    Constants.cpp
    Constants.h
    CoderInfo.cpp
    CoderInfo.h
)
target_link_libraries(NativeBindingsImageMagick PRIVATE NodeNativeBindingsCore Magick++)
target_compile_options(
    NativeBindingsImageMagick PRIVATE
    -Wfatal-errors
    #-pedantic -Wall -Werror -Wextra -Wfatal-errors
    # -Wno-error=unused-parameter
)

if(DEFINED CMAKE_JS_VERSION)
    set_target_properties(NativeBindingsImageMagick PROPERTIES PREFIX "" SUFFIX ".node")
endif()
