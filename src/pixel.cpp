#include "pixel.h"

Napi::FunctionReference Pixel::constructor;

Napi::Object Pixel::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    auto func = DefineClass(env,
                            "Pixel",
                            {InstanceMethod("getPixel", &Pixel::GetPixelEx)});
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();

    exports.Set("Pixel", func);
    return exports;
}

Pixel::Pixel(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<Pixel>(info), hDC_(GetDC(nullptr))
{
    auto env = info.Env();
    Napi::HandleScope scope(env);
}

Pixel::~Pixel()
{
    ReleaseDC(nullptr, hDC_);
}

Napi::Value Pixel::GetPixelEx(const Napi::CallbackInfo &info)
{
    auto env = info.Env();

    if (info.Length() != 2)
    {
        Napi::Error::New(env, "the wrong number of arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    if (!info[0].IsNumber() || !info[1].IsNumber())
    {
        Napi::TypeError::New(env, "the wrong type of argument").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    auto x = info[0].ToNumber().Int32Value();
    auto y = info[1].ToNumber().Int32Value();

    auto pixel = GetPixel(hDC_, x, y);
    if (pixel == CLR_INVALID)
    {
        Napi::Error::New(env, "invalid value").ThrowAsJavaScriptException();
        return env.Undefined();
    }
    else
    {
        auto rgb = Napi::Object::New(env);
        rgb.Set("r", GetRValue(pixel));
        rgb.Set("g", GetGValue(pixel));
        rgb.Set("b", GetBValue(pixel));

        return rgb;
    }
}
