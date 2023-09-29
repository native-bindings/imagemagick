#ifndef NODE_IMAGEMAGICK_GEOMETRY_H
#define NODE_IMAGEMAGICK_GEOMETRY_H

#include <nan.h>
#include <Magick++.h>

class Geometry : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::Function> constructor;
    static void Init(v8::Local<v8::Object>);
    Magick::Geometry value;
private:
    static NAN_METHOD(New);
    static NAN_METHOD(Width);
    static NAN_METHOD(IsValid);
    static NAN_METHOD(Height);
    static NAN_METHOD(Aspect);
    Geometry(size_t,size_t,ssize_t,ssize_t);
    Geometry(std::string&);
};


#endif //NODE_IMAGEMAGICK_GEOMETRY_H
