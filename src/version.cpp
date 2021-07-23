#include "fn.h"
#include "version.h"

napi_value VersionFn(napi_env env, napi_callback_info info) {
	napi_status status;

	size_t argc = 0;
	status = napi_get_cb_info(env, info, &argc, nullptr, nullptr, nullptr);
	assert(status == napi_ok);

	napi_value argv[argc];
	status = napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
	assert(status == napi_ok);

	napi_value version;
	status = napi_create_string_utf8(env, AppVersion, NAPI_AUTO_LENGTH, &version);
	assert(status == napi_ok);

	return version;
}
