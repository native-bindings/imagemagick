export class Geometry {
    constructor(geometry: string);
    constructor(width: number, height: number, x: number, y: number);
    isValid(): boolean;
    width(): number;
    width(value: number): void;
    height(): number;
    height(value: number): void;
    aspect(): boolean;
    aspect(value: boolean): void;
    limitPixels(): boolean;
    limitPixels(value: boolean): void;
    percentage(): boolean;
    percentage(value: boolean): void;
    fillArea(): boolean;
    fillArea(value: boolean): void;
    greater(): boolean;
    greater(value: boolean): void;
    less(): boolean;
    less(value: boolean): void;
    xNegative(): boolean;
    xNegative(value: boolean): void;
    yNegative(): boolean;
    yNegative(value: boolean): void;
    toString(): string;
}

export const constants: import("./constants").IConstants;

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
    motionBlur(radius: number, sigma: number, angle: number): void;
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
    resize(value: Geometry): void;
    antiAlias(): boolean;
    antiAlias(value: boolean): void;
    magick(): string;
    magick(value: string): void;
    defineValue(magick: string, key: string): string;
    defineValue(magick: string, key: string, value: string): void;
    defineSet(magick: string, key: string): boolean;
    defineSet(magick: string, key: string, flag: boolean): void;
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

export class CoderInfo {
    constructor();
    name(): string;
    description(): string;
    mimeType(): string;
    isReadable(): boolean;
    isWritable(): boolean;
    isMultiFrame(): boolean;
}

export function coderInfoList(): CoderInfo[];
