# @native-bindings/imagemagick6

### Installation

```
npm i @native-bindings/imagemagick6
```

### Requirements

- C++20
- CMake >=3.10

### Usage

```ts
import { Geometry, Image } from "@native-bindings/imagemagick6";

const img = new Image();
img.read("image.png");
img.resize(new Geometry(100, 100, 0, 0));
img.write("new-image.png");
```

```ts
import { Image } from "@native-bindings/imagemagick6";

const img1 = new Image();
img1.read("image.png");

const img2 = new Image();
img2.read("image.png");
img2.motionBlur(20, 3, 40);

console.log(img2.compare(img1));
```

```ts
import { Image, Color, Geometry } from "@native-bindings/imagemagick6";

const img = new Image();
img.density(new Point(256, 256));
img.backgroundColor(new Color(0, 0, 0, 0));
img.read(path.resolve(__dirname, "icon.svg"));
img.resize(new Geometry(256, 256, 0, 0));
img.write(__dirname + "/icon.png");
```
