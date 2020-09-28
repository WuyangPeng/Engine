//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:16)

#ifndef SYSTEM_OPENGL_WGL_EXTENSIONS_USING_H
#define SYSTEM_OPENGL_WGL_EXTENSIONS_USING_H

#include "System/SystemDll.h"

#include "System/Helper/Detail/OpenGL/WglExtensionsMacro.h"

#if defined(SYSTEM_PLATFORM_WIN32)

    #include "System/Helper/Platform.h"

// (ARB 11) WGL_ARB_pbuffer

DECLARE_HANDLE(HPBUFFERARB);

// (EXT 171) WGL_EXT_pbuffer

using HPBUFFEREXT = HPBUFFERARB;

using WglHPBufferARB = HPBUFFERARB;
using WglHPBufferEXT = HPBUFFEREXT;
using WglHandle = HANDLE;
using WglHDC = HDC;
using WglUInt = UINT;
using WglBool = BOOL;
using WglFloat = FLOAT;
using WglHGLRC = HGLRC;

#else  // !SYSTEM_PLATFORM_WIN32

extern "C"
{
    using WglHandle = void*;
    struct WglHDC__
    {
        int unused;
    };
    using WglHDC = struct WglHDC__*;
    using WglUInt = uint32_t;
    using WglBool = int;
    using WglFloat = float;
    struct WglHGLRC__
    {
        int unused;
    };
    using WglHGLRC = struct WglHGLRC__*;
    struct WglHPBufferARB__
    {
        int unused;
    };
    using WglHPBufferARB = struct WglHPBufferARB__*;
    using WglHPBufferEXT = WglHPBufferARB;
}

#endif  // SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_OPENGL_WGL_EXTENSIONS_USING_H
