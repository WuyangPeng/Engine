//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 0:54)

#include "System/SystemExport.h"

#include "ConsoleTitle.h"
#include "System/Helper/WindowsMacro.h"

System::WindowDWord System::GetSystemConsoleTitle([[maybe_unused]] TChar* consoleTitle, [[maybe_unused]] WindowDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetConsoleTitle(consoleTitle, size);
#else  // !SYSTEM_PLATFORM_WIN32 
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::GetSystemConsoleOriginalTitle([[maybe_unused]] TChar* consoleTitle, [[maybe_unused]] WindowDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::GetConsoleOriginalTitle(consoleTitle, size);
#else  // !SYSTEM_PLATFORM_WIN32 
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleTitle([[maybe_unused]] const TChar* consoleTitle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::SetConsoleTitle(consoleTitle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
