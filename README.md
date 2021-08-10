# image-m

### Installation

```
yarn add image-m
```

### Debian 10

```
apt install -y --install-recommends \
    "libmagick++-6.q16-8" libmagick++-dev cmake
```

### Requirements

- ImageMagick 6.9.12
- C++14
- CMake >= 3.7

### Usage

```ts
import {Geometry,Image} from 'image-m';

const img = new Image();
img.read('image.png');
img.resize(new Geometry(100,100,0,0));
img.write('new-image.png');
```

```ts
import {Image} from 'image-m';

const img1 = new Image();
img1.read('image.png');

const img2 = new Image();
img2.read('image.png');
img2.motionBlur(20,3,40);

console.log(img2.compare(img1));
```

```ts
import {
    Image,
    Color,
    Geometry
} from 'image-m';

const img = new Image();
img.density(new Point(256,256));
img.backgroundColor(new Color(0,0,0,0));
img.read(
    path.resolve(__dirname,'icon.svg')
);
img.resize(new Geometry(256,256,0,0));
img.write(__dirname + '/icon.png');
```
