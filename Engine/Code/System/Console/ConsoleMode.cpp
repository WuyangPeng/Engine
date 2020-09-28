//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:51)

#include "System/SystemExport.h"

#include "ConsoleMode.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::GetSystemConsoleMode([[maybe_unused]] WindowHandle consoleHandle, [[maybe_unused]] WindowDWordPtr mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::GetConsoleMode(consoleHandle, mode) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleMode([[maybe_unused]] WindowHandle consoleHandle, [[maybe_unused]] ConsoleInputMode mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleMode(consoleHandle, EnumCastUnderlying(mode)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleMode([[maybe_unused]] WindowHandle consoleHandle, [[maybe_unused]] ConsoleOutputMode mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleMode(consoleHandle, EnumCastUnderlying(mode)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
