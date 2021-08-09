#ifndef NODE_IMAGEMAGICK_POINT_H
#define NODE_IMAGEMAGICK_POINT_H

#include <Magick++.h>
#include <nan.h>

class Point : public Nan::ObjectWrap {
public:
    Magick::Point value;
    static Nan::Persistent<v8::Function> constructor;
    static void Init(v8::Local<v8::Object>);
private:
    Point(double,double);
    static Point* FromArguments(const Nan::FunctionCallbackInfo<v8::Value>&);
    explicit Point(double);
    Point();
    explicit Point(std::string&);
    static NAN_METHOD(New);
    static NAN_METHOD(X);
    static NAN_METHOD(Y);
};


#endif //NODE_IMAGEMAGICK_POINT_H
