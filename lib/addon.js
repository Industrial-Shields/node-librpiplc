const rpiplc = require('bindings')('rpiplc.node');

const models = require('./models');

rpiplc.initPins();

class RPIPLC {
	constructor(modelName) {
		this.modelName = modelName;
		this.hw = models[modelName];
	}

	get INPUT() { return rpiplc.INPUT; }
	get OUTPUT() { return rpiplc.OUTPUT; }

	get LOW() { return rpiplc.LOW; }
	get HIGH() { return rpiplc.HIGH; }

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
