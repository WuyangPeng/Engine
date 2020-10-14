//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/09/28 10:40)

#include "System/SystemExport.h"

#include "OpenGLWglPrototypes.h"
#include "System/Helper/WindowsMacro.h"

System::OpenGLHdc System::GetWglCurrentDC() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::wglGetCurrentDC();
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CopyWglContext([[maybe_unused]] OpenGLHglrc arg1, [[maybe_unused]] OpenGLHglrc arg2, [[maybe_unused]] WindowUInt arg3) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::wglCopyContext(arg1, arg2, arg3) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLHglrc System::CreateWglContext([[maybe_unused]] OpenGLHdc arg1) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::wglCreateContext(arg1);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool SYSTEM_DEFAULT_DECLARE System::DeleteWglContext([[maybe_unused]] OpenGLHglrc arg1) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::wglDeleteContext(arg1) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLHglrc System::GetWglCurrentContext() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::wglGetCurrentContext();
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::MakeWglCurrent([[maybe_unused]] OpenGLHdc arg1, [[maybe_unused]] OpenGLHglrc arg2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::wglMakeCurrent(arg1, arg2) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ShareWglLists([[maybe_unused]] OpenGLHglrc arg1, [[maybe_unused]] OpenGLHglrc arg2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::wglShareLists(arg1, arg2) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SwapWglLayerBuffers([[maybe_unused]] OpenGLHdc arg1, [[maybe_unused]] WindowUInt arg2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::wglSwapLayerBuffers(arg1, arg2) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::SwapWglMultipleBuffers([[maybe_unused]] WindowUInt arg1, [[maybe_unused]] const WglSwap* arg2) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::wglSwapMultipleBuffers(arg1, arg2);

#else  // !SYSTEM_PLATFORM_WIN32

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::ChooseWindowPixelFormat([[maybe_unused]] OpenGLHdc hdc, [[maybe_unused]] const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::ChoosePixelFormat(hdc, pixelFormatDescriptor);

#else  // !SYSTEM_PLATFORM_WIN32

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetWindowPixelFormat([[maybe_unused]] OpenGLHdc hdc, [[maybe_unused]] int format, [[maybe_unused]] const PixelFormatDescriptor* pixelFormatDescriptor) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetPixelFormat(hdc, format, pixelFormatDescriptor) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::OpenGLProc System::GetWglProcAddress([[maybe_unused]] const char* glFunction) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::wglGetProcAddress(glFunction);
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}