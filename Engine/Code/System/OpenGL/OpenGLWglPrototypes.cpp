/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 17:25)

#include "System/SystemExport.h"

#include "OpenGLWglPrototypes.h"
#include "Detail/WglExtensions.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

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

System::OpenGLRcHandle System::CreateWglContext(WindowsHdc hDc) noexcept
{
    return WglCreateContext(hDc);
}

bool SYSTEM_DEFAULT_DECLARE System::DeleteWglContext(OpenGLRcHandle oldContext) noexcept
{
    if (WglDeleteContext(oldContext) != gFalse)
        return true;
    else
        return false;
}

System::OpenGLRcHandle System::GetCurrentWglContext() noexcept
{
    return WglGetCurrentContext();
}

bool System::MakeWglCurrent(WindowsHdc hdc, OpenGLRcHandle newContext) noexcept
{
    if (WglMakeCurrent(hdc, newContext) != gFalse)
        return true;
    else
        return false;
}

int System::ChooseWindowPixelFormat(WindowsHdc hdc, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
    return System::ChoosePixelFormat(hdc, pixelFormatDescriptor);
}

bool System::SetWindowPixelFormat(WindowsHdc hdc, int format, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
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

bool System::SwapDeviceBuffers(WindowsHdc hdc) noexcept
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

bool System::DisplayColorBuffer(WindowsHdc hdc, int syncInterval) noexcept
{
    if (WglSwapIntervalEXT(0 < syncInterval ? 1 : 0) != gFalse && SwapDeviceBuffers(hdc))
        return true;
    else
        return false;
}
