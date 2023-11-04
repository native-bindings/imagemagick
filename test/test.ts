import path from "path";
import Magick from "../app";
import test from "ava";
import mapVariablePositions from "../core/mapVariablePositions";
import resolveVariables from "../core/resolveVariables";

test("mapVariablePositions: it should resolve variables of pkg config files", (t) => {
    t.deepEqual(
        mapVariablePositions("hello ${a}, ${b} and ${c}!"),
        new Map([
            ["a", { start: 6, end: 9 }],
            ["b", { start: 12, end: 15 }],
            ["c", { start: 21, end: 24 }],
        ])
    );

    t.deepEqual(
        resolveVariables(
            "final",
            new Map([
                ["final", "hello ${a}, ${b} and ${c}!"],
                ["a", "${prefix} ${name}"],
                ["name", "Queiroz"],
                ["prefix", "Mr."],
                ["b", "${prefix} ${name}"],
                ["c", "${prefix} ${name}"],
            ])
        ),
        "hello Mr. Queiroz, Mr. Queiroz and Mr. Queiroz!"
    );
});

test("Image#crop: it should crop an image", (t) => {
    const img = new Magick.Image();
    img.read(path.resolve(__dirname, "apartment-8318376_640.jpg"));
    img.crop(new Magick.Geometry(159, 128, 146, 166));
    img.write(path.resolve(__dirname, "temp2.jpg"));

    const img2 = new Magick.Image();
    img2.read(path.resolve(__dirname, "temp2.jpg"));

    const img3 = new Magick.Image();
    img3.read(path.resolve(__dirname, "house.jpg"));
    t.assert(img2.compare(img3));
});

test("Image#oilPaint: it should oil-paint an image", (t) => {
    const img = new Magick.Image();
    img.read(path.resolve(__dirname, "apartment-8318376_640.jpg"));
    img.oilPaint(2);
    img.write(path.resolve(__dirname, "temp1.jpg"));

    const img2 = new Magick.Image();
    img2.read(path.resolve(__dirname, "temp1.jpg"));

    const img3 = new Magick.Image();
    img3.read(path.resolve(__dirname, "expected-oil-paint-call-output.jpg"));
    t.assert(img3.compare(img2));
});

test("Image#rotate: it should rotate an image", (t) => {
    const img = new Magick.Image();
    img.read(path.resolve(__dirname, "apartment-8318376_640.jpg"));
    img.rotate(3);
    img.write(path.resolve(__dirname, "temp3.jpg"));

    const img2 = new Magick.Image();
    img2.read(path.resolve(__dirname, "temp3.jpg"));

    const img3 = new Magick.Image();
    img3.read(path.resolve(__dirname, "expected-rotated-output.jpg"));
    t.assert(img3.compare(img2));
});

test("Image#negate: it should negate an image with grayscale equal to false", (t) => {
    const img = new Magick.Image();
    img.read(path.resolve(__dirname, "apartment-8318376_640.jpg"));
    img.negate(false);
    img.write(path.resolve(__dirname, "temp5.jpg"));

    const img2 = new Magick.Image();
    img2.read(path.resolve(__dirname, "temp5.jpg"));

    const img3 = new Magick.Image();
    img3.read(path.resolve(__dirname, "expected-negate-output.jpg"));
    t.assert(img3.compare(img2));
});

test("Image#negate: it should negate an image with grayscale equal to true", (t) => {
    const img = new Magick.Image();
    img.read(path.resolve(__dirname, "apartment-8318376_640.jpg"));
    img.negate(true);
    img.write(path.resolve(__dirname, "temp6.jpg"));

    const img2 = new Magick.Image();
    img2.read(path.resolve(__dirname, "temp6.jpg"));

    const img3 = new Magick.Image();
    img3.read(path.resolve(__dirname, "expected-negate-grayscale-output.jpg"));
    t.assert(img3.compare(img2));
});

test("Image#resize: it should upscale an image", (t) => {
    const img = new Magick.Image();
    img.read(path.resolve(__dirname, "apartment-8318376_640.jpg"));
    img.resize(new Magick.Geometry(4000, 4000, 0, 0));
    img.write(path.resolve(__dirname, "temp7.jpg"));

    const img2 = new Magick.Image();
    img2.read(path.resolve(__dirname, "temp7.jpg"));

    const img3 = new Magick.Image();
    img3.read(path.resolve(__dirname, "expected-upscale-output.jpg"));
    t.assert(img3.compare(img2));
});

