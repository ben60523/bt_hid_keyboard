#include "hidapi.h"
#include <cstdio>
#include <napi.h>

Napi::Value enumerate(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();
  struct hid_device_info *devices, *cur_dev;
  devices = hid_enumerate(0x0, 0x0);
  cur_dev = devices;
  while (cur_dev) {
    // printf("Device: vid/pid: %04hx/%04hx\n  path: %s\n  serial_number: %ls usage_page: %x, usage: %x",
    //   cur_dev->vendor_id, cur_dev->product_id, cur_dev->path, cur_dev->serial_number, cur_dev->usage_page, cur_dev->usage);
    // printf("\n");
    // printf("  Manufacturer: %ls\n", cur_dev->manufacturer_string);
    // printf("  Product:      %ls\n", cur_dev->product_string);
    // printf("\n");
    if( cur_dev->vendor_id == 0x4e8 && cur_dev->product_id == 28705 ) {
      hid_free_enumeration(devices);
      printf("%ls\n", cur_dev->product_string);
      return Napi::Boolean::New(env, true);
    }
    cur_dev = cur_dev->next;
  }
  hid_free_enumeration(devices);
  return Napi::Boolean::New(env, false);
}

Napi::Value checkBTPedal(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
# ifdef __APPLE__
    return enumerate(info);
# else
    hid_init();
    hid_device *handle = hid_open(0x4e8, 28705, NULL);
    if (!handle)
    {
        printf("unable to open device\n");
        printf("%ls\n", hid_error(handle));
        hid_close(handle);
        hid_exit();
        return Napi::Boolean::New(env, false);
    }
    else {
        hid_close(handle);
        hid_exit();
        return Napi::Boolean::New(env, true);
    }
#endif
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(Napi::String::New(env, "checkBTPedal"), Napi::Function::New(env, checkBTPedal));
  exports.Set(Napi::String::New(env, "enumerate"), Napi::Function::New(env, enumerate));
  return exports;
}
NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init);