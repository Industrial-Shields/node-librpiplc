const rpiplc = require('bindings')('rpiplc.node');

const models = require('./models');

class RPIPLC {
	constructor(modelName) {
		this.modelName = modelName;
		this.hw = models[modelName];

		rpiplc.initPins();
	}

	get INPUT() { return 0; }
	get OUTPUT() { return 1; }

	get LOW() { return 0; }
	get HIGH() { return 1; }

	get version() { return rpiplc.version; }

	analogRead(pinName) { return rpiplc.analogRead(this.hw[pinName]); }
	analogWrite(pinName, value) { rpiplc.analogWrite(this.hw[pinName], value); }
	delay(value) { rpiplc.delay(value); }
	digitalRead(pinName) { return rpiplc.digitalRead(this.hw[pinName]); }
	digitalWrite(pinName, value) { rpiplc.digitalWrite(this.hw[pinName], value); }
	pinMode(pinName, mode) { rpiplc.pinMode(this.hw[pinName], mode); }
}

module.exports = function(modelName) {
	return new RPIPLC(modelName);
}
