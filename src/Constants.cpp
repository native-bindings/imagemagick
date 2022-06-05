#include "Constants.h"

std::unordered_map<std::string,Magick::CompositeOperator> Constants::getCompositeOperators() {
    static std::unordered_map<std::string,Magick::CompositeOperator> compositeOperators {
        {"UndefinedCompositeOp",Magick::CompositeOperator::UndefinedCompositeOp},
        {"AlphaCompositeOp",Magick::CompositeOperator::AlphaCompositeOp},
        {"AtopCompositeOp",Magick::CompositeOperator::AtopCompositeOp},
        {"BlendCompositeOp",Magick::CompositeOperator::BlendCompositeOp},
        {"BlurCompositeOp",Magick::CompositeOperator::BlurCompositeOp},
        {"BumpmapCompositeOp",Magick::CompositeOperator::BumpmapCompositeOp},
        {"ChangeMaskCompositeOp",Magick::CompositeOperator::ChangeMaskCompositeOp},
        {"ClearCompositeOp",Magick::CompositeOperator::ClearCompositeOp},
        {"ColorBurnCompositeOp",Magick::CompositeOperator::ColorBurnCompositeOp},
        {"ColorDodgeCompositeOp",Magick::CompositeOperator::ColorDodgeCompositeOp},
        {"ColorizeCompositeOp",Magick::CompositeOperator::ColorizeCompositeOp},
        {"CopyBlackCompositeOp",Magick::CompositeOperator::CopyBlackCompositeOp},
        {"CopyBlueCompositeOp",Magick::CompositeOperator::CopyBlueCompositeOp},
        {"CopyCompositeOp",Magick::CompositeOperator::CopyCompositeOp},
        {"CopyCyanCompositeOp",Magick::CompositeOperator::CopyCyanCompositeOp},
        {"CopyGreenCompositeOp",Magick::CompositeOperator::CopyGreenCompositeOp},
        {"CopyMagentaCompositeOp",Magick::CompositeOperator::CopyMagentaCompositeOp},
        {"CopyAlphaCompositeOp",Magick::CompositeOperator::CopyAlphaCompositeOp},
        {"CopyRedCompositeOp",Magick::CompositeOperator::CopyRedCompositeOp},
        {"CopyYellowCompositeOp",Magick::CompositeOperator::CopyYellowCompositeOp},
        {"DarkenCompositeOp",Magick::CompositeOperator::DarkenCompositeOp},
        {"DarkenIntensityCompositeOp",Magick::CompositeOperator::DarkenIntensityCompositeOp},
        {"DifferenceCompositeOp",Magick::CompositeOperator::DifferenceCompositeOp},
        {"DisplaceCompositeOp",Magick::CompositeOperator::DisplaceCompositeOp},
        {"DissolveCompositeOp",Magick::CompositeOperator::DissolveCompositeOp},
        {"DistortCompositeOp",Magick::CompositeOperator::DistortCompositeOp},
        {"DivideDstCompositeOp",Magick::CompositeOperator::DivideDstCompositeOp},
        {"DivideSrcCompositeOp",Magick::CompositeOperator::DivideSrcCompositeOp},
        {"DstAtopCompositeOp",Magick::CompositeOperator::DstAtopCompositeOp},
        {"DstCompositeOp",Magick::CompositeOperator::DstCompositeOp},
        {"DstInCompositeOp",Magick::CompositeOperator::DstInCompositeOp},
        {"DstOutCompositeOp",Magick::CompositeOperator::DstOutCompositeOp},
        {"DstOverCompositeOp",Magick::CompositeOperator::DstOverCompositeOp},
        {"ExclusionCompositeOp",Magick::CompositeOperator::ExclusionCompositeOp},
        {"HardLightCompositeOp",Magick::CompositeOperator::HardLightCompositeOp},
        {"HardMixCompositeOp",Magick::CompositeOperator::HardMixCompositeOp},
        {"HueCompositeOp",Magick::CompositeOperator::HueCompositeOp},
        {"InCompositeOp",Magick::CompositeOperator::InCompositeOp},
        {"IntensityCompositeOp",Magick::CompositeOperator::IntensityCompositeOp},
        {"LightenCompositeOp",Magick::CompositeOperator::LightenCompositeOp},
        {"LightenIntensityCompositeOp",Magick::CompositeOperator::LightenIntensityCompositeOp},
        {"LinearBurnCompositeOp",Magick::CompositeOperator::LinearBurnCompositeOp},
        {"LinearDodgeCompositeOp",Magick::CompositeOperator::LinearDodgeCompositeOp},
        {"LinearLightCompositeOp",Magick::CompositeOperator::LinearLightCompositeOp},
        {"LuminizeCompositeOp",Magick::CompositeOperator::LuminizeCompositeOp},
        {"MathematicsCompositeOp",Magick::CompositeOperator::MathematicsCompositeOp},
        {"MinusDstCompositeOp",Magick::CompositeOperator::MinusDstCompositeOp},
        {"MinusSrcCompositeOp",Magick::CompositeOperator::MinusSrcCompositeOp},
        {"ModulateCompositeOp",Magick::CompositeOperator::ModulateCompositeOp},
        {"ModulusAddCompositeOp",Magick::CompositeOperator::ModulusAddCompositeOp},
        {"ModulusSubtractCompositeOp",Magick::CompositeOperator::ModulusSubtractCompositeOp},
        {"MultiplyCompositeOp",Magick::CompositeOperator::MultiplyCompositeOp},
        {"NoCompositeOp",Magick::CompositeOperator::NoCompositeOp},
        {"OutCompositeOp",Magick::CompositeOperator::OutCompositeOp},
        {"OverCompositeOp",Magick::CompositeOperator::OverCompositeOp},
        {"OverlayCompositeOp",Magick::CompositeOperator::OverlayCompositeOp},
        {"PegtopLightCompositeOp",Magick::CompositeOperator::PegtopLightCompositeOp},
        {"PinLightCompositeOp",Magick::CompositeOperator::PinLightCompositeOp},
        {"PlusCompositeOp",Magick::CompositeOperator::PlusCompositeOp},
        {"ReplaceCompositeOp",Magick::CompositeOperator::ReplaceCompositeOp},
        {"SaturateCompositeOp",Magick::CompositeOperator::SaturateCompositeOp},
        {"ScreenCompositeOp",Magick::CompositeOperator::ScreenCompositeOp},
        {"SoftLightCompositeOp",Magick::CompositeOperator::SoftLightCompositeOp},
        {"SrcAtopCompositeOp",Magick::CompositeOperator::SrcAtopCompositeOp},
        {"SrcCompositeOp",Magick::CompositeOperator::SrcCompositeOp},
        {"SrcInCompositeOp",Magick::CompositeOperator::SrcInCompositeOp},
        {"SrcOutCompositeOp",Magick::CompositeOperator::SrcOutCompositeOp},
        {"SrcOverCompositeOp",Magick::CompositeOperator::SrcOverCompositeOp},
        {"ThresholdCompositeOp",Magick::CompositeOperator::ThresholdCompositeOp},
        {"VividLightCompositeOp",Magick::CompositeOperator::VividLightCompositeOp},
        {"XorCompositeOp",Magick::CompositeOperator::XorCompositeOp},
        {"StereoCompositeOp",Magick::CompositeOperator::StereoCompositeOp},
        {"FreezeCompositeOp",Magick::CompositeOperator::FreezeCompositeOp},
        {"InterpolateCompositeOp",Magick::CompositeOperator::InterpolateCompositeOp},
        {"NegateCompositeOp",Magick::CompositeOperator::NegateCompositeOp},
        {"ReflectCompositeOp",Magick::CompositeOperator::ReflectCompositeOp},
        {"SoftBurnCompositeOp",Magick::CompositeOperator::SoftBurnCompositeOp},
        {"SoftDodgeCompositeOp",Magick::CompositeOperator::SoftDodgeCompositeOp},
        {"StampCompositeOp",Magick::CompositeOperator::StampCompositeOp},
        {"RMSECompositeOp",Magick::CompositeOperator::RMSECompositeOp},
        {"SaliencyBlendCompositeOp",Magick::CompositeOperator::SaliencyBlendCompositeOp},
        {"SeamlessBlendCompositeOp",Magick::CompositeOperator::SeamlessBlendCompositeOp}
    };
    return compositeOperators;
}

