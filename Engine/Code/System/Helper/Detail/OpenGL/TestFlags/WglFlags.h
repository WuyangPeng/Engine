//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 17:41)

#ifndef SYSTEM_HELPER_WGL_FLAGS_H
#define SYSTEM_HELPER_WGL_FLAGS_H

#include "System/Helper/UserMacro.h"

namespace System
{
    enum class WGLARBBufferRegion
    {
        CreateBufferRegionARB,
        DeleteBufferRegionARB,
        SaveBufferRegionARB,
        RestoreBufferRegionARB,
    };

    enum class WGLARBExtensionsString
    {
        GetExtensionsStringARB,
    };

    enum class WGLARBPixelFormat
    {
        GetPixelFormatAttribivARB,
        GetPixelFormatAttribfvARB,
        ChoosePixelFormatARB
    };

    enum class WGLARBMakeCurrentRead
    {
        MakeContextCurrentARB,
        GetCurrentReadDCARB,
    };

    enum class WGLARBPbuffer
    {
        CreatePbufferARB,
        GetPbufferDCARB,
        ReleasePbufferDCARB,
        DestroyPbufferARB,
        QueryPbufferARB
    };

    enum class WGLARBRenderTexture
    {
        BindTexImageARB,
        ReleaseTexImageARB,
        SetPbufferAttribARB,
    };

    enum class WGLARBCreateContext
    {
        CreateContextAttribsARB
    };

    enum class WGLEXTDisplayColorTable
    {
        CreateDisplayColorTableEXT,
        LoadDisplayColorTableEXT,
        BindDisplayColorTableEXT,
        DestroyDisplayColorTableEXT
    };

    enum class WGLEXTExtensionsString
    {
        GetExtensionsStringEXT,
    };

    enum class WGLEXTMakeCurrentRead
    {
        MakeContextCurrentEXT,
        GetCurrentReadDCEXT,
    };

    enum class WGLEXTPixelFormat
    {
        GetPixelFormatAttribivEXT,
        GetPixelFormatAttribfvEXT,
        ChoosePixelFormatEXT,
    };

    enum class WGLEXTPbuffer
    {
        CreatePbufferEXT,
        GetPbufferDCEXT,
        ReleasePbufferDCEXT,
        DestroyPbufferEXT,
        QueryPbufferEXT
    };

    enum class WGLEXTSwapControl
    {
        SwapIntervalEXT,
        GetSwapIntervalEXT
    };
}

#endif  // SYSTEM_HELPER_WGL_FLAGS_H
