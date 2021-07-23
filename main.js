const rpiplc = require('./lib/addon.js')

console.log('Version: ' + rpiplc.version());

rpiplc.initPins();

let inputs = [
	0x00002105,
	0x00002103,
	0x00002102,
	0x00002101,
	0x00002100,
	13,
	12,
	0x00004a00,
	0x00004a01,
	0x00004b00,
	0x00004802,
	0x00004800,
	0x00004801,
];

inputs.forEach((input) => {
	console.log(rpiplc.digitalRead(input));
});
