#ifndef NODE_IMAGEMAGICK_CONSTANTS_H
#define NODE_IMAGEMAGICK_CONSTANTS_H

#include <nan.h>

#include <unordered_map>
#include <Magick++.h>


class Constants {
public:
    static std::unordered_map<std::string,Magick::CompositeOperator> getCompositeOperators();
    static std::unordered_map<std::string,Magick::MetricType> getMetricTypes();
    static std::unordered_map<std::string,Magick::ChannelType> getChannelTypes();
    static void Init(v8::Local<v8::Object>);
    template<typename T> static void CreateEnum(v8::Local<v8::Object> exports, std::string&& key,std::unordered_map<std::string,T> map) {
        auto obj = Nan::New<v8::Object>();
        for(auto& pair : map){
            Nan::Set(obj,Nan::New(pair.first).ToLocalChecked(),Nan::New<v8::Integer>(pair.second));
        }
        Nan::Set(exports,Nan::New(key).ToLocalChecked(),obj);
    }
//private:
//    static std::unordered_map<std::string,Magick::CompositeOperator> compositeOperators;
};


#endif //NODE_IMAGEMAGICK_CONSTANTS_H
