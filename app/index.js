"use strict";
Object.defineProperty(exports, "__esModule", { value: true });

const devBinary = "../build/debug/Debug/node_imagemagick";
const paths = ["../build/release/Release/node_imagemagick"];

if (process.env["NODE_ENV"] === "development") {
    paths.unshift(devBinary);
} else {
    paths.push(devBinary);
}

for (const p of paths) {
    try {
        Object.assign(exports, require(p));
    } catch (reason) {
        if (p === paths[paths.length - 1]) {
            throw reason;
        }
    }
}
