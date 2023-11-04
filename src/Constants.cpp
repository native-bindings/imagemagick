#include "Constants.h"

static void SetNoiseTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedNoise").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("UniformNoise").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("GaussianNoise").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("MultiplicativeGaussianNoise").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("ImpulseNoise").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("LaplacianNoise").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("PoissonNoise").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("RandomNoise").ToLocalChecked(), Nan::New(8));
    Nan::Set(exports, Nan::New("NoiseType").ToLocalChecked(), constants);
}

bool Constants::ConvertNoiseType(const v8::Local<v8::Value> val, Magick::NoiseType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to NoiseType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::NoiseType::UndefinedNoise;
        return true;
    }
    if(input == 2) {
        out = Magick::NoiseType::UniformNoise;
        return true;
    }
    if(input == 3) {
        out = Magick::NoiseType::GaussianNoise;
        return true;
    }
    if(input == 4) {
        out = Magick::NoiseType::MultiplicativeGaussianNoise;
        return true;
    }
    if(input == 5) {
        out = Magick::NoiseType::ImpulseNoise;
        return true;
    }
    if(input == 6) {
        out = Magick::NoiseType::LaplacianNoise;
        return true;
    }
    if(input == 7) {
        out = Magick::NoiseType::PoissonNoise;
        return true;
    }
    if(input == 8) {
        out = Magick::NoiseType::RandomNoise;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to NoiseType").ToLocalChecked());
    return false;
}

static void SetPathTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedPath").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("MagickPath").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("RootPath").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("HeadPath").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("TailPath").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("BasePath").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("ExtensionPath").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("SubimagePath").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("CanonicalPath").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("SubcanonicalPath").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("BasePathSansCompressExtension").ToLocalChecked(), Nan::New(11));
    Nan::Set(exports, Nan::New("PathType").ToLocalChecked(), constants);
}

bool Constants::ConvertPathType(const v8::Local<v8::Value> val, MagickCore::PathType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to PathType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::PathType::UndefinedPath;
        return true;
    }
    if(input == 2) {
        out = MagickCore::PathType::MagickPath;
        return true;
    }
    if(input == 3) {
        out = MagickCore::PathType::RootPath;
        return true;
    }
    if(input == 4) {
        out = MagickCore::PathType::HeadPath;
        return true;
    }
    if(input == 5) {
        out = MagickCore::PathType::TailPath;
        return true;
    }
    if(input == 6) {
        out = MagickCore::PathType::BasePath;
        return true;
    }
    if(input == 7) {
        out = MagickCore::PathType::ExtensionPath;
        return true;
    }
    if(input == 8) {
        out = MagickCore::PathType::SubimagePath;
        return true;
    }
    if(input == 9) {
        out = MagickCore::PathType::CanonicalPath;
        return true;
    }
    if(input == 10) {
        out = MagickCore::PathType::SubcanonicalPath;
        return true;
    }
    if(input == 11) {
        out = MagickCore::PathType::BasePathSansCompressExtension;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to PathType").ToLocalChecked());
    return false;
}

static void SetStretchTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedStretch").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("NormalStretch").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("UltraCondensedStretch").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("ExtraCondensedStretch").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("CondensedStretch").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("SemiCondensedStretch").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("SemiExpandedStretch").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("ExpandedStretch").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("ExtraExpandedStretch").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("UltraExpandedStretch").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("AnyStretch").ToLocalChecked(), Nan::New(11));
    Nan::Set(exports, Nan::New("StretchType").ToLocalChecked(), constants);
}

bool Constants::ConvertStretchType(const v8::Local<v8::Value> val, Magick::StretchType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to StretchType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::StretchType::UndefinedStretch;
        return true;
    }
    if(input == 2) {
        out = Magick::StretchType::NormalStretch;
        return true;
    }
    if(input == 3) {
        out = Magick::StretchType::UltraCondensedStretch;
        return true;
    }
    if(input == 4) {
        out = Magick::StretchType::ExtraCondensedStretch;
        return true;
    }
    if(input == 5) {
        out = Magick::StretchType::CondensedStretch;
        return true;
    }
    if(input == 6) {
        out = Magick::StretchType::SemiCondensedStretch;
        return true;
    }
    if(input == 7) {
        out = Magick::StretchType::SemiExpandedStretch;
        return true;
    }
    if(input == 8) {
        out = Magick::StretchType::ExpandedStretch;
        return true;
    }
    if(input == 9) {
        out = Magick::StretchType::ExtraExpandedStretch;
        return true;
    }
    if(input == 10) {
        out = Magick::StretchType::UltraExpandedStretch;
        return true;
    }
    if(input == 11) {
        out = Magick::StretchType::AnyStretch;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to StretchType").ToLocalChecked());
    return false;
}

static void SetStyleTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedStyle").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("NormalStyle").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ItalicStyle").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("ObliqueStyle").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("AnyStyle").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("BoldStyle").ToLocalChecked(), Nan::New(6));
    Nan::Set(exports, Nan::New("StyleType").ToLocalChecked(), constants);
}

bool Constants::ConvertStyleType(const v8::Local<v8::Value> val, Magick::StyleType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to StyleType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::StyleType::UndefinedStyle;
        return true;
    }
    if(input == 2) {
        out = Magick::StyleType::NormalStyle;
        return true;
    }
    if(input == 3) {
        out = Magick::StyleType::ItalicStyle;
        return true;
    }
    if(input == 4) {
        out = Magick::StyleType::ObliqueStyle;
        return true;
    }
    if(input == 5) {
        out = Magick::StyleType::AnyStyle;
        return true;
    }
    if(input == 6) {
        out = Magick::StyleType::BoldStyle;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to StyleType").ToLocalChecked());
    return false;
}

static void SetTimerStateBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedTimerState").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("StoppedTimerState").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("RunningTimerState").ToLocalChecked(), Nan::New(3));
    Nan::Set(exports, Nan::New("TimerState").ToLocalChecked(), constants);
}

bool Constants::ConvertTimerState(const v8::Local<v8::Value> val, MagickCore::TimerState& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to TimerState: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::TimerState::UndefinedTimerState;
        return true;
    }
    if(input == 2) {
        out = MagickCore::TimerState::StoppedTimerState;
        return true;
    }
    if(input == 3) {
        out = MagickCore::TimerState::RunningTimerState;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to TimerState").ToLocalChecked());
    return false;
}

static void SetAutoThresholdMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedThresholdMethod").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("KapurThresholdMethod").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("OTSUThresholdMethod").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("TriangleThresholdMethod").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("AutoThresholdMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertAutoThresholdMethod(const v8::Local<v8::Value> val, MagickCore::AutoThresholdMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to AutoThresholdMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::AutoThresholdMethod::UndefinedThresholdMethod;
        return true;
    }
    if(input == 2) {
        out = MagickCore::AutoThresholdMethod::KapurThresholdMethod;
        return true;
    }
    if(input == 3) {
        out = MagickCore::AutoThresholdMethod::OTSUThresholdMethod;
        return true;
    }
    if(input == 4) {
        out = MagickCore::AutoThresholdMethod::TriangleThresholdMethod;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to AutoThresholdMethod").ToLocalChecked());
    return false;
}

static void SetMagickEvaluateOperatorBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedEvaluateOperator").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("AddEvaluateOperator").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("AndEvaluateOperator").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("DivideEvaluateOperator").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("LeftShiftEvaluateOperator").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("MaxEvaluateOperator").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("MinEvaluateOperator").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("MultiplyEvaluateOperator").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("OrEvaluateOperator").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("RightShiftEvaluateOperator").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("SetEvaluateOperator").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("SubtractEvaluateOperator").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("XorEvaluateOperator").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("PowEvaluateOperator").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("LogEvaluateOperator").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("ThresholdEvaluateOperator").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("ThresholdBlackEvaluateOperator").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("ThresholdWhiteEvaluateOperator").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("GaussianNoiseEvaluateOperator").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("ImpulseNoiseEvaluateOperator").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("LaplacianNoiseEvaluateOperator").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("MultiplicativeNoiseEvaluateOperator").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("PoissonNoiseEvaluateOperator").ToLocalChecked(), Nan::New(23));
    Nan::Set(constants, Nan::New("UniformNoiseEvaluateOperator").ToLocalChecked(), Nan::New(24));
    Nan::Set(constants, Nan::New("CosineEvaluateOperator").ToLocalChecked(), Nan::New(25));
    Nan::Set(constants, Nan::New("SineEvaluateOperator").ToLocalChecked(), Nan::New(26));
    Nan::Set(constants, Nan::New("AddModulusEvaluateOperator").ToLocalChecked(), Nan::New(27));
    Nan::Set(constants, Nan::New("MeanEvaluateOperator").ToLocalChecked(), Nan::New(28));
    Nan::Set(constants, Nan::New("AbsEvaluateOperator").ToLocalChecked(), Nan::New(29));
    Nan::Set(constants, Nan::New("ExponentialEvaluateOperator").ToLocalChecked(), Nan::New(30));
    Nan::Set(constants, Nan::New("MedianEvaluateOperator").ToLocalChecked(), Nan::New(31));
    Nan::Set(constants, Nan::New("SumEvaluateOperator").ToLocalChecked(), Nan::New(32));
    Nan::Set(constants, Nan::New("RootMeanSquareEvaluateOperator").ToLocalChecked(), Nan::New(33));
    Nan::Set(constants, Nan::New("InverseLogEvaluateOperator").ToLocalChecked(), Nan::New(34));
    Nan::Set(exports, Nan::New("MagickEvaluateOperator").ToLocalChecked(), constants);
}

bool Constants::ConvertMagickEvaluateOperator(const v8::Local<v8::Value> val, Magick::MagickEvaluateOperator& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MagickEvaluateOperator: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::MagickEvaluateOperator::UndefinedEvaluateOperator;
        return true;
    }
    if(input == 2) {
        out = Magick::MagickEvaluateOperator::AddEvaluateOperator;
        return true;
    }
    if(input == 3) {
        out = Magick::MagickEvaluateOperator::AndEvaluateOperator;
        return true;
    }
    if(input == 4) {
        out = Magick::MagickEvaluateOperator::DivideEvaluateOperator;
        return true;
    }
    if(input == 5) {
        out = Magick::MagickEvaluateOperator::LeftShiftEvaluateOperator;
        return true;
    }
    if(input == 6) {
        out = Magick::MagickEvaluateOperator::MaxEvaluateOperator;
        return true;
    }
    if(input == 7) {
        out = Magick::MagickEvaluateOperator::MinEvaluateOperator;
        return true;
    }
    if(input == 8) {
        out = Magick::MagickEvaluateOperator::MultiplyEvaluateOperator;
        return true;
    }
    if(input == 9) {
        out = Magick::MagickEvaluateOperator::OrEvaluateOperator;
        return true;
    }
    if(input == 10) {
        out = Magick::MagickEvaluateOperator::RightShiftEvaluateOperator;
        return true;
    }
    if(input == 11) {
        out = Magick::MagickEvaluateOperator::SetEvaluateOperator;
        return true;
    }
    if(input == 12) {
        out = Magick::MagickEvaluateOperator::SubtractEvaluateOperator;
        return true;
    }
    if(input == 13) {
        out = Magick::MagickEvaluateOperator::XorEvaluateOperator;
        return true;
    }
    if(input == 14) {
        out = Magick::MagickEvaluateOperator::PowEvaluateOperator;
        return true;
    }
    if(input == 15) {
        out = Magick::MagickEvaluateOperator::LogEvaluateOperator;
        return true;
    }
    if(input == 16) {
        out = Magick::MagickEvaluateOperator::ThresholdEvaluateOperator;
        return true;
    }
    if(input == 17) {
        out = Magick::MagickEvaluateOperator::ThresholdBlackEvaluateOperator;
        return true;
    }
    if(input == 18) {
        out = Magick::MagickEvaluateOperator::ThresholdWhiteEvaluateOperator;
        return true;
    }
    if(input == 19) {
        out = Magick::MagickEvaluateOperator::GaussianNoiseEvaluateOperator;
        return true;
    }
    if(input == 20) {
        out = Magick::MagickEvaluateOperator::ImpulseNoiseEvaluateOperator;
        return true;
    }
    if(input == 21) {
        out = Magick::MagickEvaluateOperator::LaplacianNoiseEvaluateOperator;
        return true;
    }
    if(input == 22) {
        out = Magick::MagickEvaluateOperator::MultiplicativeNoiseEvaluateOperator;
        return true;
    }
    if(input == 23) {
        out = Magick::MagickEvaluateOperator::PoissonNoiseEvaluateOperator;
        return true;
    }
    if(input == 24) {
        out = Magick::MagickEvaluateOperator::UniformNoiseEvaluateOperator;
        return true;
    }
    if(input == 25) {
        out = Magick::MagickEvaluateOperator::CosineEvaluateOperator;
        return true;
    }
    if(input == 26) {
        out = Magick::MagickEvaluateOperator::SineEvaluateOperator;
        return true;
    }
    if(input == 27) {
        out = Magick::MagickEvaluateOperator::AddModulusEvaluateOperator;
        return true;
    }
    if(input == 28) {
        out = Magick::MagickEvaluateOperator::MeanEvaluateOperator;
        return true;
    }
    if(input == 29) {
        out = Magick::MagickEvaluateOperator::AbsEvaluateOperator;
        return true;
    }
    if(input == 30) {
        out = Magick::MagickEvaluateOperator::ExponentialEvaluateOperator;
        return true;
    }
    if(input == 31) {
        out = Magick::MagickEvaluateOperator::MedianEvaluateOperator;
        return true;
    }
    if(input == 32) {
        out = Magick::MagickEvaluateOperator::SumEvaluateOperator;
        return true;
    }
    if(input == 33) {
        out = Magick::MagickEvaluateOperator::RootMeanSquareEvaluateOperator;
        return true;
    }
    if(input == 34) {
        out = Magick::MagickEvaluateOperator::InverseLogEvaluateOperator;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MagickEvaluateOperator").ToLocalChecked());
    return false;
}

static void SetMagickFunctionBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedFunction").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("PolynomialFunction").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("SinusoidFunction").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("ArcsinFunction").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("ArctanFunction").ToLocalChecked(), Nan::New(5));
    Nan::Set(exports, Nan::New("MagickFunction").ToLocalChecked(), constants);
}

bool Constants::ConvertMagickFunction(const v8::Local<v8::Value> val, Magick::MagickFunction& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MagickFunction: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::MagickFunction::UndefinedFunction;
        return true;
    }
    if(input == 2) {
        out = Magick::MagickFunction::PolynomialFunction;
        return true;
    }
    if(input == 3) {
        out = Magick::MagickFunction::SinusoidFunction;
        return true;
    }
    if(input == 4) {
        out = Magick::MagickFunction::ArcsinFunction;
        return true;
    }
    if(input == 5) {
        out = Magick::MagickFunction::ArctanFunction;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MagickFunction").ToLocalChecked());
    return false;
}

static void SetStatisticTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedStatistic").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("GradientStatistic").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("MaximumStatistic").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("MeanStatistic").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("MedianStatistic").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("MinimumStatistic").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("ModeStatistic").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("NonpeakStatistic").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("StandardDeviationStatistic").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("RootMeanSquareStatistic").ToLocalChecked(), Nan::New(10));
    Nan::Set(exports, Nan::New("StatisticType").ToLocalChecked(), constants);
}

bool Constants::ConvertStatisticType(const v8::Local<v8::Value> val, MagickCore::StatisticType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to StatisticType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::StatisticType::UndefinedStatistic;
        return true;
    }
    if(input == 2) {
        out = MagickCore::StatisticType::GradientStatistic;
        return true;
    }
    if(input == 3) {
        out = MagickCore::StatisticType::MaximumStatistic;
        return true;
    }
    if(input == 4) {
        out = MagickCore::StatisticType::MeanStatistic;
        return true;
    }
    if(input == 5) {
        out = MagickCore::StatisticType::MedianStatistic;
        return true;
    }
    if(input == 6) {
        out = MagickCore::StatisticType::MinimumStatistic;
        return true;
    }
    if(input == 7) {
        out = MagickCore::StatisticType::ModeStatistic;
        return true;
    }
    if(input == 8) {
        out = MagickCore::StatisticType::NonpeakStatistic;
        return true;
    }
    if(input == 9) {
        out = MagickCore::StatisticType::StandardDeviationStatistic;
        return true;
    }
    if(input == 10) {
        out = MagickCore::StatisticType::RootMeanSquareStatistic;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to StatisticType").ToLocalChecked());
    return false;
}

static void SetResourceTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedResource").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("AreaResource").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("DiskResource").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("FileResource").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("MapResource").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("MemoryResource").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("ThreadResource").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("TimeResource").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("ThrottleResource").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("WidthResource").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("HeightResource").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("ListLengthResource").ToLocalChecked(), Nan::New(12));
    Nan::Set(exports, Nan::New("ResourceType").ToLocalChecked(), constants);
}

bool Constants::ConvertResourceType(const v8::Local<v8::Value> val, Magick::ResourceType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ResourceType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::ResourceType::UndefinedResource;
        return true;
    }
    if(input == 2) {
        out = Magick::ResourceType::AreaResource;
        return true;
    }
    if(input == 3) {
        out = Magick::ResourceType::DiskResource;
        return true;
    }
    if(input == 4) {
        out = Magick::ResourceType::FileResource;
        return true;
    }
    if(input == 5) {
        out = Magick::ResourceType::MapResource;
        return true;
    }
    if(input == 6) {
        out = Magick::ResourceType::MemoryResource;
        return true;
    }
    if(input == 7) {
        out = Magick::ResourceType::ThreadResource;
        return true;
    }
    if(input == 8) {
        out = Magick::ResourceType::TimeResource;
        return true;
    }
    if(input == 9) {
        out = Magick::ResourceType::ThrottleResource;
        return true;
    }
    if(input == 10) {
        out = Magick::ResourceType::WidthResource;
        return true;
    }
    if(input == 11) {
        out = Magick::ResourceType::HeightResource;
        return true;
    }
    if(input == 12) {
        out = Magick::ResourceType::ListLengthResource;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ResourceType").ToLocalChecked());
    return false;
}

static void SetFilterTypesBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedFilter").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("PointFilter").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("BoxFilter").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("TriangleFilter").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("HermiteFilter").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("HanningFilter").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("HammingFilter").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("BlackmanFilter").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("GaussianFilter").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("QuadraticFilter").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("CubicFilter").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("CatromFilter").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("MitchellFilter").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("JincFilter").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("SincFilter").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("SincFastFilter").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("KaiserFilter").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("WelshFilter").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("ParzenFilter").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("BohmanFilter").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("BartlettFilter").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("LagrangeFilter").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("LanczosFilter").ToLocalChecked(), Nan::New(23));
    Nan::Set(constants, Nan::New("LanczosSharpFilter").ToLocalChecked(), Nan::New(24));
    Nan::Set(constants, Nan::New("Lanczos2Filter").ToLocalChecked(), Nan::New(25));
    Nan::Set(constants, Nan::New("Lanczos2SharpFilter").ToLocalChecked(), Nan::New(26));
    Nan::Set(constants, Nan::New("RobidouxFilter").ToLocalChecked(), Nan::New(27));
    Nan::Set(constants, Nan::New("RobidouxSharpFilter").ToLocalChecked(), Nan::New(28));
    Nan::Set(constants, Nan::New("CosineFilter").ToLocalChecked(), Nan::New(29));
    Nan::Set(constants, Nan::New("SplineFilter").ToLocalChecked(), Nan::New(30));
    Nan::Set(constants, Nan::New("LanczosRadiusFilter").ToLocalChecked(), Nan::New(31));
    Nan::Set(constants, Nan::New("SentinelFilter").ToLocalChecked(), Nan::New(32));
    Nan::Set(exports, Nan::New("FilterTypes").ToLocalChecked(), constants);
}

bool Constants::ConvertFilterTypes(const v8::Local<v8::Value> val, Magick::FilterTypes& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to FilterTypes: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::FilterTypes::UndefinedFilter;
        return true;
    }
    if(input == 2) {
        out = Magick::FilterTypes::PointFilter;
        return true;
    }
    if(input == 3) {
        out = Magick::FilterTypes::BoxFilter;
        return true;
    }
    if(input == 4) {
        out = Magick::FilterTypes::TriangleFilter;
        return true;
    }
    if(input == 5) {
        out = Magick::FilterTypes::HermiteFilter;
        return true;
    }
    if(input == 6) {
        out = Magick::FilterTypes::HanningFilter;
        return true;
    }
    if(input == 7) {
        out = Magick::FilterTypes::HammingFilter;
        return true;
    }
    if(input == 8) {
        out = Magick::FilterTypes::BlackmanFilter;
        return true;
    }
    if(input == 9) {
        out = Magick::FilterTypes::GaussianFilter;
        return true;
    }
    if(input == 10) {
        out = Magick::FilterTypes::QuadraticFilter;
        return true;
    }
    if(input == 11) {
        out = Magick::FilterTypes::CubicFilter;
        return true;
    }
    if(input == 12) {
        out = Magick::FilterTypes::CatromFilter;
        return true;
    }
    if(input == 13) {
        out = Magick::FilterTypes::MitchellFilter;
        return true;
    }
    if(input == 14) {
        out = Magick::FilterTypes::JincFilter;
        return true;
    }
    if(input == 15) {
        out = Magick::FilterTypes::SincFilter;
        return true;
    }
    if(input == 16) {
        out = Magick::FilterTypes::SincFastFilter;
        return true;
    }
    if(input == 17) {
        out = Magick::FilterTypes::KaiserFilter;
        return true;
    }
    if(input == 18) {
        out = Magick::FilterTypes::WelshFilter;
        return true;
    }
    if(input == 19) {
        out = Magick::FilterTypes::ParzenFilter;
        return true;
    }
    if(input == 20) {
        out = Magick::FilterTypes::BohmanFilter;
        return true;
    }
    if(input == 21) {
        out = Magick::FilterTypes::BartlettFilter;
        return true;
    }
    if(input == 22) {
        out = Magick::FilterTypes::LagrangeFilter;
        return true;
    }
    if(input == 23) {
        out = Magick::FilterTypes::LanczosFilter;
        return true;
    }
    if(input == 24) {
        out = Magick::FilterTypes::LanczosSharpFilter;
        return true;
    }
    if(input == 25) {
        out = Magick::FilterTypes::Lanczos2Filter;
        return true;
    }
    if(input == 26) {
        out = Magick::FilterTypes::Lanczos2SharpFilter;
        return true;
    }
    if(input == 27) {
        out = Magick::FilterTypes::RobidouxFilter;
        return true;
    }
    if(input == 28) {
        out = Magick::FilterTypes::RobidouxSharpFilter;
        return true;
    }
    if(input == 29) {
        out = Magick::FilterTypes::CosineFilter;
        return true;
    }
    if(input == 30) {
        out = Magick::FilterTypes::SplineFilter;
        return true;
    }
    if(input == 31) {
        out = Magick::FilterTypes::LanczosRadiusFilter;
        return true;
    }
    if(input == 32) {
        out = Magick::FilterTypes::SentinelFilter;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to FilterTypes").ToLocalChecked());
    return false;
}

