#include "Geometry.h"
#include "TypeConverter.h"

#include <nan.h>

Nan::Persistent<v8::Function> Geometry::constructor;

NAN_METHOD(Geometry::Aspect) {
    Geometry* g;
    if(!TypeConverter::Unwrap(info.This(),&g)) {
        Nan::ThrowError("aspect() called under invalid context");
        return;
    }
    bool newValue;
    if(TypeConverter::GetArgument(info[0], newValue)){
        g->value.aspect(newValue);
    } else {
        info.GetReturnValue().Set(Nan::New(g->value.aspect()));
    }
}

void Geometry::Init(v8::Local<v8::Object> exports) {
    auto tpl = Nan::New<v8::FunctionTemplate>(New);

    tpl->SetClassName(Nan::New("Geometry").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl,"width",Width);
    Nan::SetPrototypeMethod(tpl,"isValid",IsValid);
    Nan::SetPrototypeMethod(tpl,"aspect",Aspect);
    Nan::SetPrototypeMethod(tpl,"height",Height);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());

    Nan::Set(exports,Nan::New("Geometry").ToLocalChecked(),Nan::GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(Geometry::Width) {
    Geometry* g;
    if(!TypeConverter::Unwrap(info.This(),&g)) {
        Nan::ThrowError("width() called under invalid context");
        return;
    }
    uint32_t value;
    if(TypeConverter::GetArgument(info[0],value)) {
        g->value.width(value);
        return;
    }
    info.GetReturnValue().Set(Nan::New<v8::Number>(g->value.width()));
}

NAN_METHOD(Geometry::IsValid) {
    Geometry* g;
    if(!TypeConverter::Unwrap(info.This(),&g)) {
        Nan::ThrowError("width() called under invalid context");
        return;
    }
    info.GetReturnValue().Set(g->value.isValid());
}

NAN_METHOD(Geometry::Height) {
    Geometry* g;
    if(!TypeConverter::Unwrap(info.This(),&g)) {
        Nan::ThrowError("width() called under invalid context");
        return;
    }
    uint32_t value;
    if(TypeConverter::GetArgument(info[0],value)) {
        g->value.height(value);
        return;
    }
    info.GetReturnValue().Set(Nan::New<v8::Number>(g->value.height()));
}

NAN_METHOD(Geometry::New) {
    Geometry* geometry;
    std::string value;
    if(TypeConverter::GetArgument(info[0],value)) {
        geometry = new Geometry(value);
    } else {
        uint32_t width;
        uint32_t height;
        uint32_t xOff;
        uint32_t yOff;
        if(!TypeConverter::GetArgument(info[0],width)) {
            Nan::ThrowError("First argument must be a valid unsigned 32-bit integer");
            return;
        }
        if(!TypeConverter::GetArgument(info[1],height)) {
            Nan::ThrowError("Second argument must be a valid unsigned 32-bit integer");
            return;
        }
        if(!TypeConverter::GetArgument(info[2],xOff)) {
            Nan::ThrowError("Third argument must be a valid unsigned 32-bit integer");
            return;
        }
        if(!TypeConverter::GetArgument(info[3],yOff)) {
            Nan::ThrowError("Forth argument must be a valid unsigned 32-bit integer");
            return;
        }
        geometry = new Geometry(width,height,xOff,yOff);
    }
    geometry->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

Geometry::Geometry(size_t w, size_t h, ssize_t x, ssize_t y): value(w,h,x,y) {

}

Geometry::Geometry(std::string& value): value(value) {

}
