/**
 * Copyright (c) 2024 Industrial Shields. All rights reserved
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

#include "fn.h"

napi_value DigitalWriteFn(napi_env env, napi_callback_info info) {
	napi_status status;
	napi_valuetype argtype;

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

	if (argtype != napi_number) {
		napi_throw_type_error(env, nullptr, "Wrong argument");
		return nullptr;
	}

	status = napi_typeof(env, argv[1], &argtype);
	assert(status == napi_ok);

	if (argtype != napi_number) {
		napi_throw_type_error(env, nullptr, "Wrong argument");
		return nullptr;
	}

	uint32_t pin;
	status = napi_get_value_uint32(env, argv[0], &pin);
	assert(status == napi_ok);

	uint32_t value;
	status = napi_get_value_uint32(env, argv[1], &value);
	assert(status == napi_ok);

        int write_ret = digitalWrite(pin, value);
	napi_value ret;
	status = napi_create_int32(env, write_ret, &ret);
	assert(status == napi_ok);

	return ret;
}
