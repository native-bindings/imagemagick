set(ImageMagick6_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/../ImageMagick6)

set(
    ImageMagick6_SOURCES
    ${ImageMagick6_FOLDER}/Magick++/lib/Options.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/Drawable.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/CoderInfo.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/TypeMetric.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/ChannelMoments.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/ResourceLimits.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/Functions.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/BlobRef.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/Blob.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/Thread.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/STL.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/Exception.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/Image.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/Pixels.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/Geometry.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/Montage.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/ImageRef.cpp
    ${ImageMagick6_FOLDER}/Magick++/lib/Color.cpp
)

file (STRINGS "CFLAGS" ImageMagick6_CFLAGS)
file (STRINGS "CPPFLAGS" ImageMagick6_CPPFLAGS)

add_library(
    ImageMagick6 SHARED
    ${ImageMagick6_SOURCES}
)
target_include_directories(
    ImageMagick6
    PRIVATE ${ImageMagick6_FOLDER}/Magick++/lib ${ImageMagick6_FOLDER}
    PUBLIC ${ImageMagick6_FOLDER}/Magick++/lib ${ImageMagick6_FOLDER}
)
target_compile_definitions(ImageMagick6 PUBLIC ${ImageMagick6_CPPFLAGS})
