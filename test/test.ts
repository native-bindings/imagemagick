import path from "path";
import { Image, Color } from "../app";
import test from "ava";
import mapVariablePositions from "../pkgconfig/mapVariablePositions";
import resolveVariables from "../pkgconfig/resolveVariables";

test("it should resolve variables of pkg config files", (t) => {
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

test("Color#constructor: it should throw an error when an invalid color is passed", (t) => {
    t.throws(
        () => {
            new Color("x");
        },
        undefined,
        "unrecognized color"
    );
});

test("Image#read: that it throws an error when an invalid file is passed", (t) => {
    t.throws(
        () => {
            new Image().read("!");
        },
        undefined,
        "unable to open image"
    );
});

test("it should get read a png image", (t) => {
    const img1 = new Image();
    img1.read(
        path.resolve(__dirname, "Screenshot from 2021-07-22 11-13-30.png")
    );
    t.deepEqual(img1.size().width(), 849);
    t.deepEqual(img1.size().height(), 596);
});

test("it should read an svg image", (t) => {
    const img1 = new Image();
    img1.read(path.resolve(__dirname, "icons8-spotify.svg"));
    t.deepEqual(img1.size().width(), 48);
    t.deepEqual(img1.size().height(), 48);
});
