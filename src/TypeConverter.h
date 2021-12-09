#ifndef NODE_IMAGEMAGICK_TYPECONVERTER_H
#define NODE_IMAGEMAGICK_TYPECONVERTER_H

#include <nan.h>
#include <Magick++.h>
#include <unordered_map>

class TypeConverter {
public:
    static bool GetArgument(v8::Local<v8::Value>,uint32_t&);
    static bool GetArgument(v8::Local<v8::Value>,int64_t&);
    static bool GetArgument(v8::Local<v8::Value>,double&);
    static bool GetArgument(v8::Local<v8::Value>,float&);
    static bool GetArgument(v8::Local<v8::Value>,unsigned short&);
    static bool GetArgument(v8::Local<v8::Value>,bool&);
    static bool GetArgument(v8::Local<v8::Value>,std::string&);
    static bool GetArgument(v8::Local<v8::Value>,Magick::MetricType&);
    static bool GetArgument(v8::Local<v8::Value>,Magick::ChannelType &);
    static bool GetArgument(v8::Local<v8::Value> val, Magick::CompositeOperator&);
    template<typename T>
    static bool Unwrap(v8::Local<v8::Value> obj, T** out) {
        *out = nullptr;
        if(!obj->IsObject()) {
            return false;
        }
        Nan::Persistent<v8::Function>& constructor = T::constructor;
        if(!obj->InstanceOf(Nan::GetCurrentContext(),Nan::To<v8::Object>(Nan::New(constructor)).ToLocalChecked()).ToChecked()){
            return false;
        }
        *out = Nan::ObjectWrap::Unwrap<T>(Nan::To<v8::Object>(obj).ToLocalChecked());
        return true;
    }
private:
    template<typename T> static bool GetEnum(v8::Local<v8::Value> val,T& out,std::unordered_map<std::string,T>&& map){
        int64_t id;
        if(!TypeConverter::GetArgument(val,id)) {
            return false;
        }
        out = static_cast<T>(id);
        return false;
    }
};

#endif //NODE_IMAGEMAGICK_TYPECONVERTER_H
