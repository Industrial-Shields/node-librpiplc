const rpiplc = require('../../lib/addon.js')('RPIPLC_V5', 'RPIPLC_19R');

console.log(`Version: ${rpiplc.version}`);

rpiplc.analogWriteSetFrequency('Q0.0', 24);
rpiplc.analogWrite('Q0.0', 200);

rpiplc.delay(5000);

rpiplc.analogWrite('Q0.0', 0);
