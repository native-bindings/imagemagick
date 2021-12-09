#ifndef NODE_IMAGEMAGICK_IMAGE_H
#define NODE_IMAGEMAGICK_IMAGE_H

#include <nan.h>
#include <Magick++.h>

class Image : public Nan::ObjectWrap {
public:
    static Nan::Persistent<v8::Function> constructor;
    static void Init(v8::Local<v8::Object>);
private:
    Magick::Image value;
    static NAN_METHOD(New);
    static NAN_METHOD(BackgroundColor);
    static NAN_METHOD(Read);
    static NAN_METHOD(Write);
    static NAN_METHOD(Size);
    static NAN_METHOD(Magick);
    static NAN_METHOD(Negate);
    static NAN_METHOD(Compare);
    static NAN_METHOD(Emboss);
    static NAN_METHOD(Encipher);
    static NAN_METHOD(Density);
    static NAN_METHOD(Decipher);
    static NAN_METHOD(Crop);
    static NAN_METHOD(Roll);
    static NAN_METHOD(Rotate);
    static NAN_METHOD(Scale);
    static NAN_METHOD(Shave);
    static NAN_METHOD(Sample);
    static NAN_METHOD(Composite);
    static NAN_METHOD(DefineValue);
    static NAN_METHOD(Resize);
    static NAN_METHOD(Normalize);
    static NAN_METHOD(OilPaint);
    static NAN_METHOD(MotionBlur);
};


#endif //NODE_IMAGEMAGICK_IMAGE_H