void Constants::Init(v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    CreateEnum(constants,"CompositeOperator",getCompositeOperators());
    CreateEnum(constants,"MetricType",getMetricTypes());
    CreateEnum(constants,"ChannelType",getChannelTypes());
    Nan::Set(exports,Nan::New("constants").ToLocalChecked(),constants);
}

std::unordered_map<std::string, Magick::MetricType> Constants::getMetricTypes() {
    static std::unordered_map<std::string, Magick::MetricType> metricTypes {
        {"UndefinedErrorMetric",Magick::MetricType::UndefinedErrorMetric},
        {"AbsoluteErrorMetric",Magick::MetricType::AbsoluteErrorMetric},
        {"FuzzErrorMetric",Magick::MetricType::FuzzErrorMetric},
        {"MeanAbsoluteErrorMetric",Magick::MetricType::MeanAbsoluteErrorMetric},
        {"MeanErrorPerPixelErrorMetric",Magick::MetricType::MeanErrorPerPixelErrorMetric},
        {"MeanSquaredErrorMetric",Magick::MetricType::MeanSquaredErrorMetric},
        {"NormalizedCrossCorrelationErrorMetric",Magick::MetricType::NormalizedCrossCorrelationErrorMetric},
        {"PeakAbsoluteErrorMetric",Magick::MetricType::PeakAbsoluteErrorMetric},
        {"PeakSignalToNoiseRatioErrorMetric",Magick::MetricType::PeakSignalToNoiseRatioErrorMetric},
        {"PerceptualHashErrorMetric",Magick::MetricType::PerceptualHashErrorMetric},
        {"RootMeanSquaredErrorMetric",Magick::MetricType::RootMeanSquaredErrorMetric},
        {"StructuralSimilarityErrorMetric",Magick::MetricType::StructuralSimilarityErrorMetric},
        {"StructuralDissimilarityErrorMetric",Magick::MetricType::StructuralDissimilarityErrorMetric}
    };
    return metricTypes;
}

