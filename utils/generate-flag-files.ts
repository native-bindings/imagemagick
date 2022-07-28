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
        return [key,l.substring(fullMatch.length).trim().split(' ').filter(s => s.trim().length > 0).join('\n')];
    }));
    const dest = path.resolve(__dirname,'../ImageMagick6-cmake');
    let cFlags = flags.get('CFLAGS');
    const includeDirs = new Set<string>();
    if(cFlags){
        const includeFlag = '-I';
        const allFlags = new Set(cFlags.split('\n'));
        for(const flag of allFlags){
            const includeFlagIndex = flag.indexOf(includeFlag);
            if(includeFlagIndex === -1) continue;
            includeDirs.add(flag.substring(includeFlagIndex + includeFlag.length));
            allFlags.delete(flag);
        }
        flags.set('CFLAGS',Array.from(allFlags).join('\n'));
        flags.set('INCLUDE_DIRS',Array.from(includeDirs).join('\n'));
    }
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
