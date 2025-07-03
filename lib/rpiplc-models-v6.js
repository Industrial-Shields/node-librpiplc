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

const mapping = require("./mapping");

const analog0 = {
	"I0.0": mapping.makePinMcp23008(0x20, 0x04),
	"I0.1": mapping.makePinMcp23008(0x20, 0x02),
	"I0.2": mapping.makePinMcp23008(0x20, 0x03),
	"I0.3": mapping.makePinMcp23008(0x20, 0x00),
	"I0.4": mapping.makePinMcp23008(0x20, 0x01),
	"I0.5": mapping.makePinDirect(13),
	"I0.6": mapping.makePinDirect(12),
	"I0.7": mapping.makePinLtc2309(0x08, 0x06),
	"I0.8": mapping.makePinLtc2309(0x08, 0x00),
	"I0.9": mapping.makePinLtc2309(0x0A, 0x06),
	"I0.10": mapping.makePinLtc2309(0x08, 0x04),
	"I0.11": mapping.makePinLtc2309(0x0A, 0x04),
	"I0.12": mapping.makePinLtc2309(0x08, 0x02),

	"Q0.0": mapping.makePinPca9685(0x40, 0x0C),
	"Q0.1": mapping.makePinPca9685(0x40, 0x0B),
	"Q0.2": mapping.makePinPca9685(0x40, 0x0F),
	"Q0.3": mapping.makePinPca9685(0x40, 0x0E),
	"Q0.4": mapping.makePinPca9685(0x40, 0x06),
	"Q0.5": mapping.makePinPca9685(0x40, 0x07),
	"Q0.6": mapping.makePinPca9685(0x40, 0x02),
	"Q0.7": mapping.makePinPca9685(0x40, 0x00),

	"A0.5": mapping.makePinPca9685(0x40, 0x07),
	"A0.6": mapping.makePinPca9685(0x40, 0x02),
	"A0.7": mapping.makePinPca9685(0x40, 0x00),
};
const analog1 = {
	"I1.0": mapping.makePinMcp23008(0x21, 0x00),
	"I1.1": mapping.makePinMcp23008(0x20, 0x06),
	"I1.2": mapping.makePinMcp23008(0x21, 0x01),
	"I1.3": mapping.makePinMcp23008(0x20, 0x05),
	"I1.4": mapping.makePinMcp23008(0x21, 0x02),
	"I1.5": mapping.makePinDirect(27),
	"I1.6": mapping.makePinDirect(5),
	"I1.7": mapping.makePinLtc2309(0x08, 0x07),
	"I1.8": mapping.makePinLtc2309(0x08, 0x05),
	"I1.9": mapping.makePinLtc2309(0x0A, 0x07),
	"I1.10": mapping.makePinLtc2309(0x0A, 0x01),
	"I1.11": mapping.makePinLtc2309(0x08, 0x03),
	"I1.12": mapping.makePinLtc2309(0x0A, 0x00),

	"Q1.0": mapping.makePinPca9685(0x40, 0x0A),
	"Q1.1": mapping.makePinPca9685(0x41, 0x01),
	"Q1.2": mapping.makePinPca9685(0x40, 0x09),
	"Q1.3": mapping.makePinPca9685(0x41, 0x00),
	"Q1.4": mapping.makePinPca9685(0x40, 0x0D),
	"Q1.5": mapping.makePinPca9685(0x40, 0x08),
	"Q1.6": mapping.makePinPca9685(0x40, 0x05),
	"Q1.7": mapping.makePinPca9685(0x40, 0x01),

	"A1.5": mapping.makePinPca9685(0x40, 0x08),
	"A1.6": mapping.makePinPca9685(0x40, 0x05),
	"A1.7": mapping.makePinPca9685(0x40, 0x01),
};
const analog2 = {
	"I2.0": mapping.makePinMcp23008(0x21, 0x07),
	"I2.1": mapping.makePinMcp23008(0x21, 0x04),
	"I2.2": mapping.makePinMcp23008(0x21, 0x06),
	"I2.3": mapping.makePinMcp23008(0x21, 0x03),
	"I2.4": mapping.makePinMcp23008(0x21, 0x05),
	"I2.5": mapping.makePinDirect(26),
	"I2.6": mapping.makePinDirect(4),
	"I2.7": mapping.makePinLtc2309(0x08, 0x01),
	"I2.8": mapping.makePinLtc2309(0x0A, 0x03),
	"I2.9": mapping.makePinLtc2309(0x0A, 0x02),
	"I2.10": mapping.makePinLtc2309(0x28, 0x06),
	"I2.11": mapping.makePinLtc2309(0x0A, 0x05),
	"I2.12": mapping.makePinLtc2309(0x28, 0x07),

	"Q2.0": mapping.makePinPca9685(0x41, 0x07),
	"Q2.1": mapping.makePinPca9685(0x41, 0x06),
	"Q2.2": mapping.makePinPca9685(0x41, 0x03),
	"Q2.3": mapping.makePinPca9685(0x41, 0x05),
	"Q2.4": mapping.makePinPca9685(0x41, 0x02),
	"Q2.5": mapping.makePinPca9685(0x41, 0x04),
	"Q2.6": mapping.makePinPca9685(0x40, 0x04),
	"Q2.7": mapping.makePinPca9685(0x40, 0x03),

	"A2.5": mapping.makePinPca9685(0x41, 0x04),
	"A2.6": mapping.makePinPca9685(0x40, 0x04),
	"A2.7": mapping.makePinPca9685(0x40, 0x03),
};
const relay0 = {
	"I0.0": mapping.makePinDirect(13),
	"I0.1": mapping.makePinDirect(12),
	"I0.2": mapping.makePinLtc2309(0x08, 0x06),
	"I0.3": mapping.makePinLtc2309(0x08, 0x00),
	"I0.4": mapping.makePinLtc2309(0x0A, 0x06),
	"I0.5": mapping.makePinLtc2309(0x08, 0x04),

	"Q0.0": mapping.makePinPca9685(0x40, 0x07),
	"Q0.1": mapping.makePinPca9685(0x40, 0x02),
	"Q0.2": mapping.makePinPca9685(0x40, 0x00),

	"A0.0": mapping.makePinPca9685(0x40, 0x07),
	"A0.1": mapping.makePinPca9685(0x40, 0x02),
	"A0.2": mapping.makePinPca9685(0x40, 0x00),

	"R0.1": mapping.makePinMcp23008(0x20, 0x02),
	"R0.2": mapping.makePinMcp23008(0x20, 0x04),
	"R0.3": mapping.makePinMcp23008(0x20, 0x00),
	"R0.4": mapping.makePinMcp23008(0x20, 0x03),
	"R0.5": mapping.makePinPca9685(0x40, 0x06),
	"R0.6": mapping.makePinPca9685(0x40, 0x0E),
	"R0.7": mapping.makePinPca9685(0x40, 0x0F),
	"R0.8": mapping.makePinPca9685(0x40, 0x0B),
};
const relay1 = {
	"I1.0": mapping.makePinDirect(27),
	"I1.1": mapping.makePinDirect(5),
	"I1.2": mapping.makePinLtc2309(0x08, 0x07),
	"I1.3": mapping.makePinLtc2309(0x08, 0x05),
	"I1.4": mapping.makePinLtc2309(0x0A, 0x07),
	"I1.5": mapping.makePinLtc2309(0x0A, 0x01),

	"Q1.0": mapping.makePinPca9685(0x40, 0x08),
	"Q1.1": mapping.makePinPca9685(0x40, 0x05),
	"Q1.2": mapping.makePinPca9685(0x40, 0x01),

	"A1.0": mapping.makePinPca9685(0x40, 0x08),
	"A1.1": mapping.makePinPca9685(0x40, 0x05),
	"A1.2": mapping.makePinPca9685(0x40, 0x01),

	"R1.1": mapping.makePinMcp23008(0x20, 0x06),
	"R1.2": mapping.makePinMcp23008(0x21, 0x00),
	"R1.3": mapping.makePinMcp23008(0x20, 0x05),
	"R1.4": mapping.makePinMcp23008(0x21, 0x01),
	"R1.5": mapping.makePinPca9685(0x40, 0x0D),
	"R1.6": mapping.makePinPca9685(0x41, 0x00),
	"R1.7": mapping.makePinPca9685(0x40, 0x09),
	"R1.8": mapping.makePinPca9685(0x41, 0x01),
};
const relay2 = {
	"I2.0": mapping.makePinDirect(26),
	"I2.1": mapping.makePinDirect(4),
	"I2.2": mapping.makePinLtc2309(0x08, 0x01),
	"I2.3": mapping.makePinLtc2309(0x0A, 0x03),
	"I2.4": mapping.makePinLtc2309(0x0A, 0x02),
	"I2.5": mapping.makePinLtc2309(0x28, 0x06),

	"Q2.0": mapping.makePinPca9685(0x41, 0x04),
	"Q2.1": mapping.makePinPca9685(0x40, 0x04),
	"Q2.2": mapping.makePinPca9685(0x40, 0x03),

	"A2.0": mapping.makePinPca9685(0x41, 0x04),
	"A2.1": mapping.makePinPca9685(0x40, 0x04),
	"A2.2": mapping.makePinPca9685(0x40, 0x03),

	"R2.1": mapping.makePinMcp23008(0x21, 0x04),
	"R2.2": mapping.makePinMcp23008(0x21, 0x07),
	"R2.3": mapping.makePinMcp23008(0x21, 0x03),
	"R2.4": mapping.makePinMcp23008(0x21, 0x06),
	"R2.5": mapping.makePinPca9685(0x41, 0x02),
	"R2.6": mapping.makePinPca9685(0x41, 0x05),
	"R2.7": mapping.makePinPca9685(0x41, 0x03),
	"R2.8": mapping.makePinPca9685(0x41, 0x06),
};

