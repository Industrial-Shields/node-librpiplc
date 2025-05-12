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

#include "functions.h"

napi_value DeinitExpandedGPIONoResetFn(napi_env env, napi_callback_info info) {
	napi_status status;

	size_t argc = 0;
	napi_value argv[1];
	status = napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
	assert(status == napi_ok);

	if (argc != 0) {
		napi_throw_type_error(env, nullptr, "Wrong number of arguments");
		return nullptr;
	}

	if (_deinitExpandedGPIONoReset) {
		int ret = _deinitExpandedGPIONoReset();
		napi_value node_ret;
		status = napi_create_int32(env, ret, &node_ret);
		assert(status == napi_ok);
	}
	else {
		napi_throw_type_error(env, nullptr, "The function doesn't exist in this version of the library");
	}

	return nullptr;
}
