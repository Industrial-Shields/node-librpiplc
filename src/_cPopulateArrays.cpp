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
#include <string>

napi_value _cPopulateArraysFn(napi_env env, napi_callback_info info) {
	assert(_peripherals_struct != nullptr);
	
	napi_status status;
  	napi_valuetype argtype;
	size_t str_len;

	size_t argc = 2;
	napi_value argv[2];
	status = napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
	assert(status == napi_ok);

	if (argc < 2) {
		napi_throw_type_error(env, nullptr, "Wrong number of arguments");
		return nullptr;
	}

	status = napi_typeof(env, argv[0], &argtype);
	assert(status == napi_ok);
	if (argtype != napi_string) {
		napi_throw_type_error(env, nullptr, "Wrong argument");
		return nullptr;
	}
	status = napi_get_value_string_utf8(env, argv[0], nullptr, 0, &str_len);
	assert(status == napi_ok);
	std::string version_name(str_len, '\0');
	status = napi_get_value_string_utf8(env, argv[0], version_name.data(), version_name.size(), &str_len);
	assert(status == napi_ok);

	status = napi_typeof(env, argv[1], &argtype);
	assert(status == napi_ok);
	if (argtype != napi_string) {
		napi_throw_type_error(env, nullptr, "Wrong argument");
		return nullptr;
	}
	status = napi_get_value_string_utf8(env, argv[1], nullptr, 0, &str_len);
	assert(status == napi_ok);
	std::string model_name(str_len, '\0');
	status = napi_get_value_string_utf8(env, argv[1], model_name.data(), model_name.size(), &str_len);
	assert(status == napi_ok);

	if (version_name == "RPIPLC_V3" || version_name == "RPIPLC_V4" ||
	    version_name == "RPIPLC_V6") {
		static uint8_t mcp23008_array[] = {0x20, 0x21};
		_peripherals_struct->arrayMCP23008 = mcp23008_array;
		_peripherals_struct->numArrayMCP23008 = sizeof(mcp23008_array) / sizeof(mcp23008_array[0]);
	}
	else {
		_peripherals_struct->arrayMCP23008 = nullptr;
		_peripherals_struct->numArrayMCP23008 = 0;
	}

	if (version_name == "RPIPLC_V3") {
		static uint8_t ads1015_array[] = {0x48, 0x49, 0x4A, 0x4B};
		_peripherals_struct->arrayADS1015 = ads1015_array;
		_peripherals_struct->numArrayADS1015 =
		    sizeof(ads1015_array) / sizeof(ads1015_array[0]);
	}
	else if (version_name == "TOUCHBERRY_PI_V1") {
		static uint8_t ads1015_array[] = {0x49};
		_peripherals_struct->arrayADS1015 = ads1015_array;
		_peripherals_struct->numArrayADS1015 =
		    sizeof(ads1015_array) / sizeof(ads1015_array[0]);
	}
	else {
		_peripherals_struct->arrayADS1015 = nullptr;
		_peripherals_struct->numArrayADS1015 = 0;
	}

	if (version_name == "RPIPLC_V3" || version_name == "RPIPLC_V4" ||
	    version_name == "RPIPLC_V6") {
		static uint8_t pca9685_array[] = {0x40, 0x41};
		_peripherals_struct->arrayPCA9685 = pca9685_array;
		_peripherals_struct->numArrayPCA9685 =
		    sizeof(pca9685_array) / sizeof(pca9685_array[0]);
	}
	else {
		_peripherals_struct->arrayPCA9685 = nullptr;
		_peripherals_struct->numArrayPCA9685 = 0;
	}

	if (version_name == "RPIPLC_V4" || version_name == "RPIPLC_V6") {
		if (model_name == "RPIPLC_21" || model_name == "RPIPLC_19R" ||
		    model_name == "RPIPLC") {
			static uint8_t ltc2309_array[] = {0x08, 0x0A};
			_peripherals_struct->arrayLTC2309 = ltc2309_array;
			_peripherals_struct->numArrayLTC2309 =
			    sizeof(ltc2309_array) / sizeof(ltc2309_array[0]);
		}
		else {
			static uint8_t ltc2309_array[] = {0x08, 0x0A, 0x28};
			_peripherals_struct->arrayLTC2309 = ltc2309_array;
			_peripherals_struct->numArrayLTC2309 =
			    sizeof(ltc2309_array) / sizeof(ltc2309_array[0]);
		}
	}
	else {
		_peripherals_struct->arrayLTC2309 = nullptr;
		_peripherals_struct->numArrayLTC2309 = 0;
	}

	_peripherals_struct->arrayMCP23017 = nullptr;
	_peripherals_struct->numArrayMCP23017 = 0;

	return nullptr;
}
