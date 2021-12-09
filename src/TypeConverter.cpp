#include "TypeConverter.h"
#include "Constants.h"

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, int64_t & out) {
    if(!val->IsNumber()) {
        return false;
    }
    out = Nan::To<v8::Integer>(val).ToLocalChecked()->Value();
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, uint32_t & out) {
    if(!val->IsUint32()) {
        return false;
    }
    out = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, double & out) {
    if(!val->IsNumber()) {
        return false;
    }
    out = Nan::To<v8::Number>(val).ToLocalChecked()->Value();
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, std::string & out) {
    if(!val->IsString()) {
        return false;
    }
    ssize_t len = Nan::DecodeBytes(val,Nan::Encoding::BINARY);
    char value[len];
    if(Nan::DecodeWrite(value, len, val, Nan::Encoding::BINARY) != len) return false;
    out = std::string(value,len);
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, bool& out) {
    if(!val->IsBoolean()) {
        return false;
    }
    out = Nan::To<v8::Boolean>(val).ToLocalChecked()->Value();
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val,Magick::MetricType& out) {
    return GetEnum(val, out, Constants::getMetricTypes());
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, Magick::CompositeOperator& out) {
    return GetEnum(val, out, Constants::getCompositeOperators());
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> value, float& v) {
    if(!value->IsNumber()) return false;
    v = float(Nan::To<v8::Number>(value).ToLocalChecked()->Value());
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, unsigned short& out) {
    if(!val->IsInt32()) return false;
    out = uint16_t(Nan::To<v8::Uint32>(val).ToLocalChecked()->Value());
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, MagickCore::ChannelType & out) {
    return GetEnum(val, out, Constants::getChannelTypes());
}
