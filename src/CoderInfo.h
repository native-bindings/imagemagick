
#ifndef NODE_NODE_IMAGEMAGICK_CODERINFO_H
#define NODE_NODE_IMAGEMAGICK_CODERINFO_H

#include <Magick++.h>
#include <nan.h>

class CoderInfo : public Nan::ObjectWrap {
public:
    static constexpr const char* className = "CodeInfo";
    static Nan::Persistent<v8::Function> constructor;
    static void Init(v8::Local<v8::Object>);
private:
    Magick::CoderInfo value;
    static NAN_METHOD(New);
    static NAN_METHOD(CoderInfoList);
    static NAN_METHOD(Name);
    static NAN_METHOD(MimeType);
    static NAN_METHOD(Description);
    static NAN_METHOD(IsMultiFrame);
    static NAN_METHOD(IsReadable);
    static NAN_METHOD(IsWritable);
};


#endif //NODE_NODE_IMAGEMAGICK_CODERINFO_H
