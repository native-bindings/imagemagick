import { spawn } from "child-process-utilities";
import path from "path";
import { getArgument } from "cli-argument-helper";
import {
    InterfaceLibrariesGenerator,
    Compiler,
    ILibrary,
    Tokenizer,
    Parser,
} from "../core";
import { glob } from "glob";
import fs from "fs";
import { IEnumDefinition } from "../core/Parser";
import CodeStream from "textstreamjs";

const libsDir = path.resolve(__dirname, "../libs");

async function generateBindingConstants() {
    const enumDefinitions = new Array<IEnumDefinition>();
    const headerFiles = await glob(path.resolve(libsDir, "**/*.h"));
    for (const file of headerFiles) {
        const tokens = new Tokenizer({
            contents: await fs.promises.readFile(file),
            file,
        }).tokenize();

        try {
            enumDefinitions.push(...new Parser(tokens).parse().enumDefinitions);
        } catch (reason) {
            console.error(`Failed to parse ${file}`);
            throw reason;
        }
    }
    const bindingConstants = enumDefinitions.map((def) => ({
        name: def.name,
        values: def.values.reduce(
            (acc, value) => {
                acc.options.push({
                    name: value.name,
                    value: acc.value,
                });
                acc.value++;
                return acc;
            },
            {
                options: new Array<{
                    name: string;
                    value: number;
                }>(),
                value: 1,
            }
        ),
    }));
    const cs = new CodeStream();
    const signatures = new Array<string>();
    cs.write('#include "Constants.h"\n\n');
    const enumNamespaces = new Map<string, string>([
        ["PixelComponent", "MagickCore"],
        ["MagickOpenCLProgram", "MagickCore"],
        ["PathType", "MagickCore"],
        ["SpreadMethod", "MagickCore"],
        ["QuantumFormatType", "MagickCore"],
        ["AutoThresholdMethod", "MagickCore"],
        ["StatisticType", "MagickCore"],
        ["PolicyDomain", "MagickCore"],
        ["MagickLayerMethod", "MagickCore"],
        ["CacheType", "MagickCore"],
        ["MagickOpenCLEnvParam", "MagickCore"],
        ["GeometryFlags", "MagickCore"],
        ["MapMode", "MagickCore"],
        ["TransmitType", "MagickCore"],
        ["AlignType", "MagickCore"],
        ["PrimitiveType", "MagickCore"],
        ["ClipPathUnits", "MagickCore"],
        ["ImageMagickOpenCLMode", "MagickCore"],
        ["CommandOptionFlags", "MagickCore"],
        ["RegistryType", "MagickCore"],
        ["QuantumAlphaType", "MagickCore"],
        ["MagickFormatType", "MagickCore"],
        ["ValidateType", "MagickCore"],
        ["MagickModuleType", "MagickCore"],
        ["MagickThreadSupport", "MagickCore"],
        ["TimerState", "MagickCore"],
        ["ComplexOperator", "MagickCore"],
        ["ExceptionType", "MagickCore"],
        ["MontageMode", "MagickCore"],
        ["PolicyRights", "MagickCore"],
        ["GradientType", "MagickCore"],
        ["ComplianceType", "MagickCore"],
        ["ReferenceType", "MagickCore"],
    ]);
    function getNamespaceFromDef(def: string) {
        return enumNamespaces.get(def) ?? "Magick";
    }
    for (const def of bindingConstants) {
        cs.write(
            `static void Set${def.name}BindingConstants(const v8::Local<v8::Object> exports) {\n`,
            () => {
                cs.write("auto constants = Nan::New<v8::Object>();\n");
                for (const value of def.values.options) {
                    cs.write(
                        `Nan::Set(constants, Nan::New("${value.name}").ToLocalChecked(), Nan::New(${value.value}));\n`
                    );
                }
                cs.write(
                    `Nan::Set(exports, Nan::New("${def.name}").ToLocalChecked(), constants);\n`
                );
            },
            "}\n\n"
        );
        const namespace = getNamespaceFromDef(def.name);
        signatures.push(
            `[[nodiscard]] static bool Convert${def.name}(v8::Local<v8::Value> val, ${namespace}::${def.name}& out)`
        );
        cs.write(
            `bool Constants::Convert${def.name}(const v8::Local<v8::Value> val, ${namespace}::${def.name}& out) {\n`,
            () => {
                cs.write(
                    `if(!val->IsUint32()) {\n`,
                    () => {
                        cs.write(
                            `${createThrowErrorCall(
                                `"Failed to convert to ${def.name}: Expected a valid unsigned 32-bit integer"`
                            )};\n`
                        );
                        cs.write("return false;\n");
                    },
                    "}\n"
                );
                cs.write(
                    `const std::uint32_t input = Nan::To<v8::Uint32>(val).ToLocalChecked()->Value();\n`
                );
                for (const value of def.values.options) {
                    cs.write(
                        `if(input == ${value.value}) {\n`,
                        () => {
                            cs.write(
                                `out = ${namespace}::${def.name}::${value.name};\n`
                            );
                            cs.write(`return true;\n`);
                        },
                        "}\n"
                    );
                }
                cs.write(
                    `${createThrowErrorCall(
                        `"Failed to convert " + std::to_string(input) + " to ${def.name}"`
                    )};\n`
                );
                cs.write("return false;\n");
            },
            "}\n"
        );
        if (def !== bindingConstants[bindingConstants.length - 1]) {
            cs.write("\n");
        }
    }
    signatures.push("static void Init(v8::Local<v8::Object> exports)");
    cs.write(
        "void Constants::Init(const v8::Local<v8::Object> exports) {\n",
        () => {
            cs.write("auto constants = Nan::New<v8::Object>();\n");
            for (const def of bindingConstants) {
                cs.write(`Set${def.name}BindingConstants(constants);\n`);
            }
            cs.write(
                'Nan::Set(exports, Nan::New("constants").ToLocalChecked(), constants);\n'
            );
        },
        "}\n"
    );
    await fs.promises.writeFile(
        path.resolve(__dirname, "../src/Constants.cpp"),
        cs.value()
    );

    cs.write("#ifndef NATIVE_BINDINGS_IMAGEMAGICK_H_\n");
    cs.write("#define NATIVE_BINDINGS_IMAGEMAGICK_H_\n\n");
    cs.write("#include <Magick++.h>\n");
    cs.write("#include <nan.h>\n\n");
    cs.write("class Constants {\n");
    cs.write("public:\n");
    cs.indentBlock(() => {
        for (const signature of signatures) {
            cs.write(`${signature};\n`);
        }
    });
    cs.write("};\n\n");
    cs.write("#endif // NATIVE_BINDINGS_IMAGEMAGICK_H_\n");
    await fs.promises.writeFile(
        path.resolve(__dirname, "../src/Constants.h"),
        cs.value()
    );

    cs.write(
        "export interface IConstants {\n",
        () => {
            for (const def of bindingConstants) {
                cs.write(
                    `${def.name}: {\n`,
                    () => {
                        for (const v of def.values.options) {
                            cs.write(`${v.name}: ${v.value};\n`);
                        }
                    },
                    "};\n"
                );
            }
        },
        "}\n"
    );
    await fs.promises.writeFile(
        path.resolve(__dirname, "../app/constants.d.ts"),
        cs.value()
    );
}

function createThrowErrorCall(message: string) {
    return `Nan::ThrowError(Nan::New(${message}).ToLocalChecked())`;
}

(async () => {
    const args = process.argv.slice(2);
    const configure = getArgument(args, "--configure") !== null;
    const libraries: ILibrary[] = [
        {
            sourceDir: path.resolve(__dirname, "../deps/ImageMagick-6.9.12-98"),
        },
    ];

    if (getArgument(args, "--generate-binding-constants")) {
        await generateBindingConstants();
    }

    const interfaceLibrariesGenerator = new InterfaceLibrariesGenerator(
        libsDir
    );

    if (getArgument(args, "--skip-compilation") === null) {
        const compiler = new Compiler(libsDir, libraries);
        await compiler.compile({
            configure,
        });
    }

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
