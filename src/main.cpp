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

#include <assert.h>

napi_status InitVersioning(napi_env env, napi_value exports) {
	const int* cVersionMajor = (const int*)dlsym(rpiplc_dl, "LIB_RPIPLC_VERSION_MAJOR_NUM");
	assert(cVersionMajor != nullptr && "LIB_RPIPLC_VERSION_MAJOR_NUM not found");
	const int* cVersionMinor = (const int*)dlsym(rpiplc_dl, "LIB_RPIPLC_VERSION_MINOR_NUM");
	assert(cVersionMinor != nullptr && "LIB_RPIPLC_VERSION_MINOR_NUM not found");
	const int* cVersionPatch = (const int*)dlsym(rpiplc_dl, "LIB_RPIPLC_VERSION_PATCH_NUM");
	assert(cVersionPatch != nullptr && "LIB_RPIPLC_VERSION_PATCH_NUM not found");
	const char** cVersion = (const char**)dlsym(rpiplc_dl, "LIB_RPIPLC_VERSION");
	assert(cVersion != nullptr && "LIB_RPIPLC_VERSION not found");


	napi_status status;


	napi_value napiCVersionMajor;
	status = napi_create_int32(env, *cVersionMajor, &napiCVersionMajor);
	assert(status == napi_ok);

	napi_value napiCVersionMinor;
	status = napi_create_int32(env, *cVersionMinor, &napiCVersionMinor);
	assert(status == napi_ok);

	napi_value napiCVersionPatch;
	status = napi_create_int32(env, *cVersionPatch, &napiCVersionPatch);
	assert(status == napi_ok);

	napi_value napiCVersion;
	status = napi_create_string_utf8(env, *cVersion, NAPI_AUTO_LENGTH, &napiCVersion);
	assert(status == napi_ok);

	const napi_property_descriptor descriptors[] = {
		{ "cVersionMajor", nullptr, nullptr, nullptr, nullptr, napiCVersionMajor, napi_default, nullptr },
		{ "cVersionMinor", nullptr, nullptr, nullptr, nullptr, napiCVersionMinor, napi_default, nullptr },
		{ "cVersionPatch", nullptr, nullptr, nullptr, nullptr, napiCVersionPatch, napi_default, nullptr },
		{ "cVersion", nullptr, nullptr, nullptr, nullptr, napiCVersion, napi_default, nullptr }
	};


	const int numDescriptors = sizeof(descriptors) / sizeof(napi_property_descriptor);
	return napi_define_properties(env, exports, numDescriptors, descriptors);
}

napi_status InitConstants(napi_env env, napi_value exports) {
	napi_status status;

	napi_value cINPUT;
	status = napi_create_int32(env, 0, &cINPUT);
	assert(status == napi_ok);

	napi_value cOUTPUT;
	status = napi_create_int32(env, 1, &cOUTPUT);
	assert(status == napi_ok);

	napi_value cLOW;
	status = napi_create_int32(env, 0, &cLOW);
	assert(status == napi_ok);

	napi_value cHIGH;
	status = napi_create_int32(env, 1, &cHIGH);
	assert(status == napi_ok);

	const napi_property_descriptor descriptors[] = {
		{ "INPUT", nullptr, nullptr, nullptr, nullptr, cINPUT, napi_default, nullptr },
		{ "OUTPUT", nullptr, nullptr, nullptr, nullptr, cOUTPUT, napi_default, nullptr },
		{ "LOW", nullptr, nullptr, nullptr, nullptr, cLOW, napi_default, nullptr },
		{ "HIGH", nullptr, nullptr, nullptr, nullptr, cHIGH, napi_default, nullptr },
	};
	const int numDescriptors = sizeof(descriptors) / sizeof(napi_property_descriptor);
	return napi_define_properties(env, exports, numDescriptors, descriptors);
}

napi_status InitMethods(napi_env env, napi_value exports) {
	const napi_property_descriptor descriptors[] = {
		{ "analogRead", nullptr, AnalogReadFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "analogWrite", nullptr, AnalogWriteFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "analogWriteSetFrequency", nullptr, AnalogWriteSetFrequencyFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "_cPopulateArrays", nullptr, _cPopulateArraysFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "deinitExpandedGPIO", nullptr, DeinitExpandedGPIOFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "deinitExpandedGPIONoReset", nullptr, DeinitExpandedGPIONoResetFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "delay", nullptr, DelayFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "digitalRead", nullptr, DigitalReadFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "digitalWrite", nullptr, DigitalWriteFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "initExpandedGPIO", nullptr, InitExpandedGPIOFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "pinMode", nullptr, PinModeFn, nullptr, nullptr, nullptr, napi_default, nullptr },
	};
	const int numDescriptors = sizeof(descriptors) / sizeof(napi_property_descriptor);
	return napi_define_properties(env, exports, numDescriptors, descriptors);
}

void* rpiplc_dl = nullptr;

napi_value Init(napi_env env, napi_value exports) {

	rpiplc_dl = dlopen("librpiplc.so.4", RTLD_NOW);
	if (rpiplc_dl == nullptr) {
		rpiplc_dl = dlopen("librpiplc.so", RTLD_NOW);
	}
	if (rpiplc_dl == nullptr) {
		rpiplc_dl = dlopen("librpiplc.so.3", RTLD_NOW);
	}
	if (rpiplc_dl == nullptr) {
		napi_throw_error(env, nullptr, "librpiplc is not installed in this system");
		return nullptr;
	}

	const int* cVersionMajor = (const int*)dlsym(rpiplc_dl, "LIB_RPIPLC_VERSION_MAJOR_NUM");
	assert(cVersionMajor != nullptr && "LIB_RPIPLC_VERSION_MAJOR_NUM not found");
	bool isOlderThan4 = *cVersionMajor < 4;
	loadSymbols(isOlderThan4);


	napi_status status;

	status = InitVersioning(env, exports);
	assert(status == napi_ok);

	status = InitConstants(env, exports);
	assert(status == napi_ok);

	status = InitMethods(env, exports);
	assert(status == napi_ok);

	return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
