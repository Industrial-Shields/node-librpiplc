#include "fn.h"

napi_value DelayFn(napi_env env, napi_callback_info info) {
	napi_status status;

	size_t argc = 1;
	napi_value argv[1];
	status = napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
	assert(status == napi_ok);

	if (argc < 1) {
		napi_throw_type_error(env, nullptr, "Wrong number of arguments");
		return nullptr;
	}

	napi_valuetype argtype;
	status = napi_typeof(env, argv[0], &argtype);
	assert(status == napi_ok);

	if (argtype != napi_number) {
		napi_throw_type_error(env, nullptr, "Wrong argument");
		return nullptr;
	}

	uint32_t ms;
	status = napi_get_value_uint32(env, argv[0], &ms);
	assert(status == napi_ok);

	delay(ms);

	return nullptr;
}
