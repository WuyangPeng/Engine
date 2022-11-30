///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 18:47)

#include "System/SystemExport.h"

#include "OpenGLWglPrototypes.h"
#include "Detail/WglExtensions.h"
#include "System/Helper/WindowsMacro.h"
#include "System/OpenGL/Detail/WglExtensions.h"

bool System::IsWglSwapInterval(int interval) noexcept
{
    if (WglSwapIntervalEXT(interval) != gFalse)
        return true;
    else
        return false;
}

int System::GetWglSwapInterval() noexcept
{
    return WglGetSwapIntervalEXT();
}

System::OpenGLHglrc System::CreateWglContext(WindowsHDC hDc) noexcept
{
    return WglCreateContext(hDc);
}

bool SYSTEM_DEFAULT_DECLARE System::DeleteWglContext(OpenGLHglrc oldContext) noexcept
{
    if (WglDeleteContext(oldContext) != gFalse)
        return true;
    else
        return false;
}

System::OpenGLHglrc System::GetCurrentWglContext() noexcept
{
    return WglGetCurrentContext();
}

bool System::MakeWglCurrent(WindowsHDC hDc, OpenGLHglrc newContext) noexcept
{
    if (WglMakeCurrent(hDc, newContext) != gFalse)
        return true;
    else
        return false;
}

int System::ChooseWindowPixelFormat(WindowsHDC hdc, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
    return System::ChoosePixelFormat(hdc, pixelFormatDescriptor);
}

bool System::SetWindowPixelFormat(WindowsHDC hdc, int format, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
    if (System::SetPixelFormat(hdc, format, pixelFormatDescriptor) != gFalse)
        return true;
    else
        return false;
}

System::OpenGLProc System::GetWglProcAddress(const char* glFunction) noexcept
{
    return WglGetProcAddress(glFunction);
}

bool System::SwapDeviceBuffers(WindowsHDC hdc) noexcept
{
#if defined(SYSTEM_PLATFORM_WIN32)

    if (System::SwapBuffers(hdc) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(hdc);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool SYSTEM_DEFAULT_DECLARE System::DisplayColorBuffer(WindowsHDC hdc, int syncInterval) noexcept
{
    if (WglSwapIntervalEXT(syncInterval > 0 ? 1 : 0) != gFalse && SwapDeviceBuffers(hdc))
        return true;
    else
        return false;
}
