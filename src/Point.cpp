#include "Point.h"
#include "TypeConverter.h"

#include <iostream>

Nan::Persistent<v8::Function> Point::constructor;

void Point::Init(v8::Local<v8::Object> exports) {
    auto tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Point").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl,"x",X);
    Nan::SetPrototypeMethod(tpl,"y",Y);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());

    Nan::Set(exports,Nan::New("Point").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(Point::New) {
    try {
        auto* point = FromArguments(info);
        point->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
    }
}

Point::Point(std::string& value): value(value) {

}

Point::Point(double x, double y): value(x, y) {

}

Point::Point(double xy): value(xy) {

}

NAN_METHOD(Point::X) {
    Point* p;
    if(!TypeConverter::Unwrap(info.This(),&p)) {
        Nan::ThrowError("x() called under invalid context");
        return;
    }
    info.GetReturnValue().Set(Nan::New(p->value.x()));
}

NAN_METHOD(Point::Y) {
    Point* p;
    if(!TypeConverter::Unwrap(info.This(),&p)) {
        Nan::ThrowError("y() called under invalid context");
        return;
    }
    info.GetReturnValue().Set(Nan::New(p->value.y()));
}

Point *Point::FromArguments(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    Point* point;
    double x, y, xy;
    std::string value;
    if(TypeConverter::GetArgument(info[0],value)) {
        point = new Point(value);
    } else if(TypeConverter::GetArgument(info[0],x) && TypeConverter::GetArgument(info[1],y)) {
        point = new Point(x, y);
    } else if(TypeConverter::GetArgument(info[0],xy)) {
        point = new Point(xy);
    } else {
        point = new Point();
    }
    return point;
}

Point::Point(): value() {

}
