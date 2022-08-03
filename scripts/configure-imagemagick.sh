DATAROOTDIR=$PWD/ImageMagick6-out
cd ImageMagick6
if [ ! -e config/configure.xml ]
then
    ./configure --prefix=$DATAROOTDIR
fi