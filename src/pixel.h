#ifndef PIXEL_H
#define PIXEL_H

#include <napi.h>
#include <Windows.h>

class Pixel : public Napi::ObjectWrap<Pixel>
{
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Pixel(const Napi::CallbackInfo &info);
    ~Pixel();

private:
    static Napi::FunctionReference constructor;

    Napi::Value GetPixelEx(const Napi::CallbackInfo &info);

    HDC hDC_;
};

#endif
