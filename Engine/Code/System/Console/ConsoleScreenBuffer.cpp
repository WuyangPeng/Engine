///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/04/07 11:33)

#include "System/SystemExport.h"

#include "ConsoleScreenBuffer.h"
#include "Flags/ConsoleScreenBufferFlags.h"
#include "System/Helper/EnumCast.h"
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

    NullFunction<DesiredAccessGeneric, ConsoleScreenBufferShareMode, const WindowSecurityAttributes*>(desiredAccess, shareMode, securityAttributes);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemConsole(WindowsHandle consoleHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(consoleHandle) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle>(consoleHandle);

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

    if (::GetConsoleScreenBufferInfo(consoleOutput, consoleScreenBufferInfo) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, ConsoleScreenBufferInfoPtr>(consoleOutput, consoleScreenBufferInfo);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemConsoleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetConsoleScreenBufferInfoEx(consoleOutput, consoleScreenBufferInfoEx) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, ConsoleScreenBufferInfoExPtr>(consoleOutput, consoleScreenBufferInfoEx);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetConsoleHandleScreenBufferInfo(WindowsHandle consoleOutput, ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetConsoleScreenBufferInfoEx(consoleOutput, consoleScreenBufferInfoEx) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, ConsoleScreenBufferInfoExPtr>(consoleOutput, consoleScreenBufferInfoEx);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleScreenBufferSize(WindowsHandle consoleOutput, ConsoleCoord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetConsoleScreenBufferSize(consoleOutput, size) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, ConsoleCoord>(consoleOutput, size);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
