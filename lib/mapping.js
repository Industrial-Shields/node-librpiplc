/*
Copyright (c) 2025 Industrial Shields. All rights reserved

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


// Enum for PeripheralType
const PeripheralType = {
    PLC_DIRECT: { value: 0x00 },
    PLC_PCA9685: { value: 0x01 },
    PLC_MCP23008: { value: 0x02 },
    PLC_MCP23017: { value: 0x03 },
    PLC_LTC2309: { value: 0x04 },
    PLC_ADS1015: { value: 0x05 }
};

/**
 * Construct a pin identifier for a peripheral according to the librpiplc specifications
 *
 * @param {Object} peripheralType - The type of peripheral (e.g., PLC_DIRECT, PLC_PCA9685).
 * @param {number} byte2 - The second byte of the pin identifier.
 * @param {number} byte3 - The third byte of the pin identifier.
 * @param {number} byte4 - The fourth byte of the pin identifier.
 * @returns {number} The constructed pin identifier.
 */
function _makePinPlc(peripheralType, byte2, byte3, byte4) {
    return ((peripheralType.value & 0xFF) << 24) |
           ((byte2 & 0xFF) << 16) |
           ((byte3 & 0xFF) << 8) |
           (byte4 & 0xFF);
}

/**
 * Create a pin identifier for a direct GPIO (also known as normal GPIO).
 *
 * @param {number} index - The index of the pin.
 * @returns {number} The constructed pin identifier for the direct PLC GPIO.
 */
function makePinDirect(index) {
    return _makePinPlc(
        PeripheralType.PLC_DIRECT,
        (index & 0xFF0000) >> 16,
        (index & 0xFF00) >> 8,
        index
    );
}

/**
 * Create a pin identifier for a PCA9685.
 *
 * @param {number} addr - The address of the PCA9685.
 * @param {number} index - The index of the pin.
 * @returns {number} The constructed pin identifier for the PCA9685.
 */
function makePinPca9685(addr, index) {
    return _makePinPlc(PeripheralType.PLC_PCA9685, addr, 0x00, index);
}

/**
 * Create a pin identifier for an MCP23008.
 *
 * @param {number} addr - The address of the MCP23008.
 * @param {number} index - The index of the pin.
 * @returns {number} The constructed pin identifier for the MCP23008.
 */
function makePinMcp23008(addr, index) {
    return _makePinPlc(PeripheralType.PLC_MCP23008, addr, 0x00, index);
}

/**
 * Create a pin identifier for an MCP23017.
 *
 * @param {number} addr - The address of the MCP23017.
 * @param {number} index - The index of the pin.
 * @returns {number} The constructed pin identifier for the MCP23017.
 */
function makePinMcp23017(addr, index) {
    return _makePinPlc(PeripheralType.PLC_MCP23017, addr, 0x00, index);
}

/**
 * Create a pin identifier for an LTC2309.
 *
 * @param {number} addr - The address of the LTC2309.
 * @param {number} index - The index of the pin.
 * @returns {number} The constructed pin identifier for the LTC2309.
 */
function makePinLtc2309(addr, index) {
    return _makePinPlc(PeripheralType.PLC_LTC2309, addr, 0x00, index);
}

/**
 * Create a pin identifier for an ADS1015.
 *
 * @param {number} addr - The address of the ADS1015.
 * @param {number} index - The index of the pin.
 * @returns {number} The constructed pin identifier for the ADS1015.
 */
function makePinAds1015(addr, index) {
    return _makePinPlc(PeripheralType.PLC_ADS1015, addr, 0x00, index);
}

// Export the functions
module.exports = {
    makePinDirect,
    makePinPca9685,
    makePinMcp23008,
    makePinMcp23017,
    makePinLtc2309,
    makePinAds1015,
    PeripheralType
};
