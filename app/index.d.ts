export class Geometry {
    constructor(geometry: string);
    constructor(
        width: number,
        height: number,
        x: number,
        y: number
    );
    isValid(): boolean;
    width(): number;
    width(value: number): void;
    height(): number;
    height(value: number): void;
}

export const constants: {
    ChannelType: {
        UndefinedChannel: number;
        RedChannel: number;
        GrayChannel: number;
        CyanChannel: number;
        LChannel: number;
        GreenChannel: number;
        MagentaChannel: number;
        aChannel: number;
        BlueChannel: number;
        bChannel: number;
        YellowChannel: number;
        BlackChannel: number;
        AlphaChannel: number;
        OpacityChannel: number;
        IndexChannel: number;
        ReadMaskChannel: number;
        WriteMaskChannel: number;
        MetaChannel: number;
        CompositeMaskChannel: number;
        CompositeChannels: number;
        AllChannels: number;
        TrueAlphaChannel: number;
        RGBChannels: number;
        GrayChannels: number;
        SyncChannels: number;
        DefaultChannels: number;
    };
    CompositeOperator: {
        UndefinedCompositeOp: number;
        AlphaCompositeOp: number;
        AtopCompositeOp: number;
        BlendCompositeOp: number;
        BlurCompositeOp: number;
        BumpmapCompositeOp: number;
        ChangeMaskCompositeOp: number;
        ClearCompositeOp: number;
        ColorBurnCompositeOp: number;
        ColorDodgeCompositeOp: number;
        ColorizeCompositeOp: number;
        CopyBlackCompositeOp: number;
        CopyBlueCompositeOp: number;
        CopyCompositeOp: number;
        CopyCyanCompositeOp: number;
        CopyGreenCompositeOp: number;
        CopyMagentaCompositeOp: number;
        CopyAlphaCompositeOp: number;
        CopyRedCompositeOp: number;
        CopyYellowCompositeOp: number;
        DarkenCompositeOp: number;
        DarkenIntensityCompositeOp: number;
        DifferenceCompositeOp: number;
        DisplaceCompositeOp: number;
        DissolveCompositeOp: number;
        DistortCompositeOp: number;
        DivideDstCompositeOp: number;
        DivideSrcCompositeOp: number;
        DstAtopCompositeOp: number;
        DstCompositeOp: number;
        DstInCompositeOp: number;
        DstOutCompositeOp: number;
        DstOverCompositeOp: number;
        ExclusionCompositeOp: number;
        HardLightCompositeOp: number;
        HardMixCompositeOp: number;
        HueCompositeOp: number;
        InCompositeOp: number;
        IntensityCompositeOp: number;
        LightenCompositeOp: number;
        LightenIntensityCompositeOp: number;
        LinearBurnCompositeOp: number;
        LinearDodgeCompositeOp: number;
        LinearLightCompositeOp: number;
        LuminizeCompositeOp: number;
        MathematicsCompositeOp: number;
        MinusDstCompositeOp: number;
        MinusSrcCompositeOp: number;
        ModulateCompositeOp: number;
        ModulusAddCompositeOp: number;
        ModulusSubtractCompositeOp: number;
        MultiplyCompositeOp: number;
        NoCompositeOp: number;
        OutCompositeOp: number;
        OverCompositeOp: number;
        OverlayCompositeOp: number;
        PegtopLightCompositeOp: number;
        PinLightCompositeOp: number;
        PlusCompositeOp: number;
        ReplaceCompositeOp: number;
        SaturateCompositeOp: number;
        ScreenCompositeOp: number;
        SoftLightCompositeOp: number;
        SrcAtopCompositeOp: number;
        SrcCompositeOp: number;
        SrcInCompositeOp: number;
        SrcOutCompositeOp: number;
        SrcOverCompositeOp: number;
        ThresholdCompositeOp: number;
        VividLightCompositeOp: number;
        XorCompositeOp: number;
        StereoCompositeOp: number;
        FreezeCompositeOp: number;
        InterpolateCompositeOp: number;
        NegateCompositeOp: number;
        ReflectCompositeOp: number;
        SoftBurnCompositeOp: number;
        SoftDodgeCompositeOp: number;
        StampCompositeOp: number;
        RMSECompositeOp: number;
        SaliencyBlendCompositeOp: number;
        SeamlessBlendCompositeOp: number;
    };
    MetricType: {
        UndefinedErrorMetric: number;
        AbsoluteErrorMetric: number;
        FuzzErrorMetric: number;
        MeanAbsoluteErrorMetric: number;
        MeanErrorPerPixelErrorMetric: number;
        MeanSquaredErrorMetric: number;
        NormalizedCrossCorrelationErrorMetric: number;
        PeakAbsoluteErrorMetric: number;
        PeakSignalToNoiseRatioErrorMetric: number;
        PerceptualHashErrorMetric: number;
        RootMeanSquaredErrorMetric: number;
        StructuralSimilarityErrorMetric: number;
        StructuralDissimilarityErrorMetric: number;
    };
};

export class Color {
    constructor(value: string);
    constructor(r: number, g: number, b: number);
    constructor(r: number, g: number, b: number, a: number);
    constructor(
        cyan: number,
        magenta: number,
        yellow: number,
        black: number,
        alpha: number
    );
}

export class Image {
    resize(value: Geometry): void;
    oilPaint(radius: number): void;
    emboss(radius: number, sigma: number): void;
    rotate(degrees: number): void;
    normalize(): void;
    backgroundColor(): Color;
    backgroundColor(value: Color): void;
    motionBlur(radius: number, sigma: number,angle:number): void;
    sample(value: Geometry): void;
    scale(value: Geometry): void;
    roll(value: Geometry): void;
    shave(value: Geometry): void;
    crop(value: Geometry): void;
    write(file: string): void;
    read(value: string): void;
    decipher(value: string): void;
    encipher(value: string): void;
    density(): Geometry;
    density(value: Geometry): void;
    size(): Geometry;
    size(value: Geometry): void;
    magick(): string;
    magick(value: string): void;
    defineValue(magick:string,key: string): string;
    defineValue(magick:string,key: string, value: string): void;
    defineSet(magick:string,key: string): boolean;
    defineSet(magick:string,key: string, flag: boolean): void;
    composite(
        compositeImage: Image,
        offset: Geometry,
        compose?: CompositeOperator
    ): void;
    /**
     * False is returned if the images are identical
     */
    compare(ref: Image): boolean;
    compare(ref: Image, metric: MetricType): number;
    negate(grayscale: boolean): void;
}

export type CompositeOperator = number;

export type MetricType = number;
