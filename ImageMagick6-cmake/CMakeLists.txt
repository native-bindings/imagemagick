
file(STRINGS "CFLAGS" ImageMagick6_CFLAGS)
file(STRINGS "CPPFLAGS" ImageMagick6_CPPFLAGS)
file(STRINGS "INCLUDE_DIRS" MagickCore6_INCLUDE_DIRS)

set(ImageMagick6_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/../ImageMagick6)

set(MagickCore6_INCLUDE_DIRS ${MagickCore6_INCLUDE_DIRS} ${ImageMagick6_FOLDER}/Magick++/lib ${ImageMagick6_FOLDER})

set(
    MagickCore6_SOURCES ${ImageMagick6_FOLDER}/magick/quantum-export.c
    ${ImageMagick6_FOLDER}/magick/splay-tree.c
    ${ImageMagick6_FOLDER}/magick/threshold.c
    ${ImageMagick6_FOLDER}/magick/visual-effects.c
    ${ImageMagick6_FOLDER}/magick/utility.c
    ${ImageMagick6_FOLDER}/magick/effect.c
    ${ImageMagick6_FOLDER}/magick/list.c
    ${ImageMagick6_FOLDER}/magick/client.c
    ${ImageMagick6_FOLDER}/magick/channel.c
    ${ImageMagick6_FOLDER}/magick/enhance.c
    ${ImageMagick6_FOLDER}/magick/fourier.c
    ${ImageMagick6_FOLDER}/magick/random.c
    ${ImageMagick6_FOLDER}/magick/decorate.c
    ${ImageMagick6_FOLDER}/magick/fx.c
    ${ImageMagick6_FOLDER}/magick/vms.c
    ${ImageMagick6_FOLDER}/magick/log.c
    ${ImageMagick6_FOLDER}/magick/vision.c
    ${ImageMagick6_FOLDER}/magick/colormap.c
    ${ImageMagick6_FOLDER}/magick/mac.c
    ${ImageMagick6_FOLDER}/magick/module.c
    ${ImageMagick6_FOLDER}/magick/property.c
    ${ImageMagick6_FOLDER}/magick/quantize.c
    ${ImageMagick6_FOLDER}/magick/statistic.c
    ${ImageMagick6_FOLDER}/magick/locale.c
    ${ImageMagick6_FOLDER}/magick/distribute-cache.c
    ${ImageMagick6_FOLDER}/magick/attribute.c
    ${ImageMagick6_FOLDER}/magick/cipher.c
    ${ImageMagick6_FOLDER}/magick/type.c
    ${ImageMagick6_FOLDER}/magick/timer.c
    ${ImageMagick6_FOLDER}/magick/accelerate.c
    ${ImageMagick6_FOLDER}/magick/token.c
    ${ImageMagick6_FOLDER}/magick/nt-feature.c
    ${ImageMagick6_FOLDER}/magick/option.c
    ${ImageMagick6_FOLDER}/magick/prepress.c
    ${ImageMagick6_FOLDER}/magick/cache.c
    ${ImageMagick6_FOLDER}/magick/mime.c
    ${ImageMagick6_FOLDER}/magick/constitute.c
    ${ImageMagick6_FOLDER}/magick/image-view.c
    ${ImageMagick6_FOLDER}/magick/animate.c
    ${ImageMagick6_FOLDER}/magick/image.c
    ${ImageMagick6_FOLDER}/magick/cache-view.c
    ${ImageMagick6_FOLDER}/magick/transform.c
    ${ImageMagick6_FOLDER}/magick/compare.c
    ${ImageMagick6_FOLDER}/magick/configure.c
    ${ImageMagick6_FOLDER}/magick/display.c
    ${ImageMagick6_FOLDER}/magick/profile.c
    ${ImageMagick6_FOLDER}/magick/deprecate.c
    ${ImageMagick6_FOLDER}/magick/morphology.c
    ${ImageMagick6_FOLDER}/magick/magick.c
    ${ImageMagick6_FOLDER}/magick/shear.c
    ${ImageMagick6_FOLDER}/magick/compress.c
    ${ImageMagick6_FOLDER}/magick/policy.c
    ${ImageMagick6_FOLDER}/magick/static.c
    ${ImageMagick6_FOLDER}/magick/composite.c
    ${ImageMagick6_FOLDER}/magick/segment.c
    ${ImageMagick6_FOLDER}/magick/registry.c
    ${ImageMagick6_FOLDER}/magick/semaphore.c
    ${ImageMagick6_FOLDER}/magick/xml-tree.c
    ${ImageMagick6_FOLDER}/magick/annotate.c
    ${ImageMagick6_FOLDER}/magick/paint.c
    ${ImageMagick6_FOLDER}/magick/draw.c
    ${ImageMagick6_FOLDER}/magick/thread.c
    ${ImageMagick6_FOLDER}/magick/resource.c
    ${ImageMagick6_FOLDER}/magick/resample.c
    ${ImageMagick6_FOLDER}/magick/feature.c
    ${ImageMagick6_FOLDER}/magick/magic.c
    ${ImageMagick6_FOLDER}/magick/distort.c
    ${ImageMagick6_FOLDER}/magick/memory.c
    ${ImageMagick6_FOLDER}/magick/identify.c
    ${ImageMagick6_FOLDER}/magick/hashmap.c
    ${ImageMagick6_FOLDER}/magick/quantum.c
    ${ImageMagick6_FOLDER}/magick/gem.c
    ${ImageMagick6_FOLDER}/magick/opencl.c
    ${ImageMagick6_FOLDER}/magick/montage.c
    ${ImageMagick6_FOLDER}/magick/monitor.c
    ${ImageMagick6_FOLDER}/magick/geometry.c
    ${ImageMagick6_FOLDER}/magick/string.c
    ${ImageMagick6_FOLDER}/magick/histogram.c
    ${ImageMagick6_FOLDER}/magick/stream.c
    ${ImageMagick6_FOLDER}/magick/artifact.c
    ${ImageMagick6_FOLDER}/magick/colorspace.c
    ${ImageMagick6_FOLDER}/magick/pixel.c
    ${ImageMagick6_FOLDER}/magick/coder.c
    ${ImageMagick6_FOLDER}/magick/blob.c
    ${ImageMagick6_FOLDER}/magick/delegate.c
    ${ImageMagick6_FOLDER}/magick/signature.c
    ${ImageMagick6_FOLDER}/magick/version.c
    ${ImageMagick6_FOLDER}/magick/nt-base.c
    ${ImageMagick6_FOLDER}/magick/xwindow.c
    ${ImageMagick6_FOLDER}/magick/resize.c
    ${ImageMagick6_FOLDER}/magick/quantum-import.c
    ${ImageMagick6_FOLDER}/magick/exception.c
    ${ImageMagick6_FOLDER}/magick/layer.c
    ${ImageMagick6_FOLDER}/magick/widget.c
    ${ImageMagick6_FOLDER}/magick/matrix.c
)
add_library(
    MagickCore6 SHARED ${MagickCore6_SOURCES}
)
target_compile_options(MagickCore6 PUBLIC ${ImageMagick6_CFLAGS} PRIVATE -Wfatal-errors)
target_compile_definitions(MagickCore6 PUBLIC ${ImageMagick6_CPPFLAGS})
target_include_directories(MagickCore6 PRIVATE ${MagickCore6_INCLUDE_DIRS})

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
add_library(
    ImageMagick6 SHARED
    ${ImageMagick6_SOURCES}
)
target_include_directories(
    ImageMagick6
    PRIVATE ${ImageMagick6_FOLDER}/Magick++/lib ${ImageMagick6_FOLDER}
    PUBLIC ${ImageMagick6_FOLDER}/Magick++/lib ${ImageMagick6_FOLDER}
)
target_link_libraries(ImageMagick6 PRIVATE MagickCore6)
target_compile_options(ImageMagick6 PRIVATE -Wfatal-errors)
target_compile_definitions(
    ImageMagick6
    PRIVATE ${ImageMagick6_CPPFLAGS}
    PUBLIC ${ImageMagick6_CPPFLAGS}
)
