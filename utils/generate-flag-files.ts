import assert from 'assert';
import fs from 'fs';
import path from 'path';

(async () => {
    const expr = /^(((C|CPP)FLAGS) = )/;
    const makefile = (await fs.promises.readFile(path.resolve(__dirname,'../ImageMagick6/Makefile'),'utf8')).split('\n');
    const flags = new Map(makefile.filter(l => expr.test(l)).map(l => {
        const match = l.match(expr);
        assert.strict.ok(match !== null);
        const key = match[2];
        const fullMatch = match[0];
        assert.strict.ok(fullMatch && key);
        return [key,l.substring(fullMatch.length).trim().split(' ').join('\n')];
    }));
    const dest = path.resolve(__dirname,'../ImageMagick6-cmake');
    for(const [key,value] of flags){
        await fs.promises.writeFile(
            path.resolve(dest,`${key}`),
            value
        );
    }
})().catch(reason => {
    process.exitCode = 1;
    console.error(reason);
});
