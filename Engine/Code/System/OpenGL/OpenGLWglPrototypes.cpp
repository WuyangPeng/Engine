///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.5 (2021/06/25 22:56)

#include "System/SystemExport.h"

#include "OpenGLWglPrototypes.h"
#include "Detail/WglExtensions.h"
#include "System/Helper/WindowsMacro.h"

bool System::IsWglSwapInterval(int interval) noexcept
{
    if (WglSwapIntervalEXT(interval) != g_False)
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
    if (WglDeleteContext(oldContext) != g_False)
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
    if (WglMakeCurrent(hDc, newContext) != g_False)
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
    if (System::SetPixelFormat(hdc, format, pixelFormatDescriptor) != g_False)
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

    if (System::SwapBuffers(hdc) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHDC>(hdc);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