test("Image#resize: it should downscale an image", (t) => {
    const img = new Magick.Image();
    img.read(path.resolve(__dirname, "apartment-8318376_640.jpg"));
    img.resize(new Magick.Geometry(48, 48, 0, 0));
    img.write(path.resolve(__dirname, "temp9.jpg"));

    const img2 = new Magick.Image();
    img2.read(path.resolve(__dirname, "temp9.jpg"));

    const img3 = new Magick.Image();
    img3.read(path.resolve(__dirname, "expected-downscale-output.jpg"));
    t.assert(img3.compare(img2));
});

test("Image#resize: it should correct aspect ratio based on the width when resize is called", (t) => {
    const img = new Magick.Image();
    img.read(path.resolve(__dirname, "apartment-8318376_640.jpg"));
    img.resize(new Magick.Geometry(4000, 4000, 0, 0));
    img.write(path.resolve(__dirname, "temp8.jpg"));

    const img2 = new Magick.Image();
    img2.read(path.resolve(__dirname, "temp8.jpg"));
    t.deepEqual(img2.size().width(), 4000);
    t.deepEqual(img2.size().height(), 2669);

    const img3 = new Magick.Image();
    img3.read(path.resolve(__dirname, "expected-upscale-output.jpg"));
    t.assert(img3.compare(img2));
});

test("Image#encipher: it should encipher an image", (t) => {
    const img = new Magick.Image();
    img.read(path.resolve(__dirname, "apartment-8318376_640.jpg"));
    img.encipher("1234567");
    img.write(path.resolve(__dirname, "temp4.jpg"));

    const img2 = new Magick.Image();
    img2.read(path.resolve(__dirname, "temp4.jpg"));

    const img3 = new Magick.Image();
    img3.read(path.resolve(__dirname, "expected-encipher-output.jpg"));
    t.assert(img3.compare(img2));
});

test("Color#constructor: it should throw an error when an invalid color is passed", (t) => {
    t.throws(
        () => {
            new Magick.Color("x");
        },
        {
            message:
                "node: unrecognized color `x' @ warning/color.c/GetColorCompliance/1057",
        }
    );
});

test("Image#read: that it throws an error when an invalid file is passed", (t) => {
    t.throws(
        () => {
            new Magick.Image().read("!");
        },
        undefined,
        "unable to open image"
    );
});

test("Image#read: it should get read a png image", (t) => {
    const img1 = new Magick.Image();
    img1.read(
        path.resolve(__dirname, "Screenshot from 2021-07-22 11-13-30.png")
    );
    t.deepEqual(img1.size().width(), 849);
    t.deepEqual(img1.size().height(), 596);
});

test("Image#read: it should read an svg image", (t) => {
    const img1 = new Magick.Image();
    img1.read(path.resolve(__dirname, "icons8-spotify.svg"));
    t.deepEqual(img1.size().width(), 48);
    t.deepEqual(img1.size().height(), 48);
});

test("Geometry#width: it should throw an error if an invalid type is passed", (t) => {
    const img1 = new Magick.Image();
    img1.read(path.resolve(__dirname, "icons8-spotify.svg"));
    t.throws(
        () => {
            img1.size().width(
                // @ts-expect-error testing invalid type
                ""
            );
        },
        undefined,
        "Expected argument number 1 to be of type Uint32."
    );
});

test("Geometry#height: it should throw an error if an invalid type is passed", (t) => {
    const img1 = new Magick.Image();
    img1.read(path.resolve(__dirname, "icons8-spotify.svg"));
    t.throws(
        () => {
            img1.size().height(
                // @ts-expect-error testing invalid type
                ""
            );
        },
        { message: "Expected argument number 1 to be of type Uint32." }
    );
});

test("Image#read: it should throw an error if an invalid type is passed", (t) => {
    const img1 = new Magick.Image();
    t.throws(
        () => {
            img1.read(
                // @ts-expect-error testing invalid type
                1
            );
        },
        { message: "Expected argument number 1 to be of type String." }
    );
});

test("Image#size: it should throw an error if an invalid type is passed", (t) => {
    const img1 = new Magick.Image();
    t.throws(
        () => {
            img1.size(
                // @ts-expect-error testing invalid type
                1
            );
        },
        { message: "Expected argument number 1 to be of type Geometry." }
    );
});

test("Image#resize: it should throw an error if an invalid type is passed", (t) => {
    const img1 = new Magick.Image();
    t.throws(
        () => {
            img1.resize(
                // @ts-expect-error testing invalid type
                1
            );
        },
        {
            message: "Expected argument number 1 to be of type Geometry.",
        }
    );
});