static void SetRegistryTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedRegistryType").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("ImageRegistryType").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ImageInfoRegistryType").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("StringRegistryType").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("RegistryType").ToLocalChecked(), constants);
}

bool Constants::ConvertRegistryType(const v8::Local<v8::Value> val, MagickCore::RegistryType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to RegistryType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::RegistryType::UndefinedRegistryType;
        return true;
    }
    if(input == 2) {
        out = MagickCore::RegistryType::ImageRegistryType;
        return true;
    }
    if(input == 3) {
        out = MagickCore::RegistryType::ImageInfoRegistryType;
        return true;
    }
    if(input == 4) {
        out = MagickCore::RegistryType::StringRegistryType;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to RegistryType").ToLocalChecked());
    return false;
}

static void SetEndianTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedEndian").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("LSBEndian").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("MSBEndian").ToLocalChecked(), Nan::New(3));
    Nan::Set(exports, Nan::New("EndianType").ToLocalChecked(), constants);
}

bool Constants::ConvertEndianType(const v8::Local<v8::Value> val, Magick::EndianType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to EndianType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::EndianType::UndefinedEndian;
        return true;
    }
    if(input == 2) {
        out = Magick::EndianType::LSBEndian;
        return true;
    }
    if(input == 3) {
        out = Magick::EndianType::MSBEndian;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to EndianType").ToLocalChecked());
    return false;
}

static void SetQuantumAlphaTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedQuantumAlpha").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("AssociatedQuantumAlpha").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("DisassociatedQuantumAlpha").ToLocalChecked(), Nan::New(3));
    Nan::Set(exports, Nan::New("QuantumAlphaType").ToLocalChecked(), constants);
}

bool Constants::ConvertQuantumAlphaType(const v8::Local<v8::Value> val, MagickCore::QuantumAlphaType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to QuantumAlphaType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::QuantumAlphaType::UndefinedQuantumAlpha;
        return true;
    }
    if(input == 2) {
        out = MagickCore::QuantumAlphaType::AssociatedQuantumAlpha;
        return true;
    }
    if(input == 3) {
        out = MagickCore::QuantumAlphaType::DisassociatedQuantumAlpha;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to QuantumAlphaType").ToLocalChecked());
    return false;
}

static void SetQuantumFormatTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedQuantumFormat").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("FloatingPointQuantumFormat").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("SignedQuantumFormat").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("UnsignedQuantumFormat").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("QuantumFormatType").ToLocalChecked(), constants);
}

bool Constants::ConvertQuantumFormatType(const v8::Local<v8::Value> val, MagickCore::QuantumFormatType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to QuantumFormatType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::QuantumFormatType::UndefinedQuantumFormat;
        return true;
    }
    if(input == 2) {
        out = MagickCore::QuantumFormatType::FloatingPointQuantumFormat;
        return true;
    }
    if(input == 3) {
        out = MagickCore::QuantumFormatType::SignedQuantumFormat;
        return true;
    }
    if(input == 4) {
        out = MagickCore::QuantumFormatType::UnsignedQuantumFormat;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to QuantumFormatType").ToLocalChecked());
    return false;
}

static void SetQuantumTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedQuantum").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("AlphaQuantum").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("BlackQuantum").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("BlueQuantum").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("CMYKAQuantum").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("CMYKQuantum").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("CyanQuantum").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("GrayAlphaQuantum").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("GrayQuantum").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("GreenQuantum").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("IndexAlphaQuantum").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("IndexQuantum").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("MagentaQuantum").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("OpacityQuantum").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("RedQuantum").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("RGBAQuantum").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("BGRAQuantum").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("RGBOQuantum").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("RGBQuantum").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("YellowQuantum").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("GrayPadQuantum").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("RGBPadQuantum").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("CbYCrYQuantum").ToLocalChecked(), Nan::New(23));
    Nan::Set(constants, Nan::New("CbYCrQuantum").ToLocalChecked(), Nan::New(24));
    Nan::Set(constants, Nan::New("CbYCrAQuantum").ToLocalChecked(), Nan::New(25));
    Nan::Set(constants, Nan::New("CMYKOQuantum").ToLocalChecked(), Nan::New(26));
    Nan::Set(constants, Nan::New("BGRQuantum").ToLocalChecked(), Nan::New(27));
    Nan::Set(constants, Nan::New("BGROQuantum").ToLocalChecked(), Nan::New(28));
    Nan::Set(exports, Nan::New("QuantumType").ToLocalChecked(), constants);
}

bool Constants::ConvertQuantumType(const v8::Local<v8::Value> val, Magick::QuantumType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to QuantumType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::QuantumType::UndefinedQuantum;
        return true;
    }
    if(input == 2) {
        out = Magick::QuantumType::AlphaQuantum;
        return true;
    }
    if(input == 3) {
        out = Magick::QuantumType::BlackQuantum;
        return true;
    }
    if(input == 4) {
        out = Magick::QuantumType::BlueQuantum;
        return true;
    }
    if(input == 5) {
        out = Magick::QuantumType::CMYKAQuantum;
        return true;
    }
    if(input == 6) {
        out = Magick::QuantumType::CMYKQuantum;
        return true;
    }
    if(input == 7) {
        out = Magick::QuantumType::CyanQuantum;
        return true;
    }
    if(input == 8) {
        out = Magick::QuantumType::GrayAlphaQuantum;
        return true;
    }
    if(input == 9) {
        out = Magick::QuantumType::GrayQuantum;
        return true;
    }
    if(input == 10) {
        out = Magick::QuantumType::GreenQuantum;
        return true;
    }
    if(input == 11) {
        out = Magick::QuantumType::IndexAlphaQuantum;
        return true;
    }
    if(input == 12) {
        out = Magick::QuantumType::IndexQuantum;
        return true;
    }
    if(input == 13) {
        out = Magick::QuantumType::MagentaQuantum;
        return true;
    }
    if(input == 14) {
        out = Magick::QuantumType::OpacityQuantum;
        return true;
    }
    if(input == 15) {
        out = Magick::QuantumType::RedQuantum;
        return true;
    }
    if(input == 16) {
        out = Magick::QuantumType::RGBAQuantum;
        return true;
    }
    if(input == 17) {
        out = Magick::QuantumType::BGRAQuantum;
        return true;
    }
    if(input == 18) {
        out = Magick::QuantumType::RGBOQuantum;
        return true;
    }
    if(input == 19) {
        out = Magick::QuantumType::RGBQuantum;
        return true;
    }
    if(input == 20) {
        out = Magick::QuantumType::YellowQuantum;
        return true;
    }
    if(input == 21) {
        out = Magick::QuantumType::GrayPadQuantum;
        return true;
    }
    if(input == 22) {
        out = Magick::QuantumType::RGBPadQuantum;
        return true;
    }
    if(input == 23) {
        out = Magick::QuantumType::CbYCrYQuantum;
        return true;
    }
    if(input == 24) {
        out = Magick::QuantumType::CbYCrQuantum;
        return true;
    }
    if(input == 25) {
        out = Magick::QuantumType::CbYCrAQuantum;
        return true;
    }
    if(input == 26) {
        out = Magick::QuantumType::CMYKOQuantum;
        return true;
    }
    if(input == 27) {
        out = Magick::QuantumType::BGRQuantum;
        return true;
    }
    if(input == 28) {
        out = Magick::QuantumType::BGROQuantum;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to QuantumType").ToLocalChecked());
    return false;
}

static void SetDitherMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedDitherMethod").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("NoDitherMethod").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("RiemersmaDitherMethod").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("FloydSteinbergDitherMethod").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("DitherMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertDitherMethod(const v8::Local<v8::Value> val, Magick::DitherMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to DitherMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::DitherMethod::UndefinedDitherMethod;
        return true;
    }
    if(input == 2) {
        out = Magick::DitherMethod::NoDitherMethod;
        return true;
    }
    if(input == 3) {
        out = Magick::DitherMethod::RiemersmaDitherMethod;
        return true;
    }
    if(input == 4) {
        out = Magick::DitherMethod::FloydSteinbergDitherMethod;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to DitherMethod").ToLocalChecked());
    return false;
}

static void SetRenderingIntentBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedIntent").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("SaturationIntent").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("PerceptualIntent").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("AbsoluteIntent").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("RelativeIntent").ToLocalChecked(), Nan::New(5));
    Nan::Set(exports, Nan::New("RenderingIntent").ToLocalChecked(), constants);
}

bool Constants::ConvertRenderingIntent(const v8::Local<v8::Value> val, Magick::RenderingIntent& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to RenderingIntent: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::RenderingIntent::UndefinedIntent;
        return true;
    }
    if(input == 2) {
        out = Magick::RenderingIntent::SaturationIntent;
        return true;
    }
    if(input == 3) {
        out = Magick::RenderingIntent::PerceptualIntent;
        return true;
    }
    if(input == 4) {
        out = Magick::RenderingIntent::AbsoluteIntent;
        return true;
    }
    if(input == 5) {
        out = Magick::RenderingIntent::RelativeIntent;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to RenderingIntent").ToLocalChecked());
    return false;
}

static void SetPolicyDomainBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedPolicyDomain").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("CoderPolicyDomain").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("DelegatePolicyDomain").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("FilterPolicyDomain").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("PathPolicyDomain").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("ResourcePolicyDomain").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("SystemPolicyDomain").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("CachePolicyDomain").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("ModulePolicyDomain").ToLocalChecked(), Nan::New(9));
    Nan::Set(exports, Nan::New("PolicyDomain").ToLocalChecked(), constants);
}

bool Constants::ConvertPolicyDomain(const v8::Local<v8::Value> val, MagickCore::PolicyDomain& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to PolicyDomain: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::PolicyDomain::UndefinedPolicyDomain;
        return true;
    }
    if(input == 2) {
        out = MagickCore::PolicyDomain::CoderPolicyDomain;
        return true;
    }
    if(input == 3) {
        out = MagickCore::PolicyDomain::DelegatePolicyDomain;
        return true;
    }
    if(input == 4) {
        out = MagickCore::PolicyDomain::FilterPolicyDomain;
        return true;
    }
    if(input == 5) {
        out = MagickCore::PolicyDomain::PathPolicyDomain;
        return true;
    }
    if(input == 6) {
        out = MagickCore::PolicyDomain::ResourcePolicyDomain;
        return true;
    }
    if(input == 7) {
        out = MagickCore::PolicyDomain::SystemPolicyDomain;
        return true;
    }
    if(input == 8) {
        out = MagickCore::PolicyDomain::CachePolicyDomain;
        return true;
    }
    if(input == 9) {
        out = MagickCore::PolicyDomain::ModulePolicyDomain;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to PolicyDomain").ToLocalChecked());
    return false;
}

static void SetPolicyRightsBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedPolicyRights").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("NoPolicyRights").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ReadPolicyRights").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("WritePolicyRights").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("ExecutePolicyRights").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("AllPolicyRights").ToLocalChecked(), Nan::New(6));
    Nan::Set(exports, Nan::New("PolicyRights").ToLocalChecked(), constants);
}

bool Constants::ConvertPolicyRights(const v8::Local<v8::Value> val, MagickCore::PolicyRights& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to PolicyRights: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::PolicyRights::UndefinedPolicyRights;
        return true;
    }
    if(input == 2) {
        out = MagickCore::PolicyRights::NoPolicyRights;
        return true;
    }
    if(input == 3) {
        out = MagickCore::PolicyRights::ReadPolicyRights;
        return true;
    }
    if(input == 4) {
        out = MagickCore::PolicyRights::WritePolicyRights;
        return true;
    }
    if(input == 5) {
        out = MagickCore::PolicyRights::ExecutePolicyRights;
        return true;
    }
    if(input == 6) {
        out = MagickCore::PolicyRights::AllPolicyRights;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to PolicyRights").ToLocalChecked());
    return false;
}

static void SetInterpolatePixelMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedInterpolatePixel").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("AverageInterpolatePixel").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("BicubicInterpolatePixel").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("BilinearInterpolatePixel").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("FilterInterpolatePixel").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("IntegerInterpolatePixel").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("MeshInterpolatePixel").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("NearestNeighborInterpolatePixel").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("SplineInterpolatePixel").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("Average9InterpolatePixel").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("Average16InterpolatePixel").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("BlendInterpolatePixel").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("BackgroundInterpolatePixel").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("CatromInterpolatePixel").ToLocalChecked(), Nan::New(14));
    Nan::Set(exports, Nan::New("InterpolatePixelMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertInterpolatePixelMethod(const v8::Local<v8::Value> val, Magick::InterpolatePixelMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to InterpolatePixelMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::InterpolatePixelMethod::UndefinedInterpolatePixel;
        return true;
    }
    if(input == 2) {
        out = Magick::InterpolatePixelMethod::AverageInterpolatePixel;
        return true;
    }
    if(input == 3) {
        out = Magick::InterpolatePixelMethod::BicubicInterpolatePixel;
        return true;
    }
    if(input == 4) {
        out = Magick::InterpolatePixelMethod::BilinearInterpolatePixel;
        return true;
    }
    if(input == 5) {
        out = Magick::InterpolatePixelMethod::FilterInterpolatePixel;
        return true;
    }
    if(input == 6) {
        out = Magick::InterpolatePixelMethod::IntegerInterpolatePixel;
        return true;
    }
    if(input == 7) {
        out = Magick::InterpolatePixelMethod::MeshInterpolatePixel;
        return true;
    }
    if(input == 8) {
        out = Magick::InterpolatePixelMethod::NearestNeighborInterpolatePixel;
        return true;
    }
    if(input == 9) {
        out = Magick::InterpolatePixelMethod::SplineInterpolatePixel;
        return true;
    }
    if(input == 10) {
        out = Magick::InterpolatePixelMethod::Average9InterpolatePixel;
        return true;
    }
    if(input == 11) {
        out = Magick::InterpolatePixelMethod::Average16InterpolatePixel;
        return true;
    }
    if(input == 12) {
        out = Magick::InterpolatePixelMethod::BlendInterpolatePixel;
        return true;
    }
    if(input == 13) {
        out = Magick::InterpolatePixelMethod::BackgroundInterpolatePixel;
        return true;
    }
    if(input == 14) {
        out = Magick::InterpolatePixelMethod::CatromInterpolatePixel;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to InterpolatePixelMethod").ToLocalChecked());
    return false;
}

static void SetPixelComponentBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("PixelRed").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("PixelCyan").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("PixelGray").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("PixelY").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("PixelGreen").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("PixelMagenta").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("PixelCb").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("PixelBlue").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("PixelYellow").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("PixelCr").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("PixelAlpha").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("PixelBlack").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("PixelIndex").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("MaskPixelComponent").ToLocalChecked(), Nan::New(14));
    Nan::Set(exports, Nan::New("PixelComponent").ToLocalChecked(), constants);
}

bool Constants::ConvertPixelComponent(const v8::Local<v8::Value> val, MagickCore::PixelComponent& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to PixelComponent: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::PixelComponent::PixelRed;
        return true;
    }
    if(input == 2) {
        out = MagickCore::PixelComponent::PixelCyan;
        return true;
    }
    if(input == 3) {
        out = MagickCore::PixelComponent::PixelGray;
        return true;
    }
    if(input == 4) {
        out = MagickCore::PixelComponent::PixelY;
        return true;
    }
    if(input == 5) {
        out = MagickCore::PixelComponent::PixelGreen;
        return true;
    }
    if(input == 6) {
        out = MagickCore::PixelComponent::PixelMagenta;
        return true;
    }
    if(input == 7) {
        out = MagickCore::PixelComponent::PixelCb;
        return true;
    }
    if(input == 8) {
        out = MagickCore::PixelComponent::PixelBlue;
        return true;
    }
    if(input == 9) {
        out = MagickCore::PixelComponent::PixelYellow;
        return true;
    }
    if(input == 10) {
        out = MagickCore::PixelComponent::PixelCr;
        return true;
    }
    if(input == 11) {
        out = MagickCore::PixelComponent::PixelAlpha;
        return true;
    }
    if(input == 12) {
        out = MagickCore::PixelComponent::PixelBlack;
        return true;
    }
    if(input == 13) {
        out = MagickCore::PixelComponent::PixelIndex;
        return true;
    }
    if(input == 14) {
        out = MagickCore::PixelComponent::MaskPixelComponent;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to PixelComponent").ToLocalChecked());
    return false;
}

static void SetPixelIntensityMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedPixelIntensityMethod").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("AveragePixelIntensityMethod").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("BrightnessPixelIntensityMethod").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("LightnessPixelIntensityMethod").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("Rec601LumaPixelIntensityMethod").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("Rec601LuminancePixelIntensityMethod").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("Rec709LumaPixelIntensityMethod").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("Rec709LuminancePixelIntensityMethod").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("RMSPixelIntensityMethod").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("MSPixelIntensityMethod").ToLocalChecked(), Nan::New(10));
    Nan::Set(exports, Nan::New("PixelIntensityMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertPixelIntensityMethod(const v8::Local<v8::Value> val, Magick::PixelIntensityMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to PixelIntensityMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::PixelIntensityMethod::UndefinedPixelIntensityMethod;
        return true;
    }
    if(input == 2) {
        out = Magick::PixelIntensityMethod::AveragePixelIntensityMethod;
        return true;
    }
    if(input == 3) {
        out = Magick::PixelIntensityMethod::BrightnessPixelIntensityMethod;
        return true;
    }
    if(input == 4) {
        out = Magick::PixelIntensityMethod::LightnessPixelIntensityMethod;
        return true;
    }
    if(input == 5) {
        out = Magick::PixelIntensityMethod::Rec601LumaPixelIntensityMethod;
        return true;
    }
    if(input == 6) {
        out = Magick::PixelIntensityMethod::Rec601LuminancePixelIntensityMethod;
        return true;
    }
    if(input == 7) {
        out = Magick::PixelIntensityMethod::Rec709LumaPixelIntensityMethod;
        return true;
    }
    if(input == 8) {
        out = Magick::PixelIntensityMethod::Rec709LuminancePixelIntensityMethod;
        return true;
    }
    if(input == 9) {
        out = Magick::PixelIntensityMethod::RMSPixelIntensityMethod;
        return true;
    }
    if(input == 10) {
        out = Magick::PixelIntensityMethod::MSPixelIntensityMethod;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to PixelIntensityMethod").ToLocalChecked());
    return false;
}

static void SetCommandOptionBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("MagickUndefinedOptions").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("MagickAlignOptions").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("MagickAlphaOptions").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("MagickBooleanOptions").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("MagickCacheOptions").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("MagickChannelOptions").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("MagickClassOptions").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("MagickClipPathOptions").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("MagickCoderOptions").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("MagickColorOptions").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("MagickColorspaceOptions").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("MagickCommandOptions").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("MagickComposeOptions").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("MagickCompressOptions").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("MagickConfigureOptions").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("MagickDataTypeOptions").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("MagickDebugOptions").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("MagickDecorateOptions").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("MagickDelegateOptions").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("MagickDirectionOptions").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("MagickDisposeOptions").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("MagickDistortOptions").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("MagickDitherOptions").ToLocalChecked(), Nan::New(23));
    Nan::Set(constants, Nan::New("MagickEndianOptions").ToLocalChecked(), Nan::New(24));
    Nan::Set(constants, Nan::New("MagickEvaluateOptions").ToLocalChecked(), Nan::New(25));
    Nan::Set(constants, Nan::New("MagickFillRuleOptions").ToLocalChecked(), Nan::New(26));
    Nan::Set(constants, Nan::New("MagickFilterOptions").ToLocalChecked(), Nan::New(27));
    Nan::Set(constants, Nan::New("MagickFontOptions").ToLocalChecked(), Nan::New(28));
    Nan::Set(constants, Nan::New("MagickFontsOptions").ToLocalChecked(), Nan::New(29));
    Nan::Set(constants, Nan::New("MagickFormatOptions").ToLocalChecked(), Nan::New(30));
    Nan::Set(constants, Nan::New("MagickFunctionOptions").ToLocalChecked(), Nan::New(31));
    Nan::Set(constants, Nan::New("MagickGravityOptions").ToLocalChecked(), Nan::New(32));
    Nan::Set(constants, Nan::New("MagickIntentOptions").ToLocalChecked(), Nan::New(33));
    Nan::Set(constants, Nan::New("MagickInterlaceOptions").ToLocalChecked(), Nan::New(34));
    Nan::Set(constants, Nan::New("MagickInterpolateOptions").ToLocalChecked(), Nan::New(35));
    Nan::Set(constants, Nan::New("MagickKernelOptions").ToLocalChecked(), Nan::New(36));
    Nan::Set(constants, Nan::New("MagickLayerOptions").ToLocalChecked(), Nan::New(37));
    Nan::Set(constants, Nan::New("MagickLineCapOptions").ToLocalChecked(), Nan::New(38));
    Nan::Set(constants, Nan::New("MagickLineJoinOptions").ToLocalChecked(), Nan::New(39));
    Nan::Set(constants, Nan::New("MagickListOptions").ToLocalChecked(), Nan::New(40));
    Nan::Set(constants, Nan::New("MagickLocaleOptions").ToLocalChecked(), Nan::New(41));
    Nan::Set(constants, Nan::New("MagickLogEventOptions").ToLocalChecked(), Nan::New(42));
    Nan::Set(constants, Nan::New("MagickLogOptions").ToLocalChecked(), Nan::New(43));
    Nan::Set(constants, Nan::New("MagickMagicOptions").ToLocalChecked(), Nan::New(44));
    Nan::Set(constants, Nan::New("MagickMethodOptions").ToLocalChecked(), Nan::New(45));
    Nan::Set(constants, Nan::New("MagickMetricOptions").ToLocalChecked(), Nan::New(46));
    Nan::Set(constants, Nan::New("MagickMimeOptions").ToLocalChecked(), Nan::New(47));
    Nan::Set(constants, Nan::New("MagickModeOptions").ToLocalChecked(), Nan::New(48));
    Nan::Set(constants, Nan::New("MagickModuleOptions").ToLocalChecked(), Nan::New(49));
    Nan::Set(constants, Nan::New("MagickMorphologyOptions").ToLocalChecked(), Nan::New(50));
    Nan::Set(constants, Nan::New("MagickNoiseOptions").ToLocalChecked(), Nan::New(51));
    Nan::Set(constants, Nan::New("MagickOrientationOptions").ToLocalChecked(), Nan::New(52));
    Nan::Set(constants, Nan::New("MagickPixelIntensityOptions").ToLocalChecked(), Nan::New(53));
    Nan::Set(constants, Nan::New("MagickPolicyOptions").ToLocalChecked(), Nan::New(54));
    Nan::Set(constants, Nan::New("MagickPolicyDomainOptions").ToLocalChecked(), Nan::New(55));
    Nan::Set(constants, Nan::New("MagickPolicyRightsOptions").ToLocalChecked(), Nan::New(56));
    Nan::Set(constants, Nan::New("MagickPreviewOptions").ToLocalChecked(), Nan::New(57));
    Nan::Set(constants, Nan::New("MagickPrimitiveOptions").ToLocalChecked(), Nan::New(58));
    Nan::Set(constants, Nan::New("MagickQuantumFormatOptions").ToLocalChecked(), Nan::New(59));
    Nan::Set(constants, Nan::New("MagickResolutionOptions").ToLocalChecked(), Nan::New(60));
    Nan::Set(constants, Nan::New("MagickResourceOptions").ToLocalChecked(), Nan::New(61));
    Nan::Set(constants, Nan::New("MagickSparseColorOptions").ToLocalChecked(), Nan::New(62));
    Nan::Set(constants, Nan::New("MagickStatisticOptions").ToLocalChecked(), Nan::New(63));
    Nan::Set(constants, Nan::New("MagickStorageOptions").ToLocalChecked(), Nan::New(64));
    Nan::Set(constants, Nan::New("MagickStretchOptions").ToLocalChecked(), Nan::New(65));
    Nan::Set(constants, Nan::New("MagickStyleOptions").ToLocalChecked(), Nan::New(66));
    Nan::Set(constants, Nan::New("MagickThresholdOptions").ToLocalChecked(), Nan::New(67));
    Nan::Set(constants, Nan::New("MagickTypeOptions").ToLocalChecked(), Nan::New(68));
    Nan::Set(constants, Nan::New("MagickValidateOptions").ToLocalChecked(), Nan::New(69));
    Nan::Set(constants, Nan::New("MagickVirtualPixelOptions").ToLocalChecked(), Nan::New(70));
    Nan::Set(constants, Nan::New("MagickComplexOptions").ToLocalChecked(), Nan::New(71));
    Nan::Set(constants, Nan::New("MagickIntensityOptions").ToLocalChecked(), Nan::New(72));
    Nan::Set(constants, Nan::New("MagickGradientOptions").ToLocalChecked(), Nan::New(73));
    Nan::Set(constants, Nan::New("MagickWeightOptions").ToLocalChecked(), Nan::New(74));
    Nan::Set(constants, Nan::New("MagickComplianceOptions").ToLocalChecked(), Nan::New(75));
    Nan::Set(constants, Nan::New("MagickAutoThresholdOptions").ToLocalChecked(), Nan::New(76));
    Nan::Set(constants, Nan::New("MagickPagesizeOptions").ToLocalChecked(), Nan::New(77));
    Nan::Set(exports, Nan::New("CommandOption").ToLocalChecked(), constants);
}

