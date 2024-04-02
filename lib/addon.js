const rpiplc = require("bindings")("rpiplc.node");

const ROOT_PATH = __dirname;

class UnknownPLCConf {
	constructor(message) {
		this.message = message;
		this.name = "Error";
	}
}

class RPIPLC {
	constructor(versionName, modelName, restart_peripherals = false) {
		rpiplc.initExpandedGPIO(restart_peripherals);

		let allModels;

		if (versionName === "RPIPLC_V5") {
			allModels = require("./models-v5");
		}
		else if (versionName === "RPIPLC_V4") {
			allModels = require("./models-v4");
		}
		else if (versionName === "RPIPLC_V3") {
			allModels = require("./models-v3");
		}
		else {
			throw new UnknownPLCConf(`Unknown version ${version_name}, the only available versions are RPIPLC_V5, RPIPLC_V4 and RPIPLC_V3`)
		}

		this.hw = allModels[modelName];
	}

	get INPUT() { return rpiplc.INPUT; }
	get OUTPUT() { return rpiplc.OUTPUT; }

	get LOW() { return rpiplc.LOW; }
	get HIGH() { return rpiplc.HIGH; }

	get version() { return rpiplc.version; }

	analogRead(pinName) { return rpiplc.analogRead(this.hw[pinName]); }
	analogWrite(pinName, value) { return rpiplc.analogWrite(this.hw[pinName], value); }
	analogWriteSetFrequency(pinName, value) { return rpiplc.analogWriteSetFrequency(this.hw[pinName], value); }
	delay(value) { rpiplc.delay(value); }
	digitalRead(pinName) { return rpiplc.digitalRead(this.hw[pinName]); }
	digitalWrite(pinName, value) { return rpiplc.digitalWrite(this.hw[pinName], value); }
	pinMode(pinName, mode) { return rpiplc.pinMode(this.hw[pinName], mode); }
}

module.exports = function(versionName, modelName) {
	return new RPIPLC(versionName, modelName);
}
