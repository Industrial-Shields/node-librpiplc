/**
 * Copyright (c) 2025 Industrial Shields. All rights reserved
 *
 * This file is part of node-librpiplc.
 *
 * EUPL-1.2 notice:
 * LIBARY is licensed under the EUPL,
 * with extension of article 5 (compatibility clause) to any licence
 * for distributing derivative works that have been produced by the
 * normal use of the Work as a library.
 *
 * LGPL-3.0-or-later notice:
 * node-librpiplc is free software: you can redistribute
 * it and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either version
 * 3 of the License, or (at your option) any later version.
 *
 * node-librpiplc is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "functions.h"
#include <cstdint>

// Define the function pointers
int (*_initExpandedGPIO)(bool);
int (*_deinitExpandedGPIO)();
int (*_deinitExpandedGPIONoReset)();
int (*_pinMode)(uint32_t, uint8_t);
int (*_digitalWrite)(uint32_t, uint8_t);
int (*_digitalRead)(uint32_t);
int (*_analogWrite)(uint32_t, uint16_t);
int (*_analogWriteSetFrequency)(uint32_t, uint32_t);
uint16_t (*_analogRead)(uint32_t);
int (*_digitalWriteAll)(uint8_t, uint32_t);
int (*_digitalReadAll)(uint8_t, void*);
int (*_analogWriteAll)(uint8_t, const void*);
void (*_delay)(uint32_t);

peripherals_t* _peripherals_struct = NULL;

// Function to load symbols from the shared library
int loadSymbols(bool isOlderThan4) {
	if (rpiplc_dl == nullptr) {
		return -1;
	}

	if (!isOlderThan4) {
		_peripherals_struct = (peripherals_t*) dlsym(rpiplc_dl, "_peripherals_struct");
		if (_peripherals_struct == nullptr) {
			return -1;
		}
	}
	_initExpandedGPIO = (int (*)(bool)) dlsym(rpiplc_dl, "initExpandedGPIO");
	if (_initExpandedGPIO == nullptr) {
		return -1;
	}

	_deinitExpandedGPIO = (int (*)()) dlsym(rpiplc_dl, "deinitExpandedGPIO");
	if (_deinitExpandedGPIO == nullptr) {
		return -1;
	}

	if (!isOlderThan4) {
		_deinitExpandedGPIONoReset = (int (*)()) dlsym(rpiplc_dl, "deinitExpandedGPIONoReset");
		if (_deinitExpandedGPIONoReset == nullptr) {
			return -1;
		}
	}

	
	_delay = (void (*)(uint32_t)) dlsym(rpiplc_dl, "delay");
	if (_delay == nullptr) {
		return -1;
	}

	_pinMode = (int (*)(uint32_t, uint8_t)) dlsym(rpiplc_dl, "pinMode");
	if (_pinMode == nullptr) {
		return -1;
	}

	_digitalWrite = (int (*)(uint32_t, uint8_t)) dlsym(rpiplc_dl, "digitalWrite");
	if (_digitalWrite == nullptr) {
		return -1;
	}

	_digitalRead = (int (*)(uint32_t)) dlsym(rpiplc_dl, "digitalRead");
	if (_digitalRead == nullptr) {
		return -1;
	}

	_analogWrite = (int (*)(uint32_t, uint16_t)) dlsym(rpiplc_dl, "analogWrite");
	if (_analogWrite == nullptr) {
		return -1;
	}

	_analogWriteSetFrequency = (int (*)(uint32_t, uint32_t)) dlsym(rpiplc_dl, "analogWriteSetFrequency");
	if (_analogWriteSetFrequency == nullptr) {
		return -1;
	}

	_analogRead = (uint16_t (*)(uint32_t)) dlsym(rpiplc_dl, "analogRead");
	if (_analogRead == nullptr) {
		return -1;
	}

	_digitalWriteAll = (int (*)(uint8_t, uint32_t)) dlsym(rpiplc_dl, "digitalWriteAll");
	if (_digitalWriteAll == nullptr) {
		return -1;
	}

	_digitalReadAll = (int (*)(uint8_t, void*)) dlsym(rpiplc_dl, "digitalReadAll");
	if (_digitalReadAll == nullptr) {
		return -1;
	}

	_analogWriteAll = (int (*)(uint8_t, const void*)) dlsym(rpiplc_dl, "analogWriteAll");
	if (_analogWriteAll == nullptr) {
		return -1;
	}

	return 0;
}
