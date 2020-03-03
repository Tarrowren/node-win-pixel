#include <napi.h>
// #include <WinUser.h>

using namespace Napi;

Object InitAll(Env env, Object exports)
{
    exports.Set("asd", 332);
    return exports;
}

NODE_API_MODULE(pixel, InitAll)
