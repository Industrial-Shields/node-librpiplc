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
