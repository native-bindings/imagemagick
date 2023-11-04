#include "Color.h"
#include "core/Arguments.h"

Nan::Persistent<v8::Function> Color::constructor;

void Color::Init(v8::Local<v8::Object> exports) {
    auto tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Color").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());

    Nan::Set(exports,Nan::New("Color").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

Color* Color::FromArguments(Nan::NAN_METHOD_ARGS_TYPE info) {
    Magick::Quantum r, g, b, a;
    std::string colorStr;
    Color* color;
    Arguments args(info, "Color#constructor");
    if(info[0]->IsString()) {
        if(!args.Convert(0, colorStr)) {
            return nullptr;
        }
        color = new Color(colorStr);
    } else if(!info[3]->IsUndefined()) { // if the forth argument is not undefined, we must have an RGBA color
        if(
            !args.Convert(0, r) ||
            !args.Convert(1, g) ||
            !args.Convert(2, b) ||
            !args.Convert(3, a)
        ) {
            return nullptr;
        }
        color = new Color(r, g, b, a);
    } else if(
        !info[0]->IsUndefined()
    ) { // if the first argument is not undefined, we must have an RGB color
        if(
            !args.Convert(0, r) ||
            !args.Convert(1, g) ||
            !args.Convert(2, b)
        ) {
            return nullptr;
        }
        color = new Color(r, g, b);
    } else {
        color = new Color();
    }
    return color;
}

NAN_METHOD(Color::New) {
    try {
        auto* color = FromArguments(info);
        if(!color){
            return;
        }
        color->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

Color::Color(): value() {

}

Color::Color(
    const MagickCore::Quantum &red,
    const MagickCore::Quantum &green,
    const MagickCore::Quantum &blue
): value(red, green, blue) {

}

Color::Color(
    const MagickCore::Quantum &red,
    const MagickCore::Quantum &green,
    const MagickCore::Quantum &blue,
    const MagickCore::Quantum &alpha
): value(red, green, blue, alpha) {

}

Color::Color(std::string& value): value(value) {

}
