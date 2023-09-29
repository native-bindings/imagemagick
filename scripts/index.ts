import { spawn } from "child-process-utilities";
import path from "path";
import { getArgument } from "cli-argument-helper";

(async () => {
    const args = process.argv.slice(2);
    const PKG_CONFIG_PATH = path.resolve(
        __dirname,
        "../ImageMagick6-out/lib/pkgconfig"
    );
    const srcFolder = path.resolve(__dirname, "../ImageMagick6");
    if (getArgument(args, "--configure") !== null) {
        await spawn(
            "./configure",
            ["--prefix", path.resolve(__dirname, "../ImageMagick6-out")],
            {
                cwd: srcFolder,
            }
        ).wait();
    }
    await spawn("make", [], {
        cwd: srcFolder,
    }).wait();
    await spawn("make", ["install"], {
        cwd: srcFolder,
    }).wait();

    await spawn(
        "npx",
        [
            "cmake-js",
            "compile",
            "-C",
            "--out",
            path.resolve(__dirname, "../build/release"),
        ],
        {
            env: {
                ...process.env,
                PKG_CONFIG_PATH,
            },
        }
    ).wait();
    await spawn(
        "npx",
        [
            "cmake-js",
            "compile",
            "-C",
            "-D",
            "--out",
            path.resolve(__dirname, "../build/debug"),
        ],
        {
            env: {
                ...process.env,
                PKG_CONFIG_PATH,
            },
        }
    ).wait();
})().catch((reason) => {
    process.exitCode = 1;
    console.error(reason);
});
