///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.2 (2021/04/07 20:01)

#include "System/SystemExport.h"

#include "ConsoleMode.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::GetSystemConsoleMode(WindowsHandle consoleHandle, WindowsDWordPtr mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::GetConsoleMode(consoleHandle, mode) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, WindowsDWordPtr>(consoleHandle, mode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleInputMode mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetConsoleMode(consoleHandle, EnumCastUnderlying(mode)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, ConsoleInputMode>(consoleHandle, mode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleOutputMode mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetConsoleMode(consoleHandle, EnumCastUnderlying(mode)) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<WindowsHandle, ConsoleOutputMode>(consoleHandle, mode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
