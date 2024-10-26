/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/03 00:13)

#include "System/SystemExport.h"

#include "OpenGLWglPrototypes.h"
#include "Detail/WglExtensions.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

bool System::IsWglSwapInterval(int interval) noexcept
{
    return WglSwapIntervalEXT(interval) != gFalse;
}

int System::GetWglSwapInterval() noexcept
{
    return WglGetSwapIntervalEXT();
}

System::OpenGLRcHandle System::CreateWglContext(WindowsHdc hdc) noexcept
{
    return WglCreateContext(hdc);
}

bool SYSTEM_DEFAULT_DECLARE System::DeleteWglContext(OpenGLRcHandle oldContext) noexcept
{
    return WglDeleteContext(oldContext) != gFalse;
}

System::OpenGLRcHandle System::GetCurrentWglContext() noexcept
{
    return WglGetCurrentContext();
}

bool System::MakeWglCurrent(WindowsHdc hdc, OpenGLRcHandle newContext) noexcept
{
    return WglMakeCurrent(hdc, newContext) != gFalse;
}

int System::ChooseWindowPixelFormat(WindowsHdc hdc, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
    return System::ChoosePixelFormat(hdc, pixelFormatDescriptor);
}

bool System::SetWindowPixelFormat(WindowsHdc hdc, int format, const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
    return System::SetPixelFormat(hdc, format, pixelFormatDescriptor) != gFalse;
}

System::OpenGLProc System::GetWglProcAddress(const char* glFunction) noexcept
{
    return WglGetProcAddress(glFunction);
}

bool System::SwapDeviceBuffers(WindowsHdc hdc) noexcept
{
    return System::SwapBuffers(hdc) != gFalse;
}

bool System::DisplayColorBuffer(WindowsHdc hdc, int syncInterval) noexcept
{
    return WglSwapIntervalEXT(0 < syncInterval ? 1 : 0) != gFalse && SwapDeviceBuffers(hdc);
}