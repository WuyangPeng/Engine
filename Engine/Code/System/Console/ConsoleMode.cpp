/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 17:02)

#include "System/SystemExport.h"

#include "ConsoleMode.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

bool System::GetSystemConsoleMode(WindowsHandle consoleHandle, WindowsDWordPtr mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetConsoleMode(consoleHandle, mode) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, mode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleInputMode mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetConsoleMode(consoleHandle, EnumCastUnderlying(mode)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, mode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetSystemConsoleMode(WindowsHandle consoleHandle, ConsoleOutputMode mode) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SetConsoleMode(consoleHandle, EnumCastUnderlying(mode)) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(consoleHandle, mode);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
