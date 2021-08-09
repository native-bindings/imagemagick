#include "Color.h"
#include "TypeConverter.h"

Nan::Persistent<v8::Function> Color::constructor;

void Color::Init(v8::Local<v8::Object> exports) {
    auto tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Color").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());

    Nan::Set(exports,Nan::New("Color").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

Color* Color::FromArguments(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    Magick::Quantum r, g, b, a;
    std::string colorStr;
    Color* color;
    if(TypeConverter::GetArgument(info[0],colorStr)) {
        color = new Color(colorStr);
    } else if(
        TypeConverter::GetArgument(info[0],r) &&
        TypeConverter::GetArgument(info[1],g) &&
        TypeConverter::GetArgument(info[2],b) &&
        TypeConverter::GetArgument(info[3],a)
    ) {
        color = new Color(r, g, b, a);
    } else if(
        TypeConverter::GetArgument(info[0],r) &&
        TypeConverter::GetArgument(info[1],g) &&
        TypeConverter::GetArgument(info[2],b)
    ) {
        color = new Color(r, g, b);
    } else {
        color = new Color();
    }
    return color;
}

NAN_METHOD(Color::New) {
    try {
        auto* color = FromArguments(info);
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
