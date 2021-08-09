#include "Image.h"
#include "Geometry.h"
#include "Point.h"
#include "Color.h"

#include <nan.h>
#include <Magick++.h>

NAN_MODULE_INIT(Init) {
    Magick::InitializeMagick(nullptr);
    Image::Init(target);
    Geometry::Init(target);
    Point::Init(target);
    Color::Init(target);
}

NODE_MODULE(imagemagick,Init)
