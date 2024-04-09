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

#ifndef __NODE_ADDON_FN_H__
#define __NODE_ADDON_FN_H__

#include <node_api.h>
#include <assert.h>
#include <rpiplc.h>

napi_value AnalogReadFn(napi_env env, napi_callback_info info);
napi_value AnalogWriteFn(napi_env env, napi_callback_info info);
napi_value AnalogWriteSetFrequencyFn(napi_env env, napi_callback_info info);
napi_value DelayFn(napi_env env, napi_callback_info info);
napi_value DigitalReadFn(napi_env env, napi_callback_info info);
napi_value DigitalWriteFn(napi_env env, napi_callback_info info);
napi_value InitExpandedGPIOFn(napi_env env, napi_callback_info info);
napi_value PinModeFn(napi_env env, napi_callback_info info);

#endif
