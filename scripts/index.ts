import { spawn } from "child-process-utilities";
import path from "path";
import { getArgument } from "cli-argument-helper";
import Compiler, { ILibrary } from "../pkgconfig/Compiler";
import InterfaceLibrariesGenerator from "../pkgconfig/InterfaceLibrariesGenerator";

const libsDir = path.resolve(__dirname, "../libs");

(async () => {
    const args = process.argv.slice(2);
    const configure = getArgument(args, "--configure") !== null;
    const libraries: ILibrary[] = [
        {
            sourceDir: path.resolve(__dirname, "../deps/ImageMagick-6.9.12-98"),
        },
    ];

    const compiler = new Compiler(libsDir, libraries);
    const interfaceLibrariesGenerator = new InterfaceLibrariesGenerator(
        libsDir
    );

    await compiler.compile({
        configure,
    });

    await interfaceLibrariesGenerator.generateInterfaceLibraries(libraries);

    await spawn("npx", [
        "cmake-js",
        "compile",
        "-C",
        "--out",
        path.resolve(__dirname, "../build/release"),
    ]).wait();

    if (getArgument(args, "--production") === null) {
        await spawn("npx", [
            "cmake-js",
            "compile",
            "-C",
            "-D",
            "--out",
            path.resolve(__dirname, "../build/debug"),
        ]).wait();
    }
})().catch((reason) => {
    process.exitCode = 1;
    console.error(reason);
});
