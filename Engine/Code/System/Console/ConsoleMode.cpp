///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 22:26)

#include "System/SystemExport.h"

#include "ConsoleMode.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::GetSystemConsoleMode(WindowsHandle consoleHandle, WindowsDWordPtr mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetConsoleMode(consoleHandle, mode) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, mode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleInputMode mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetConsoleMode(consoleHandle, EnumCastUnderlying(mode)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, mode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleOutputMode mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetConsoleMode(consoleHandle, EnumCastUnderlying(mode)) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, mode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