bool Constants::ConvertCommandOption(const v8::Local<v8::Value> val, Magick::CommandOption& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to CommandOption: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::CommandOption::MagickUndefinedOptions;
        return true;
    }
    if(input == 2) {
        out = Magick::CommandOption::MagickAlignOptions;
        return true;
    }
    if(input == 3) {
        out = Magick::CommandOption::MagickAlphaOptions;
        return true;
    }
    if(input == 4) {
        out = Magick::CommandOption::MagickBooleanOptions;
        return true;
    }
    if(input == 5) {
        out = Magick::CommandOption::MagickCacheOptions;
        return true;
    }
    if(input == 6) {
        out = Magick::CommandOption::MagickChannelOptions;
        return true;
    }
    if(input == 7) {
        out = Magick::CommandOption::MagickClassOptions;
        return true;
    }
    if(input == 8) {
        out = Magick::CommandOption::MagickClipPathOptions;
        return true;
    }
    if(input == 9) {
        out = Magick::CommandOption::MagickCoderOptions;
        return true;
    }
    if(input == 10) {
        out = Magick::CommandOption::MagickColorOptions;
        return true;
    }
    if(input == 11) {
        out = Magick::CommandOption::MagickColorspaceOptions;
        return true;
    }
    if(input == 12) {
        out = Magick::CommandOption::MagickCommandOptions;
        return true;
    }
    if(input == 13) {
        out = Magick::CommandOption::MagickComposeOptions;
        return true;
    }
    if(input == 14) {
        out = Magick::CommandOption::MagickCompressOptions;
        return true;
    }
    if(input == 15) {
        out = Magick::CommandOption::MagickConfigureOptions;
        return true;
    }
    if(input == 16) {
        out = Magick::CommandOption::MagickDataTypeOptions;
        return true;
    }
    if(input == 17) {
        out = Magick::CommandOption::MagickDebugOptions;
        return true;
    }
    if(input == 18) {
        out = Magick::CommandOption::MagickDecorateOptions;
        return true;
    }
    if(input == 19) {
        out = Magick::CommandOption::MagickDelegateOptions;
        return true;
    }
    if(input == 20) {
        out = Magick::CommandOption::MagickDirectionOptions;
        return true;
    }
    if(input == 21) {
        out = Magick::CommandOption::MagickDisposeOptions;
        return true;
    }
    if(input == 22) {
        out = Magick::CommandOption::MagickDistortOptions;
        return true;
    }
    if(input == 23) {
        out = Magick::CommandOption::MagickDitherOptions;
        return true;
    }
    if(input == 24) {
        out = Magick::CommandOption::MagickEndianOptions;
        return true;
    }
    if(input == 25) {
        out = Magick::CommandOption::MagickEvaluateOptions;
        return true;
    }
    if(input == 26) {
        out = Magick::CommandOption::MagickFillRuleOptions;
        return true;
    }
    if(input == 27) {
        out = Magick::CommandOption::MagickFilterOptions;
        return true;
    }
    if(input == 28) {
        out = Magick::CommandOption::MagickFontOptions;
        return true;
    }
    if(input == 29) {
        out = Magick::CommandOption::MagickFontsOptions;
        return true;
    }
    if(input == 30) {
        out = Magick::CommandOption::MagickFormatOptions;
        return true;
    }
    if(input == 31) {
        out = Magick::CommandOption::MagickFunctionOptions;
        return true;
    }
    if(input == 32) {
        out = Magick::CommandOption::MagickGravityOptions;
        return true;
    }
    if(input == 33) {
        out = Magick::CommandOption::MagickIntentOptions;
        return true;
    }
    if(input == 34) {
        out = Magick::CommandOption::MagickInterlaceOptions;
        return true;
    }
    if(input == 35) {
        out = Magick::CommandOption::MagickInterpolateOptions;
        return true;
    }
    if(input == 36) {
        out = Magick::CommandOption::MagickKernelOptions;
        return true;
    }
    if(input == 37) {
        out = Magick::CommandOption::MagickLayerOptions;
        return true;
    }
    if(input == 38) {
        out = Magick::CommandOption::MagickLineCapOptions;
        return true;
    }
    if(input == 39) {
        out = Magick::CommandOption::MagickLineJoinOptions;
        return true;
    }
    if(input == 40) {
        out = Magick::CommandOption::MagickListOptions;
        return true;
    }
    if(input == 41) {
        out = Magick::CommandOption::MagickLocaleOptions;
        return true;
    }
    if(input == 42) {
        out = Magick::CommandOption::MagickLogEventOptions;
        return true;
    }
    if(input == 43) {
        out = Magick::CommandOption::MagickLogOptions;
        return true;
    }
    if(input == 44) {
        out = Magick::CommandOption::MagickMagicOptions;
        return true;
    }
    if(input == 45) {
        out = Magick::CommandOption::MagickMethodOptions;
        return true;
    }
    if(input == 46) {
        out = Magick::CommandOption::MagickMetricOptions;
        return true;
    }
    if(input == 47) {
        out = Magick::CommandOption::MagickMimeOptions;
        return true;
    }
    if(input == 48) {
        out = Magick::CommandOption::MagickModeOptions;
        return true;
    }
    if(input == 49) {
        out = Magick::CommandOption::MagickModuleOptions;
        return true;
    }
    if(input == 50) {
        out = Magick::CommandOption::MagickMorphologyOptions;
        return true;
    }
    if(input == 51) {
        out = Magick::CommandOption::MagickNoiseOptions;
        return true;
    }
    if(input == 52) {
        out = Magick::CommandOption::MagickOrientationOptions;
        return true;
    }
    if(input == 53) {
        out = Magick::CommandOption::MagickPixelIntensityOptions;
        return true;
    }
    if(input == 54) {
        out = Magick::CommandOption::MagickPolicyOptions;
        return true;
    }
    if(input == 55) {
        out = Magick::CommandOption::MagickPolicyDomainOptions;
        return true;
    }
    if(input == 56) {
        out = Magick::CommandOption::MagickPolicyRightsOptions;
        return true;
    }
    if(input == 57) {
        out = Magick::CommandOption::MagickPreviewOptions;
        return true;
    }
    if(input == 58) {
        out = Magick::CommandOption::MagickPrimitiveOptions;
        return true;
    }
    if(input == 59) {
        out = Magick::CommandOption::MagickQuantumFormatOptions;
        return true;
    }
    if(input == 60) {
        out = Magick::CommandOption::MagickResolutionOptions;
        return true;
    }
    if(input == 61) {
        out = Magick::CommandOption::MagickResourceOptions;
        return true;
    }
    if(input == 62) {
        out = Magick::CommandOption::MagickSparseColorOptions;
        return true;
    }
    if(input == 63) {
        out = Magick::CommandOption::MagickStatisticOptions;
        return true;
    }
    if(input == 64) {
        out = Magick::CommandOption::MagickStorageOptions;
        return true;
    }
    if(input == 65) {
        out = Magick::CommandOption::MagickStretchOptions;
        return true;
    }
    if(input == 66) {
        out = Magick::CommandOption::MagickStyleOptions;
        return true;
    }
    if(input == 67) {
        out = Magick::CommandOption::MagickThresholdOptions;
        return true;
    }
    if(input == 68) {
        out = Magick::CommandOption::MagickTypeOptions;
        return true;
    }
    if(input == 69) {
        out = Magick::CommandOption::MagickValidateOptions;
        return true;
    }
    if(input == 70) {
        out = Magick::CommandOption::MagickVirtualPixelOptions;
        return true;
    }
    if(input == 71) {
        out = Magick::CommandOption::MagickComplexOptions;
        return true;
    }
    if(input == 72) {
        out = Magick::CommandOption::MagickIntensityOptions;
        return true;
    }
    if(input == 73) {
        out = Magick::CommandOption::MagickGradientOptions;
        return true;
    }
    if(input == 74) {
        out = Magick::CommandOption::MagickWeightOptions;
        return true;
    }
    if(input == 75) {
        out = Magick::CommandOption::MagickComplianceOptions;
        return true;
    }
    if(input == 76) {
        out = Magick::CommandOption::MagickAutoThresholdOptions;
        return true;
    }
    if(input == 77) {
        out = Magick::CommandOption::MagickPagesizeOptions;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to CommandOption").ToLocalChecked());
    return false;
}

static void SetValidateTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedValidate").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("NoValidate").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ColorspaceValidate").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("CompareValidate").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("CompositeValidate").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("ConvertValidate").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("FormatsDiskValidate").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("FormatsMapValidate").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("FormatsMemoryValidate").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("IdentifyValidate").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("ImportExportValidate").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("MontageValidate").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("StreamValidate").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("AllValidate").ToLocalChecked(), Nan::New(14));
    Nan::Set(exports, Nan::New("ValidateType").ToLocalChecked(), constants);
}

bool Constants::ConvertValidateType(const v8::Local<v8::Value> val, MagickCore::ValidateType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ValidateType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::ValidateType::UndefinedValidate;
        return true;
    }
    if(input == 2) {
        out = MagickCore::ValidateType::NoValidate;
        return true;
    }
    if(input == 3) {
        out = MagickCore::ValidateType::ColorspaceValidate;
        return true;
    }
    if(input == 4) {
        out = MagickCore::ValidateType::CompareValidate;
        return true;
    }
    if(input == 5) {
        out = MagickCore::ValidateType::CompositeValidate;
        return true;
    }
    if(input == 6) {
        out = MagickCore::ValidateType::ConvertValidate;
        return true;
    }
    if(input == 7) {
        out = MagickCore::ValidateType::FormatsDiskValidate;
        return true;
    }
    if(input == 8) {
        out = MagickCore::ValidateType::FormatsMapValidate;
        return true;
    }
    if(input == 9) {
        out = MagickCore::ValidateType::FormatsMemoryValidate;
        return true;
    }
    if(input == 10) {
        out = MagickCore::ValidateType::IdentifyValidate;
        return true;
    }
    if(input == 11) {
        out = MagickCore::ValidateType::ImportExportValidate;
        return true;
    }
    if(input == 12) {
        out = MagickCore::ValidateType::MontageValidate;
        return true;
    }
    if(input == 13) {
        out = MagickCore::ValidateType::StreamValidate;
        return true;
    }
    if(input == 14) {
        out = MagickCore::ValidateType::AllValidate;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ValidateType").ToLocalChecked());
    return false;
}

static void SetCommandOptionFlagsBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedOptionFlag").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("FireOptionFlag").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ImageInfoOptionFlag").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("DrawInfoOptionFlag").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("QuantizeInfoOptionFlag").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("GlobalOptionFlag").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("SimpleOperatorOptionFlag").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("ListOperatorOptionFlag").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("SpecialOperatorOptionFlag").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("GenesisOptionFlag").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("NonConvertOptionFlag").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("DeprecateOptionFlag").ToLocalChecked(), Nan::New(12));
    Nan::Set(exports, Nan::New("CommandOptionFlags").ToLocalChecked(), constants);
}

bool Constants::ConvertCommandOptionFlags(const v8::Local<v8::Value> val, MagickCore::CommandOptionFlags& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to CommandOptionFlags: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::CommandOptionFlags::UndefinedOptionFlag;
        return true;
    }
    if(input == 2) {
        out = MagickCore::CommandOptionFlags::FireOptionFlag;
        return true;
    }
    if(input == 3) {
        out = MagickCore::CommandOptionFlags::ImageInfoOptionFlag;
        return true;
    }
    if(input == 4) {
        out = MagickCore::CommandOptionFlags::DrawInfoOptionFlag;
        return true;
    }
    if(input == 5) {
        out = MagickCore::CommandOptionFlags::QuantizeInfoOptionFlag;
        return true;
    }
    if(input == 6) {
        out = MagickCore::CommandOptionFlags::GlobalOptionFlag;
        return true;
    }
    if(input == 7) {
        out = MagickCore::CommandOptionFlags::SimpleOperatorOptionFlag;
        return true;
    }
    if(input == 8) {
        out = MagickCore::CommandOptionFlags::ListOperatorOptionFlag;
        return true;
    }
    if(input == 9) {
        out = MagickCore::CommandOptionFlags::SpecialOperatorOptionFlag;
        return true;
    }
    if(input == 10) {
        out = MagickCore::CommandOptionFlags::GenesisOptionFlag;
        return true;
    }
    if(input == 11) {
        out = MagickCore::CommandOptionFlags::NonConvertOptionFlag;
        return true;
    }
    if(input == 12) {
        out = MagickCore::CommandOptionFlags::DeprecateOptionFlag;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to CommandOptionFlags").ToLocalChecked());
    return false;
}

static void SetMagickOpenCLProgramBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_ACCELERATE").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_NUM_PROGRAMS").ToLocalChecked(), Nan::New(2));
    Nan::Set(exports, Nan::New("MagickOpenCLProgram").ToLocalChecked(), constants);
}

bool Constants::ConvertMagickOpenCLProgram(const v8::Local<v8::Value> val, MagickCore::MagickOpenCLProgram& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MagickOpenCLProgram: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::MagickOpenCLProgram::MAGICK_OPENCL_ACCELERATE;
        return true;
    }
    if(input == 2) {
        out = MagickCore::MagickOpenCLProgram::MAGICK_OPENCL_NUM_PROGRAMS;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MagickOpenCLProgram").ToLocalChecked());
    return false;
}

static void SetImageMagickOpenCLModeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_OFF").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_DEVICE_SELECT_AUTO").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_DEVICE_SELECT_USER").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_DEVICE_SELECT_AUTO_CLEAR_CACHE").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("ImageMagickOpenCLMode").ToLocalChecked(), constants);
}

bool Constants::ConvertImageMagickOpenCLMode(const v8::Local<v8::Value> val, MagickCore::ImageMagickOpenCLMode& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ImageMagickOpenCLMode: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::ImageMagickOpenCLMode::MAGICK_OPENCL_OFF;
        return true;
    }
    if(input == 2) {
        out = MagickCore::ImageMagickOpenCLMode::MAGICK_OPENCL_DEVICE_SELECT_AUTO;
        return true;
    }
    if(input == 3) {
        out = MagickCore::ImageMagickOpenCLMode::MAGICK_OPENCL_DEVICE_SELECT_USER;
        return true;
    }
    if(input == 4) {
        out = MagickCore::ImageMagickOpenCLMode::MAGICK_OPENCL_DEVICE_SELECT_AUTO_CLEAR_CACHE;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ImageMagickOpenCLMode").ToLocalChecked());
    return false;
}

static void SetMagickOpenCLEnvParamBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_ENV_PARAM_DEVICE").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_ENV_PARAM_OPENCL_DISABLED").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_ENV_PARAM_OPENCL_INITIALIZED").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_ENV_PARAM_PROGRAM_CACHE_DISABLED").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_ENV_PARAM_REGENERATE_PROFILE").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_ENV_PARAM_PLATFORM_VENDOR").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("MAGICK_OPENCL_ENV_PARAM_DEVICE_NAME").ToLocalChecked(), Nan::New(7));
    Nan::Set(exports, Nan::New("MagickOpenCLEnvParam").ToLocalChecked(), constants);
}

bool Constants::ConvertMagickOpenCLEnvParam(const v8::Local<v8::Value> val, MagickCore::MagickOpenCLEnvParam& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MagickOpenCLEnvParam: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::MagickOpenCLEnvParam::MAGICK_OPENCL_ENV_PARAM_DEVICE;
        return true;
    }
    if(input == 2) {
        out = MagickCore::MagickOpenCLEnvParam::MAGICK_OPENCL_ENV_PARAM_OPENCL_DISABLED;
        return true;
    }
    if(input == 3) {
        out = MagickCore::MagickOpenCLEnvParam::MAGICK_OPENCL_ENV_PARAM_OPENCL_INITIALIZED;
        return true;
    }
    if(input == 4) {
        out = MagickCore::MagickOpenCLEnvParam::MAGICK_OPENCL_ENV_PARAM_PROGRAM_CACHE_DISABLED;
        return true;
    }
    if(input == 5) {
        out = MagickCore::MagickOpenCLEnvParam::MAGICK_OPENCL_ENV_PARAM_REGENERATE_PROFILE;
        return true;
    }
    if(input == 6) {
        out = MagickCore::MagickOpenCLEnvParam::MAGICK_OPENCL_ENV_PARAM_PLATFORM_VENDOR;
        return true;
    }
    if(input == 7) {
        out = MagickCore::MagickOpenCLEnvParam::MAGICK_OPENCL_ENV_PARAM_DEVICE_NAME;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MagickOpenCLEnvParam").ToLocalChecked());
    return false;
}

static void SetKernelInfoTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedKernel").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("UnityKernel").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("GaussianKernel").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("DoGKernel").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("LoGKernel").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("BlurKernel").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("CometKernel").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("LaplacianKernel").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("SobelKernel").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("FreiChenKernel").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("RobertsKernel").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("PrewittKernel").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("CompassKernel").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("KirschKernel").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("DiamondKernel").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("SquareKernel").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("RectangleKernel").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("OctagonKernel").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("DiskKernel").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("PlusKernel").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("CrossKernel").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("RingKernel").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("PeaksKernel").ToLocalChecked(), Nan::New(23));
    Nan::Set(constants, Nan::New("EdgesKernel").ToLocalChecked(), Nan::New(24));
    Nan::Set(constants, Nan::New("CornersKernel").ToLocalChecked(), Nan::New(25));
    Nan::Set(constants, Nan::New("DiagonalsKernel").ToLocalChecked(), Nan::New(26));
    Nan::Set(constants, Nan::New("LineEndsKernel").ToLocalChecked(), Nan::New(27));
    Nan::Set(constants, Nan::New("LineJunctionsKernel").ToLocalChecked(), Nan::New(28));
    Nan::Set(constants, Nan::New("RidgesKernel").ToLocalChecked(), Nan::New(29));
    Nan::Set(constants, Nan::New("ConvexHullKernel").ToLocalChecked(), Nan::New(30));
    Nan::Set(constants, Nan::New("ThinSEKernel").ToLocalChecked(), Nan::New(31));
    Nan::Set(constants, Nan::New("SkeletonKernel").ToLocalChecked(), Nan::New(32));
    Nan::Set(constants, Nan::New("ChebyshevKernel").ToLocalChecked(), Nan::New(33));
    Nan::Set(constants, Nan::New("ManhattanKernel").ToLocalChecked(), Nan::New(34));
    Nan::Set(constants, Nan::New("OctagonalKernel").ToLocalChecked(), Nan::New(35));
    Nan::Set(constants, Nan::New("EuclideanKernel").ToLocalChecked(), Nan::New(36));
    Nan::Set(constants, Nan::New("UserDefinedKernel").ToLocalChecked(), Nan::New(37));
    Nan::Set(constants, Nan::New("BinomialKernel").ToLocalChecked(), Nan::New(38));
    Nan::Set(exports, Nan::New("KernelInfoType").ToLocalChecked(), constants);
}

