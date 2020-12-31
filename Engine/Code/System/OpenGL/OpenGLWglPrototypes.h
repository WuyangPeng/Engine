//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/09/28 10:40)

#ifndef SYSTEM_WINDOW_OPENGL_WGL_PROTOTYPES_H
#define SYSTEM_WINDOW_OPENGL_WGL_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Using/OpenGLWglPrototypesUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    [[nodiscard]] OpenGLHdc SYSTEM_DEFAULT_DECLARE GetWglCurrentDC() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CopyWglContext(OpenGLHglrc arg1, OpenGLHglrc arg2, WindowUInt arg3) noexcept;
    [[nodiscard]] OpenGLHglrc SYSTEM_DEFAULT_DECLARE CreateWglContext(OpenGLHdc arg1) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DeleteWglContext(OpenGLHglrc arg1) noexcept;
    [[nodiscard]] OpenGLHglrc SYSTEM_DEFAULT_DECLARE GetWglCurrentContext() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE MakeWglCurrent(OpenGLHdc arg1, OpenGLHglrc arg2) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ShareWglLists(OpenGLHglrc arg1, OpenGLHglrc arg2) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SwapWglLayerBuffers(OpenGLHdc arg1, WindowUInt arg2) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE SwapWglMultipleBuffers(WindowUInt arg1, const WglSwap* arg2) noexcept;

    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE ChooseWindowPixelFormat(OpenGLHdc hdc, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetWindowPixelFormat(OpenGLHdc hdc, int format, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;

    [[nodiscard]] OpenGLProc SYSTEM_DEFAULT_DECLARE GetWglProcAddress(const char* glFunction) noexcept;
}

#endif  // SYSTEM_WINDOW_OPENGL_WGL_PROTOTYPES_H
