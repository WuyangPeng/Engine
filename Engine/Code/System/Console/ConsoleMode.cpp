///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 16:22)

#include "System/SystemExport.h"

#include "ConsoleMode.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
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
