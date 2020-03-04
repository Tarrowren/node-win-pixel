#include <napi.h>
#include "pixel.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    return Pixel::Init(env, exports);
}

NODE_API_MODULE(pixel, InitAll)
