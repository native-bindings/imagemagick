#include "Image.h"
#include "core/Arguments.h"
#include "Geometry.h"
#include "Color.h"
#include "Constants.h"

using Nan::Set;
using v8::FunctionTemplate;
using v8::Local;
using v8::Value;

Nan::Persistent<v8::Function> Image::constructor;

void Image::Init(v8::Local<v8::Object> exports) {
    auto tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Image").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl,"defineValue",DefineValue);
    Nan::SetPrototypeMethod(tpl,"defineSet",DefineSet);
    Nan::SetPrototypeMethod(tpl,"read",Read);
    Nan::SetPrototypeMethod(tpl,"write",Write);
    Nan::SetPrototypeMethod(tpl,"composite",Composite);
    Nan::SetPrototypeMethod(tpl,"backgroundColor",BackgroundColor);
    Nan::SetPrototypeMethod(tpl,"encipher",Encipher);
    Nan::SetPrototypeMethod(tpl,"decipher",Decipher);
    Nan::SetPrototypeMethod(tpl,"density",Density);
    Nan::SetPrototypeMethod(tpl,"magick",Magick);
    Nan::SetPrototypeMethod(tpl,"emboss",Emboss);
    Nan::SetPrototypeMethod(tpl,"negate",Negate);
    Nan::SetPrototypeMethod(tpl,"crop",Crop);
    Nan::SetPrototypeMethod(tpl,"compare",Compare);
    Nan::SetPrototypeMethod(tpl,"sample",Sample);
    Nan::SetPrototypeMethod(tpl,"normalize",Normalize);
    Nan::SetPrototypeMethod(tpl,"oilPaint",OilPaint);
    Nan::SetPrototypeMethod(tpl,"size",Size);
    Nan::SetPrototypeMethod(tpl,"motionBlur",MotionBlur);
    Nan::SetPrototypeMethod(tpl,"resize",Resize);
    Nan::SetPrototypeMethod(tpl,"shave",Shave);
    Nan::SetPrototypeMethod(tpl,"scale",Scale);
    Nan::SetPrototypeMethod(tpl,"antiAlias",AntiAlias);
    Nan::SetPrototypeMethod(tpl,"rotate",Rotate);
    Nan::SetPrototypeMethod(tpl,"sample",Sample);
    Nan::SetPrototypeMethod(tpl,"scale",Scale);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());

    Set(exports,Nan::New("Image").ToLocalChecked(),Nan::GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(Image::DefineValue) {
    std::string magick,key,value;
    Image* img;
    Arguments args(info, "defineValue");
    if(!args.Unwrap(img)) {
        return;
    }
    if(
        !args.Convert(0,magick) ||
        !args.Convert(1,key)
    ){
        return;
    }
    try {
        if(args.ConvertOptional(2,value)){
            img->value.defineValue(magick,key,value);
        } else {
            info.GetReturnValue().Set(Nan::New(img->value.defineValue(magick,key)).ToLocalChecked());
        }
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::DefineSet) {
    std::string magick,key;
    bool flag;
    Image* img;
    Arguments args(info, "defineSet");
    if(!args.Unwrap(img)) {
        return;
    }
    if(
        !args.Convert(0,magick) ||
        !args.Convert(1,key)
    ){
        return;
    }
    try {
        if(args.ConvertOptional(2,flag)){
            img->value.defineSet(magick,key,flag);
        } else {
            info.GetReturnValue().Set(Nan::New(img->value.defineSet(magick,key)));
        }
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::New) {
    auto* img = new Image();
    img->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

NAN_METHOD(Image::Read) {
    std::string file;
    Arguments args(info, "read");
    Image* img;
    if(!args.Unwrap(img) || !args.Convert(0,file)) {
        return;
    }
    try {
        img->value.read(file);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Write) {
    std::string file;
    Image* img;
    Arguments args(info, "write");
    if(!args.Unwrap(img)) {
        return;
    }
    if(!args.Convert(0,file)) {
        return;
    }
    try {
        img->value.write(file);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Crop) {
    Geometry* g;
    Arguments args(info, "crop");
    Image* img;
    if(!args.Unwrap(img)) {
        return;
    }
    if(!args.Unwrap(0, g)) {
        return;
    }
    try {
        img->value.crop(g->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Shave) {
    Geometry* g;
    Arguments args(info, "shave");
    Image* img;
    if(!args.Unwrap(img)) {
        return;
    }
    if(!args.Unwrap(0, g)) {
        return;
    }
    try {
        img->value.shave(g->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::BackgroundColor) {
    Image* img;
    Arguments args(info, "backgroundColor");
    if(!args.Unwrap(img)) {
        return;
    }
    Color* color;
    if(!info[0]->IsUndefined()) {
        if(!args.Unwrap(0, color)) {
            return;
        }
        img->value.backgroundColor(color->value);
    } else {
        v8::Local<v8::Value> argv[] = {
            Nan::New(std::string(img->value.backgroundColor())).ToLocalChecked()
        };
        info.GetReturnValue().Set(Nan::NewInstance(
            Nan::New(Color::constructor),
            1,
            argv
        ).ToLocalChecked());
    }
}

NAN_METHOD(Image::Roll) {
    Geometry* g;
    Arguments args(info, "roll");
    Image* img;
    if(!args.Unwrap(img)) {
        return;
    }
    if(!args.Unwrap(0, g)) {
        return;
    }
    try {
        img->value.roll(g->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Composite) {
    Image* img;
    Arguments args(info, "composite");
    Image* compositeImage;
    Geometry* g;
    Magick::CompositeOperator compositeOp;
    if(!args.Unwrap(img) || !args.Unwrap(0,compositeImage) || !args.Unwrap(1, g)) {
        return;
    }
    if(!info[2]->IsUndefined()) {
        if(!Constants::ConvertCompositeOperator(info[2], compositeOp)) {
            return;
        }
    } else {
        compositeOp = Magick::CompositeOperator::InCompositeOp;
    }
    try {
        img->value.composite(compositeImage->value, g->value, compositeOp);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Scale) {
    Geometry* g;
    Arguments args(info, "scale");
    Image* img;
    if(!args.Unwrap(img) || !args.Unwrap(0, g)) {
        return;
    }
    try {
        img->value.scale(g->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Sample) {
    Geometry* g;
    Arguments args(info, "sample");
    Image* img;
    if(!args.Unwrap(img) || !args.Unwrap(0, g)) {
        return;
    }
    try {
        img->value.sample(g->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::MotionBlur) {
    double radius;
    double sigma;
    double angle;
    Arguments args(info, "motionBlur");
    Image* img;
    if(!args.Unwrap(img)) {
        return;
    }
    if(!args.Convert(0, radius) || !args.Convert(1, sigma) || !args.Convert(2, angle)) {
        return;
    }
    try {
        img->value.motionBlur(radius,sigma,angle);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Normalize) {
    Image* img;
    Arguments args(info, "normalize");
    if(!args.Unwrap(img)) {
        return;
    }
    try {
        img->value.normalize();
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Rotate) {
    double degrees;
    Image* img;
    Arguments args(info, "rotate");
    if(!args.Unwrap(img) || !args.Convert(0, degrees)) {
        return;
    }
    try {
        img->value.rotate(degrees);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Encipher) {
    std::string passphrase;
    Arguments args(info, "encipher");
    Image* img;
    if(!args.Unwrap(img) || !args.Convert(0, passphrase)) {
        return;
    }
    try {
        img->value.encipher(passphrase);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Decipher) {
    std::string passphrase;
    Arguments args(info, "decipher");
    Image* img;
    if(!args.Unwrap(img) || !args.Convert(0, passphrase)) {
        return;
    }
    try {
        img->value.decipher(passphrase);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::OilPaint) {
    double radius;
    Arguments args(info, "oilPaint");
    Image* img;
    if(!args.Unwrap(img) || !args.Convert(0, radius)) {
        return;
    }
    try {
        img->value.oilPaint(radius);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Emboss) {
    double radius;
    double sigma;
    Arguments args(info, "emboss");
    Image* img;
    if(
        !args.Unwrap(img) ||
        !args.Convert(0, radius) ||
        !args.Convert(1, sigma)
    ) {
        return;
    }
    try {
        img->value.emboss(radius,sigma);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Resize) {
    Arguments args(info, "resize");
    Image* img;
    Geometry* geo;
    if(!args.Unwrap(img)) {
        return;
    }
    if(!args.Unwrap(0, geo)) {
        return;
    }
    try {
        img->value.resize(geo->value);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::AntiAlias) {
    bool flag;
    Arguments args(info, "antiAlias");
    Image* img;
    if(!args.Unwrap(img)) {
        return;
    }
    if(!args.HasArgument(0)) {
        info.GetReturnValue().Set(Nan::New(img->value.antiAlias()));
        return;
    }
    if(!args.Convert(0, flag)) {
        return;
    }
    try {
        img->value.antiAlias(flag);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Negate) {
    bool grayscale;
    Arguments args(info, "negate");
    Image* img;
    if(!args.Unwrap(img) || !args.Convert(0, grayscale)) {
        return;
    }
    try {
        img->value.negate(grayscale);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Compare) {
    Image* img, *ref;
    Arguments args(info, "compare");
    if(!args.Unwrap(img) || !args.Unwrap(0,ref)) {
        return;
    }
    try {
        Magick::MetricType metricType;
        Local<Value> result;
        if(!info[1]->IsUndefined()) {
            if(!Constants::ConvertMetricType(info[1], metricType)) {
                return;
            }
            result = Nan::New(img->value.compare(ref->value,metricType));
        } else {
            result = Nan::New(img->value.compare(ref->value));
        }
        info.GetReturnValue().Set(result);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Magick) {
    Image* img;
    Arguments args(info, "magick");
    if(!args.Unwrap(img)) {
        return;
    }
    try {
        std::string format;
        if(!info[0]->IsUndefined()) {
            if(!args.Convert(0,format)) {
                return;
            }
            img->value.magick(format);
        } else {
            info.GetReturnValue().Set(Nan::New(img->value.magick()).ToLocalChecked());
        }
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Density) {
    Image* img;
    Arguments args(info, "density");
    if(!args.Unwrap(img)) {
        return;
    }
    try {
        Geometry* density;
        if(!info[0]->IsUndefined()) {
            if(!args.Unwrap(0, density)) {
                return;
            }
            img->value.density(density->value);
            return;
        }
        Local<v8::Value> argv[] {
            Nan::New(std::string(img->value.density())).ToLocalChecked()
        };
        info.GetReturnValue().Set(Nan::NewInstance(
            Nan::New(Geometry::constructor),
            1,
            argv
        ).ToLocalChecked());
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

NAN_METHOD(Image::Size) {
    Image* img;
    Arguments args(info, "size");
    if(!args.Unwrap(img)) {
        return;
    }
    try {
        Geometry* density;
        if(!info[0]->IsUndefined()) {
            if(!args.Unwrap(0, density)) {
                return;
            }
            img->value.size(density->value);
            return;
        }
        Local<v8::Value> argv[] {
            Nan::New(std::string(img->value.size())).ToLocalChecked()
        };
        info.GetReturnValue().Set(Nan::NewInstance(
            Nan::New(Geometry::constructor),
            1,
            argv
        ).ToLocalChecked());
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}
