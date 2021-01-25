#include "hidapi.h"
#include <napi.h>

Napi::Value checkBTPedal(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    hid_device *handle = hid_open(0x4e8, 28705, NULL);
    if (!handle)
    {
        printf("unable to open device\n");
        return Napi::Boolean::New(env, false);
    }
    else {
        return Napi::Boolean::New(env, true);
    }
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "checkBTPedal"), Napi::Function::New(env, checkBTPedal));
  return exports;
}
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);