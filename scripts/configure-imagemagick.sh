#!/bin/bash

DATAROOTDIR=$PWD/ImageMagick6-out
cd ImageMagick6
if [ ! -f config/configure.xml ]; then
    ./configure --prefix=$DATAROOTDIR
fi