bool Constants::ConvertKernelInfoType(const v8::Local<v8::Value> val, Magick::KernelInfoType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to KernelInfoType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::KernelInfoType::UndefinedKernel;
        return true;
    }
    if(input == 2) {
        out = Magick::KernelInfoType::UnityKernel;
        return true;
    }
    if(input == 3) {
        out = Magick::KernelInfoType::GaussianKernel;
        return true;
    }
    if(input == 4) {
        out = Magick::KernelInfoType::DoGKernel;
        return true;
    }
    if(input == 5) {
        out = Magick::KernelInfoType::LoGKernel;
        return true;
    }
    if(input == 6) {
        out = Magick::KernelInfoType::BlurKernel;
        return true;
    }
    if(input == 7) {
        out = Magick::KernelInfoType::CometKernel;
        return true;
    }
    if(input == 8) {
        out = Magick::KernelInfoType::LaplacianKernel;
        return true;
    }
    if(input == 9) {
        out = Magick::KernelInfoType::SobelKernel;
        return true;
    }
    if(input == 10) {
        out = Magick::KernelInfoType::FreiChenKernel;
        return true;
    }
    if(input == 11) {
        out = Magick::KernelInfoType::RobertsKernel;
        return true;
    }
    if(input == 12) {
        out = Magick::KernelInfoType::PrewittKernel;
        return true;
    }
    if(input == 13) {
        out = Magick::KernelInfoType::CompassKernel;
        return true;
    }
    if(input == 14) {
        out = Magick::KernelInfoType::KirschKernel;
        return true;
    }
    if(input == 15) {
        out = Magick::KernelInfoType::DiamondKernel;
        return true;
    }
    if(input == 16) {
        out = Magick::KernelInfoType::SquareKernel;
        return true;
    }
    if(input == 17) {
        out = Magick::KernelInfoType::RectangleKernel;
        return true;
    }
    if(input == 18) {
        out = Magick::KernelInfoType::OctagonKernel;
        return true;
    }
    if(input == 19) {
        out = Magick::KernelInfoType::DiskKernel;
        return true;
    }
    if(input == 20) {
        out = Magick::KernelInfoType::PlusKernel;
        return true;
    }
    if(input == 21) {
        out = Magick::KernelInfoType::CrossKernel;
        return true;
    }
    if(input == 22) {
        out = Magick::KernelInfoType::RingKernel;
        return true;
    }
    if(input == 23) {
        out = Magick::KernelInfoType::PeaksKernel;
        return true;
    }
    if(input == 24) {
        out = Magick::KernelInfoType::EdgesKernel;
        return true;
    }
    if(input == 25) {
        out = Magick::KernelInfoType::CornersKernel;
        return true;
    }
    if(input == 26) {
        out = Magick::KernelInfoType::DiagonalsKernel;
        return true;
    }
    if(input == 27) {
        out = Magick::KernelInfoType::LineEndsKernel;
        return true;
    }
    if(input == 28) {
        out = Magick::KernelInfoType::LineJunctionsKernel;
        return true;
    }
    if(input == 29) {
        out = Magick::KernelInfoType::RidgesKernel;
        return true;
    }
    if(input == 30) {
        out = Magick::KernelInfoType::ConvexHullKernel;
        return true;
    }
    if(input == 31) {
        out = Magick::KernelInfoType::ThinSEKernel;
        return true;
    }
    if(input == 32) {
        out = Magick::KernelInfoType::SkeletonKernel;
        return true;
    }
    if(input == 33) {
        out = Magick::KernelInfoType::ChebyshevKernel;
        return true;
    }
    if(input == 34) {
        out = Magick::KernelInfoType::ManhattanKernel;
        return true;
    }
    if(input == 35) {
        out = Magick::KernelInfoType::OctagonalKernel;
        return true;
    }
    if(input == 36) {
        out = Magick::KernelInfoType::EuclideanKernel;
        return true;
    }
    if(input == 37) {
        out = Magick::KernelInfoType::UserDefinedKernel;
        return true;
    }
    if(input == 38) {
        out = Magick::KernelInfoType::BinomialKernel;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to KernelInfoType").ToLocalChecked());
    return false;
}

static void SetMorphologyMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedMorphology").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("ConvolveMorphology").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("CorrelateMorphology").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("ErodeMorphology").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("DilateMorphology").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("ErodeIntensityMorphology").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("DilateIntensityMorphology").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("DistanceMorphology").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("OpenMorphology").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("CloseMorphology").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("OpenIntensityMorphology").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("CloseIntensityMorphology").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("SmoothMorphology").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("EdgeInMorphology").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("EdgeOutMorphology").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("EdgeMorphology").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("TopHatMorphology").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("BottomHatMorphology").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("HitAndMissMorphology").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("ThinningMorphology").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("ThickenMorphology").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("VoronoiMorphology").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("IterativeDistanceMorphology").ToLocalChecked(), Nan::New(23));
    Nan::Set(exports, Nan::New("MorphologyMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertMorphologyMethod(const v8::Local<v8::Value> val, Magick::MorphologyMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MorphologyMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::MorphologyMethod::UndefinedMorphology;
        return true;
    }
    if(input == 2) {
        out = Magick::MorphologyMethod::ConvolveMorphology;
        return true;
    }
    if(input == 3) {
        out = Magick::MorphologyMethod::CorrelateMorphology;
        return true;
    }
    if(input == 4) {
        out = Magick::MorphologyMethod::ErodeMorphology;
        return true;
    }
    if(input == 5) {
        out = Magick::MorphologyMethod::DilateMorphology;
        return true;
    }
    if(input == 6) {
        out = Magick::MorphologyMethod::ErodeIntensityMorphology;
        return true;
    }
    if(input == 7) {
        out = Magick::MorphologyMethod::DilateIntensityMorphology;
        return true;
    }
    if(input == 8) {
        out = Magick::MorphologyMethod::DistanceMorphology;
        return true;
    }
    if(input == 9) {
        out = Magick::MorphologyMethod::OpenMorphology;
        return true;
    }
    if(input == 10) {
        out = Magick::MorphologyMethod::CloseMorphology;
        return true;
    }
    if(input == 11) {
        out = Magick::MorphologyMethod::OpenIntensityMorphology;
        return true;
    }
    if(input == 12) {
        out = Magick::MorphologyMethod::CloseIntensityMorphology;
        return true;
    }
    if(input == 13) {
        out = Magick::MorphologyMethod::SmoothMorphology;
        return true;
    }
    if(input == 14) {
        out = Magick::MorphologyMethod::EdgeInMorphology;
        return true;
    }
    if(input == 15) {
        out = Magick::MorphologyMethod::EdgeOutMorphology;
        return true;
    }
    if(input == 16) {
        out = Magick::MorphologyMethod::EdgeMorphology;
        return true;
    }
    if(input == 17) {
        out = Magick::MorphologyMethod::TopHatMorphology;
        return true;
    }
    if(input == 18) {
        out = Magick::MorphologyMethod::BottomHatMorphology;
        return true;
    }
    if(input == 19) {
        out = Magick::MorphologyMethod::HitAndMissMorphology;
        return true;
    }
    if(input == 20) {
        out = Magick::MorphologyMethod::ThinningMorphology;
        return true;
    }
    if(input == 21) {
        out = Magick::MorphologyMethod::ThickenMorphology;
        return true;
    }
    if(input == 22) {
        out = Magick::MorphologyMethod::VoronoiMorphology;
        return true;
    }
    if(input == 23) {
        out = Magick::MorphologyMethod::IterativeDistanceMorphology;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MorphologyMethod").ToLocalChecked());
    return false;
}

static void SetMontageModeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedMode").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("FrameMode").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("UnframeMode").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("ConcatenateMode").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("MontageMode").ToLocalChecked(), constants);
}

bool Constants::ConvertMontageMode(const v8::Local<v8::Value> val, MagickCore::MontageMode& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MontageMode: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::MontageMode::UndefinedMode;
        return true;
    }
    if(input == 2) {
        out = MagickCore::MontageMode::FrameMode;
        return true;
    }
    if(input == 3) {
        out = MagickCore::MontageMode::UnframeMode;
        return true;
    }
    if(input == 4) {
        out = MagickCore::MontageMode::ConcatenateMode;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MontageMode").ToLocalChecked());
    return false;
}

static void SetMagickModuleTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("MagickImageCoderModule").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("MagickImageFilterModule").ToLocalChecked(), Nan::New(2));
    Nan::Set(exports, Nan::New("MagickModuleType").ToLocalChecked(), constants);
}

bool Constants::ConvertMagickModuleType(const v8::Local<v8::Value> val, MagickCore::MagickModuleType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MagickModuleType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::MagickModuleType::MagickImageCoderModule;
        return true;
    }
    if(input == 2) {
        out = MagickCore::MagickModuleType::MagickImageFilterModule;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MagickModuleType").ToLocalChecked());
    return false;
}

static void SetMagickFormatTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedFormatType").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("ImplicitFormatType").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ExplicitFormatType").ToLocalChecked(), Nan::New(3));
    Nan::Set(exports, Nan::New("MagickFormatType").ToLocalChecked(), constants);
}

bool Constants::ConvertMagickFormatType(const v8::Local<v8::Value> val, MagickCore::MagickFormatType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MagickFormatType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::MagickFormatType::UndefinedFormatType;
        return true;
    }
    if(input == 2) {
        out = MagickCore::MagickFormatType::ImplicitFormatType;
        return true;
    }
    if(input == 3) {
        out = MagickCore::MagickFormatType::ExplicitFormatType;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MagickFormatType").ToLocalChecked());
    return false;
}

static void SetMagickThreadSupportBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("NoThreadSupport").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("DecoderThreadSupport").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("EncoderThreadSupport").ToLocalChecked(), Nan::New(3));
    Nan::Set(exports, Nan::New("MagickThreadSupport").ToLocalChecked(), constants);
}

bool Constants::ConvertMagickThreadSupport(const v8::Local<v8::Value> val, MagickCore::MagickThreadSupport& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MagickThreadSupport: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::MagickThreadSupport::NoThreadSupport;
        return true;
    }
    if(input == 2) {
        out = MagickCore::MagickThreadSupport::DecoderThreadSupport;
        return true;
    }
    if(input == 3) {
        out = MagickCore::MagickThreadSupport::EncoderThreadSupport;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MagickThreadSupport").ToLocalChecked());
    return false;
}

static void SetChannelTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedChannel").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("RedChannel").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("GrayChannel").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("CyanChannel").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("GreenChannel").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("MagentaChannel").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("BlueChannel").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("YellowChannel").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("AlphaChannel").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("OpacityChannel").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("MatteChannel").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("BlackChannel").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("IndexChannel").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("CompositeChannels").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("AllChannels").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("TrueAlphaChannel").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("RGBChannels").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("GrayChannels").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("SyncChannels").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("DefaultChannels").ToLocalChecked(), Nan::New(20));
    Nan::Set(exports, Nan::New("ChannelType").ToLocalChecked(), constants);
}

bool Constants::ConvertChannelType(const v8::Local<v8::Value> val, Magick::ChannelType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ChannelType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::ChannelType::UndefinedChannel;
        return true;
    }
    if(input == 2) {
        out = Magick::ChannelType::RedChannel;
        return true;
    }
    if(input == 3) {
        out = Magick::ChannelType::GrayChannel;
        return true;
    }
    if(input == 4) {
        out = Magick::ChannelType::CyanChannel;
        return true;
    }
    if(input == 5) {
        out = Magick::ChannelType::GreenChannel;
        return true;
    }
    if(input == 6) {
        out = Magick::ChannelType::MagentaChannel;
        return true;
    }
    if(input == 7) {
        out = Magick::ChannelType::BlueChannel;
        return true;
    }
    if(input == 8) {
        out = Magick::ChannelType::YellowChannel;
        return true;
    }
    if(input == 9) {
        out = Magick::ChannelType::AlphaChannel;
        return true;
    }
    if(input == 10) {
        out = Magick::ChannelType::OpacityChannel;
        return true;
    }
    if(input == 11) {
        out = Magick::ChannelType::MatteChannel;
        return true;
    }
    if(input == 12) {
        out = Magick::ChannelType::BlackChannel;
        return true;
    }
    if(input == 13) {
        out = Magick::ChannelType::IndexChannel;
        return true;
    }
    if(input == 14) {
        out = Magick::ChannelType::CompositeChannels;
        return true;
    }
    if(input == 15) {
        out = Magick::ChannelType::AllChannels;
        return true;
    }
    if(input == 16) {
        out = Magick::ChannelType::TrueAlphaChannel;
        return true;
    }
    if(input == 17) {
        out = Magick::ChannelType::RGBChannels;
        return true;
    }
    if(input == 18) {
        out = Magick::ChannelType::GrayChannels;
        return true;
    }
    if(input == 19) {
        out = Magick::ChannelType::SyncChannels;
        return true;
    }
    if(input == 20) {
        out = Magick::ChannelType::DefaultChannels;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ChannelType").ToLocalChecked());
    return false;
}

static void SetClassTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedClass").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("DirectClass").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("PseudoClass").ToLocalChecked(), Nan::New(3));
    Nan::Set(exports, Nan::New("ClassType").ToLocalChecked(), constants);
}

bool Constants::ConvertClassType(const v8::Local<v8::Value> val, Magick::ClassType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ClassType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::ClassType::UndefinedClass;
        return true;
    }
    if(input == 2) {
        out = Magick::ClassType::DirectClass;
        return true;
    }
    if(input == 3) {
        out = Magick::ClassType::PseudoClass;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ClassType").ToLocalChecked());
    return false;
}

static void SetMagickBooleanTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("MagickFalse").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("MagickTrue").ToLocalChecked(), Nan::New(2));
    Nan::Set(exports, Nan::New("MagickBooleanType").ToLocalChecked(), constants);
}

bool Constants::ConvertMagickBooleanType(const v8::Local<v8::Value> val, Magick::MagickBooleanType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MagickBooleanType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::MagickBooleanType::MagickFalse;
        return true;
    }
    if(input == 2) {
        out = Magick::MagickBooleanType::MagickTrue;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MagickBooleanType").ToLocalChecked());
    return false;
}

static void SetLogEventTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedEvents").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("NoEvents").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("TraceEvent").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("AnnotateEvent").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("BlobEvent").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("CacheEvent").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("CoderEvent").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("ConfigureEvent").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("DeprecateEvent").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("DrawEvent").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("ExceptionEvent").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("ImageEvent").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("LocaleEvent").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("ModuleEvent").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("PolicyEvent").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("ResourceEvent").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("TransformEvent").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("UserEvent").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("WandEvent").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("X11Event").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("AccelerateEvent").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("AllEvents").ToLocalChecked(), Nan::New(22));
    Nan::Set(exports, Nan::New("LogEventType").ToLocalChecked(), constants);
}

bool Constants::ConvertLogEventType(const v8::Local<v8::Value> val, Magick::LogEventType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to LogEventType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::LogEventType::UndefinedEvents;
        return true;
    }
    if(input == 2) {
        out = Magick::LogEventType::NoEvents;
        return true;
    }
    if(input == 3) {
        out = Magick::LogEventType::TraceEvent;
        return true;
    }
    if(input == 4) {
        out = Magick::LogEventType::AnnotateEvent;
        return true;
    }
    if(input == 5) {
        out = Magick::LogEventType::BlobEvent;
        return true;
    }
    if(input == 6) {
        out = Magick::LogEventType::CacheEvent;
        return true;
    }
    if(input == 7) {
        out = Magick::LogEventType::CoderEvent;
        return true;
    }
    if(input == 8) {
        out = Magick::LogEventType::ConfigureEvent;
        return true;
    }
    if(input == 9) {
        out = Magick::LogEventType::DeprecateEvent;
        return true;
    }
    if(input == 10) {
        out = Magick::LogEventType::DrawEvent;
        return true;
    }
    if(input == 11) {
        out = Magick::LogEventType::ExceptionEvent;
        return true;
    }
    if(input == 12) {
        out = Magick::LogEventType::ImageEvent;
        return true;
    }
    if(input == 13) {
        out = Magick::LogEventType::LocaleEvent;
        return true;
    }
    if(input == 14) {
        out = Magick::LogEventType::ModuleEvent;
        return true;
    }
    if(input == 15) {
        out = Magick::LogEventType::PolicyEvent;
        return true;
    }
    if(input == 16) {
        out = Magick::LogEventType::ResourceEvent;
        return true;
    }
    if(input == 17) {
        out = Magick::LogEventType::TransformEvent;
        return true;
    }
    if(input == 18) {
        out = Magick::LogEventType::UserEvent;
        return true;
    }
    if(input == 19) {
        out = Magick::LogEventType::WandEvent;
        return true;
    }
    if(input == 20) {
        out = Magick::LogEventType::X11Event;
        return true;
    }
    if(input == 21) {
        out = Magick::LogEventType::AccelerateEvent;
        return true;
    }
    if(input == 22) {
        out = Magick::LogEventType::AllEvents;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to LogEventType").ToLocalChecked());
    return false;
}

static void SetDisposeTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UnrecognizedDispose").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("UndefinedDispose").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("NoneDispose").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("BackgroundDispose").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("PreviousDispose").ToLocalChecked(), Nan::New(5));
    Nan::Set(exports, Nan::New("DisposeType").ToLocalChecked(), constants);
}

bool Constants::ConvertDisposeType(const v8::Local<v8::Value> val, Magick::DisposeType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to DisposeType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::DisposeType::UnrecognizedDispose;
        return true;
    }
    if(input == 2) {
        out = Magick::DisposeType::UndefinedDispose;
        return true;
    }
    if(input == 3) {
        out = Magick::DisposeType::NoneDispose;
        return true;
    }
    if(input == 4) {
        out = Magick::DisposeType::BackgroundDispose;
        return true;
    }
    if(input == 5) {
        out = Magick::DisposeType::PreviousDispose;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to DisposeType").ToLocalChecked());
    return false;
}

static void SetImageLayerMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedLayer").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("CoalesceLayer").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("CompareAnyLayer").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("CompareClearLayer").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("CompareOverlayLayer").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("DisposeLayer").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("OptimizeLayer").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("OptimizeImageLayer").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("OptimizePlusLayer").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("OptimizeTransLayer").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("RemoveDupsLayer").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("RemoveZeroLayer").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("CompositeLayer").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("MergeLayer").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("FlattenLayer").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("MosaicLayer").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("TrimBoundsLayer").ToLocalChecked(), Nan::New(17));
    Nan::Set(exports, Nan::New("ImageLayerMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertImageLayerMethod(const v8::Local<v8::Value> val, Magick::ImageLayerMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ImageLayerMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::ImageLayerMethod::UndefinedLayer;
        return true;
    }
    if(input == 2) {
        out = Magick::ImageLayerMethod::CoalesceLayer;
        return true;
    }
    if(input == 3) {
        out = Magick::ImageLayerMethod::CompareAnyLayer;
        return true;
    }
    if(input == 4) {
        out = Magick::ImageLayerMethod::CompareClearLayer;
        return true;
    }
    if(input == 5) {
        out = Magick::ImageLayerMethod::CompareOverlayLayer;
        return true;
    }
    if(input == 6) {
        out = Magick::ImageLayerMethod::DisposeLayer;
        return true;
    }
    if(input == 7) {
        out = Magick::ImageLayerMethod::OptimizeLayer;
        return true;
    }
    if(input == 8) {
        out = Magick::ImageLayerMethod::OptimizeImageLayer;
        return true;
    }
    if(input == 9) {
        out = Magick::ImageLayerMethod::OptimizePlusLayer;
        return true;
    }
    if(input == 10) {
        out = Magick::ImageLayerMethod::OptimizeTransLayer;
        return true;
    }
    if(input == 11) {
        out = Magick::ImageLayerMethod::RemoveDupsLayer;
        return true;
    }
    if(input == 12) {
        out = Magick::ImageLayerMethod::RemoveZeroLayer;
        return true;
    }
    if(input == 13) {
        out = Magick::ImageLayerMethod::CompositeLayer;
        return true;
    }
    if(input == 14) {
        out = Magick::ImageLayerMethod::MergeLayer;
        return true;
    }
    if(input == 15) {
        out = Magick::ImageLayerMethod::FlattenLayer;
        return true;
    }
    if(input == 16) {
        out = Magick::ImageLayerMethod::MosaicLayer;
        return true;
    }
    if(input == 17) {
        out = Magick::ImageLayerMethod::TrimBoundsLayer;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ImageLayerMethod").ToLocalChecked());
    return false;
}

static void SetAlphaChannelTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedAlphaChannel").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("ActivateAlphaChannel").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("BackgroundAlphaChannel").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("CopyAlphaChannel").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("DeactivateAlphaChannel").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("ExtractAlphaChannel").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("OpaqueAlphaChannel").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("ResetAlphaChannel").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("SetAlphaChannel").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("ShapeAlphaChannel").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("TransparentAlphaChannel").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("FlattenAlphaChannel").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("RemoveAlphaChannel").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("AssociateAlphaChannel").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("DisassociateAlphaChannel").ToLocalChecked(), Nan::New(15));
    Nan::Set(exports, Nan::New("AlphaChannelType").ToLocalChecked(), constants);
}

