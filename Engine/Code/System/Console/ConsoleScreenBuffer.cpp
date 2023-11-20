///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 16:23)

#include "System/SystemExport.h"

#include "ConsoleScreenBuffer.h"
#include "Flags/ConsoleScreenBufferFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "System/Windows/WindowsSystem.h"

System::WindowsHandle System::CreateSystemConsoleScreenBuffer(DesiredAccessGeneric desiredAccess,
                                                              ConsoleScreenBufferShareMode shareMode,
                                                              const WindowSecurityAttributes* securityAttributes) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreateConsoleScreenBuffer(EnumCastUnderlying(desiredAccess), EnumCastUnderlying(shareMode), securityAttributes, EnumCastUnderlying(ConsoleScreenBuffer::TextModeBuffer), nullptr);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(desiredAccess, shareMode, securityAttributes);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemConsole(WindowsHandle consoleHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(consoleHandle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetDefaultConsoleSecurityAttributes(WindowSecurityAttributes& securityAttributes, bool inheritHandle) noexcept
{
    securityAttributes.nLength = sizeof(WindowSecurityAttributes);
    securityAttributes.lpSecurityDescriptor = nullptr;
    securityAttributes.bInheritHandle = BoolConversion(inheritHandle);
}

bool System::GetSystemConsoleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoPtr consoleScreenBufferInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetConsoleScreenBufferInfo(consoleOutput, consoleScreenBufferInfo) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleOutput, consoleScreenBufferInfo);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemConsoleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetConsoleScreenBufferInfoEx(consoleOutput, consoleScreenBufferInfoEx) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleOutput, consoleScreenBufferInfoEx);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetConsoleHandleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetConsoleScreenBufferInfoEx(consoleOutput, consoleScreenBufferInfoEx) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleOutput, consoleScreenBufferInfoEx);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleScreenBufferSize(WindowsHandle consoleOutput, ConsoleCoord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetConsoleScreenBufferSize(consoleOutput, size) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleOutput, size);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
