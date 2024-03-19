const rpiplc = require('../../lib/addon.js')('RPIPLC_V5', 'RPIPLC_19R');

console.log(`Version: ${rpiplc.version}`);

rpiplc.pinMode('I0.0', rpiplc.INPUT);
rpiplc.pinMode('Q0.0', rpiplc.OUTPUT);
rpiplc.pinMode('Q0.1', rpiplc.OUTPUT);

const value = rpiplc.digitalRead('I0.0');
console.log(`Read value: ${value}`);

rpiplc.delay(1000);

console.log(`Set outputs`);
rpiplc.digitalWrite('Q0.0', value);
rpiplc.digitalWrite('Q0.1', rpiplc.HIGH);
