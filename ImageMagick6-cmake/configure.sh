cd ImageMagick6
make clean
./configure --enable-hdri
cd ..
npx ts-node --project utils/tsconfig.json utils/generate-flag-files.ts