extras = {
	"EXP1_RST": mapping.makePinPca9685(0x41, 0x0C),
	"EXP2_RST": mapping.makePinPca9685(0x41, 0x0D),
	"PIN8": mapping.makePinDirect(8),
	"P_RELAY": mapping.makePinDirect(26),
	"OPTO_OUT_2": mapping.makePinDirect(27),
	"OPTO_OUT_1": mapping.makePinDirect(13),
	"OPTO_IN_2": mapping.makePinDirect(5),
	"OPTO_IN_1": mapping.makePinDirect(12),
	"INT31": mapping.makePinDirect(4),
}

module.exports = {
	"RPIPLC_CPU": {...extras},
	"RPIPLC_19R": {...relay0, ...extras},
	"RPIPLC_21": {...analog0, ...extras},
	"RPIPLC_38AR": {...analog0, ...relay1, ...extras},
	"RPIPLC_38R": {...relay0, ...relay1, ...extras},
	"RPIPLC_42": {...analog0, ...analog1, ...extras},
	"RPIPLC_50RRA": {...relay0, ...relay1, ...analog2, ...extras},
	"RPIPLC_53ARR": {...analog0, ...relay1, ...relay2, ...extras},
	"RPIPLC_54ARA": {...analog0, ...relay1, ...analog2, ...extras},
	"RPIPLC_57AAR": {...analog0, ...analog1, ...relay2, ...extras},
	"RPIPLC_57R": {...relay0, ...relay1, ...relay2, ...extras},
	"RPIPLC_58": {...analog0, ...analog1, ...analog2, ...extras},
};
