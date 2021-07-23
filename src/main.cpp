#include "fn.h"

#include <assert.h>
#include <node_api.h>

#define ADD_FUNC(name, fn, desc) \
	napi_property_descriptor desc = { name, nullptr, fn, nullptr, nullptr, nullptr, napi_default, nullptr };\
	status = napi_define_properties(env, exports, 1, & desc);\
	assert(status == napi_ok);

napi_value Init(napi_env env, napi_value exports) {
	napi_status status;

	ADD_FUNC("analogRead", AnalogReadFn, analogReadDesc);
	ADD_FUNC("analogWrite", AnalogWriteFn, analogWriteDesc);
	ADD_FUNC("delay", DelayFn, delayDesc);
	ADD_FUNC("digitalRead", DigitalReadFn, digitalReadDesc);
	ADD_FUNC("digitalWrite", DigitalWriteFn, digitalWriteDesc);
	ADD_FUNC("initPins", InitPinsFn, initPinsDesc);
	ADD_FUNC("pinMode", PinModeFn, pinModeDesc);
	ADD_FUNC("version", VersionFn, versionDesc);

	return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
