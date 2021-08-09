#include "TypeConverter.h"

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

bool TypeConverter::GetArgument(v8::Local<v8::Value> val,Magick::MetricType& metricType) {
    uint32_t metricTypeInt;
    if(!TypeConverter::GetArgument(val,metricTypeInt)) {
        return false;
    }
    switch(metricTypeInt) {
        case 0:
            metricType = Magick::MetricType::UndefinedErrorMetric;
            break;
        case 1:
            metricType = Magick::MetricType::AbsoluteErrorMetric;
            break;
        case 2:
            metricType = Magick::MetricType::FuzzErrorMetric;
            break;
        case 3:
            metricType = Magick::MetricType::MeanAbsoluteErrorMetric;
            break;
        case 4:
            metricType = Magick::MetricType::MeanErrorPerPixelErrorMetric;
            break;
        case 5:
            metricType = Magick::MetricType::MeanSquaredErrorMetric;
            break;
        case 6:
            metricType = Magick::MetricType::NormalizedCrossCorrelationErrorMetric;
            break;
        case 7:
            metricType = Magick::MetricType::PeakAbsoluteErrorMetric;
            break;
        case 8:
            metricType = Magick::MetricType::PeakSignalToNoiseRatioErrorMetric;
            break;
        case 9:
            metricType = Magick::MetricType::PerceptualHashErrorMetric;
            break;
        case 10:
            metricType = Magick::MetricType::RootMeanSquaredErrorMetric;
            break;
        case 11:
            metricType = Magick::MetricType::StructuralSimilarityErrorMetric;
            break;
        case 12:
            metricType = Magick::MetricType::StructuralDissimilarityErrorMetric;
            break;
        default:
            return false;
    }
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> val, Magick::CompositeOperator& out) {
    uint32_t compositeOpInt;
    if(!TypeConverter::GetArgument(val,compositeOpInt)) {
        return false;
    }
    switch(compositeOpInt) {
        case 0:
            out = Magick::CompositeOperator::UndefinedCompositeOp;
            break;
        case 1:
            out = Magick::CompositeOperator::AlphaCompositeOp;
            break;
        case 2:
            out = Magick::CompositeOperator::AtopCompositeOp;
            break;
        case 3:
            out = Magick::CompositeOperator::BlendCompositeOp;
            break;
        case 4:
            out = Magick::CompositeOperator::BlurCompositeOp;
            break;
        case 5:
            out = Magick::CompositeOperator::BumpmapCompositeOp;
            break;
        case 6:
            out = Magick::CompositeOperator::ChangeMaskCompositeOp;
            break;
        case 7:
            out = Magick::CompositeOperator::ClearCompositeOp;
            break;
        case 8:
            out = Magick::CompositeOperator::ColorBurnCompositeOp;
            break;
        case 9:
            out = Magick::CompositeOperator::ColorDodgeCompositeOp;
            break;
        case 10:
            out = Magick::CompositeOperator::ColorizeCompositeOp;
            break;
        case 11:
            out = Magick::CompositeOperator::CopyBlackCompositeOp;
            break;
        case 12:
            out = Magick::CompositeOperator::CopyBlueCompositeOp;
            break;
        case 13:
            out = Magick::CompositeOperator::CopyCompositeOp;
            break;
        case 14:
            out = Magick::CompositeOperator::CopyCyanCompositeOp;
            break;
        case 15:
            out = Magick::CompositeOperator::CopyGreenCompositeOp;
            break;
        case 16:
            out = Magick::CompositeOperator::CopyMagentaCompositeOp;
            break;
        case 17:
            out = Magick::CompositeOperator::CopyAlphaCompositeOp;
            break;
        case 18:
            out = Magick::CompositeOperator::CopyRedCompositeOp;
            break;
        case 19:
            out = Magick::CompositeOperator::CopyYellowCompositeOp;
            break;
        case 20:
            out = Magick::CompositeOperator::DarkenCompositeOp;
            break;
        case 21:
            out = Magick::CompositeOperator::DarkenIntensityCompositeOp;
            break;
        case 22:
            out = Magick::CompositeOperator::DifferenceCompositeOp;
            break;
        case 23:
            out = Magick::CompositeOperator::DisplaceCompositeOp;
            break;
        case 24:
            out = Magick::CompositeOperator::DissolveCompositeOp;
            break;
        case 25:
            out = Magick::CompositeOperator::DistortCompositeOp;
            break;
        case 26:
            out = Magick::CompositeOperator::DivideDstCompositeOp;
            break;
        case 27:
            out = Magick::CompositeOperator::DivideSrcCompositeOp;
            break;
        case 28:
            out = Magick::CompositeOperator::DstAtopCompositeOp;
            break;
        case 29:
            out = Magick::CompositeOperator::DstCompositeOp;
            break;
        case 30:
            out = Magick::CompositeOperator::DstInCompositeOp;
            break;
        case 31:
            out = Magick::CompositeOperator::DstOutCompositeOp;
            break;
        case 32:
            out = Magick::CompositeOperator::DstOverCompositeOp;
            break;
        case 33:
            out = Magick::CompositeOperator::ExclusionCompositeOp;
            break;
        case 34:
            out = Magick::CompositeOperator::HardLightCompositeOp;
            break;
        case 35:
            out = Magick::CompositeOperator::HardMixCompositeOp;
            break;
        case 36:
            out = Magick::CompositeOperator::HueCompositeOp;
            break;
        case 37:
            out = Magick::CompositeOperator::InCompositeOp;
            break;
        case 38:
            out = Magick::CompositeOperator::IntensityCompositeOp;
            break;
        case 39:
            out = Magick::CompositeOperator::LightenCompositeOp;
            break;
        case 40:
            out = Magick::CompositeOperator::LightenIntensityCompositeOp;
            break;
        case 41:
            out = Magick::CompositeOperator::LinearBurnCompositeOp;
            break;
        case 42:
            out = Magick::CompositeOperator::LinearDodgeCompositeOp;
            break;
        case 43:
            out = Magick::CompositeOperator::LinearLightCompositeOp;
            break;
        case 44:
            out = Magick::CompositeOperator::LuminizeCompositeOp;
            break;
        case 45:
            out = Magick::CompositeOperator::MathematicsCompositeOp;
            break;
        case 46:
            out = Magick::CompositeOperator::MinusDstCompositeOp;
            break;
        case 47:
            out = Magick::CompositeOperator::MinusSrcCompositeOp;
            break;
        case 48:
            out = Magick::CompositeOperator::ModulateCompositeOp;
            break;
        case 49:
            out = Magick::CompositeOperator::ModulusAddCompositeOp;
            break;
        case 50:
            out = Magick::CompositeOperator::ModulusSubtractCompositeOp;
            break;
        case 51:
            out = Magick::CompositeOperator::MultiplyCompositeOp;
            break;
        case 52:
            out = Magick::CompositeOperator::NoCompositeOp;
            break;
        case 53:
            out = Magick::CompositeOperator::OutCompositeOp;
            break;
        case 54:
            out = Magick::CompositeOperator::OverCompositeOp;
            break;
        case 55:
            out = Magick::CompositeOperator::OverlayCompositeOp;
            break;
        case 56:
            out = Magick::CompositeOperator::PegtopLightCompositeOp;
            break;
        case 57:
            out = Magick::CompositeOperator::PinLightCompositeOp;
            break;
        case 58:
            out = Magick::CompositeOperator::PlusCompositeOp;
            break;
        case 59:
            out = Magick::CompositeOperator::ReplaceCompositeOp;
            break;
        case 60:
            out = Magick::CompositeOperator::SaturateCompositeOp;
            break;
        case 61:
            out = Magick::CompositeOperator::ScreenCompositeOp;
            break;
        case 62:
            out = Magick::CompositeOperator::SoftLightCompositeOp;
            break;
        case 63:
            out = Magick::CompositeOperator::SrcAtopCompositeOp;
            break;
        case 64:
            out = Magick::CompositeOperator::SrcCompositeOp;
            break;
        case 65:
            out = Magick::CompositeOperator::SrcInCompositeOp;
            break;
        case 66:
            out = Magick::CompositeOperator::SrcOutCompositeOp;
            break;
        case 67:
            out = Magick::CompositeOperator::SrcOverCompositeOp;
            break;
        case 68:
            out = Magick::CompositeOperator::ThresholdCompositeOp;
            break;
        case 69:
            out = Magick::CompositeOperator::VividLightCompositeOp;
            break;
        case 70:
            out = Magick::CompositeOperator::XorCompositeOp;
            break;
        case 71:
            out = Magick::CompositeOperator::StereoCompositeOp;
            break;
        case 72:
            out = Magick::CompositeOperator::FreezeCompositeOp;
            break;
        case 73:
            out = Magick::CompositeOperator::InterpolateCompositeOp;
            break;
        case 74:
            out = Magick::CompositeOperator::NegateCompositeOp;
            break;
        case 75:
            out = Magick::CompositeOperator::ReflectCompositeOp;
            break;
        case 76:
            out = Magick::CompositeOperator::SoftBurnCompositeOp;
            break;
        case 77:
            out = Magick::CompositeOperator::SoftDodgeCompositeOp;
            break;
        case 78:
            out = Magick::CompositeOperator::StampCompositeOp;
            break;
        case 79:
            out = Magick::CompositeOperator::RMSECompositeOp;
            break;
        default:
            return false;
    }
    return true;
}

bool TypeConverter::GetArgument(v8::Local<v8::Value> value, float& v) {
    if(!value->IsNumber()) return false;
    v = float(Nan::To<v8::Number>(value).ToLocalChecked()->Value());
    return true;
}
