"use strict";
Object.defineProperty(exports, "__esModule", { value: true });

exports.ChannelType = void 0;
var ChannelType;
(function (ChannelType) {
    ChannelType[ChannelType["UndefinedChannel"] = 0] = "UndefinedChannel";
    ChannelType[ChannelType["RedChannel"] = 1] = "RedChannel";
    ChannelType[ChannelType["GrayChannel"] = 1] = "GrayChannel";
    ChannelType[ChannelType["CyanChannel"] = 1] = "CyanChannel";
    ChannelType[ChannelType["LChannel"] = 1] = "LChannel";
    ChannelType[ChannelType["GreenChannel"] = 2] = "GreenChannel";
    ChannelType[ChannelType["MagentaChannel"] = 2] = "MagentaChannel";
    ChannelType[ChannelType["aChannel"] = 2] = "aChannel";
    ChannelType[ChannelType["BlueChannel"] = 4] = "BlueChannel";
    ChannelType[ChannelType["bChannel"] = 2] = "bChannel";
    ChannelType[ChannelType["YellowChannel"] = 4] = "YellowChannel";
    ChannelType[ChannelType["BlackChannel"] = 8] = "BlackChannel";
    ChannelType[ChannelType["AlphaChannel"] = 16] = "AlphaChannel";
    ChannelType[ChannelType["OpacityChannel"] = 16] = "OpacityChannel";
    ChannelType[ChannelType["IndexChannel"] = 32] = "IndexChannel";
    ChannelType[ChannelType["ReadMaskChannel"] = 64] = "ReadMaskChannel";
    ChannelType[ChannelType["WriteMaskChannel"] = 128] = "WriteMaskChannel";
    ChannelType[ChannelType["MetaChannel"] = 256] = "MetaChannel";
    ChannelType[ChannelType["CompositeMaskChannel"] = 512] = "CompositeMaskChannel";
    ChannelType[ChannelType["CompositeChannels"] = 31] = "CompositeChannels";
    ChannelType[ChannelType["AllChannels"] = 134217727] = "AllChannels";
    /*
        Special purpose channel types.
        FUTURE: are these needed any more - they are more like hacks
        SyncChannels for example is NOT a real channel but a 'flag'
        It really says -- "User has not defined channels"
        Though it does have extra meaning in the "-auto-level" operator
    */
    ChannelType[ChannelType["TrueAlphaChannel"] = 256] = "TrueAlphaChannel";
    ChannelType[ChannelType["RGBChannels"] = 512] = "RGBChannels";
    ChannelType[ChannelType["GrayChannels"] = 1024] = "GrayChannels";
    ChannelType[ChannelType["SyncChannels"] = 131072] = "SyncChannels";
    ChannelType[ChannelType["DefaultChannels"] = 134217727] = "DefaultChannels";
})(ChannelType = exports.ChannelType || (exports.ChannelType = {}));

exports.MetricType = void 0;
var MetricType;
(function (MetricType) {
    MetricType[MetricType["UndefinedErrorMetric"] = 0] = "UndefinedErrorMetric";
    MetricType[MetricType["AbsoluteErrorMetric"] = 1] = "AbsoluteErrorMetric";
    MetricType[MetricType["FuzzErrorMetric"] = 2] = "FuzzErrorMetric";
    MetricType[MetricType["MeanAbsoluteErrorMetric"] = 3] = "MeanAbsoluteErrorMetric";
    MetricType[MetricType["MeanErrorPerPixelErrorMetric"] = 4] = "MeanErrorPerPixelErrorMetric";
    MetricType[MetricType["MeanSquaredErrorMetric"] = 5] = "MeanSquaredErrorMetric";
    MetricType[MetricType["NormalizedCrossCorrelationErrorMetric"] = 6] = "NormalizedCrossCorrelationErrorMetric";
    MetricType[MetricType["PeakAbsoluteErrorMetric"] = 7] = "PeakAbsoluteErrorMetric";
    MetricType[MetricType["PeakSignalToNoiseRatioErrorMetric"] = 8] = "PeakSignalToNoiseRatioErrorMetric";
    MetricType[MetricType["PerceptualHashErrorMetric"] = 9] = "PerceptualHashErrorMetric";
    MetricType[MetricType["RootMeanSquaredErrorMetric"] = 10] = "RootMeanSquaredErrorMetric";
    MetricType[MetricType["StructuralSimilarityErrorMetric"] = 11] = "StructuralSimilarityErrorMetric";
    MetricType[MetricType["StructuralDissimilarityErrorMetric"] = 12] = "StructuralDissimilarityErrorMetric";
})(MetricType = exports.MetricType || (exports.MetricType = {}));