bool Constants::ConvertAlphaChannelType(const v8::Local<v8::Value> val, Magick::AlphaChannelType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to AlphaChannelType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::AlphaChannelType::UndefinedAlphaChannel;
        return true;
    }
    if(input == 2) {
        out = Magick::AlphaChannelType::ActivateAlphaChannel;
        return true;
    }
    if(input == 3) {
        out = Magick::AlphaChannelType::BackgroundAlphaChannel;
        return true;
    }
    if(input == 4) {
        out = Magick::AlphaChannelType::CopyAlphaChannel;
        return true;
    }
    if(input == 5) {
        out = Magick::AlphaChannelType::DeactivateAlphaChannel;
        return true;
    }
    if(input == 6) {
        out = Magick::AlphaChannelType::ExtractAlphaChannel;
        return true;
    }
    if(input == 7) {
        out = Magick::AlphaChannelType::OpaqueAlphaChannel;
        return true;
    }
    if(input == 8) {
        out = Magick::AlphaChannelType::ResetAlphaChannel;
        return true;
    }
    if(input == 9) {
        out = Magick::AlphaChannelType::SetAlphaChannel;
        return true;
    }
    if(input == 10) {
        out = Magick::AlphaChannelType::ShapeAlphaChannel;
        return true;
    }
    if(input == 11) {
        out = Magick::AlphaChannelType::TransparentAlphaChannel;
        return true;
    }
    if(input == 12) {
        out = Magick::AlphaChannelType::FlattenAlphaChannel;
        return true;
    }
    if(input == 13) {
        out = Magick::AlphaChannelType::RemoveAlphaChannel;
        return true;
    }
    if(input == 14) {
        out = Magick::AlphaChannelType::AssociateAlphaChannel;
        return true;
    }
    if(input == 15) {
        out = Magick::AlphaChannelType::DisassociateAlphaChannel;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to AlphaChannelType").ToLocalChecked());
    return false;
}

static void SetImageTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedType").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("BilevelType").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("GrayscaleType").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("GrayscaleMatteType").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("PaletteType").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("PaletteMatteType").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("TrueColorType").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("TrueColorMatteType").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("ColorSeparationType").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("ColorSeparationMatteType").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("OptimizeType").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("PaletteBilevelMatteType").ToLocalChecked(), Nan::New(12));
    Nan::Set(exports, Nan::New("ImageType").ToLocalChecked(), constants);
}

bool Constants::ConvertImageType(const v8::Local<v8::Value> val, Magick::ImageType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ImageType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::ImageType::UndefinedType;
        return true;
    }
    if(input == 2) {
        out = Magick::ImageType::BilevelType;
        return true;
    }
    if(input == 3) {
        out = Magick::ImageType::GrayscaleType;
        return true;
    }
    if(input == 4) {
        out = Magick::ImageType::GrayscaleMatteType;
        return true;
    }
    if(input == 5) {
        out = Magick::ImageType::PaletteType;
        return true;
    }
    if(input == 6) {
        out = Magick::ImageType::PaletteMatteType;
        return true;
    }
    if(input == 7) {
        out = Magick::ImageType::TrueColorType;
        return true;
    }
    if(input == 8) {
        out = Magick::ImageType::TrueColorMatteType;
        return true;
    }
    if(input == 9) {
        out = Magick::ImageType::ColorSeparationType;
        return true;
    }
    if(input == 10) {
        out = Magick::ImageType::ColorSeparationMatteType;
        return true;
    }
    if(input == 11) {
        out = Magick::ImageType::OptimizeType;
        return true;
    }
    if(input == 12) {
        out = Magick::ImageType::PaletteBilevelMatteType;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ImageType").ToLocalChecked());
    return false;
}

static void SetInterlaceTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedInterlace").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("NoInterlace").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("LineInterlace").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("PlaneInterlace").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("PartitionInterlace").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("GIFInterlace").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("JPEGInterlace").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("PNGInterlace").ToLocalChecked(), Nan::New(8));
    Nan::Set(exports, Nan::New("InterlaceType").ToLocalChecked(), constants);
}

bool Constants::ConvertInterlaceType(const v8::Local<v8::Value> val, Magick::InterlaceType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to InterlaceType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::InterlaceType::UndefinedInterlace;
        return true;
    }
    if(input == 2) {
        out = Magick::InterlaceType::NoInterlace;
        return true;
    }
    if(input == 3) {
        out = Magick::InterlaceType::LineInterlace;
        return true;
    }
    if(input == 4) {
        out = Magick::InterlaceType::PlaneInterlace;
        return true;
    }
    if(input == 5) {
        out = Magick::InterlaceType::PartitionInterlace;
        return true;
    }
    if(input == 6) {
        out = Magick::InterlaceType::GIFInterlace;
        return true;
    }
    if(input == 7) {
        out = Magick::InterlaceType::JPEGInterlace;
        return true;
    }
    if(input == 8) {
        out = Magick::InterlaceType::PNGInterlace;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to InterlaceType").ToLocalChecked());
    return false;
}

static void SetOrientationTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedOrientation").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("TopLeftOrientation").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("TopRightOrientation").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("BottomRightOrientation").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("BottomLeftOrientation").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("LeftTopOrientation").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("RightTopOrientation").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("RightBottomOrientation").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("LeftBottomOrientation").ToLocalChecked(), Nan::New(9));
    Nan::Set(exports, Nan::New("OrientationType").ToLocalChecked(), constants);
}

bool Constants::ConvertOrientationType(const v8::Local<v8::Value> val, Magick::OrientationType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to OrientationType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::OrientationType::UndefinedOrientation;
        return true;
    }
    if(input == 2) {
        out = Magick::OrientationType::TopLeftOrientation;
        return true;
    }
    if(input == 3) {
        out = Magick::OrientationType::TopRightOrientation;
        return true;
    }
    if(input == 4) {
        out = Magick::OrientationType::BottomRightOrientation;
        return true;
    }
    if(input == 5) {
        out = Magick::OrientationType::BottomLeftOrientation;
        return true;
    }
    if(input == 6) {
        out = Magick::OrientationType::LeftTopOrientation;
        return true;
    }
    if(input == 7) {
        out = Magick::OrientationType::RightTopOrientation;
        return true;
    }
    if(input == 8) {
        out = Magick::OrientationType::RightBottomOrientation;
        return true;
    }
    if(input == 9) {
        out = Magick::OrientationType::LeftBottomOrientation;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to OrientationType").ToLocalChecked());
    return false;
}

static void SetResolutionTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedResolution").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("PixelsPerInchResolution").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("PixelsPerCentimeterResolution").ToLocalChecked(), Nan::New(3));
    Nan::Set(exports, Nan::New("ResolutionType").ToLocalChecked(), constants);
}

bool Constants::ConvertResolutionType(const v8::Local<v8::Value> val, Magick::ResolutionType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ResolutionType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::ResolutionType::UndefinedResolution;
        return true;
    }
    if(input == 2) {
        out = Magick::ResolutionType::PixelsPerInchResolution;
        return true;
    }
    if(input == 3) {
        out = Magick::ResolutionType::PixelsPerCentimeterResolution;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ResolutionType").ToLocalChecked());
    return false;
}

static void SetTransmitTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedTransmitType").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("FileTransmitType").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("BlobTransmitType").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("StreamTransmitType").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("ImageTransmitType").ToLocalChecked(), Nan::New(5));
    Nan::Set(exports, Nan::New("TransmitType").ToLocalChecked(), constants);
}

bool Constants::ConvertTransmitType(const v8::Local<v8::Value> val, MagickCore::TransmitType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to TransmitType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::TransmitType::UndefinedTransmitType;
        return true;
    }
    if(input == 2) {
        out = MagickCore::TransmitType::FileTransmitType;
        return true;
    }
    if(input == 3) {
        out = MagickCore::TransmitType::BlobTransmitType;
        return true;
    }
    if(input == 4) {
        out = MagickCore::TransmitType::StreamTransmitType;
        return true;
    }
    if(input == 5) {
        out = MagickCore::TransmitType::ImageTransmitType;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to TransmitType").ToLocalChecked());
    return false;
}

static void SetGeometryFlagsBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("NoValue").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("XValue").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("XiValue").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("YValue").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("PsiValue").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("WidthValue").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("RhoValue").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("HeightValue").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("SigmaValue").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("ChiValue").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("XiNegative").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("XNegative").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("PsiNegative").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("YNegative").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("ChiNegative").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("PercentValue").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("AspectValue").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("NormalizeValue").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("LessValue").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("GreaterValue").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("MinimumValue").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("CorrelateNormalizeValue").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("AreaValue").ToLocalChecked(), Nan::New(23));
    Nan::Set(constants, Nan::New("DecimalValue").ToLocalChecked(), Nan::New(24));
    Nan::Set(constants, Nan::New("SeparatorValue").ToLocalChecked(), Nan::New(25));
    Nan::Set(constants, Nan::New("AspectRatioValue").ToLocalChecked(), Nan::New(26));
    Nan::Set(constants, Nan::New("AlphaValue").ToLocalChecked(), Nan::New(27));
    Nan::Set(constants, Nan::New("AllValues").ToLocalChecked(), Nan::New(28));
    Nan::Set(exports, Nan::New("GeometryFlags").ToLocalChecked(), constants);
}

bool Constants::ConvertGeometryFlags(const v8::Local<v8::Value> val, MagickCore::GeometryFlags& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to GeometryFlags: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::GeometryFlags::NoValue;
        return true;
    }
    if(input == 2) {
        out = MagickCore::GeometryFlags::XValue;
        return true;
    }
    if(input == 3) {
        out = MagickCore::GeometryFlags::XiValue;
        return true;
    }
    if(input == 4) {
        out = MagickCore::GeometryFlags::YValue;
        return true;
    }
    if(input == 5) {
        out = MagickCore::GeometryFlags::PsiValue;
        return true;
    }
    if(input == 6) {
        out = MagickCore::GeometryFlags::WidthValue;
        return true;
    }
    if(input == 7) {
        out = MagickCore::GeometryFlags::RhoValue;
        return true;
    }
    if(input == 8) {
        out = MagickCore::GeometryFlags::HeightValue;
        return true;
    }
    if(input == 9) {
        out = MagickCore::GeometryFlags::SigmaValue;
        return true;
    }
    if(input == 10) {
        out = MagickCore::GeometryFlags::ChiValue;
        return true;
    }
    if(input == 11) {
        out = MagickCore::GeometryFlags::XiNegative;
        return true;
    }
    if(input == 12) {
        out = MagickCore::GeometryFlags::XNegative;
        return true;
    }
    if(input == 13) {
        out = MagickCore::GeometryFlags::PsiNegative;
        return true;
    }
    if(input == 14) {
        out = MagickCore::GeometryFlags::YNegative;
        return true;
    }
    if(input == 15) {
        out = MagickCore::GeometryFlags::ChiNegative;
        return true;
    }
    if(input == 16) {
        out = MagickCore::GeometryFlags::PercentValue;
        return true;
    }
    if(input == 17) {
        out = MagickCore::GeometryFlags::AspectValue;
        return true;
    }
    if(input == 18) {
        out = MagickCore::GeometryFlags::NormalizeValue;
        return true;
    }
    if(input == 19) {
        out = MagickCore::GeometryFlags::LessValue;
        return true;
    }
    if(input == 20) {
        out = MagickCore::GeometryFlags::GreaterValue;
        return true;
    }
    if(input == 21) {
        out = MagickCore::GeometryFlags::MinimumValue;
        return true;
    }
    if(input == 22) {
        out = MagickCore::GeometryFlags::CorrelateNormalizeValue;
        return true;
    }
    if(input == 23) {
        out = MagickCore::GeometryFlags::AreaValue;
        return true;
    }
    if(input == 24) {
        out = MagickCore::GeometryFlags::DecimalValue;
        return true;
    }
    if(input == 25) {
        out = MagickCore::GeometryFlags::SeparatorValue;
        return true;
    }
    if(input == 26) {
        out = MagickCore::GeometryFlags::AspectRatioValue;
        return true;
    }
    if(input == 27) {
        out = MagickCore::GeometryFlags::AlphaValue;
        return true;
    }
    if(input == 28) {
        out = MagickCore::GeometryFlags::AllValues;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to GeometryFlags").ToLocalChecked());
    return false;
}

static void SetGravityTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedGravity").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("ForgetGravity").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("NorthWestGravity").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("NorthGravity").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("NorthEastGravity").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("WestGravity").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("CenterGravity").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("EastGravity").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("SouthWestGravity").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("SouthGravity").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("SouthEastGravity").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("StaticGravity").ToLocalChecked(), Nan::New(12));
    Nan::Set(exports, Nan::New("GravityType").ToLocalChecked(), constants);
}

bool Constants::ConvertGravityType(const v8::Local<v8::Value> val, Magick::GravityType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to GravityType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::GravityType::UndefinedGravity;
        return true;
    }
    if(input == 2) {
        out = Magick::GravityType::ForgetGravity;
        return true;
    }
    if(input == 3) {
        out = Magick::GravityType::NorthWestGravity;
        return true;
    }
    if(input == 4) {
        out = Magick::GravityType::NorthGravity;
        return true;
    }
    if(input == 5) {
        out = Magick::GravityType::NorthEastGravity;
        return true;
    }
    if(input == 6) {
        out = Magick::GravityType::WestGravity;
        return true;
    }
    if(input == 7) {
        out = Magick::GravityType::CenterGravity;
        return true;
    }
    if(input == 8) {
        out = Magick::GravityType::EastGravity;
        return true;
    }
    if(input == 9) {
        out = Magick::GravityType::SouthWestGravity;
        return true;
    }
    if(input == 10) {
        out = Magick::GravityType::SouthGravity;
        return true;
    }
    if(input == 11) {
        out = Magick::GravityType::SouthEastGravity;
        return true;
    }
    if(input == 12) {
        out = Magick::GravityType::StaticGravity;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to GravityType").ToLocalChecked());
    return false;
}

static void SetComplexOperatorBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedComplexOperator").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("AddComplexOperator").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ConjugateComplexOperator").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("DivideComplexOperator").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("MagnitudePhaseComplexOperator").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("MultiplyComplexOperator").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("RealImaginaryComplexOperator").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("SubtractComplexOperator").ToLocalChecked(), Nan::New(8));
    Nan::Set(exports, Nan::New("ComplexOperator").ToLocalChecked(), constants);
}

bool Constants::ConvertComplexOperator(const v8::Local<v8::Value> val, MagickCore::ComplexOperator& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ComplexOperator: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::ComplexOperator::UndefinedComplexOperator;
        return true;
    }
    if(input == 2) {
        out = MagickCore::ComplexOperator::AddComplexOperator;
        return true;
    }
    if(input == 3) {
        out = MagickCore::ComplexOperator::ConjugateComplexOperator;
        return true;
    }
    if(input == 4) {
        out = MagickCore::ComplexOperator::DivideComplexOperator;
        return true;
    }
    if(input == 5) {
        out = MagickCore::ComplexOperator::MagnitudePhaseComplexOperator;
        return true;
    }
    if(input == 6) {
        out = MagickCore::ComplexOperator::MultiplyComplexOperator;
        return true;
    }
    if(input == 7) {
        out = MagickCore::ComplexOperator::RealImaginaryComplexOperator;
        return true;
    }
    if(input == 8) {
        out = MagickCore::ComplexOperator::SubtractComplexOperator;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ComplexOperator").ToLocalChecked());
    return false;
}

static void SetExceptionTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedException").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("WarningException").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ResourceLimitWarning").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("TypeWarning").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("OptionWarning").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("DelegateWarning").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("MissingDelegateWarning").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("CorruptImageWarning").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("FileOpenWarning").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("BlobWarning").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("StreamWarning").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("CacheWarning").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("CoderWarning").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("FilterWarning").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("ModuleWarning").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("DrawWarning").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("ImageWarning").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("WandWarning").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("RandomWarning").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("XServerWarning").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("MonitorWarning").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("RegistryWarning").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("ConfigureWarning").ToLocalChecked(), Nan::New(23));
    Nan::Set(constants, Nan::New("PolicyWarning").ToLocalChecked(), Nan::New(24));
    Nan::Set(constants, Nan::New("ErrorException").ToLocalChecked(), Nan::New(25));
    Nan::Set(constants, Nan::New("ResourceLimitError").ToLocalChecked(), Nan::New(26));
    Nan::Set(constants, Nan::New("TypeError").ToLocalChecked(), Nan::New(27));
    Nan::Set(constants, Nan::New("OptionError").ToLocalChecked(), Nan::New(28));
    Nan::Set(constants, Nan::New("DelegateError").ToLocalChecked(), Nan::New(29));
    Nan::Set(constants, Nan::New("MissingDelegateError").ToLocalChecked(), Nan::New(30));
    Nan::Set(constants, Nan::New("CorruptImageError").ToLocalChecked(), Nan::New(31));
    Nan::Set(constants, Nan::New("FileOpenError").ToLocalChecked(), Nan::New(32));
    Nan::Set(constants, Nan::New("BlobError").ToLocalChecked(), Nan::New(33));
    Nan::Set(constants, Nan::New("StreamError").ToLocalChecked(), Nan::New(34));
    Nan::Set(constants, Nan::New("CacheError").ToLocalChecked(), Nan::New(35));
    Nan::Set(constants, Nan::New("CoderError").ToLocalChecked(), Nan::New(36));
    Nan::Set(constants, Nan::New("FilterError").ToLocalChecked(), Nan::New(37));
    Nan::Set(constants, Nan::New("ModuleError").ToLocalChecked(), Nan::New(38));
    Nan::Set(constants, Nan::New("DrawError").ToLocalChecked(), Nan::New(39));
    Nan::Set(constants, Nan::New("ImageError").ToLocalChecked(), Nan::New(40));
    Nan::Set(constants, Nan::New("WandError").ToLocalChecked(), Nan::New(41));
    Nan::Set(constants, Nan::New("RandomError").ToLocalChecked(), Nan::New(42));
    Nan::Set(constants, Nan::New("XServerError").ToLocalChecked(), Nan::New(43));
    Nan::Set(constants, Nan::New("MonitorError").ToLocalChecked(), Nan::New(44));
    Nan::Set(constants, Nan::New("RegistryError").ToLocalChecked(), Nan::New(45));
    Nan::Set(constants, Nan::New("ConfigureError").ToLocalChecked(), Nan::New(46));
    Nan::Set(constants, Nan::New("PolicyError").ToLocalChecked(), Nan::New(47));
    Nan::Set(constants, Nan::New("FatalErrorException").ToLocalChecked(), Nan::New(48));
    Nan::Set(constants, Nan::New("ResourceLimitFatalError").ToLocalChecked(), Nan::New(49));
    Nan::Set(constants, Nan::New("TypeFatalError").ToLocalChecked(), Nan::New(50));
    Nan::Set(constants, Nan::New("OptionFatalError").ToLocalChecked(), Nan::New(51));
    Nan::Set(constants, Nan::New("DelegateFatalError").ToLocalChecked(), Nan::New(52));
    Nan::Set(constants, Nan::New("MissingDelegateFatalError").ToLocalChecked(), Nan::New(53));
    Nan::Set(constants, Nan::New("CorruptImageFatalError").ToLocalChecked(), Nan::New(54));
    Nan::Set(constants, Nan::New("FileOpenFatalError").ToLocalChecked(), Nan::New(55));
    Nan::Set(constants, Nan::New("BlobFatalError").ToLocalChecked(), Nan::New(56));
    Nan::Set(constants, Nan::New("StreamFatalError").ToLocalChecked(), Nan::New(57));
    Nan::Set(constants, Nan::New("CacheFatalError").ToLocalChecked(), Nan::New(58));
    Nan::Set(constants, Nan::New("CoderFatalError").ToLocalChecked(), Nan::New(59));
    Nan::Set(constants, Nan::New("FilterFatalError").ToLocalChecked(), Nan::New(60));
    Nan::Set(constants, Nan::New("ModuleFatalError").ToLocalChecked(), Nan::New(61));
    Nan::Set(constants, Nan::New("DrawFatalError").ToLocalChecked(), Nan::New(62));
    Nan::Set(constants, Nan::New("ImageFatalError").ToLocalChecked(), Nan::New(63));
    Nan::Set(constants, Nan::New("WandFatalError").ToLocalChecked(), Nan::New(64));
    Nan::Set(constants, Nan::New("RandomFatalError").ToLocalChecked(), Nan::New(65));
    Nan::Set(constants, Nan::New("XServerFatalError").ToLocalChecked(), Nan::New(66));
    Nan::Set(constants, Nan::New("MonitorFatalError").ToLocalChecked(), Nan::New(67));
    Nan::Set(constants, Nan::New("RegistryFatalError").ToLocalChecked(), Nan::New(68));
    Nan::Set(constants, Nan::New("ConfigureFatalError").ToLocalChecked(), Nan::New(69));
    Nan::Set(constants, Nan::New("PolicyFatalError").ToLocalChecked(), Nan::New(70));
    Nan::Set(exports, Nan::New("ExceptionType").ToLocalChecked(), constants);
}

