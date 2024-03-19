#include "fn.h"
#include "version.h"

#include <assert.h>
#include <node_api.h>

napi_status InitVersioning(napi_env env, napi_value exports) {
	napi_status status;

	napi_value version;
	status = napi_create_string_utf8(env, AppVersion, NAPI_AUTO_LENGTH, &version);
	assert(status == napi_ok);

	const napi_property_descriptor descriptors[] = {
		{ "version", nullptr, nullptr, nullptr, nullptr, version, napi_default, nullptr },
	};
	const int numDescriptors = sizeof(descriptors) / sizeof(napi_property_descriptor);
	return napi_define_properties(env, exports, numDescriptors, descriptors);
}

napi_status InitConstants(napi_env env, napi_value exports) {
	napi_status status;

	napi_value cINPUT;
	status = napi_create_int32(env, INPUT, &cINPUT);
	assert(status == napi_ok);

	napi_value cOUTPUT;
	status = napi_create_int32(env, OUTPUT, &cOUTPUT);
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
		{ "delay", nullptr, DelayFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "digitalRead", nullptr, DigitalReadFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "digitalWrite", nullptr, DigitalWriteFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "initExpandedGPIO", nullptr, InitExpandedGPIOFn, nullptr, nullptr, nullptr, napi_default, nullptr },
		{ "pinMode", nullptr, PinModeFn, nullptr, nullptr, nullptr, napi_default, nullptr },
	};
	const int numDescriptors = sizeof(descriptors) / sizeof(napi_property_descriptor);
	return napi_define_properties(env, exports, numDescriptors, descriptors);
}

napi_value Init(napi_env env, napi_value exports) {
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
