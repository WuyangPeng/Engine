/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 17:37)

#ifndef SYSTEM_WINDOWS_OPENGL_WGL_PROTOTYPES_H
#define SYSTEM_WINDOWS_OPENGL_WGL_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsWglSwapInterval(int interval) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetWglSwapInterval() noexcept;

    NODISCARD OpenGLRcHandle SYSTEM_DEFAULT_DECLARE CreateWglContext(WindowsHdc hdc) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE DeleteWglContext(OpenGLRcHandle oldContext) noexcept;
    NODISCARD OpenGLRcHandle SYSTEM_DEFAULT_DECLARE GetCurrentWglContext() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE MakeWglCurrent(WindowsHdc hdc, OpenGLRcHandle newContext) noexcept;

    NODISCARD int SYSTEM_DEFAULT_DECLARE ChooseWindowPixelFormat(WindowsHdc hdc, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetWindowPixelFormat(WindowsHdc hdc, int format, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;

    NODISCARD OpenGLProc SYSTEM_DEFAULT_DECLARE GetWglProcAddress(const char* glFunction) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SwapDeviceBuffers(WindowsHdc hdc) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE DisplayColorBuffer(WindowsHdc hdc, int syncInterval) noexcept;

}

#endif  // SYSTEM_WINDOWS_OPENGL_WGL_PROTOTYPES_H