bool Constants::ConvertExceptionType(const v8::Local<v8::Value> val, MagickCore::ExceptionType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ExceptionType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::ExceptionType::UndefinedException;
        return true;
    }
    if(input == 2) {
        out = MagickCore::ExceptionType::WarningException;
        return true;
    }
    if(input == 3) {
        out = MagickCore::ExceptionType::ResourceLimitWarning;
        return true;
    }
    if(input == 4) {
        out = MagickCore::ExceptionType::TypeWarning;
        return true;
    }
    if(input == 5) {
        out = MagickCore::ExceptionType::OptionWarning;
        return true;
    }
    if(input == 6) {
        out = MagickCore::ExceptionType::DelegateWarning;
        return true;
    }
    if(input == 7) {
        out = MagickCore::ExceptionType::MissingDelegateWarning;
        return true;
    }
    if(input == 8) {
        out = MagickCore::ExceptionType::CorruptImageWarning;
        return true;
    }
    if(input == 9) {
        out = MagickCore::ExceptionType::FileOpenWarning;
        return true;
    }
    if(input == 10) {
        out = MagickCore::ExceptionType::BlobWarning;
        return true;
    }
    if(input == 11) {
        out = MagickCore::ExceptionType::StreamWarning;
        return true;
    }
    if(input == 12) {
        out = MagickCore::ExceptionType::CacheWarning;
        return true;
    }
    if(input == 13) {
        out = MagickCore::ExceptionType::CoderWarning;
        return true;
    }
    if(input == 14) {
        out = MagickCore::ExceptionType::FilterWarning;
        return true;
    }
    if(input == 15) {
        out = MagickCore::ExceptionType::ModuleWarning;
        return true;
    }
    if(input == 16) {
        out = MagickCore::ExceptionType::DrawWarning;
        return true;
    }
    if(input == 17) {
        out = MagickCore::ExceptionType::ImageWarning;
        return true;
    }
    if(input == 18) {
        out = MagickCore::ExceptionType::WandWarning;
        return true;
    }
    if(input == 19) {
        out = MagickCore::ExceptionType::RandomWarning;
        return true;
    }
    if(input == 20) {
        out = MagickCore::ExceptionType::XServerWarning;
        return true;
    }
    if(input == 21) {
        out = MagickCore::ExceptionType::MonitorWarning;
        return true;
    }
    if(input == 22) {
        out = MagickCore::ExceptionType::RegistryWarning;
        return true;
    }
    if(input == 23) {
        out = MagickCore::ExceptionType::ConfigureWarning;
        return true;
    }
    if(input == 24) {
        out = MagickCore::ExceptionType::PolicyWarning;
        return true;
    }
    if(input == 25) {
        out = MagickCore::ExceptionType::ErrorException;
        return true;
    }
    if(input == 26) {
        out = MagickCore::ExceptionType::ResourceLimitError;
        return true;
    }
    if(input == 27) {
        out = MagickCore::ExceptionType::TypeError;
        return true;
    }
    if(input == 28) {
        out = MagickCore::ExceptionType::OptionError;
        return true;
    }
    if(input == 29) {
        out = MagickCore::ExceptionType::DelegateError;
        return true;
    }
    if(input == 30) {
        out = MagickCore::ExceptionType::MissingDelegateError;
        return true;
    }
    if(input == 31) {
        out = MagickCore::ExceptionType::CorruptImageError;
        return true;
    }
    if(input == 32) {
        out = MagickCore::ExceptionType::FileOpenError;
        return true;
    }
    if(input == 33) {
        out = MagickCore::ExceptionType::BlobError;
        return true;
    }
    if(input == 34) {
        out = MagickCore::ExceptionType::StreamError;
        return true;
    }
    if(input == 35) {
        out = MagickCore::ExceptionType::CacheError;
        return true;
    }
    if(input == 36) {
        out = MagickCore::ExceptionType::CoderError;
        return true;
    }
    if(input == 37) {
        out = MagickCore::ExceptionType::FilterError;
        return true;
    }
    if(input == 38) {
        out = MagickCore::ExceptionType::ModuleError;
        return true;
    }
    if(input == 39) {
        out = MagickCore::ExceptionType::DrawError;
        return true;
    }
    if(input == 40) {
        out = MagickCore::ExceptionType::ImageError;
        return true;
    }
    if(input == 41) {
        out = MagickCore::ExceptionType::WandError;
        return true;
    }
    if(input == 42) {
        out = MagickCore::ExceptionType::RandomError;
        return true;
    }
    if(input == 43) {
        out = MagickCore::ExceptionType::XServerError;
        return true;
    }
    if(input == 44) {
        out = MagickCore::ExceptionType::MonitorError;
        return true;
    }
    if(input == 45) {
        out = MagickCore::ExceptionType::RegistryError;
        return true;
    }
    if(input == 46) {
        out = MagickCore::ExceptionType::ConfigureError;
        return true;
    }
    if(input == 47) {
        out = MagickCore::ExceptionType::PolicyError;
        return true;
    }
    if(input == 48) {
        out = MagickCore::ExceptionType::FatalErrorException;
        return true;
    }
    if(input == 49) {
        out = MagickCore::ExceptionType::ResourceLimitFatalError;
        return true;
    }
    if(input == 50) {
        out = MagickCore::ExceptionType::TypeFatalError;
        return true;
    }
    if(input == 51) {
        out = MagickCore::ExceptionType::OptionFatalError;
        return true;
    }
    if(input == 52) {
        out = MagickCore::ExceptionType::DelegateFatalError;
        return true;
    }
    if(input == 53) {
        out = MagickCore::ExceptionType::MissingDelegateFatalError;
        return true;
    }
    if(input == 54) {
        out = MagickCore::ExceptionType::CorruptImageFatalError;
        return true;
    }
    if(input == 55) {
        out = MagickCore::ExceptionType::FileOpenFatalError;
        return true;
    }
    if(input == 56) {
        out = MagickCore::ExceptionType::BlobFatalError;
        return true;
    }
    if(input == 57) {
        out = MagickCore::ExceptionType::StreamFatalError;
        return true;
    }
    if(input == 58) {
        out = MagickCore::ExceptionType::CacheFatalError;
        return true;
    }
    if(input == 59) {
        out = MagickCore::ExceptionType::CoderFatalError;
        return true;
    }
    if(input == 60) {
        out = MagickCore::ExceptionType::FilterFatalError;
        return true;
    }
    if(input == 61) {
        out = MagickCore::ExceptionType::ModuleFatalError;
        return true;
    }
    if(input == 62) {
        out = MagickCore::ExceptionType::DrawFatalError;
        return true;
    }
    if(input == 63) {
        out = MagickCore::ExceptionType::ImageFatalError;
        return true;
    }
    if(input == 64) {
        out = MagickCore::ExceptionType::WandFatalError;
        return true;
    }
    if(input == 65) {
        out = MagickCore::ExceptionType::RandomFatalError;
        return true;
    }
    if(input == 66) {
        out = MagickCore::ExceptionType::XServerFatalError;
        return true;
    }
    if(input == 67) {
        out = MagickCore::ExceptionType::MonitorFatalError;
        return true;
    }
    if(input == 68) {
        out = MagickCore::ExceptionType::RegistryFatalError;
        return true;
    }
    if(input == 69) {
        out = MagickCore::ExceptionType::ConfigureFatalError;
        return true;
    }
    if(input == 70) {
        out = MagickCore::ExceptionType::PolicyFatalError;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ExceptionType").ToLocalChecked());
    return false;
}

static void SetPreviewTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedPreview").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("RotatePreview").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ShearPreview").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("RollPreview").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("HuePreview").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("SaturationPreview").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("BrightnessPreview").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("GammaPreview").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("SpiffPreview").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("DullPreview").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("GrayscalePreview").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("QuantizePreview").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("DespecklePreview").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("ReduceNoisePreview").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("AddNoisePreview").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("SharpenPreview").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("BlurPreview").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("ThresholdPreview").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("EdgeDetectPreview").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("SpreadPreview").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("SolarizePreview").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("ShadePreview").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("RaisePreview").ToLocalChecked(), Nan::New(23));
    Nan::Set(constants, Nan::New("SegmentPreview").ToLocalChecked(), Nan::New(24));
    Nan::Set(constants, Nan::New("SwirlPreview").ToLocalChecked(), Nan::New(25));
    Nan::Set(constants, Nan::New("ImplodePreview").ToLocalChecked(), Nan::New(26));
    Nan::Set(constants, Nan::New("WavePreview").ToLocalChecked(), Nan::New(27));
    Nan::Set(constants, Nan::New("OilPaintPreview").ToLocalChecked(), Nan::New(28));
    Nan::Set(constants, Nan::New("CharcoalDrawingPreview").ToLocalChecked(), Nan::New(29));
    Nan::Set(constants, Nan::New("JPEGPreview").ToLocalChecked(), Nan::New(30));
    Nan::Set(exports, Nan::New("PreviewType").ToLocalChecked(), constants);
}

bool Constants::ConvertPreviewType(const v8::Local<v8::Value> val, Magick::PreviewType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to PreviewType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::PreviewType::UndefinedPreview;
        return true;
    }
    if(input == 2) {
        out = Magick::PreviewType::RotatePreview;
        return true;
    }
    if(input == 3) {
        out = Magick::PreviewType::ShearPreview;
        return true;
    }
    if(input == 4) {
        out = Magick::PreviewType::RollPreview;
        return true;
    }
    if(input == 5) {
        out = Magick::PreviewType::HuePreview;
        return true;
    }
    if(input == 6) {
        out = Magick::PreviewType::SaturationPreview;
        return true;
    }
    if(input == 7) {
        out = Magick::PreviewType::BrightnessPreview;
        return true;
    }
    if(input == 8) {
        out = Magick::PreviewType::GammaPreview;
        return true;
    }
    if(input == 9) {
        out = Magick::PreviewType::SpiffPreview;
        return true;
    }
    if(input == 10) {
        out = Magick::PreviewType::DullPreview;
        return true;
    }
    if(input == 11) {
        out = Magick::PreviewType::GrayscalePreview;
        return true;
    }
    if(input == 12) {
        out = Magick::PreviewType::QuantizePreview;
        return true;
    }
    if(input == 13) {
        out = Magick::PreviewType::DespecklePreview;
        return true;
    }
    if(input == 14) {
        out = Magick::PreviewType::ReduceNoisePreview;
        return true;
    }
    if(input == 15) {
        out = Magick::PreviewType::AddNoisePreview;
        return true;
    }
    if(input == 16) {
        out = Magick::PreviewType::SharpenPreview;
        return true;
    }
    if(input == 17) {
        out = Magick::PreviewType::BlurPreview;
        return true;
    }
    if(input == 18) {
        out = Magick::PreviewType::ThresholdPreview;
        return true;
    }
    if(input == 19) {
        out = Magick::PreviewType::EdgeDetectPreview;
        return true;
    }
    if(input == 20) {
        out = Magick::PreviewType::SpreadPreview;
        return true;
    }
    if(input == 21) {
        out = Magick::PreviewType::SolarizePreview;
        return true;
    }
    if(input == 22) {
        out = Magick::PreviewType::ShadePreview;
        return true;
    }
    if(input == 23) {
        out = Magick::PreviewType::RaisePreview;
        return true;
    }
    if(input == 24) {
        out = Magick::PreviewType::SegmentPreview;
        return true;
    }
    if(input == 25) {
        out = Magick::PreviewType::SwirlPreview;
        return true;
    }
    if(input == 26) {
        out = Magick::PreviewType::ImplodePreview;
        return true;
    }
    if(input == 27) {
        out = Magick::PreviewType::WavePreview;
        return true;
    }
    if(input == 28) {
        out = Magick::PreviewType::OilPaintPreview;
        return true;
    }
    if(input == 29) {
        out = Magick::PreviewType::CharcoalDrawingPreview;
        return true;
    }
    if(input == 30) {
        out = Magick::PreviewType::JPEGPreview;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to PreviewType").ToLocalChecked());
    return false;
}

static void SetAlignTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedAlign").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("LeftAlign").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("CenterAlign").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("RightAlign").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("AlignType").ToLocalChecked(), constants);
}

bool Constants::ConvertAlignType(const v8::Local<v8::Value> val, MagickCore::AlignType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to AlignType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::AlignType::UndefinedAlign;
        return true;
    }
    if(input == 2) {
        out = MagickCore::AlignType::LeftAlign;
        return true;
    }
    if(input == 3) {
        out = MagickCore::AlignType::CenterAlign;
        return true;
    }
    if(input == 4) {
        out = MagickCore::AlignType::RightAlign;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to AlignType").ToLocalChecked());
    return false;
}

static void SetClipPathUnitsBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedPathUnits").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("UserSpace").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("UserSpaceOnUse").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("ObjectBoundingBox").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("ClipPathUnits").ToLocalChecked(), constants);
}

bool Constants::ConvertClipPathUnits(const v8::Local<v8::Value> val, MagickCore::ClipPathUnits& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ClipPathUnits: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::ClipPathUnits::UndefinedPathUnits;
        return true;
    }
    if(input == 2) {
        out = MagickCore::ClipPathUnits::UserSpace;
        return true;
    }
    if(input == 3) {
        out = MagickCore::ClipPathUnits::UserSpaceOnUse;
        return true;
    }
    if(input == 4) {
        out = MagickCore::ClipPathUnits::ObjectBoundingBox;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ClipPathUnits").ToLocalChecked());
    return false;
}

static void SetDecorationTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedDecoration").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("NoDecoration").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("UnderlineDecoration").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("OverlineDecoration").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("LineThroughDecoration").ToLocalChecked(), Nan::New(5));
    Nan::Set(exports, Nan::New("DecorationType").ToLocalChecked(), constants);
}

bool Constants::ConvertDecorationType(const v8::Local<v8::Value> val, Magick::DecorationType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to DecorationType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::DecorationType::UndefinedDecoration;
        return true;
    }
    if(input == 2) {
        out = Magick::DecorationType::NoDecoration;
        return true;
    }
    if(input == 3) {
        out = Magick::DecorationType::UnderlineDecoration;
        return true;
    }
    if(input == 4) {
        out = Magick::DecorationType::OverlineDecoration;
        return true;
    }
    if(input == 5) {
        out = Magick::DecorationType::LineThroughDecoration;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to DecorationType").ToLocalChecked());
    return false;
}

static void SetDirectionTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedDirection").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("RightToLeftDirection").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("LeftToRightDirection").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("TopToBottomDirection").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("DirectionType").ToLocalChecked(), constants);
}

bool Constants::ConvertDirectionType(const v8::Local<v8::Value> val, Magick::DirectionType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to DirectionType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::DirectionType::UndefinedDirection;
        return true;
    }
    if(input == 2) {
        out = Magick::DirectionType::RightToLeftDirection;
        return true;
    }
    if(input == 3) {
        out = Magick::DirectionType::LeftToRightDirection;
        return true;
    }
    if(input == 4) {
        out = Magick::DirectionType::TopToBottomDirection;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to DirectionType").ToLocalChecked());
    return false;
}

static void SetFillRuleBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedRule").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("EvenOddRule").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("NonZeroRule").ToLocalChecked(), Nan::New(3));
    Nan::Set(exports, Nan::New("FillRule").ToLocalChecked(), constants);
}

bool Constants::ConvertFillRule(const v8::Local<v8::Value> val, Magick::FillRule& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to FillRule: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::FillRule::UndefinedRule;
        return true;
    }
    if(input == 2) {
        out = Magick::FillRule::EvenOddRule;
        return true;
    }
    if(input == 3) {
        out = Magick::FillRule::NonZeroRule;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to FillRule").ToLocalChecked());
    return false;
}

static void SetGradientTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedGradient").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("LinearGradient").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("RadialGradient").ToLocalChecked(), Nan::New(3));
    Nan::Set(exports, Nan::New("GradientType").ToLocalChecked(), constants);
}

bool Constants::ConvertGradientType(const v8::Local<v8::Value> val, MagickCore::GradientType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to GradientType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::GradientType::UndefinedGradient;
        return true;
    }
    if(input == 2) {
        out = MagickCore::GradientType::LinearGradient;
        return true;
    }
    if(input == 3) {
        out = MagickCore::GradientType::RadialGradient;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to GradientType").ToLocalChecked());
    return false;
}

static void SetLineCapBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedCap").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("ButtCap").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("RoundCap").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("SquareCap").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("LineCap").ToLocalChecked(), constants);
}

bool Constants::ConvertLineCap(const v8::Local<v8::Value> val, Magick::LineCap& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to LineCap: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::LineCap::UndefinedCap;
        return true;
    }
    if(input == 2) {
        out = Magick::LineCap::ButtCap;
        return true;
    }
    if(input == 3) {
        out = Magick::LineCap::RoundCap;
        return true;
    }
    if(input == 4) {
        out = Magick::LineCap::SquareCap;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to LineCap").ToLocalChecked());
    return false;
}

static void SetLineJoinBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedJoin").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("MiterJoin").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("RoundJoin").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("BevelJoin").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("LineJoin").ToLocalChecked(), constants);
}

bool Constants::ConvertLineJoin(const v8::Local<v8::Value> val, Magick::LineJoin& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to LineJoin: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::LineJoin::UndefinedJoin;
        return true;
    }
    if(input == 2) {
        out = Magick::LineJoin::MiterJoin;
        return true;
    }
    if(input == 3) {
        out = Magick::LineJoin::RoundJoin;
        return true;
    }
    if(input == 4) {
        out = Magick::LineJoin::BevelJoin;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to LineJoin").ToLocalChecked());
    return false;
}

static void SetPaintMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedMethod").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("PointMethod").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ReplaceMethod").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("FloodfillMethod").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("FillToBorderMethod").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("ResetMethod").ToLocalChecked(), Nan::New(6));
    Nan::Set(exports, Nan::New("PaintMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertPaintMethod(const v8::Local<v8::Value> val, Magick::PaintMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to PaintMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::PaintMethod::UndefinedMethod;
        return true;
    }
    if(input == 2) {
        out = Magick::PaintMethod::PointMethod;
        return true;
    }
    if(input == 3) {
        out = Magick::PaintMethod::ReplaceMethod;
        return true;
    }
    if(input == 4) {
        out = Magick::PaintMethod::FloodfillMethod;
        return true;
    }
    if(input == 5) {
        out = Magick::PaintMethod::FillToBorderMethod;
        return true;
    }
    if(input == 6) {
        out = Magick::PaintMethod::ResetMethod;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to PaintMethod").ToLocalChecked());
    return false;
}

static void SetPrimitiveTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedPrimitive").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("PointPrimitive").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("LinePrimitive").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("RectanglePrimitive").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("RoundRectanglePrimitive").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("ArcPrimitive").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("EllipsePrimitive").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("CirclePrimitive").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("PolylinePrimitive").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("PolygonPrimitive").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("BezierPrimitive").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("ColorPrimitive").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("MattePrimitive").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("TextPrimitive").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("ImagePrimitive").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("PathPrimitive").ToLocalChecked(), Nan::New(16));
    Nan::Set(exports, Nan::New("PrimitiveType").ToLocalChecked(), constants);
}

bool Constants::ConvertPrimitiveType(const v8::Local<v8::Value> val, MagickCore::PrimitiveType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to PrimitiveType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::PrimitiveType::UndefinedPrimitive;
        return true;
    }
    if(input == 2) {
        out = MagickCore::PrimitiveType::PointPrimitive;
        return true;
    }
    if(input == 3) {
        out = MagickCore::PrimitiveType::LinePrimitive;
        return true;
    }
    if(input == 4) {
        out = MagickCore::PrimitiveType::RectanglePrimitive;
        return true;
    }
    if(input == 5) {
        out = MagickCore::PrimitiveType::RoundRectanglePrimitive;
        return true;
    }
    if(input == 6) {
        out = MagickCore::PrimitiveType::ArcPrimitive;
        return true;
    }
    if(input == 7) {
        out = MagickCore::PrimitiveType::EllipsePrimitive;
        return true;
    }
    if(input == 8) {
        out = MagickCore::PrimitiveType::CirclePrimitive;
        return true;
    }
    if(input == 9) {
        out = MagickCore::PrimitiveType::PolylinePrimitive;
        return true;
    }
    if(input == 10) {
        out = MagickCore::PrimitiveType::PolygonPrimitive;
        return true;
    }
    if(input == 11) {
        out = MagickCore::PrimitiveType::BezierPrimitive;
        return true;
    }
    if(input == 12) {
        out = MagickCore::PrimitiveType::ColorPrimitive;
        return true;
    }
    if(input == 13) {
        out = MagickCore::PrimitiveType::MattePrimitive;
        return true;
    }
    if(input == 14) {
        out = MagickCore::PrimitiveType::TextPrimitive;
        return true;
    }
    if(input == 15) {
        out = MagickCore::PrimitiveType::ImagePrimitive;
        return true;
    }
    if(input == 16) {
        out = MagickCore::PrimitiveType::PathPrimitive;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to PrimitiveType").ToLocalChecked());
    return false;
}

static void SetReferenceTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedReference").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("GradientReference").ToLocalChecked(), Nan::New(2));
    Nan::Set(exports, Nan::New("ReferenceType").ToLocalChecked(), constants);
}

bool Constants::ConvertReferenceType(const v8::Local<v8::Value> val, MagickCore::ReferenceType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ReferenceType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::ReferenceType::UndefinedReference;
        return true;
    }
    if(input == 2) {
        out = MagickCore::ReferenceType::GradientReference;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ReferenceType").ToLocalChecked());
    return false;
}

static void SetSpreadMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedSpread").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("PadSpread").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ReflectSpread").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("RepeatSpread").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("SpreadMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertSpreadMethod(const v8::Local<v8::Value> val, MagickCore::SpreadMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to SpreadMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::SpreadMethod::UndefinedSpread;
        return true;
    }
    if(input == 2) {
        out = MagickCore::SpreadMethod::PadSpread;
        return true;
    }
    if(input == 3) {
        out = MagickCore::SpreadMethod::ReflectSpread;
        return true;
    }
    if(input == 4) {
        out = MagickCore::SpreadMethod::RepeatSpread;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to SpreadMethod").ToLocalChecked());
    return false;
}

