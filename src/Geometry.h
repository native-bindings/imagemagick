#ifndef NODE_IMAGEMAGICK_GEOMETRY_H
#define NODE_IMAGEMAGICK_GEOMETRY_H

#include <nan.h>
#include <Magick++.h>

class Geometry : public Nan::ObjectWrap {
public:
    static constexpr auto className = "Geometry";
    static Nan::Persistent<v8::Function> constructor;
    static void Init(v8::Local<v8::Object>);
    Magick::Geometry value;
private:
    static NAN_METHOD(New);
    static NAN_METHOD(Width);
    static NAN_METHOD(IsValid);
    static NAN_METHOD(Height);
    static NAN_METHOD(Aspect);
    static NAN_METHOD(LimitPixels);
    static NAN_METHOD(Percentage);
    static NAN_METHOD(FillArea);
    static NAN_METHOD(Greater);
    static NAN_METHOD(Less);
    static NAN_METHOD(XNegative);
    static NAN_METHOD(YNegative);
    static NAN_METHOD(ToString);
    Geometry(size_t,size_t,ssize_t,ssize_t);
    explicit Geometry(std::string&);
};


#endif //NODE_IMAGEMAGICK_GEOMETRY_H
