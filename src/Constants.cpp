#include "Constants.h"

std::unordered_map<std::string,Magick::CompositeOperator> Constants::getCompositeOperators() {
    static std::unordered_map<std::string,Magick::CompositeOperator> compositeOperators {
        {"UndefinedCompositeOp",Magick::CompositeOperator::UndefinedCompositeOp},
        {"NoCompositeOp",Magick::CompositeOperator::NoCompositeOp},
        {"ModulusAddCompositeOp",Magick::CompositeOperator::ModulusAddCompositeOp},
        {"AtopCompositeOp",Magick::CompositeOperator::AtopCompositeOp},
        {"BlendCompositeOp",Magick::CompositeOperator::BlendCompositeOp},
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
        {"CopyOpacityCompositeOp",Magick::CompositeOperator::CopyOpacityCompositeOp},
        {"CopyRedCompositeOp",Magick::CompositeOperator::CopyRedCompositeOp},
        {"CopyYellowCompositeOp",Magick::CompositeOperator::CopyYellowCompositeOp},
        {"DarkenCompositeOp",Magick::CompositeOperator::DarkenCompositeOp},
        {"DstAtopCompositeOp",Magick::CompositeOperator::DstAtopCompositeOp},
        {"DstCompositeOp",Magick::CompositeOperator::DstCompositeOp},
        {"DstInCompositeOp",Magick::CompositeOperator::DstInCompositeOp},
        {"DstOutCompositeOp",Magick::CompositeOperator::DstOutCompositeOp},
        {"DstOverCompositeOp",Magick::CompositeOperator::DstOverCompositeOp},
        {"DifferenceCompositeOp",Magick::CompositeOperator::DifferenceCompositeOp},
        {"DisplaceCompositeOp",Magick::CompositeOperator::DisplaceCompositeOp},
        {"DissolveCompositeOp",Magick::CompositeOperator::DissolveCompositeOp},
        {"ExclusionCompositeOp",Magick::CompositeOperator::ExclusionCompositeOp},
        {"HardLightCompositeOp",Magick::CompositeOperator::HardLightCompositeOp},
        {"HueCompositeOp",Magick::CompositeOperator::HueCompositeOp},
        {"InCompositeOp",Magick::CompositeOperator::InCompositeOp},
        {"LightenCompositeOp",Magick::CompositeOperator::LightenCompositeOp},
        {"LinearLightCompositeOp",Magick::CompositeOperator::LinearLightCompositeOp},
        {"LuminizeCompositeOp",Magick::CompositeOperator::LuminizeCompositeOp},
        {"MinusDstCompositeOp",Magick::CompositeOperator::MinusDstCompositeOp},
        {"ModulateCompositeOp",Magick::CompositeOperator::ModulateCompositeOp},
        {"MultiplyCompositeOp",Magick::CompositeOperator::MultiplyCompositeOp},
        {"OutCompositeOp",Magick::CompositeOperator::OutCompositeOp},
        {"OverCompositeOp",Magick::CompositeOperator::OverCompositeOp},
        {"OverlayCompositeOp",Magick::CompositeOperator::OverlayCompositeOp},
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
        {"ModulusSubtractCompositeOp",Magick::CompositeOperator::ModulusSubtractCompositeOp},
        {"ThresholdCompositeOp",Magick::CompositeOperator::ThresholdCompositeOp},
        {"XorCompositeOp",Magick::CompositeOperator::XorCompositeOp},

        /* These are new operators, added after the above was last sorted.
         * The list should be re-sorted only when a new library version is
         * created.
         */
        { "DivideDstCompositeOp",Magick::CompositeOperator::DivideDstCompositeOp },
        { "DistortCompositeOp",Magick::CompositeOperator::DistortCompositeOp },
        { "BlurCompositeOp",Magick::CompositeOperator::BlurCompositeOp },
        { "PegtopLightCompositeOp",Magick::CompositeOperator::PegtopLightCompositeOp },
        { "VividLightCompositeOp",Magick::CompositeOperator::VividLightCompositeOp },
        { "PinLightCompositeOp",Magick::CompositeOperator::PinLightCompositeOp },
        { "LinearDodgeCompositeOp",Magick::CompositeOperator::LinearDodgeCompositeOp },
        { "LinearBurnCompositeOp",Magick::CompositeOperator::LinearBurnCompositeOp },
        { "MathematicsCompositeOp",Magick::CompositeOperator::MathematicsCompositeOp },
        { "DivideSrcCompositeOp",Magick::CompositeOperator::DivideSrcCompositeOp },
        { "MinusSrcCompositeOp",Magick::CompositeOperator::MinusSrcCompositeOp },
        { "DarkenIntensityCompositeOp",Magick::CompositeOperator::DarkenIntensityCompositeOp },
        { "LightenIntensityCompositeOp",Magick::CompositeOperator::LightenIntensityCompositeOp },
        { "HardMixCompositeOp",Magick::CompositeOperator::HardMixCompositeOp },
        { "StereoCompositeOp",Magick::CompositeOperator::StereoCompositeOp }
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
        {"UndefinedMetric",Magick::MetricType::UndefinedMetric},
        {"AbsoluteErrorMetric",Magick::MetricType::AbsoluteErrorMetric},
        {"MeanAbsoluteErrorMetric",Magick::MetricType::MeanAbsoluteErrorMetric},
        {"MeanErrorPerPixelMetric",Magick::MetricType::MeanErrorPerPixelMetric},
        {"MeanSquaredErrorMetric",Magick::MetricType::MeanSquaredErrorMetric},
        {"PeakAbsoluteErrorMetric",Magick::MetricType::PeakAbsoluteErrorMetric},
        {"PeakSignalToNoiseRatioMetric",Magick::MetricType::PeakSignalToNoiseRatioMetric},
        {"RootMeanSquaredErrorMetric",Magick::MetricType::RootMeanSquaredErrorMetric},
        {"NormalizedCrossCorrelationErrorMetric",Magick::MetricType::NormalizedCrossCorrelationErrorMetric},
        {"FuzzErrorMetric",Magick::MetricType::FuzzErrorMetric},
        {"UndefinedErrorMetric",Magick::MetricType::UndefinedErrorMetric},
        {"PerceptualHashErrorMetric",Magick::MetricType::PerceptualHashErrorMetric}
    };
    return metricTypes;
}