static void SetDistortImageMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedDistortion").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("AffineDistortion").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("AffineProjectionDistortion").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("ScaleRotateTranslateDistortion").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("PerspectiveDistortion").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("PerspectiveProjectionDistortion").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("BilinearForwardDistortion").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("BilinearDistortion").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("BilinearReverseDistortion").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("PolynomialDistortion").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("ArcDistortion").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("PolarDistortion").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("DePolarDistortion").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("Cylinder2PlaneDistortion").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("Plane2CylinderDistortion").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("BarrelDistortion").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("BarrelInverseDistortion").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("ShepardsDistortion").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("ResizeDistortion").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("SentinelDistortion").ToLocalChecked(), Nan::New(20));
    Nan::Set(exports, Nan::New("DistortImageMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertDistortImageMethod(const v8::Local<v8::Value> val, Magick::DistortImageMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to DistortImageMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::DistortImageMethod::UndefinedDistortion;
        return true;
    }
    if(input == 2) {
        out = Magick::DistortImageMethod::AffineDistortion;
        return true;
    }
    if(input == 3) {
        out = Magick::DistortImageMethod::AffineProjectionDistortion;
        return true;
    }
    if(input == 4) {
        out = Magick::DistortImageMethod::ScaleRotateTranslateDistortion;
        return true;
    }
    if(input == 5) {
        out = Magick::DistortImageMethod::PerspectiveDistortion;
        return true;
    }
    if(input == 6) {
        out = Magick::DistortImageMethod::PerspectiveProjectionDistortion;
        return true;
    }
    if(input == 7) {
        out = Magick::DistortImageMethod::BilinearForwardDistortion;
        return true;
    }
    if(input == 8) {
        out = Magick::DistortImageMethod::BilinearDistortion;
        return true;
    }
    if(input == 9) {
        out = Magick::DistortImageMethod::BilinearReverseDistortion;
        return true;
    }
    if(input == 10) {
        out = Magick::DistortImageMethod::PolynomialDistortion;
        return true;
    }
    if(input == 11) {
        out = Magick::DistortImageMethod::ArcDistortion;
        return true;
    }
    if(input == 12) {
        out = Magick::DistortImageMethod::PolarDistortion;
        return true;
    }
    if(input == 13) {
        out = Magick::DistortImageMethod::DePolarDistortion;
        return true;
    }
    if(input == 14) {
        out = Magick::DistortImageMethod::Cylinder2PlaneDistortion;
        return true;
    }
    if(input == 15) {
        out = Magick::DistortImageMethod::Plane2CylinderDistortion;
        return true;
    }
    if(input == 16) {
        out = Magick::DistortImageMethod::BarrelDistortion;
        return true;
    }
    if(input == 17) {
        out = Magick::DistortImageMethod::BarrelInverseDistortion;
        return true;
    }
    if(input == 18) {
        out = Magick::DistortImageMethod::ShepardsDistortion;
        return true;
    }
    if(input == 19) {
        out = Magick::DistortImageMethod::ResizeDistortion;
        return true;
    }
    if(input == 20) {
        out = Magick::DistortImageMethod::SentinelDistortion;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to DistortImageMethod").ToLocalChecked());
    return false;
}

static void SetSparseColorMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedColorInterpolate").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("BarycentricColorInterpolate").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("BilinearColorInterpolate").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("PolynomialColorInterpolate").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("ShepardsColorInterpolate").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("VoronoiColorInterpolate").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("InverseColorInterpolate").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("ManhattanColorInterpolate").ToLocalChecked(), Nan::New(8));
    Nan::Set(exports, Nan::New("SparseColorMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertSparseColorMethod(const v8::Local<v8::Value> val, Magick::SparseColorMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to SparseColorMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::SparseColorMethod::UndefinedColorInterpolate;
        return true;
    }
    if(input == 2) {
        out = Magick::SparseColorMethod::BarycentricColorInterpolate;
        return true;
    }
    if(input == 3) {
        out = Magick::SparseColorMethod::BilinearColorInterpolate;
        return true;
    }
    if(input == 4) {
        out = Magick::SparseColorMethod::PolynomialColorInterpolate;
        return true;
    }
    if(input == 5) {
        out = Magick::SparseColorMethod::ShepardsColorInterpolate;
        return true;
    }
    if(input == 6) {
        out = Magick::SparseColorMethod::VoronoiColorInterpolate;
        return true;
    }
    if(input == 7) {
        out = Magick::SparseColorMethod::InverseColorInterpolate;
        return true;
    }
    if(input == 8) {
        out = Magick::SparseColorMethod::ManhattanColorInterpolate;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to SparseColorMethod").ToLocalChecked());
    return false;
}

static void SetMagickLayerMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedMagickLayerMethod").ToLocalChecked(), Nan::New(1));
    Nan::Set(exports, Nan::New("MagickLayerMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertMagickLayerMethod(const v8::Local<v8::Value> val, MagickCore::MagickLayerMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MagickLayerMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::MagickLayerMethod::UndefinedMagickLayerMethod;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MagickLayerMethod").ToLocalChecked());
    return false;
}

static void SetStorageTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedPixel").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("CharPixel").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("DoublePixel").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("FloatPixel").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("IntegerPixel").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("LongPixel").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("QuantumPixel").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("ShortPixel").ToLocalChecked(), Nan::New(8));
    Nan::Set(exports, Nan::New("StorageType").ToLocalChecked(), constants);
}

bool Constants::ConvertStorageType(const v8::Local<v8::Value> val, Magick::StorageType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to StorageType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::StorageType::UndefinedPixel;
        return true;
    }
    if(input == 2) {
        out = Magick::StorageType::CharPixel;
        return true;
    }
    if(input == 3) {
        out = Magick::StorageType::DoublePixel;
        return true;
    }
    if(input == 4) {
        out = Magick::StorageType::FloatPixel;
        return true;
    }
    if(input == 5) {
        out = Magick::StorageType::IntegerPixel;
        return true;
    }
    if(input == 6) {
        out = Magick::StorageType::LongPixel;
        return true;
    }
    if(input == 7) {
        out = Magick::StorageType::QuantumPixel;
        return true;
    }
    if(input == 8) {
        out = Magick::StorageType::ShortPixel;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to StorageType").ToLocalChecked());
    return false;
}

static void SetCompressionTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedCompression").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("NoCompression").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("BZipCompression").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("DXT1Compression").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("DXT3Compression").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("DXT5Compression").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("FaxCompression").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("Group4Compression").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("JPEGCompression").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("JPEG2000Compression").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("LosslessJPEGCompression").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("LZWCompression").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("RLECompression").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("ZipCompression").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("ZipSCompression").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("PizCompression").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("Pxr24Compression").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("B44Compression").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("B44ACompression").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("LZMACompression").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("JBIG1Compression").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("JBIG2Compression").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("ZstdCompression").ToLocalChecked(), Nan::New(23));
    Nan::Set(constants, Nan::New("WebPCompression").ToLocalChecked(), Nan::New(24));
    Nan::Set(exports, Nan::New("CompressionType").ToLocalChecked(), constants);
}

bool Constants::ConvertCompressionType(const v8::Local<v8::Value> val, Magick::CompressionType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to CompressionType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::CompressionType::UndefinedCompression;
        return true;
    }
    if(input == 2) {
        out = Magick::CompressionType::NoCompression;
        return true;
    }
    if(input == 3) {
        out = Magick::CompressionType::BZipCompression;
        return true;
    }
    if(input == 4) {
        out = Magick::CompressionType::DXT1Compression;
        return true;
    }
    if(input == 5) {
        out = Magick::CompressionType::DXT3Compression;
        return true;
    }
    if(input == 6) {
        out = Magick::CompressionType::DXT5Compression;
        return true;
    }
    if(input == 7) {
        out = Magick::CompressionType::FaxCompression;
        return true;
    }
    if(input == 8) {
        out = Magick::CompressionType::Group4Compression;
        return true;
    }
    if(input == 9) {
        out = Magick::CompressionType::JPEGCompression;
        return true;
    }
    if(input == 10) {
        out = Magick::CompressionType::JPEG2000Compression;
        return true;
    }
    if(input == 11) {
        out = Magick::CompressionType::LosslessJPEGCompression;
        return true;
    }
    if(input == 12) {
        out = Magick::CompressionType::LZWCompression;
        return true;
    }
    if(input == 13) {
        out = Magick::CompressionType::RLECompression;
        return true;
    }
    if(input == 14) {
        out = Magick::CompressionType::ZipCompression;
        return true;
    }
    if(input == 15) {
        out = Magick::CompressionType::ZipSCompression;
        return true;
    }
    if(input == 16) {
        out = Magick::CompressionType::PizCompression;
        return true;
    }
    if(input == 17) {
        out = Magick::CompressionType::Pxr24Compression;
        return true;
    }
    if(input == 18) {
        out = Magick::CompressionType::B44Compression;
        return true;
    }
    if(input == 19) {
        out = Magick::CompressionType::B44ACompression;
        return true;
    }
    if(input == 20) {
        out = Magick::CompressionType::LZMACompression;
        return true;
    }
    if(input == 21) {
        out = Magick::CompressionType::JBIG1Compression;
        return true;
    }
    if(input == 22) {
        out = Magick::CompressionType::JBIG2Compression;
        return true;
    }
    if(input == 23) {
        out = Magick::CompressionType::ZstdCompression;
        return true;
    }
    if(input == 24) {
        out = Magick::CompressionType::WebPCompression;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to CompressionType").ToLocalChecked());
    return false;
}

static void SetCompositeOperatorBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedCompositeOp").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("NoCompositeOp").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ModulusAddCompositeOp").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("AtopCompositeOp").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("BlendCompositeOp").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("BumpmapCompositeOp").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("ChangeMaskCompositeOp").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("ClearCompositeOp").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("ColorBurnCompositeOp").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("ColorDodgeCompositeOp").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("ColorizeCompositeOp").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("CopyBlackCompositeOp").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("CopyBlueCompositeOp").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("CopyCompositeOp").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("CopyCyanCompositeOp").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("CopyGreenCompositeOp").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("CopyMagentaCompositeOp").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("CopyOpacityCompositeOp").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("CopyRedCompositeOp").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("CopyYellowCompositeOp").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("DarkenCompositeOp").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("DstAtopCompositeOp").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("DstCompositeOp").ToLocalChecked(), Nan::New(23));
    Nan::Set(constants, Nan::New("DstInCompositeOp").ToLocalChecked(), Nan::New(24));
    Nan::Set(constants, Nan::New("DstOutCompositeOp").ToLocalChecked(), Nan::New(25));
    Nan::Set(constants, Nan::New("DstOverCompositeOp").ToLocalChecked(), Nan::New(26));
    Nan::Set(constants, Nan::New("DifferenceCompositeOp").ToLocalChecked(), Nan::New(27));
    Nan::Set(constants, Nan::New("DisplaceCompositeOp").ToLocalChecked(), Nan::New(28));
    Nan::Set(constants, Nan::New("DissolveCompositeOp").ToLocalChecked(), Nan::New(29));
    Nan::Set(constants, Nan::New("ExclusionCompositeOp").ToLocalChecked(), Nan::New(30));
    Nan::Set(constants, Nan::New("HardLightCompositeOp").ToLocalChecked(), Nan::New(31));
    Nan::Set(constants, Nan::New("HueCompositeOp").ToLocalChecked(), Nan::New(32));
    Nan::Set(constants, Nan::New("InCompositeOp").ToLocalChecked(), Nan::New(33));
    Nan::Set(constants, Nan::New("LightenCompositeOp").ToLocalChecked(), Nan::New(34));
    Nan::Set(constants, Nan::New("LinearLightCompositeOp").ToLocalChecked(), Nan::New(35));
    Nan::Set(constants, Nan::New("LuminizeCompositeOp").ToLocalChecked(), Nan::New(36));
    Nan::Set(constants, Nan::New("MinusDstCompositeOp").ToLocalChecked(), Nan::New(37));
    Nan::Set(constants, Nan::New("ModulateCompositeOp").ToLocalChecked(), Nan::New(38));
    Nan::Set(constants, Nan::New("MultiplyCompositeOp").ToLocalChecked(), Nan::New(39));
    Nan::Set(constants, Nan::New("OutCompositeOp").ToLocalChecked(), Nan::New(40));
    Nan::Set(constants, Nan::New("OverCompositeOp").ToLocalChecked(), Nan::New(41));
    Nan::Set(constants, Nan::New("OverlayCompositeOp").ToLocalChecked(), Nan::New(42));
    Nan::Set(constants, Nan::New("PlusCompositeOp").ToLocalChecked(), Nan::New(43));
    Nan::Set(constants, Nan::New("ReplaceCompositeOp").ToLocalChecked(), Nan::New(44));
    Nan::Set(constants, Nan::New("SaturateCompositeOp").ToLocalChecked(), Nan::New(45));
    Nan::Set(constants, Nan::New("ScreenCompositeOp").ToLocalChecked(), Nan::New(46));
    Nan::Set(constants, Nan::New("SoftLightCompositeOp").ToLocalChecked(), Nan::New(47));
    Nan::Set(constants, Nan::New("SrcAtopCompositeOp").ToLocalChecked(), Nan::New(48));
    Nan::Set(constants, Nan::New("SrcCompositeOp").ToLocalChecked(), Nan::New(49));
    Nan::Set(constants, Nan::New("SrcInCompositeOp").ToLocalChecked(), Nan::New(50));
    Nan::Set(constants, Nan::New("SrcOutCompositeOp").ToLocalChecked(), Nan::New(51));
    Nan::Set(constants, Nan::New("SrcOverCompositeOp").ToLocalChecked(), Nan::New(52));
    Nan::Set(constants, Nan::New("ModulusSubtractCompositeOp").ToLocalChecked(), Nan::New(53));
    Nan::Set(constants, Nan::New("ThresholdCompositeOp").ToLocalChecked(), Nan::New(54));
    Nan::Set(constants, Nan::New("XorCompositeOp").ToLocalChecked(), Nan::New(55));
    Nan::Set(constants, Nan::New("DivideDstCompositeOp").ToLocalChecked(), Nan::New(56));
    Nan::Set(constants, Nan::New("DistortCompositeOp").ToLocalChecked(), Nan::New(57));
    Nan::Set(constants, Nan::New("BlurCompositeOp").ToLocalChecked(), Nan::New(58));
    Nan::Set(constants, Nan::New("PegtopLightCompositeOp").ToLocalChecked(), Nan::New(59));
    Nan::Set(constants, Nan::New("VividLightCompositeOp").ToLocalChecked(), Nan::New(60));
    Nan::Set(constants, Nan::New("PinLightCompositeOp").ToLocalChecked(), Nan::New(61));
    Nan::Set(constants, Nan::New("LinearDodgeCompositeOp").ToLocalChecked(), Nan::New(62));
    Nan::Set(constants, Nan::New("LinearBurnCompositeOp").ToLocalChecked(), Nan::New(63));
    Nan::Set(constants, Nan::New("MathematicsCompositeOp").ToLocalChecked(), Nan::New(64));
    Nan::Set(constants, Nan::New("DivideSrcCompositeOp").ToLocalChecked(), Nan::New(65));
    Nan::Set(constants, Nan::New("MinusSrcCompositeOp").ToLocalChecked(), Nan::New(66));
    Nan::Set(constants, Nan::New("DarkenIntensityCompositeOp").ToLocalChecked(), Nan::New(67));
    Nan::Set(constants, Nan::New("LightenIntensityCompositeOp").ToLocalChecked(), Nan::New(68));
    Nan::Set(constants, Nan::New("HardMixCompositeOp").ToLocalChecked(), Nan::New(69));
    Nan::Set(constants, Nan::New("StereoCompositeOp").ToLocalChecked(), Nan::New(70));
    Nan::Set(exports, Nan::New("CompositeOperator").ToLocalChecked(), constants);
}

bool Constants::ConvertCompositeOperator(const v8::Local<v8::Value> val, Magick::CompositeOperator& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to CompositeOperator: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::CompositeOperator::UndefinedCompositeOp;
        return true;
    }
    if(input == 2) {
        out = Magick::CompositeOperator::NoCompositeOp;
        return true;
    }
    if(input == 3) {
        out = Magick::CompositeOperator::ModulusAddCompositeOp;
        return true;
    }
    if(input == 4) {
        out = Magick::CompositeOperator::AtopCompositeOp;
        return true;
    }
    if(input == 5) {
        out = Magick::CompositeOperator::BlendCompositeOp;
        return true;
    }
    if(input == 6) {
        out = Magick::CompositeOperator::BumpmapCompositeOp;
        return true;
    }
    if(input == 7) {
        out = Magick::CompositeOperator::ChangeMaskCompositeOp;
        return true;
    }
    if(input == 8) {
        out = Magick::CompositeOperator::ClearCompositeOp;
        return true;
    }
    if(input == 9) {
        out = Magick::CompositeOperator::ColorBurnCompositeOp;
        return true;
    }
    if(input == 10) {
        out = Magick::CompositeOperator::ColorDodgeCompositeOp;
        return true;
    }
    if(input == 11) {
        out = Magick::CompositeOperator::ColorizeCompositeOp;
        return true;
    }
    if(input == 12) {
        out = Magick::CompositeOperator::CopyBlackCompositeOp;
        return true;
    }
    if(input == 13) {
        out = Magick::CompositeOperator::CopyBlueCompositeOp;
        return true;
    }
    if(input == 14) {
        out = Magick::CompositeOperator::CopyCompositeOp;
        return true;
    }
    if(input == 15) {
        out = Magick::CompositeOperator::CopyCyanCompositeOp;
        return true;
    }
    if(input == 16) {
        out = Magick::CompositeOperator::CopyGreenCompositeOp;
        return true;
    }
    if(input == 17) {
        out = Magick::CompositeOperator::CopyMagentaCompositeOp;
        return true;
    }
    if(input == 18) {
        out = Magick::CompositeOperator::CopyOpacityCompositeOp;
        return true;
    }
    if(input == 19) {
        out = Magick::CompositeOperator::CopyRedCompositeOp;
        return true;
    }
    if(input == 20) {
        out = Magick::CompositeOperator::CopyYellowCompositeOp;
        return true;
    }
    if(input == 21) {
        out = Magick::CompositeOperator::DarkenCompositeOp;
        return true;
    }
    if(input == 22) {
        out = Magick::CompositeOperator::DstAtopCompositeOp;
        return true;
    }
    if(input == 23) {
        out = Magick::CompositeOperator::DstCompositeOp;
        return true;
    }
    if(input == 24) {
        out = Magick::CompositeOperator::DstInCompositeOp;
        return true;
    }
    if(input == 25) {
        out = Magick::CompositeOperator::DstOutCompositeOp;
        return true;
    }
    if(input == 26) {
        out = Magick::CompositeOperator::DstOverCompositeOp;
        return true;
    }
    if(input == 27) {
        out = Magick::CompositeOperator::DifferenceCompositeOp;
        return true;
    }
    if(input == 28) {
        out = Magick::CompositeOperator::DisplaceCompositeOp;
        return true;
    }
    if(input == 29) {
        out = Magick::CompositeOperator::DissolveCompositeOp;
        return true;
    }
    if(input == 30) {
        out = Magick::CompositeOperator::ExclusionCompositeOp;
        return true;
    }
    if(input == 31) {
        out = Magick::CompositeOperator::HardLightCompositeOp;
        return true;
    }
    if(input == 32) {
        out = Magick::CompositeOperator::HueCompositeOp;
        return true;
    }
    if(input == 33) {
        out = Magick::CompositeOperator::InCompositeOp;
        return true;
    }
    if(input == 34) {
        out = Magick::CompositeOperator::LightenCompositeOp;
        return true;
    }
    if(input == 35) {
        out = Magick::CompositeOperator::LinearLightCompositeOp;
        return true;
    }
    if(input == 36) {
        out = Magick::CompositeOperator::LuminizeCompositeOp;
        return true;
    }
    if(input == 37) {
        out = Magick::CompositeOperator::MinusDstCompositeOp;
        return true;
    }
    if(input == 38) {
        out = Magick::CompositeOperator::ModulateCompositeOp;
        return true;
    }
    if(input == 39) {
        out = Magick::CompositeOperator::MultiplyCompositeOp;
        return true;
    }
    if(input == 40) {
        out = Magick::CompositeOperator::OutCompositeOp;
        return true;
    }
    if(input == 41) {
        out = Magick::CompositeOperator::OverCompositeOp;
        return true;
    }
    if(input == 42) {
        out = Magick::CompositeOperator::OverlayCompositeOp;
        return true;
    }
    if(input == 43) {
        out = Magick::CompositeOperator::PlusCompositeOp;
        return true;
    }
    if(input == 44) {
        out = Magick::CompositeOperator::ReplaceCompositeOp;
        return true;
    }
    if(input == 45) {
        out = Magick::CompositeOperator::SaturateCompositeOp;
        return true;
    }
    if(input == 46) {
        out = Magick::CompositeOperator::ScreenCompositeOp;
        return true;
    }
    if(input == 47) {
        out = Magick::CompositeOperator::SoftLightCompositeOp;
        return true;
    }
    if(input == 48) {
        out = Magick::CompositeOperator::SrcAtopCompositeOp;
        return true;
    }
    if(input == 49) {
        out = Magick::CompositeOperator::SrcCompositeOp;
        return true;
    }
    if(input == 50) {
        out = Magick::CompositeOperator::SrcInCompositeOp;
        return true;
    }
    if(input == 51) {
        out = Magick::CompositeOperator::SrcOutCompositeOp;
        return true;
    }
    if(input == 52) {
        out = Magick::CompositeOperator::SrcOverCompositeOp;
        return true;
    }
    if(input == 53) {
        out = Magick::CompositeOperator::ModulusSubtractCompositeOp;
        return true;
    }
    if(input == 54) {
        out = Magick::CompositeOperator::ThresholdCompositeOp;
        return true;
    }
    if(input == 55) {
        out = Magick::CompositeOperator::XorCompositeOp;
        return true;
    }
    if(input == 56) {
        out = Magick::CompositeOperator::DivideDstCompositeOp;
        return true;
    }
    if(input == 57) {
        out = Magick::CompositeOperator::DistortCompositeOp;
        return true;
    }
    if(input == 58) {
        out = Magick::CompositeOperator::BlurCompositeOp;
        return true;
    }
    if(input == 59) {
        out = Magick::CompositeOperator::PegtopLightCompositeOp;
        return true;
    }
    if(input == 60) {
        out = Magick::CompositeOperator::VividLightCompositeOp;
        return true;
    }
    if(input == 61) {
        out = Magick::CompositeOperator::PinLightCompositeOp;
        return true;
    }
    if(input == 62) {
        out = Magick::CompositeOperator::LinearDodgeCompositeOp;
        return true;
    }
    if(input == 63) {
        out = Magick::CompositeOperator::LinearBurnCompositeOp;
        return true;
    }
    if(input == 64) {
        out = Magick::CompositeOperator::MathematicsCompositeOp;
        return true;
    }
    if(input == 65) {
        out = Magick::CompositeOperator::DivideSrcCompositeOp;
        return true;
    }
    if(input == 66) {
        out = Magick::CompositeOperator::MinusSrcCompositeOp;
        return true;
    }
    if(input == 67) {
        out = Magick::CompositeOperator::DarkenIntensityCompositeOp;
        return true;
    }
    if(input == 68) {
        out = Magick::CompositeOperator::LightenIntensityCompositeOp;
        return true;
    }
    if(input == 69) {
        out = Magick::CompositeOperator::HardMixCompositeOp;
        return true;
    }
    if(input == 70) {
        out = Magick::CompositeOperator::StereoCompositeOp;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to CompositeOperator").ToLocalChecked());
    return false;
}

