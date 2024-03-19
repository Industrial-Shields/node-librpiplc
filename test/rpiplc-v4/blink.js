const rpiplc = require('../../lib/addon.js')('RPIPLC_V4', 'RPIPLC_19R');

console.log(`Version: ${rpiplc.version}`);

rpiplc.pinMode('Q0.0', rpiplc.OUTPUT);

while (true) {
	rpiplc.digitalWrite('Q0.0', rpiplc.HIGH);
	rpiplc.delay(1000);
	rpiplc.digitalWrite('Q0.0', rpiplc.LOW);
	rpiplc.delay(1000);
}
