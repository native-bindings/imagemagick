#include "Image.h"
#include "Geometry.h"
#include "Color.h"
#include "Constants.h"
#include "CoderInfo.h"
#include "core/Arguments.h"

NAN_MODULE_INIT(Init) {
    Magick::InitializeMagick(nullptr);
    CoderInfo::Init(target);
    Image::Init(target);
    Geometry::Init(target);
    Color::Init(target);
    Constants::Init(target);
}

NODE_MODULE(NativeBindingsImageMagick,Init)