static void SetMetricTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedMetric").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("AbsoluteErrorMetric").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("MeanAbsoluteErrorMetric").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("MeanErrorPerPixelMetric").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("MeanSquaredErrorMetric").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("PeakAbsoluteErrorMetric").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("PeakSignalToNoiseRatioMetric").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("RootMeanSquaredErrorMetric").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("NormalizedCrossCorrelationErrorMetric").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("FuzzErrorMetric").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("UndefinedErrorMetric").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("PerceptualHashErrorMetric").ToLocalChecked(), Nan::New(12));
    Nan::Set(exports, Nan::New("MetricType").ToLocalChecked(), constants);
}

bool Constants::ConvertMetricType(const v8::Local<v8::Value> val, Magick::MetricType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MetricType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::MetricType::UndefinedMetric;
        return true;
    }
    if(input == 2) {
        out = Magick::MetricType::AbsoluteErrorMetric;
        return true;
    }
    if(input == 3) {
        out = Magick::MetricType::MeanAbsoluteErrorMetric;
        return true;
    }
    if(input == 4) {
        out = Magick::MetricType::MeanErrorPerPixelMetric;
        return true;
    }
    if(input == 5) {
        out = Magick::MetricType::MeanSquaredErrorMetric;
        return true;
    }
    if(input == 6) {
        out = Magick::MetricType::PeakAbsoluteErrorMetric;
        return true;
    }
    if(input == 7) {
        out = Magick::MetricType::PeakSignalToNoiseRatioMetric;
        return true;
    }
    if(input == 8) {
        out = Magick::MetricType::RootMeanSquaredErrorMetric;
        return true;
    }
    if(input == 9) {
        out = Magick::MetricType::NormalizedCrossCorrelationErrorMetric;
        return true;
    }
    if(input == 10) {
        out = Magick::MetricType::FuzzErrorMetric;
        return true;
    }
    if(input == 11) {
        out = Magick::MetricType::UndefinedErrorMetric;
        return true;
    }
    if(input == 12) {
        out = Magick::MetricType::PerceptualHashErrorMetric;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MetricType").ToLocalChecked());
    return false;
}

static void SetColorspaceTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedColorspace").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("RGBColorspace").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("GRAYColorspace").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("TransparentColorspace").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("OHTAColorspace").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("LabColorspace").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("XYZColorspace").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("YCbCrColorspace").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("YCCColorspace").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("YIQColorspace").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("YPbPrColorspace").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("YUVColorspace").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("CMYKColorspace").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("sRGBColorspace").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("HSBColorspace").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("HSLColorspace").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("HWBColorspace").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("Rec601LumaColorspace").ToLocalChecked(), Nan::New(18));
    Nan::Set(constants, Nan::New("Rec601YCbCrColorspace").ToLocalChecked(), Nan::New(19));
    Nan::Set(constants, Nan::New("Rec709LumaColorspace").ToLocalChecked(), Nan::New(20));
    Nan::Set(constants, Nan::New("Rec709YCbCrColorspace").ToLocalChecked(), Nan::New(21));
    Nan::Set(constants, Nan::New("LogColorspace").ToLocalChecked(), Nan::New(22));
    Nan::Set(constants, Nan::New("CMYColorspace").ToLocalChecked(), Nan::New(23));
    Nan::Set(constants, Nan::New("LuvColorspace").ToLocalChecked(), Nan::New(24));
    Nan::Set(constants, Nan::New("HCLColorspace").ToLocalChecked(), Nan::New(25));
    Nan::Set(constants, Nan::New("LCHColorspace").ToLocalChecked(), Nan::New(26));
    Nan::Set(constants, Nan::New("LMSColorspace").ToLocalChecked(), Nan::New(27));
    Nan::Set(constants, Nan::New("LCHabColorspace").ToLocalChecked(), Nan::New(28));
    Nan::Set(constants, Nan::New("LCHuvColorspace").ToLocalChecked(), Nan::New(29));
    Nan::Set(constants, Nan::New("scRGBColorspace").ToLocalChecked(), Nan::New(30));
    Nan::Set(constants, Nan::New("HSIColorspace").ToLocalChecked(), Nan::New(31));
    Nan::Set(constants, Nan::New("HSVColorspace").ToLocalChecked(), Nan::New(32));
    Nan::Set(constants, Nan::New("HCLpColorspace").ToLocalChecked(), Nan::New(33));
    Nan::Set(constants, Nan::New("YDbDrColorspace").ToLocalChecked(), Nan::New(34));
    Nan::Set(constants, Nan::New("xyYColorspace").ToLocalChecked(), Nan::New(35));
    Nan::Set(constants, Nan::New("LinearGRAYColorspace").ToLocalChecked(), Nan::New(36));
    Nan::Set(exports, Nan::New("ColorspaceType").ToLocalChecked(), constants);
}

bool Constants::ConvertColorspaceType(const v8::Local<v8::Value> val, Magick::ColorspaceType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ColorspaceType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::ColorspaceType::UndefinedColorspace;
        return true;
    }
    if(input == 2) {
        out = Magick::ColorspaceType::RGBColorspace;
        return true;
    }
    if(input == 3) {
        out = Magick::ColorspaceType::GRAYColorspace;
        return true;
    }
    if(input == 4) {
        out = Magick::ColorspaceType::TransparentColorspace;
        return true;
    }
    if(input == 5) {
        out = Magick::ColorspaceType::OHTAColorspace;
        return true;
    }
    if(input == 6) {
        out = Magick::ColorspaceType::LabColorspace;
        return true;
    }
    if(input == 7) {
        out = Magick::ColorspaceType::XYZColorspace;
        return true;
    }
    if(input == 8) {
        out = Magick::ColorspaceType::YCbCrColorspace;
        return true;
    }
    if(input == 9) {
        out = Magick::ColorspaceType::YCCColorspace;
        return true;
    }
    if(input == 10) {
        out = Magick::ColorspaceType::YIQColorspace;
        return true;
    }
    if(input == 11) {
        out = Magick::ColorspaceType::YPbPrColorspace;
        return true;
    }
    if(input == 12) {
        out = Magick::ColorspaceType::YUVColorspace;
        return true;
    }
    if(input == 13) {
        out = Magick::ColorspaceType::CMYKColorspace;
        return true;
    }
    if(input == 14) {
        out = Magick::ColorspaceType::sRGBColorspace;
        return true;
    }
    if(input == 15) {
        out = Magick::ColorspaceType::HSBColorspace;
        return true;
    }
    if(input == 16) {
        out = Magick::ColorspaceType::HSLColorspace;
        return true;
    }
    if(input == 17) {
        out = Magick::ColorspaceType::HWBColorspace;
        return true;
    }
    if(input == 18) {
        out = Magick::ColorspaceType::Rec601LumaColorspace;
        return true;
    }
    if(input == 19) {
        out = Magick::ColorspaceType::Rec601YCbCrColorspace;
        return true;
    }
    if(input == 20) {
        out = Magick::ColorspaceType::Rec709LumaColorspace;
        return true;
    }
    if(input == 21) {
        out = Magick::ColorspaceType::Rec709YCbCrColorspace;
        return true;
    }
    if(input == 22) {
        out = Magick::ColorspaceType::LogColorspace;
        return true;
    }
    if(input == 23) {
        out = Magick::ColorspaceType::CMYColorspace;
        return true;
    }
    if(input == 24) {
        out = Magick::ColorspaceType::LuvColorspace;
        return true;
    }
    if(input == 25) {
        out = Magick::ColorspaceType::HCLColorspace;
        return true;
    }
    if(input == 26) {
        out = Magick::ColorspaceType::LCHColorspace;
        return true;
    }
    if(input == 27) {
        out = Magick::ColorspaceType::LMSColorspace;
        return true;
    }
    if(input == 28) {
        out = Magick::ColorspaceType::LCHabColorspace;
        return true;
    }
    if(input == 29) {
        out = Magick::ColorspaceType::LCHuvColorspace;
        return true;
    }
    if(input == 30) {
        out = Magick::ColorspaceType::scRGBColorspace;
        return true;
    }
    if(input == 31) {
        out = Magick::ColorspaceType::HSIColorspace;
        return true;
    }
    if(input == 32) {
        out = Magick::ColorspaceType::HSVColorspace;
        return true;
    }
    if(input == 33) {
        out = Magick::ColorspaceType::HCLpColorspace;
        return true;
    }
    if(input == 34) {
        out = Magick::ColorspaceType::YDbDrColorspace;
        return true;
    }
    if(input == 35) {
        out = Magick::ColorspaceType::xyYColorspace;
        return true;
    }
    if(input == 36) {
        out = Magick::ColorspaceType::LinearGRAYColorspace;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ColorspaceType").ToLocalChecked());
    return false;
}

static void SetComplianceTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedCompliance").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("NoCompliance").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("CSSCompliance").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("SVGCompliance").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("X11Compliance").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("XPMCompliance").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("MVGCompliance").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("AllCompliance").ToLocalChecked(), Nan::New(8));
    Nan::Set(exports, Nan::New("ComplianceType").ToLocalChecked(), constants);
}

bool Constants::ConvertComplianceType(const v8::Local<v8::Value> val, MagickCore::ComplianceType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to ComplianceType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::ComplianceType::UndefinedCompliance;
        return true;
    }
    if(input == 2) {
        out = MagickCore::ComplianceType::NoCompliance;
        return true;
    }
    if(input == 3) {
        out = MagickCore::ComplianceType::CSSCompliance;
        return true;
    }
    if(input == 4) {
        out = MagickCore::ComplianceType::SVGCompliance;
        return true;
    }
    if(input == 5) {
        out = MagickCore::ComplianceType::X11Compliance;
        return true;
    }
    if(input == 6) {
        out = MagickCore::ComplianceType::XPMCompliance;
        return true;
    }
    if(input == 7) {
        out = MagickCore::ComplianceType::MVGCompliance;
        return true;
    }
    if(input == 8) {
        out = MagickCore::ComplianceType::AllCompliance;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to ComplianceType").ToLocalChecked());
    return false;
}

static void SetCacheTypeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedCache").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("MemoryCache").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("MapCache").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("DiskCache").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("PingCache").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("DistributedCache").ToLocalChecked(), Nan::New(6));
    Nan::Set(exports, Nan::New("CacheType").ToLocalChecked(), constants);
}

bool Constants::ConvertCacheType(const v8::Local<v8::Value> val, MagickCore::CacheType& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to CacheType: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::CacheType::UndefinedCache;
        return true;
    }
    if(input == 2) {
        out = MagickCore::CacheType::MemoryCache;
        return true;
    }
    if(input == 3) {
        out = MagickCore::CacheType::MapCache;
        return true;
    }
    if(input == 4) {
        out = MagickCore::CacheType::DiskCache;
        return true;
    }
    if(input == 5) {
        out = MagickCore::CacheType::PingCache;
        return true;
    }
    if(input == 6) {
        out = MagickCore::CacheType::DistributedCache;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to CacheType").ToLocalChecked());
    return false;
}

static void SetVirtualPixelMethodBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("UndefinedVirtualPixelMethod").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("BackgroundVirtualPixelMethod").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("ConstantVirtualPixelMethod").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("DitherVirtualPixelMethod").ToLocalChecked(), Nan::New(4));
    Nan::Set(constants, Nan::New("EdgeVirtualPixelMethod").ToLocalChecked(), Nan::New(5));
    Nan::Set(constants, Nan::New("MirrorVirtualPixelMethod").ToLocalChecked(), Nan::New(6));
    Nan::Set(constants, Nan::New("RandomVirtualPixelMethod").ToLocalChecked(), Nan::New(7));
    Nan::Set(constants, Nan::New("TileVirtualPixelMethod").ToLocalChecked(), Nan::New(8));
    Nan::Set(constants, Nan::New("TransparentVirtualPixelMethod").ToLocalChecked(), Nan::New(9));
    Nan::Set(constants, Nan::New("MaskVirtualPixelMethod").ToLocalChecked(), Nan::New(10));
    Nan::Set(constants, Nan::New("BlackVirtualPixelMethod").ToLocalChecked(), Nan::New(11));
    Nan::Set(constants, Nan::New("GrayVirtualPixelMethod").ToLocalChecked(), Nan::New(12));
    Nan::Set(constants, Nan::New("WhiteVirtualPixelMethod").ToLocalChecked(), Nan::New(13));
    Nan::Set(constants, Nan::New("HorizontalTileVirtualPixelMethod").ToLocalChecked(), Nan::New(14));
    Nan::Set(constants, Nan::New("VerticalTileVirtualPixelMethod").ToLocalChecked(), Nan::New(15));
    Nan::Set(constants, Nan::New("HorizontalTileEdgeVirtualPixelMethod").ToLocalChecked(), Nan::New(16));
    Nan::Set(constants, Nan::New("VerticalTileEdgeVirtualPixelMethod").ToLocalChecked(), Nan::New(17));
    Nan::Set(constants, Nan::New("CheckerTileVirtualPixelMethod").ToLocalChecked(), Nan::New(18));
    Nan::Set(exports, Nan::New("VirtualPixelMethod").ToLocalChecked(), constants);
}

bool Constants::ConvertVirtualPixelMethod(const v8::Local<v8::Value> val, Magick::VirtualPixelMethod& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to VirtualPixelMethod: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = Magick::VirtualPixelMethod::UndefinedVirtualPixelMethod;
        return true;
    }
    if(input == 2) {
        out = Magick::VirtualPixelMethod::BackgroundVirtualPixelMethod;
        return true;
    }
    if(input == 3) {
        out = Magick::VirtualPixelMethod::ConstantVirtualPixelMethod;
        return true;
    }
    if(input == 4) {
        out = Magick::VirtualPixelMethod::DitherVirtualPixelMethod;
        return true;
    }
    if(input == 5) {
        out = Magick::VirtualPixelMethod::EdgeVirtualPixelMethod;
        return true;
    }
    if(input == 6) {
        out = Magick::VirtualPixelMethod::MirrorVirtualPixelMethod;
        return true;
    }
    if(input == 7) {
        out = Magick::VirtualPixelMethod::RandomVirtualPixelMethod;
        return true;
    }
    if(input == 8) {
        out = Magick::VirtualPixelMethod::TileVirtualPixelMethod;
        return true;
    }
    if(input == 9) {
        out = Magick::VirtualPixelMethod::TransparentVirtualPixelMethod;
        return true;
    }
    if(input == 10) {
        out = Magick::VirtualPixelMethod::MaskVirtualPixelMethod;
        return true;
    }
    if(input == 11) {
        out = Magick::VirtualPixelMethod::BlackVirtualPixelMethod;
        return true;
    }
    if(input == 12) {
        out = Magick::VirtualPixelMethod::GrayVirtualPixelMethod;
        return true;
    }
    if(input == 13) {
        out = Magick::VirtualPixelMethod::WhiteVirtualPixelMethod;
        return true;
    }
    if(input == 14) {
        out = Magick::VirtualPixelMethod::HorizontalTileVirtualPixelMethod;
        return true;
    }
    if(input == 15) {
        out = Magick::VirtualPixelMethod::VerticalTileVirtualPixelMethod;
        return true;
    }
    if(input == 16) {
        out = Magick::VirtualPixelMethod::HorizontalTileEdgeVirtualPixelMethod;
        return true;
    }
    if(input == 17) {
        out = Magick::VirtualPixelMethod::VerticalTileEdgeVirtualPixelMethod;
        return true;
    }
    if(input == 18) {
        out = Magick::VirtualPixelMethod::CheckerTileVirtualPixelMethod;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to VirtualPixelMethod").ToLocalChecked());
    return false;
}

static void SetMapModeBindingConstants(const v8::Local<v8::Object> exports) {
    auto constants = Nan::New<v8::Object>();
    Nan::Set(constants, Nan::New("ReadMode").ToLocalChecked(), Nan::New(1));
    Nan::Set(constants, Nan::New("WriteMode").ToLocalChecked(), Nan::New(2));
    Nan::Set(constants, Nan::New("IOMode").ToLocalChecked(), Nan::New(3));
    Nan::Set(constants, Nan::New("PersistMode").ToLocalChecked(), Nan::New(4));
    Nan::Set(exports, Nan::New("MapMode").ToLocalChecked(), constants);
}

bool Constants::ConvertMapMode(const v8::Local<v8::Value> val, MagickCore::MapMode& out) {
    if(!val->IsUint32()) {
        Nan::ThrowError(Nan::New("Failed to convert to MapMode: Expected a valid unsigned 32-bit integer").ToLocalChecked());
        return false;
    }
    const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();
    if(input == 1) {
        out = MagickCore::MapMode::ReadMode;
        return true;
    }
    if(input == 2) {
        out = MagickCore::MapMode::WriteMode;
        return true;
    }
    if(input == 3) {
        out = MagickCore::MapMode::IOMode;
        return true;
    }
    if(input == 4) {
        out = MagickCore::MapMode::PersistMode;
        return true;
    }
    Nan::ThrowError(Nan::New("Failed to convert " + std::to_string(input) + " to MapMode").ToLocalChecked());
    return false;
}
void Constants::Init(const v8::Local<v8::Object> exports) {
    SetNoiseTypeBindingConstants(exports);
    SetPathTypeBindingConstants(exports);
    SetStretchTypeBindingConstants(exports);
    SetStyleTypeBindingConstants(exports);
    SetTimerStateBindingConstants(exports);
    SetAutoThresholdMethodBindingConstants(exports);
    SetMagickEvaluateOperatorBindingConstants(exports);
    SetMagickFunctionBindingConstants(exports);
    SetStatisticTypeBindingConstants(exports);
    SetResourceTypeBindingConstants(exports);
    SetFilterTypesBindingConstants(exports);
    SetRegistryTypeBindingConstants(exports);
    SetEndianTypeBindingConstants(exports);
    SetQuantumAlphaTypeBindingConstants(exports);
    SetQuantumFormatTypeBindingConstants(exports);
    SetQuantumTypeBindingConstants(exports);
    SetDitherMethodBindingConstants(exports);
    SetRenderingIntentBindingConstants(exports);
    SetPolicyDomainBindingConstants(exports);
    SetPolicyRightsBindingConstants(exports);
    SetInterpolatePixelMethodBindingConstants(exports);
    SetPixelComponentBindingConstants(exports);
    SetPixelIntensityMethodBindingConstants(exports);
    SetCommandOptionBindingConstants(exports);
    SetValidateTypeBindingConstants(exports);
    SetCommandOptionFlagsBindingConstants(exports);
    SetMagickOpenCLProgramBindingConstants(exports);
    SetImageMagickOpenCLModeBindingConstants(exports);
    SetMagickOpenCLEnvParamBindingConstants(exports);
    SetKernelInfoTypeBindingConstants(exports);
    SetMorphologyMethodBindingConstants(exports);
    SetMontageModeBindingConstants(exports);
    SetMagickModuleTypeBindingConstants(exports);
    SetMagickFormatTypeBindingConstants(exports);
    SetMagickThreadSupportBindingConstants(exports);
    SetChannelTypeBindingConstants(exports);
    SetClassTypeBindingConstants(exports);
    SetMagickBooleanTypeBindingConstants(exports);
    SetLogEventTypeBindingConstants(exports);
    SetDisposeTypeBindingConstants(exports);
    SetImageLayerMethodBindingConstants(exports);
    SetAlphaChannelTypeBindingConstants(exports);
    SetImageTypeBindingConstants(exports);
    SetInterlaceTypeBindingConstants(exports);
    SetOrientationTypeBindingConstants(exports);
    SetResolutionTypeBindingConstants(exports);
    SetTransmitTypeBindingConstants(exports);
    SetGeometryFlagsBindingConstants(exports);
    SetGravityTypeBindingConstants(exports);
    SetComplexOperatorBindingConstants(exports);
    SetExceptionTypeBindingConstants(exports);
    SetPreviewTypeBindingConstants(exports);
    SetAlignTypeBindingConstants(exports);
    SetClipPathUnitsBindingConstants(exports);
    SetDecorationTypeBindingConstants(exports);
    SetDirectionTypeBindingConstants(exports);
    SetFillRuleBindingConstants(exports);
    SetGradientTypeBindingConstants(exports);
    SetLineCapBindingConstants(exports);
    SetLineJoinBindingConstants(exports);
    SetPaintMethodBindingConstants(exports);
    SetPrimitiveTypeBindingConstants(exports);
    SetReferenceTypeBindingConstants(exports);
    SetSpreadMethodBindingConstants(exports);
    SetDistortImageMethodBindingConstants(exports);
    SetSparseColorMethodBindingConstants(exports);
    SetMagickLayerMethodBindingConstants(exports);
    SetStorageTypeBindingConstants(exports);
    SetCompressionTypeBindingConstants(exports);
    SetCompositeOperatorBindingConstants(exports);
    SetMetricTypeBindingConstants(exports);
    SetColorspaceTypeBindingConstants(exports);
    SetComplianceTypeBindingConstants(exports);
    SetCacheTypeBindingConstants(exports);
    SetVirtualPixelMethodBindingConstants(exports);
    SetMapModeBindingConstants(exports);
}
