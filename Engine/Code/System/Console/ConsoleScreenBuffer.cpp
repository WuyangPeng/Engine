//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:53)

#include "System/SystemExport.h"

#include "ConsoleScreenBuffer.h"
#include "Flags/ConsoleScreenBufferFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Window/WindowSystem.h"

System::WindowHandle System::CreateSystemConsoleScreenBuffer([[maybe_unused]] DesiredAccessGeneric desiredAccess, [[maybe_unused]] ConsoleScreenBufferShareMode shareMode, [[maybe_unused]] const WindowSecurityAttributes* securityAttributes) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateConsoleScreenBuffer(EnumCastUnderlying(desiredAccess), EnumCastUnderlying(shareMode), securityAttributes, EnumCastUnderlying(ConsoleScreenBuffer::TextModeBuffer), nullptr);
#else  // !SYSTEM_PLATFORM_WIN32 
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemConsole([[maybe_unused]] WindowHandle consoleHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CloseHandle(consoleHandle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SetDefaultConsoleSecurityAttributes(WindowSecurityAttributes& securityAttributes, bool inheritHandle) noexcept
{
    securityAttributes.nLength = sizeof(WindowSecurityAttributes);
    securityAttributes.lpSecurityDescriptor = nullptr;
    securityAttributes.bInheritHandle = BoolConversion(inheritHandle);
}

bool System::GetSystemConsoleScreenBufferInfo([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] ConsoleScreenBufferInfoPtr consoleScreenBufferInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetConsoleScreenBufferInfo(consoleOutput, consoleScreenBufferInfo) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetSystemConsoleScreenBufferInfo([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetConsoleScreenBufferInfoEx(consoleOutput, consoleScreenBufferInfoEx) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetConsoleHandleScreenBufferInfo([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] ConsoleScreenBufferInfoExPtr consoleScreenBufferInfoEx) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleScreenBufferInfoEx(consoleOutput, consoleScreenBufferInfoEx) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleScreenBufferSize([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] ConsoleCoord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleScreenBufferSize(consoleOutput, size) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ScrollSystemConsoleScreenBuffer([[maybe_unused]] WindowHandle consoleOutput, [[maybe_unused]] const ConsoleSmallRect* scrollRectangle, [[maybe_unused]] const ConsoleSmallRect* clipRectangle,
                                             [[maybe_unused]] ConsoleCoord destinationOrigin, [[maybe_unused]] const ConsoleCharInfo* fill) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ScrollConsoleScreenBuffer(consoleOutput, scrollRectangle, clipRectangle, destinationOrigin, fill) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