std::unordered_map<std::string, Magick::ChannelType> Constants::getChannelTypes() {
    static std::unordered_map<std::string, Magick::ChannelType> channelTypes {
        {"UndefinedChannel",Magick::ChannelType::UndefinedChannel},
        {"RedChannel",Magick::ChannelType::RedChannel},
        {"GrayChannel",Magick::ChannelType::GrayChannel},
        {"CyanChannel",Magick::ChannelType::CyanChannel},
        {"LChannel",Magick::ChannelType::LChannel},
        {"GreenChannel",Magick::ChannelType::GreenChannel},
        {"MagentaChannel",Magick::ChannelType::MagentaChannel},
        {"aChannel",Magick::ChannelType::aChannel},
        {"BlueChannel",Magick::ChannelType::BlueChannel},
        {"bChannel",Magick::ChannelType::bChannel},
        {"YellowChannel",Magick::ChannelType::YellowChannel},
        {"BlackChannel",Magick::ChannelType::BlackChannel},
        {"AlphaChannel",Magick::ChannelType::AlphaChannel},
        {"OpacityChannel",Magick::ChannelType::OpacityChannel},
        {"IndexChannel",Magick::ChannelType::IndexChannel},
        {"ReadMaskChannel",Magick::ChannelType::ReadMaskChannel},
        {"WriteMaskChannel",Magick::ChannelType::WriteMaskChannel},
        {"MetaChannel",Magick::ChannelType::MetaChannel},
        {"CompositeMaskChannel",Magick::ChannelType::CompositeMaskChannel},
        {"CompositeChannels",Magick::ChannelType::CompositeChannels},
        {"AllChannels",Magick::ChannelType::AllChannels},
        {"TrueAlphaChannel",Magick::ChannelType::TrueAlphaChannel},
        {"RGBChannels",Magick::ChannelType::RGBChannels},
        {"GrayChannels",Magick::ChannelType::GrayChannels},
        {"SyncChannels",Magick::ChannelType::SyncChannels},
        {"DefaultChannels",Magick::ChannelType::DefaultChannels}
    };
    return channelTypes;
}
