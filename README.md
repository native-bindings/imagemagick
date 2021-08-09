# image-m

### Installation

```
yarn add image-m
```

### Requirements

- ImageMagick 7
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

### Installing ImageMagick 7 from source

```bash
wget https://download.imagemagick.org/ImageMagick/download/ImageMagick-7.1.0-4.zip
unzip ImageMagick-7.1.0-4.zip
cd ImageMagick-7.1.0-4
./configure --enable-shared --with-modules --with-gslib
make
make install
```
