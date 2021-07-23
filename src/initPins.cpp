#include "fn.h"

napi_value InitPinsFn(napi_env env, napi_callback_info info) {
	initPins();
	return nullptr;
}
