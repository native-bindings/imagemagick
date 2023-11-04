#ifndef NODE_IMAGEMAGICK_CONSTANTS_H_
#define NODE_IMAGEMAGICK_CONSTANTS_H_

#include <Magick++.h>
#include <nan.h>

class Constants {
public:
    [[nodiscard]] static bool ConvertNoiseType(v8::Local<v8::Value> val, Magick::NoiseType& out);
    [[nodiscard]] static bool ConvertPathType(v8::Local<v8::Value> val, MagickCore::PathType& out);
    [[nodiscard]] static bool ConvertStretchType(v8::Local<v8::Value> val, Magick::StretchType& out);
    [[nodiscard]] static bool ConvertStyleType(v8::Local<v8::Value> val, Magick::StyleType& out);
    [[nodiscard]] static bool ConvertTimerState(v8::Local<v8::Value> val, MagickCore::TimerState& out);
    [[nodiscard]] static bool ConvertAutoThresholdMethod(v8::Local<v8::Value> val, MagickCore::AutoThresholdMethod& out);
    [[nodiscard]] static bool ConvertMagickEvaluateOperator(v8::Local<v8::Value> val, Magick::MagickEvaluateOperator& out);
    [[nodiscard]] static bool ConvertMagickFunction(v8::Local<v8::Value> val, Magick::MagickFunction& out);
    [[nodiscard]] static bool ConvertStatisticType(v8::Local<v8::Value> val, MagickCore::StatisticType& out);
    [[nodiscard]] static bool ConvertResourceType(v8::Local<v8::Value> val, Magick::ResourceType& out);
    [[nodiscard]] static bool ConvertFilterTypes(v8::Local<v8::Value> val, Magick::FilterTypes& out);
    [[nodiscard]] static bool ConvertRegistryType(v8::Local<v8::Value> val, MagickCore::RegistryType& out);
    [[nodiscard]] static bool ConvertEndianType(v8::Local<v8::Value> val, Magick::EndianType& out);
    [[nodiscard]] static bool ConvertQuantumAlphaType(v8::Local<v8::Value> val, MagickCore::QuantumAlphaType& out);
    [[nodiscard]] static bool ConvertQuantumFormatType(v8::Local<v8::Value> val, MagickCore::QuantumFormatType& out);
    [[nodiscard]] static bool ConvertQuantumType(v8::Local<v8::Value> val, Magick::QuantumType& out);
    [[nodiscard]] static bool ConvertDitherMethod(v8::Local<v8::Value> val, Magick::DitherMethod& out);
    [[nodiscard]] static bool ConvertRenderingIntent(v8::Local<v8::Value> val, Magick::RenderingIntent& out);
    [[nodiscard]] static bool ConvertPolicyDomain(v8::Local<v8::Value> val, MagickCore::PolicyDomain& out);
    [[nodiscard]] static bool ConvertPolicyRights(v8::Local<v8::Value> val, MagickCore::PolicyRights& out);
    [[nodiscard]] static bool ConvertInterpolatePixelMethod(v8::Local<v8::Value> val, Magick::InterpolatePixelMethod& out);
    [[nodiscard]] static bool ConvertPixelComponent(v8::Local<v8::Value> val, MagickCore::PixelComponent& out);
    [[nodiscard]] static bool ConvertPixelIntensityMethod(v8::Local<v8::Value> val, Magick::PixelIntensityMethod& out);
    [[nodiscard]] static bool ConvertCommandOption(v8::Local<v8::Value> val, Magick::CommandOption& out);
    [[nodiscard]] static bool ConvertValidateType(v8::Local<v8::Value> val, MagickCore::ValidateType& out);
    [[nodiscard]] static bool ConvertCommandOptionFlags(v8::Local<v8::Value> val, MagickCore::CommandOptionFlags& out);
    [[nodiscard]] static bool ConvertMagickOpenCLProgram(v8::Local<v8::Value> val, MagickCore::MagickOpenCLProgram& out);
    [[nodiscard]] static bool ConvertImageMagickOpenCLMode(v8::Local<v8::Value> val, MagickCore::ImageMagickOpenCLMode& out);
    [[nodiscard]] static bool ConvertMagickOpenCLEnvParam(v8::Local<v8::Value> val, MagickCore::MagickOpenCLEnvParam& out);
    [[nodiscard]] static bool ConvertKernelInfoType(v8::Local<v8::Value> val, Magick::KernelInfoType& out);
    [[nodiscard]] static bool ConvertMorphologyMethod(v8::Local<v8::Value> val, Magick::MorphologyMethod& out);
    [[nodiscard]] static bool ConvertMontageMode(v8::Local<v8::Value> val, MagickCore::MontageMode& out);
    [[nodiscard]] static bool ConvertMagickModuleType(v8::Local<v8::Value> val, MagickCore::MagickModuleType& out);
    [[nodiscard]] static bool ConvertMagickFormatType(v8::Local<v8::Value> val, MagickCore::MagickFormatType& out);
    [[nodiscard]] static bool ConvertMagickThreadSupport(v8::Local<v8::Value> val, MagickCore::MagickThreadSupport& out);
    [[nodiscard]] static bool ConvertChannelType(v8::Local<v8::Value> val, Magick::ChannelType& out);
    [[nodiscard]] static bool ConvertClassType(v8::Local<v8::Value> val, Magick::ClassType& out);
    [[nodiscard]] static bool ConvertMagickBooleanType(v8::Local<v8::Value> val, Magick::MagickBooleanType& out);
    [[nodiscard]] static bool ConvertLogEventType(v8::Local<v8::Value> val, Magick::LogEventType& out);
    [[nodiscard]] static bool ConvertDisposeType(v8::Local<v8::Value> val, Magick::DisposeType& out);
    [[nodiscard]] static bool ConvertImageLayerMethod(v8::Local<v8::Value> val, Magick::ImageLayerMethod& out);
    [[nodiscard]] static bool ConvertAlphaChannelType(v8::Local<v8::Value> val, Magick::AlphaChannelType& out);
    [[nodiscard]] static bool ConvertImageType(v8::Local<v8::Value> val, Magick::ImageType& out);
    [[nodiscard]] static bool ConvertInterlaceType(v8::Local<v8::Value> val, Magick::InterlaceType& out);
    [[nodiscard]] static bool ConvertOrientationType(v8::Local<v8::Value> val, Magick::OrientationType& out);
    [[nodiscard]] static bool ConvertResolutionType(v8::Local<v8::Value> val, Magick::ResolutionType& out);
    [[nodiscard]] static bool ConvertTransmitType(v8::Local<v8::Value> val, MagickCore::TransmitType& out);
    [[nodiscard]] static bool ConvertGeometryFlags(v8::Local<v8::Value> val, MagickCore::GeometryFlags& out);
    [[nodiscard]] static bool ConvertGravityType(v8::Local<v8::Value> val, Magick::GravityType& out);
    [[nodiscard]] static bool ConvertComplexOperator(v8::Local<v8::Value> val, MagickCore::ComplexOperator& out);
    [[nodiscard]] static bool ConvertExceptionType(v8::Local<v8::Value> val, MagickCore::ExceptionType& out);
    [[nodiscard]] static bool ConvertPreviewType(v8::Local<v8::Value> val, Magick::PreviewType& out);
    [[nodiscard]] static bool ConvertAlignType(v8::Local<v8::Value> val, MagickCore::AlignType& out);
    [[nodiscard]] static bool ConvertClipPathUnits(v8::Local<v8::Value> val, MagickCore::ClipPathUnits& out);
    [[nodiscard]] static bool ConvertDecorationType(v8::Local<v8::Value> val, Magick::DecorationType& out);
    [[nodiscard]] static bool ConvertDirectionType(v8::Local<v8::Value> val, Magick::DirectionType& out);
    [[nodiscard]] static bool ConvertFillRule(v8::Local<v8::Value> val, Magick::FillRule& out);
    [[nodiscard]] static bool ConvertGradientType(v8::Local<v8::Value> val, MagickCore::GradientType& out);
    [[nodiscard]] static bool ConvertLineCap(v8::Local<v8::Value> val, Magick::LineCap& out);
    [[nodiscard]] static bool ConvertLineJoin(v8::Local<v8::Value> val, Magick::LineJoin& out);
    [[nodiscard]] static bool ConvertPaintMethod(v8::Local<v8::Value> val, Magick::PaintMethod& out);
    [[nodiscard]] static bool ConvertPrimitiveType(v8::Local<v8::Value> val, MagickCore::PrimitiveType& out);
    [[nodiscard]] static bool ConvertReferenceType(v8::Local<v8::Value> val, MagickCore::ReferenceType& out);
    [[nodiscard]] static bool ConvertSpreadMethod(v8::Local<v8::Value> val, MagickCore::SpreadMethod& out);
    [[nodiscard]] static bool ConvertDistortImageMethod(v8::Local<v8::Value> val, Magick::DistortImageMethod& out);
    [[nodiscard]] static bool ConvertSparseColorMethod(v8::Local<v8::Value> val, Magick::SparseColorMethod& out);
    [[nodiscard]] static bool ConvertMagickLayerMethod(v8::Local<v8::Value> val, MagickCore::MagickLayerMethod& out);
    [[nodiscard]] static bool ConvertStorageType(v8::Local<v8::Value> val, Magick::StorageType& out);
    [[nodiscard]] static bool ConvertCompressionType(v8::Local<v8::Value> val, Magick::CompressionType& out);
    [[nodiscard]] static bool ConvertCompositeOperator(v8::Local<v8::Value> val, Magick::CompositeOperator& out);
    [[nodiscard]] static bool ConvertMetricType(v8::Local<v8::Value> val, Magick::MetricType& out);
    [[nodiscard]] static bool ConvertColorspaceType(v8::Local<v8::Value> val, Magick::ColorspaceType& out);
    [[nodiscard]] static bool ConvertComplianceType(v8::Local<v8::Value> val, MagickCore::ComplianceType& out);
    [[nodiscard]] static bool ConvertCacheType(v8::Local<v8::Value> val, MagickCore::CacheType& out);
    [[nodiscard]] static bool ConvertVirtualPixelMethod(v8::Local<v8::Value> val, Magick::VirtualPixelMethod& out);
    [[nodiscard]] static bool ConvertMapMode(v8::Local<v8::Value> val, MagickCore::MapMode& out);
    static void Init(v8::Local<v8::Object> exports);
};

#endif // NODE_IMAGEMAGICK_CONSTANTS_H_
