DATAROOTDIR=$PWD/ImageMagick6-out
cd ImageMagick6
make clean
./configure --prefix=$DATAROOTDIR
