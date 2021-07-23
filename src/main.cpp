#include "fn.h"

#include <assert.h>
#include <node_api.h>

napi_value Init(napi_env env, napi_value exports) {
	napi_status status;

	napi_property_descriptor analogReadDesc = { "analogRead", nullptr, AnalogReadFn, nullptr, nullptr, nullptr, napi_default, nullptr };
	status = napi_define_properties(env, exports, 1, &analogReadDesc);
	assert(status == napi_ok);

	napi_property_descriptor analogWriteDesc = { "analogWrite", nullptr, AnalogWriteFn, nullptr, nullptr, nullptr, napi_default, nullptr };
	status = napi_define_properties(env, exports, 1, &analogWriteDesc);
	assert(status == napi_ok);

	napi_property_descriptor digitalReadDesc = { "digitalRead", nullptr, DigitalReadFn, nullptr, nullptr, nullptr, napi_default, nullptr };
	status = napi_define_properties(env, exports, 1, &digitalReadDesc);
	assert(status == napi_ok);

	napi_property_descriptor digitalWriteDesc = { "digitalWrite", nullptr, DigitalWriteFn, nullptr, nullptr, nullptr, napi_default, nullptr };
	status = napi_define_properties(env, exports, 1, &digitalWriteDesc);
	assert(status == napi_ok);

	napi_property_descriptor initPinsDesc = { "initPins", nullptr, InitPinsFn, nullptr, nullptr, nullptr, napi_default, nullptr };
	status = napi_define_properties(env, exports, 1, &initPinsDesc);
	assert(status == napi_ok);

	napi_property_descriptor pinModeDesc = { "pinMode", nullptr, PinModeFn, nullptr, nullptr, nullptr, napi_default, nullptr };
	status = napi_define_properties(env, exports, 1, &pinModeDesc);
	assert(status == napi_ok);

	napi_property_descriptor versionDesc = { "version", nullptr, VersionFn, nullptr, nullptr, nullptr, napi_default, nullptr };
	status = napi_define_properties(env, exports, 1, &versionDesc);
	assert(status == napi_ok);

	return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
