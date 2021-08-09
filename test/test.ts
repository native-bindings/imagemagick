import assert from 'assert';
import {
    Point,
    Image,
    Color
} from '../app';

(async () => {
    new Point(2,3);
    new Point(2);
    new Point('+3x+3');
    assert.strict.equal(new Point(2).x(),2);
    assert.strict.equal(new Point(2).x(),2);
    assert.strict.equal(new Point('+3x+3').y(),3);
    assert.strict.equal(new Point('+3x+3').x(),3);

    assert.throws(() => {
        new Color('x');
    },/unrecognized color/);

    assert.throws(() => {
        new Image().read('!');
    },/unable to open image '!'/);
})().catch(reason => {
    process.exitCode = 1;
    console.error(reason);
});
