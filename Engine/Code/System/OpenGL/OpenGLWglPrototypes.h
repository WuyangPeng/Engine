///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 11:36)

#ifndef SYSTEM_WINDOWS_OPENGL_WGL_PROTOTYPES_H
#define SYSTEM_WINDOWS_OPENGL_WGL_PROTOTYPES_H

#include "System/SystemDll.h"

#include "Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsWglSwapInterval(int interval) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE GetWglSwapInterval() noexcept;

    NODISCARD OpenGLHglrc SYSTEM_DEFAULT_DECLARE CreateWglContext(WindowsHDC hDc) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE DeleteWglContext(OpenGLHglrc oldContext) noexcept;
    NODISCARD OpenGLHglrc SYSTEM_DEFAULT_DECLARE GetCurrentWglContext() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE MakeWglCurrent(WindowsHDC hDc, OpenGLHglrc newContext) noexcept;

    NODISCARD int SYSTEM_DEFAULT_DECLARE ChooseWindowPixelFormat(WindowsHDC hdc, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetWindowPixelFormat(WindowsHDC hdc, int format, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept;

    NODISCARD OpenGLProc SYSTEM_DEFAULT_DECLARE GetWglProcAddress(const char* glFunction) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE SwapDeviceBuffers(WindowsHDC hdc) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE DisplayColorBuffer(WindowsHDC hdc, int syncInterval) noexcept;

}

#endif  // SYSTEM_WINDOWS_OPENGL_WGL_PROTOTYPES_H
