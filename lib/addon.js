/*
Copyright (c) 2024 Industrial Shields. All rights reserved

This file is part of node-librpiplc.

EUPL-1.2 notice:
LIBARY is licensed under the EUPL,
with extension of article 5 (compatibility clause) to any licence
for distributing derivative works that have been produced by the
normal use of the Work as a library.

LGPL-3.0-or-later notice:
node-librpiplc is free software: you can redistribute
it and/or modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation, either version
3 of the License, or (at your option) any later version.

node-librpiplc is distributed in the hope that it will
be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

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
		const { version: nodeJSVersion } = require("../package.json");
		this.nodeJSVersion = nodeJSVersion;
		const [major, minor, patch] = nodeJSVersion.split('.').map(Number);
		this.nodeJSVersionMajor = major;
		this.nodeJSVersionMinor = minor;
		this.nodeJSVersionPatch = patch;

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
			throw new UnknownPLCConf(`Unknown version ${versionName}, the only available versions are RPIPLC_V5, RPIPLC_V4 and RPIPLC_V3`)
		}

		this.hw = allModels[modelName];
	}

	get INPUT() { return rpiplc.INPUT; }
	get OUTPUT() { return rpiplc.OUTPUT; }

	get LOW() { return rpiplc.LOW; }
	get HIGH() { return rpiplc.HIGH; }

	get cVersionMajor() { return rpiplc.cVersionMajor; }
	get cVersionMinor() { return rpiplc.cVersionMinor; }
	get cVersionPatch() { return rpiplc.cVersionPatch; }
	get cVersion() { return rpiplc.cVersion; }

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
