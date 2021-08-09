import assert from 'assert';
import path from 'path';
import {
    Image,
    Color
} from '../app';

(async () => {
    assert.throws(() => {
        new Color('x');
    },/unrecognized color/);

    assert.throws(() => {
        new Image().read('!');
    },/unable to open image/);

    const img1 = new Image();
    img1.read(path.resolve(__dirname,'Screenshot from 2021-07-22 11-13-30.png'));
    assert.strict.equal(img1.size().width(),849);
    assert.strict.equal(img1.size().height(),596);

    img1.read(path.resolve(__dirname,'icons8-spotify.svg'));
    assert.strict.equal(img1.size().width(),48);
    assert.strict.equal(img1.size().height(),48);
})().catch(reason => {
    process.exitCode = 1;
    console.error(reason);
});