std::unordered_map<std::string, Magick::ChannelType> Constants::getChannelTypes() {
    static std::unordered_map<std::string, Magick::ChannelType> channelTypes {
        {"UndefinedChannel",Magick::ChannelType::UndefinedChannel},
        {"RedChannel",Magick::ChannelType::RedChannel },
        {"GrayChannel",Magick::ChannelType::GrayChannel },
        {"CyanChannel",Magick::ChannelType::CyanChannel },
        {"GreenChannel",Magick::ChannelType::GreenChannel },
        {"MagentaChannel",Magick::ChannelType::MagentaChannel },
        {"BlueChannel",Magick::ChannelType::BlueChannel },
        {"YellowChannel",Magick::ChannelType::YellowChannel },
        {"AlphaChannel",Magick::ChannelType::AlphaChannel },
        {"OpacityChannel",Magick::ChannelType::OpacityChannel },
        {"MatteChannel",Magick::ChannelType::MatteChannel },
        {"BlackChannel",Magick::ChannelType::BlackChannel },
        {"IndexChannel",Magick::ChannelType::IndexChannel },
        {"CompositeChannels",Magick::ChannelType::CompositeChannels },
        {"AllChannels",Magick::ChannelType::AllChannels },
        {"TrueAlphaChannel",Magick::ChannelType::TrueAlphaChannel },
        {"RGBChannels",Magick::ChannelType::RGBChannels },
        {"GrayChannels",Magick::ChannelType::GrayChannels },
        {"SyncChannels",Magick::ChannelType::SyncChannels },
        {"DefaultChannels",Magick::ChannelType::DefaultChannels }
    };
    return channelTypes;
}
