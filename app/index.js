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
    MetricType[MetricType["UndefinedMetric"] = 0] = "UndefinedMetric";
    MetricType[MetricType["AbsoluteErrorMetric"] = 1] = "AbsoluteErrorMetric";
    MetricType[MetricType["MeanAbsoluteErrorMetric"] = 2] = "MeanAbsoluteErrorMetric";
    MetricType[MetricType["MeanErrorPerPixelMetric"] = 3] = "MeanErrorPerPixelMetric";
    MetricType[MetricType["MeanSquaredErrorMetric"] = 4] = "MeanSquaredErrorMetric";
    MetricType[MetricType["PeakAbsoluteErrorMetric"] = 5] = "PeakAbsoluteErrorMetric";
    MetricType[MetricType["PeakSignalToNoiseRatioMetric"] = 6] = "PeakSignalToNoiseRatioMetric";
    MetricType[MetricType["RootMeanSquaredErrorMetric"] = 7] = "RootMeanSquaredErrorMetric";
    MetricType[MetricType["NormalizedCrossCorrelationErrorMetric"] = 8] = "NormalizedCrossCorrelationErrorMetric";
    MetricType[MetricType["FuzzErrorMetric"] = 9] = "FuzzErrorMetric";
    MetricType[MetricType["UndefinedErrorMetric"] = 10] = "UndefinedErrorMetric";
    MetricType[MetricType["PerceptualHashErrorMetric"] = 11] = "PerceptualHashErrorMetric";
})(MetricType = exports.MetricType || (exports.MetricType = {}));

