#ifndef NODE_IMAGEMAGICK_COLOR_H
#define NODE_IMAGEMAGICK_COLOR_H

#include <nan.h>
#include <Magick++.h>

class Color : public Nan::ObjectWrap {
public:
    Magick::Color value;
    static void Init(v8::Local<v8::Object>);
    static Nan::Persistent<v8::Function> constructor;
private:
    Color();
    explicit Color(std::string&);
    Color(
        const Magick::Quantum& red,
        const Magick::Quantum& green,
        const Magick::Quantum& blue
    );
    Color(
        const Magick::Quantum& r,
        const Magick::Quantum& g,
        const Magick::Quantum& b,
        const Magick::Quantum& a
    );
    Color(
        const Magick::Quantum cyan,const Magick::Quantum magenta,
        const Magick::Quantum yellow,const Magick::Quantum black,
        const Magick::Quantum alpha
    );
    static NAN_METHOD(New);
};


#endif //NODE_IMAGEMAGICK_COLOR_H
