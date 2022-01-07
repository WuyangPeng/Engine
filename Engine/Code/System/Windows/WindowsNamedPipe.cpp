///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/12 13:28)

#include "System/SystemExport.h"

#include "WindowsNamedPipe.h"
#include "System/Helper/WindowsMacro.h"

bool System::CreateSystemPipe(WindowsHandlePtr readPipe, WindowsHandlePtr writePipe, WindowSecurityAttributesPtr pipeAttributes, WindowsDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CreatePipe(readPipe, writePipe, pipeAttributes, size) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(readPipe, writePipe, pipeAttributes, size);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemPipe(WindowsHandle pipeHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(pipeHandle) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pipeHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
