#include "fn.h"

napi_value InitExpandedGPIOFn(napi_env env, napi_callback_info info) {
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

	if (argtype != napi_boolean) {
		napi_throw_type_error(env, nullptr, "Wrong argument");
		return nullptr;
	}

        bool restart_peripherals;
	status = napi_get_value_bool(env, argv[0], &restart_peripherals);
	assert(status == napi_ok);

        int32_t ret = initExpandedGPIO(restart_peripherals);
	napi_value node_ret;
	status = napi_create_int32(env, ret, &node_ret);
	assert(status == napi_ok);

	return nullptr;
}