exports.CompositeOperator = void 0;
var CompositeOperator;
(function (CompositeOperator) {
    CompositeOperator[CompositeOperator["UndefinedCompositeOp"] = 0] = "UndefinedCompositeOp";
    CompositeOperator[CompositeOperator["AlphaCompositeOp"] = 1] = "AlphaCompositeOp";
    CompositeOperator[CompositeOperator["AtopCompositeOp"] = 2] = "AtopCompositeOp";
    CompositeOperator[CompositeOperator["BlendCompositeOp"] = 3] = "BlendCompositeOp";
    CompositeOperator[CompositeOperator["BlurCompositeOp"] = 4] = "BlurCompositeOp";
    CompositeOperator[CompositeOperator["BumpmapCompositeOp"] = 5] = "BumpmapCompositeOp";
    CompositeOperator[CompositeOperator["ChangeMaskCompositeOp"] = 6] = "ChangeMaskCompositeOp";
    CompositeOperator[CompositeOperator["ClearCompositeOp"] = 7] = "ClearCompositeOp";
    CompositeOperator[CompositeOperator["ColorBurnCompositeOp"] = 8] = "ColorBurnCompositeOp";
    CompositeOperator[CompositeOperator["ColorDodgeCompositeOp"] = 9] = "ColorDodgeCompositeOp";
    CompositeOperator[CompositeOperator["ColorizeCompositeOp"] = 10] = "ColorizeCompositeOp";
    CompositeOperator[CompositeOperator["CopyBlackCompositeOp"] = 11] = "CopyBlackCompositeOp";
    CompositeOperator[CompositeOperator["CopyBlueCompositeOp"] = 12] = "CopyBlueCompositeOp";
    CompositeOperator[CompositeOperator["CopyCompositeOp"] = 13] = "CopyCompositeOp";
    CompositeOperator[CompositeOperator["CopyCyanCompositeOp"] = 14] = "CopyCyanCompositeOp";
    CompositeOperator[CompositeOperator["CopyGreenCompositeOp"] = 15] = "CopyGreenCompositeOp";
    CompositeOperator[CompositeOperator["CopyMagentaCompositeOp"] = 16] = "CopyMagentaCompositeOp";
    CompositeOperator[CompositeOperator["CopyAlphaCompositeOp"] = 17] = "CopyAlphaCompositeOp";
    CompositeOperator[CompositeOperator["CopyRedCompositeOp"] = 18] = "CopyRedCompositeOp";
    CompositeOperator[CompositeOperator["CopyYellowCompositeOp"] = 19] = "CopyYellowCompositeOp";
    CompositeOperator[CompositeOperator["DarkenCompositeOp"] = 20] = "DarkenCompositeOp";
    CompositeOperator[CompositeOperator["DarkenIntensityCompositeOp"] = 21] = "DarkenIntensityCompositeOp";
    CompositeOperator[CompositeOperator["DifferenceCompositeOp"] = 22] = "DifferenceCompositeOp";
    CompositeOperator[CompositeOperator["DisplaceCompositeOp"] = 23] = "DisplaceCompositeOp";
    CompositeOperator[CompositeOperator["DissolveCompositeOp"] = 24] = "DissolveCompositeOp";
    CompositeOperator[CompositeOperator["DistortCompositeOp"] = 25] = "DistortCompositeOp";
    CompositeOperator[CompositeOperator["DivideDstCompositeOp"] = 26] = "DivideDstCompositeOp";
    CompositeOperator[CompositeOperator["DivideSrcCompositeOp"] = 27] = "DivideSrcCompositeOp";
    CompositeOperator[CompositeOperator["DstAtopCompositeOp"] = 28] = "DstAtopCompositeOp";
    CompositeOperator[CompositeOperator["DstCompositeOp"] = 29] = "DstCompositeOp";
    CompositeOperator[CompositeOperator["DstInCompositeOp"] = 30] = "DstInCompositeOp";
    CompositeOperator[CompositeOperator["DstOutCompositeOp"] = 31] = "DstOutCompositeOp";
    CompositeOperator[CompositeOperator["DstOverCompositeOp"] = 32] = "DstOverCompositeOp";
    CompositeOperator[CompositeOperator["ExclusionCompositeOp"] = 33] = "ExclusionCompositeOp";
    CompositeOperator[CompositeOperator["HardLightCompositeOp"] = 34] = "HardLightCompositeOp";
    CompositeOperator[CompositeOperator["HardMixCompositeOp"] = 35] = "HardMixCompositeOp";
    CompositeOperator[CompositeOperator["HueCompositeOp"] = 36] = "HueCompositeOp";
    CompositeOperator[CompositeOperator["InCompositeOp"] = 37] = "InCompositeOp";
    CompositeOperator[CompositeOperator["IntensityCompositeOp"] = 38] = "IntensityCompositeOp";
    CompositeOperator[CompositeOperator["LightenCompositeOp"] = 39] = "LightenCompositeOp";
    CompositeOperator[CompositeOperator["LightenIntensityCompositeOp"] = 40] = "LightenIntensityCompositeOp";
    CompositeOperator[CompositeOperator["LinearBurnCompositeOp"] = 41] = "LinearBurnCompositeOp";
    CompositeOperator[CompositeOperator["LinearDodgeCompositeOp"] = 42] = "LinearDodgeCompositeOp";
    CompositeOperator[CompositeOperator["LinearLightCompositeOp"] = 43] = "LinearLightCompositeOp";
    CompositeOperator[CompositeOperator["LuminizeCompositeOp"] = 44] = "LuminizeCompositeOp";
    CompositeOperator[CompositeOperator["MathematicsCompositeOp"] = 45] = "MathematicsCompositeOp";
    CompositeOperator[CompositeOperator["MinusDstCompositeOp"] = 46] = "MinusDstCompositeOp";
    CompositeOperator[CompositeOperator["MinusSrcCompositeOp"] = 47] = "MinusSrcCompositeOp";
    CompositeOperator[CompositeOperator["ModulateCompositeOp"] = 48] = "ModulateCompositeOp";
    CompositeOperator[CompositeOperator["ModulusAddCompositeOp"] = 49] = "ModulusAddCompositeOp";
    CompositeOperator[CompositeOperator["ModulusSubtractCompositeOp"] = 50] = "ModulusSubtractCompositeOp";
    CompositeOperator[CompositeOperator["MultiplyCompositeOp"] = 51] = "MultiplyCompositeOp";
    CompositeOperator[CompositeOperator["NoCompositeOp"] = 52] = "NoCompositeOp";
    CompositeOperator[CompositeOperator["OutCompositeOp"] = 53] = "OutCompositeOp";
    CompositeOperator[CompositeOperator["OverCompositeOp"] = 54] = "OverCompositeOp";
    CompositeOperator[CompositeOperator["OverlayCompositeOp"] = 55] = "OverlayCompositeOp";
    CompositeOperator[CompositeOperator["PegtopLightCompositeOp"] = 56] = "PegtopLightCompositeOp";
    CompositeOperator[CompositeOperator["PinLightCompositeOp"] = 57] = "PinLightCompositeOp";
    CompositeOperator[CompositeOperator["PlusCompositeOp"] = 58] = "PlusCompositeOp";
    CompositeOperator[CompositeOperator["ReplaceCompositeOp"] = 59] = "ReplaceCompositeOp";
    CompositeOperator[CompositeOperator["SaturateCompositeOp"] = 60] = "SaturateCompositeOp";
    CompositeOperator[CompositeOperator["ScreenCompositeOp"] = 61] = "ScreenCompositeOp";
    CompositeOperator[CompositeOperator["SoftLightCompositeOp"] = 62] = "SoftLightCompositeOp";
    CompositeOperator[CompositeOperator["SrcAtopCompositeOp"] = 63] = "SrcAtopCompositeOp";
    CompositeOperator[CompositeOperator["SrcCompositeOp"] = 64] = "SrcCompositeOp";
    CompositeOperator[CompositeOperator["SrcInCompositeOp"] = 65] = "SrcInCompositeOp";
    CompositeOperator[CompositeOperator["SrcOutCompositeOp"] = 66] = "SrcOutCompositeOp";
    CompositeOperator[CompositeOperator["SrcOverCompositeOp"] = 67] = "SrcOverCompositeOp";
    CompositeOperator[CompositeOperator["ThresholdCompositeOp"] = 68] = "ThresholdCompositeOp";
    CompositeOperator[CompositeOperator["VividLightCompositeOp"] = 69] = "VividLightCompositeOp";
    CompositeOperator[CompositeOperator["XorCompositeOp"] = 70] = "XorCompositeOp";
    CompositeOperator[CompositeOperator["StereoCompositeOp"] = 71] = "StereoCompositeOp";
    CompositeOperator[CompositeOperator["FreezeCompositeOp"] = 72] = "FreezeCompositeOp";
    CompositeOperator[CompositeOperator["InterpolateCompositeOp"] = 73] = "InterpolateCompositeOp";
    CompositeOperator[CompositeOperator["NegateCompositeOp"] = 74] = "NegateCompositeOp";
    CompositeOperator[CompositeOperator["ReflectCompositeOp"] = 75] = "ReflectCompositeOp";
    CompositeOperator[CompositeOperator["SoftBurnCompositeOp"] = 76] = "SoftBurnCompositeOp";
    CompositeOperator[CompositeOperator["SoftDodgeCompositeOp"] = 77] = "SoftDodgeCompositeOp";
    CompositeOperator[CompositeOperator["StampCompositeOp"] = 78] = "StampCompositeOp";
    CompositeOperator[CompositeOperator["RMSECompositeOp"] = 79] = "RMSECompositeOp";
})(CompositeOperator = exports.CompositeOperator || (exports.CompositeOperator = {}));

Object.assign(exports, (
    process.env['NODE_ENV'] === 'development' ?
        require('../build/Debug/Debug/imagemagick') :
        require('../build/Release/Release/imagemagick')
));
