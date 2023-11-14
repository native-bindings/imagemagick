#include "CoderInfo.h"
#include "core/Arguments.h"

Nan::Persistent<v8::Function> CoderInfo::constructor;

void CoderInfo::Init(v8::Local<v8::Object> exports) {
    auto tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("CoderInfo").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "name", Name);
    Nan::SetPrototypeMethod(tpl, "mimeType", MimeType);
    Nan::SetPrototypeMethod(tpl, "description", Description);
    Nan::SetPrototypeMethod(tpl, "isMultiFrame", IsMultiFrame);
    Nan::SetPrototypeMethod(tpl, "isReadable", IsReadable);
    Nan::SetPrototypeMethod(tpl, "isWritable", IsWritable);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());

    Nan::Set(exports, Nan::New("CoderInfo").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
    Nan::Set(exports, Nan::New("coderInfoList").ToLocalChecked(), Nan::New<v8::Function>(CoderInfoList));
}

NAN_METHOD(CoderInfo::Description) {
    Arguments args(info, "description");
    CoderInfo* coderInfo;
    if(!args.Unwrap(coderInfo)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(coderInfo->value.description()).ToLocalChecked());
}

NAN_METHOD(CoderInfo::CoderInfoList) {
    std::vector<Magick::CoderInfo> list;
    try {
        Magick::coderInfoList(&list);
    } catch(std::exception& e) {
        Nan::ThrowError(e.what());
        return;
    }
    auto result = Nan::New<v8::Array>();
    auto i = 0;
    CoderInfo* instance = nullptr;
    for(const Magick::CoderInfo& coderInfo : list) {
        auto jsInstance = Nan::NewInstance(Nan::New(CoderInfo::constructor), 0, nullptr).ToLocalChecked();
        if(!Arguments::Unwrap(jsInstance, instance)) {
            return;
        }
        instance->value = coderInfo;
        Nan::Set(result, Nan::New(i), jsInstance);
        i++;
    }
    info.GetReturnValue().Set(result);
}

NAN_METHOD(CoderInfo::IsMultiFrame) {
    Arguments args(info, "isMultiFrame");
    CoderInfo* coderInfo;
    if(!args.Unwrap(coderInfo)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(coderInfo->value.isMultiFrame()));
}

NAN_METHOD(CoderInfo::IsReadable) {
    Arguments args(info, "isReadable");
    CoderInfo* coderInfo;
    if(!args.Unwrap(coderInfo)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(coderInfo->value.isReadable()));
}

NAN_METHOD(CoderInfo::IsWritable) {
    Arguments args(info, "isWritable");
    CoderInfo* coderInfo;
    if(!args.Unwrap(coderInfo)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(coderInfo->value.isWritable()));
}

NAN_METHOD(CoderInfo::MimeType) {
    Arguments args(info, "mimeType");
    CoderInfo* coderInfo;
    if(!args.Unwrap(coderInfo)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(coderInfo->value.mimeType()).ToLocalChecked());
}

NAN_METHOD(CoderInfo::Name) {
    Arguments args(info, "name");
    CoderInfo* coderInfo;
    if(!args.Unwrap(coderInfo)) {
        return;
    }
    info.GetReturnValue().Set(Nan::New(coderInfo->value.name()).ToLocalChecked());
}

NAN_METHOD(CoderInfo::New) {
    if(!info.IsConstructCall()) {
        Nan::ThrowError("Constructor must be called with new");
        return;
    }
    auto coderInfo = new CoderInfo();
    coderInfo->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}