exports.CompositeOperator = void 0;
var CompositeOperator;
(function (CompositeOperator) {
    CompositeOperator[CompositeOperator["UndefinedCompositeOp"] = 0] = "UndefinedCompositeOp";
    CompositeOperator[CompositeOperator["NoCompositeOp"] = 1] = "NoCompositeOp";
    CompositeOperator[CompositeOperator["ModulusAddCompositeOp"] = 2] = "ModulusAddCompositeOp";
    CompositeOperator[CompositeOperator["AtopCompositeOp"] = 3] = "AtopCompositeOp";
    CompositeOperator[CompositeOperator["BlendCompositeOp"] = 4] = "BlendCompositeOp";
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
    CompositeOperator[CompositeOperator["CopyOpacityCompositeOp"] = 17] = "CopyOpacityCompositeOp";
    CompositeOperator[CompositeOperator["CopyRedCompositeOp"] = 18] = "CopyRedCompositeOp";
    CompositeOperator[CompositeOperator["CopyYellowCompositeOp"] = 19] = "CopyYellowCompositeOp";
    CompositeOperator[CompositeOperator["DarkenCompositeOp"] = 20] = "DarkenCompositeOp";
    CompositeOperator[CompositeOperator["DstAtopCompositeOp"] = 21] = "DstAtopCompositeOp";
    CompositeOperator[CompositeOperator["DstCompositeOp"] = 22] = "DstCompositeOp";
    CompositeOperator[CompositeOperator["DstInCompositeOp"] = 23] = "DstInCompositeOp";
    CompositeOperator[CompositeOperator["DstOutCompositeOp"] = 24] = "DstOutCompositeOp";
    CompositeOperator[CompositeOperator["DstOverCompositeOp"] = 25] = "DstOverCompositeOp";
    CompositeOperator[CompositeOperator["DifferenceCompositeOp"] = 26] = "DifferenceCompositeOp";
    CompositeOperator[CompositeOperator["DisplaceCompositeOp"] = 27] = "DisplaceCompositeOp";
    CompositeOperator[CompositeOperator["DissolveCompositeOp"] = 28] = "DissolveCompositeOp";
    CompositeOperator[CompositeOperator["ExclusionCompositeOp"] = 29] = "ExclusionCompositeOp";
    CompositeOperator[CompositeOperator["HardLightCompositeOp"] = 30] = "HardLightCompositeOp";
    CompositeOperator[CompositeOperator["HueCompositeOp"] = 31] = "HueCompositeOp";
    CompositeOperator[CompositeOperator["InCompositeOp"] = 32] = "InCompositeOp";
    CompositeOperator[CompositeOperator["LightenCompositeOp"] = 33] = "LightenCompositeOp";
    CompositeOperator[CompositeOperator["LinearLightCompositeOp"] = 34] = "LinearLightCompositeOp";
    CompositeOperator[CompositeOperator["LuminizeCompositeOp"] = 35] = "LuminizeCompositeOp";
    CompositeOperator[CompositeOperator["MinusDstCompositeOp"] = 36] = "MinusDstCompositeOp";
    CompositeOperator[CompositeOperator["ModulateCompositeOp"] = 37] = "ModulateCompositeOp";
    CompositeOperator[CompositeOperator["MultiplyCompositeOp"] = 38] = "MultiplyCompositeOp";
    CompositeOperator[CompositeOperator["OutCompositeOp"] = 39] = "OutCompositeOp";
    CompositeOperator[CompositeOperator["OverCompositeOp"] = 40] = "OverCompositeOp";
    CompositeOperator[CompositeOperator["OverlayCompositeOp"] = 41] = "OverlayCompositeOp";
    CompositeOperator[CompositeOperator["PlusCompositeOp"] = 42] = "PlusCompositeOp";
    CompositeOperator[CompositeOperator["ReplaceCompositeOp"] = 43] = "ReplaceCompositeOp";
    CompositeOperator[CompositeOperator["SaturateCompositeOp"] = 44] = "SaturateCompositeOp";
    CompositeOperator[CompositeOperator["ScreenCompositeOp"] = 45] = "ScreenCompositeOp";
    CompositeOperator[CompositeOperator["SoftLightCompositeOp"] = 46] = "SoftLightCompositeOp";
    CompositeOperator[CompositeOperator["SrcAtopCompositeOp"] = 47] = "SrcAtopCompositeOp";
    CompositeOperator[CompositeOperator["SrcCompositeOp"] = 48] = "SrcCompositeOp";
    CompositeOperator[CompositeOperator["SrcInCompositeOp"] = 49] = "SrcInCompositeOp";
    CompositeOperator[CompositeOperator["SrcOutCompositeOp"] = 50] = "SrcOutCompositeOp";
    CompositeOperator[CompositeOperator["SrcOverCompositeOp"] = 51] = "SrcOverCompositeOp";
    CompositeOperator[CompositeOperator["ModulusSubtractCompositeOp"] = 52] = "ModulusSubtractCompositeOp";
    CompositeOperator[CompositeOperator["ThresholdCompositeOp"] = 53] = "ThresholdCompositeOp";
    CompositeOperator[CompositeOperator["XorCompositeOp"] = 54] = "XorCompositeOp";
    /* These are new operators, added after the above was last sorted.
    * The list should be re-sorted only when a new library version is
    * created.
    */
    CompositeOperator[CompositeOperator["DivideDstCompositeOp"] = 55] = "DivideDstCompositeOp";
    CompositeOperator[CompositeOperator["DistortCompositeOp"] = 56] = "DistortCompositeOp";
    CompositeOperator[CompositeOperator["BlurCompositeOp"] = 57] = "BlurCompositeOp";
    CompositeOperator[CompositeOperator["PegtopLightCompositeOp"] = 58] = "PegtopLightCompositeOp";
    CompositeOperator[CompositeOperator["VividLightCompositeOp"] = 59] = "VividLightCompositeOp";
    CompositeOperator[CompositeOperator["PinLightCompositeOp"] = 60] = "PinLightCompositeOp";
    CompositeOperator[CompositeOperator["LinearDodgeCompositeOp"] = 61] = "LinearDodgeCompositeOp";
    CompositeOperator[CompositeOperator["LinearBurnCompositeOp"] = 62] = "LinearBurnCompositeOp";
    CompositeOperator[CompositeOperator["MathematicsCompositeOp"] = 63] = "MathematicsCompositeOp";
    CompositeOperator[CompositeOperator["DivideSrcCompositeOp"] = 64] = "DivideSrcCompositeOp";
    CompositeOperator[CompositeOperator["MinusSrcCompositeOp"] = 65] = "MinusSrcCompositeOp";
    CompositeOperator[CompositeOperator["DarkenIntensityCompositeOp"] = 66] = "DarkenIntensityCompositeOp";
    CompositeOperator[CompositeOperator["LightenIntensityCompositeOp"] = 67] = "LightenIntensityCompositeOp";
    CompositeOperator[CompositeOperator["HardMixCompositeOp"] = 68] = "HardMixCompositeOp";
    CompositeOperator[CompositeOperator["StereoCompositeOp"] = 69] = "StereoCompositeOp";
})(CompositeOperator = exports.CompositeOperator || (exports.CompositeOperator = {}));

Object.assign(exports, (
    process.env['NODE_ENV'] === 'development' ?
        require('../build/Debug/Debug/imagemagick') :
        require('../build/Release/Release/imagemagick')
));
