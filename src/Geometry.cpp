#include "Geometry.h"
#include "core/Arguments.h"

#include <nan.h>

Nan::Persistent<v8::Function> Geometry::constructor;

NAN_METHOD(Geometry::Aspect) {
    Geometry* g;
    Arguments args(info, "aspect");
    if(!args.Unwrap(g)) {
        return;
    }
    bool newValue;
    if(args.Convert(0, newValue)){
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
    Arguments args(info, "width");
    if(!args.Unwrap(g)) {
        return;
    }
    uint32_t value;
    if(!info[0]->IsUndefined()) {
        if(!args.Convert(0, value)) {
            return;
        }
        g->value.width(value);
        return;
    }
    info.GetReturnValue().Set(Nan::New<v8::Number>(g->value.width()));
}

NAN_METHOD(Geometry::IsValid) {
    Geometry* g;
    Arguments args(info, "isValid");
    if(!args.Unwrap(g)) {
        return;
    }
    info.GetReturnValue().Set(g->value.isValid());
}

NAN_METHOD(Geometry::Height) {
    Geometry* g;
    Arguments args(info, "height");
    if(!args.Unwrap(g)) {
        return;
    }
    uint32_t value;
    if(!info[0]->IsUndefined()) {
        if(!args.Convert(0, value)) {
            return;
        }
        g->value.height(value);
        return;
    }
    info.GetReturnValue().Set(Nan::New<v8::Number>(g->value.height()));
}

NAN_METHOD(Geometry::New) {
    Geometry* geometry;
    std::string value;
    Arguments args(info, "constructor");
    /**
     * if second argument is undefined, we must have a string in the first argument
     */
    if(!args.HasArgument(1)) {
        if(!args.Convert(0, value)) {
            return;
        }
        geometry = new Geometry(value);
    } else {
        uint32_t width;
        uint32_t height;
        uint32_t xOff;
        uint32_t yOff;
        if(
            !args.Convert(0, width) ||
            !args.Convert(1, height) ||
            !args.Convert(2, xOff) ||
            !args.Convert(3, yOff)
        ) {
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
