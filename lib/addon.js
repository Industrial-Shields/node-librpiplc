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

		const isLibrary4 = rpiplc.cVersionMajor >= 4;

		const availableVersions = {
			"RPIPLC_V6": "rpiplc-models-v6",
			"RPIPLC_V4": "rpiplc-models-v4",
			"RPIPLC_V3": "rpiplc-models-v3",
			"UPSAFEPI_V6": "upsafepi-models-v6",
			"GATEBERRY_V9": "gateberry-models-v9",
			"TOUCHBERRY_PI_V1": "touchberry-pi-models-v1"
		}

		let selectedVersion = availableVersions[versionName];
		try {
			if (!isLibrary4) {
				selectedVersion = `old-${selectedVersion}`;
			}
			this.hw = require(`./${selectedVersion}`)[modelName];
		}
		catch {
			const keysStr = Object.keys(availableVersions).join(", ");
			const errorMsg = `Unknown version ${versionName}, the available versions are: ${keysStr}`;
			throw new UnknownPLCConf(errorMsg);
		}
		if (typeof this.hw === "undefined") {
			const keysStr = Object.keys(require(`./${selectedVersion}`)).join(", ");
			const errorMsg = `Unknown model ${modelName}, the available models are: ${keysStr}`;
			throw new UnknownPLCConf(errorMsg);
		}

		if (isLibrary4) {
			rpiplc._cPopulateArrays(versionName, modelName)
		}

		this.rc = rpiplc.initExpandedGPIO(restart_peripherals);
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
	deinitExpandedGPIO() { return rpiplc.deinitExpandedGPIO(); }
	deinitExpandedGPIONoReset() { return rpiplc.deinitExpandedGPIONoReset(); }
	delay(value) { rpiplc.delay(value); }
	digitalRead(pinName) { return rpiplc.digitalRead(this.hw[pinName]); }
	digitalWrite(pinName, value) { return rpiplc.digitalWrite(this.hw[pinName], value); }
	initExpandedGPIO(reset) { return rpiplc.initExpandedGPIO(reset); }
	pinMode(pinName, mode) { return rpiplc.pinMode(this.hw[pinName], mode); }
}

module.exports = function(versionName, modelName) {
	return new RPIPLC(versionName, modelName);
}
