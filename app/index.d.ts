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

export enum MetricType {
    UndefinedMetric,
    AbsoluteErrorMetric,
    MeanAbsoluteErrorMetric,
    MeanErrorPerPixelMetric,
    MeanSquaredErrorMetric,
    PeakAbsoluteErrorMetric,
    PeakSignalToNoiseRatioMetric,
    RootMeanSquaredErrorMetric,
    NormalizedCrossCorrelationErrorMetric,
    FuzzErrorMetric,
    UndefinedErrorMetric,
    PerceptualHashErrorMetric
}

export enum CompositeOperator {
    UndefinedCompositeOp,
    NoCompositeOp,
    ModulusAddCompositeOp,
    AtopCompositeOp,
    BlendCompositeOp,
    BumpmapCompositeOp,
    ChangeMaskCompositeOp,
    ClearCompositeOp,
    ColorBurnCompositeOp,
    ColorDodgeCompositeOp,
    ColorizeCompositeOp,
    CopyBlackCompositeOp,
    CopyBlueCompositeOp,
    CopyCompositeOp,
    CopyCyanCompositeOp,
    CopyGreenCompositeOp,
    CopyMagentaCompositeOp,
    CopyOpacityCompositeOp,
    CopyRedCompositeOp,
    CopyYellowCompositeOp,
    DarkenCompositeOp,
    DstAtopCompositeOp,
    DstCompositeOp,
    DstInCompositeOp,
    DstOutCompositeOp,
    DstOverCompositeOp,
    DifferenceCompositeOp,
    DisplaceCompositeOp,
    DissolveCompositeOp,
    ExclusionCompositeOp,
    HardLightCompositeOp,
    HueCompositeOp,
    InCompositeOp,
    LightenCompositeOp,
    LinearLightCompositeOp,
    LuminizeCompositeOp,
    MinusDstCompositeOp,
    ModulateCompositeOp,
    MultiplyCompositeOp,
    OutCompositeOp,
    OverCompositeOp,
    OverlayCompositeOp,
    PlusCompositeOp,
    ReplaceCompositeOp,
    SaturateCompositeOp,
    ScreenCompositeOp,
    SoftLightCompositeOp,
    SrcAtopCompositeOp,
    SrcCompositeOp,
    SrcInCompositeOp,
    SrcOutCompositeOp,
    SrcOverCompositeOp,
    ModulusSubtractCompositeOp,
    ThresholdCompositeOp,
    XorCompositeOp,
    /* These are new operators, added after the above was last sorted.
    * The list should be re-sorted only when a new library version is
    * created.
    */
    DivideDstCompositeOp,
    DistortCompositeOp,
    BlurCompositeOp,
    PegtopLightCompositeOp,
    VividLightCompositeOp,
    PinLightCompositeOp,
    LinearDodgeCompositeOp,
    LinearBurnCompositeOp,
    MathematicsCompositeOp,
    DivideSrcCompositeOp,
    MinusSrcCompositeOp,
    DarkenIntensityCompositeOp,
    LightenIntensityCompositeOp,
    HardMixCompositeOp,
    StereoCompositeOp
}

export enum ChannelType {
    UndefinedChannel = 0x0000,
    RedChannel = 0x0001,
    GrayChannel = 0x0001,
    CyanChannel = 0x0001,
    LChannel = 0x0001,
    GreenChannel = 0x0002,
    MagentaChannel = 0x0002,
    aChannel = 0x0002,
    BlueChannel = 0x0004,
    bChannel = 0x0002,
    YellowChannel = 0x0004,
    BlackChannel = 0x0008,
    AlphaChannel = 0x0010,
    OpacityChannel = 0x0010,
    IndexChannel = 0x0020,             /* Color Index Table? */
    ReadMaskChannel = 0x0040,          /* Pixel is Not Readable? */
    WriteMaskChannel = 0x0080,         /* Pixel is Write Protected? */
    MetaChannel = 0x0100,              /* not used */
    CompositeMaskChannel = 0x0200,     /* SVG mask */
    CompositeChannels = 0x001F,
    AllChannels = 0x7ffffff,
    /*
        Special purpose channel types.
        FUTURE: are these needed any more - they are more like hacks
        SyncChannels for example is NOT a real channel but a 'flag'
        It really says -- "User has not defined channels"
        Though it does have extra meaning in the "-auto-level" operator
    */
    TrueAlphaChannel = 0x0100, /* extract actual alpha channel from opacity */
    RGBChannels = 0x0200,      /* set alpha from grayscale mask in RGB */
    GrayChannels = 0x0400,
    SyncChannels = 0x20000,    /* channels modified as a single unit */
    DefaultChannels = AllChannels
}

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
