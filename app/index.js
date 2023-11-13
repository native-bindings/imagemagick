const devBinary = "../build/debug/Debug/NativeBindingsImageMagick.node";
const paths = ["../build/release/Release/NativeBindingsImageMagick.node"];

if (process.env["NODE_ENV"] === "development") {
    paths.unshift(devBinary);
} else {
    paths.push(devBinary);
}

for (const p of paths) {
    try {
        Object.assign(exports, require(p));
        break;
    } catch (reason) {
        if (p === paths[paths.length - 1]) {
            throw reason;
        }
    }
}
