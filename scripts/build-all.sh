PKG_CONFIG_PATH=$PWD/ImageMagick6-out/lib/pkgconfig

# build and install ImageMagick6 locally
cd ImageMagick6
make
make install

cd ..
PKG_CONFIG_PATH=$PKG_CONFIG_PATH npx cmake-js compile -C --out=build/release
PKG_CONFIG_PATH=$PKG_CONFIG_PATH npx cmake-js compile -D -C --out=build/debug
