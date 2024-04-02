#include "fn.h"

napi_value AnalogWriteSetFrequencyFn(napi_env env, napi_callback_info info) {
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

	uint32_t desired_freq;
	status = napi_get_value_uint32(env, argv[1], &desired_freq);
	assert(status == napi_ok);

        int write_ret = analogWriteSetFrequency(pin, desired_freq);
	napi_value ret;
	status = napi_create_int32(env, write_ret, &ret);
	assert(status == napi_ok);
	
	return ret;
}
