///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/16 21:17)

#include "System/SystemExport.h"

#include "ConsoleCreate.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsCreate.h"

System::WindowsHWnd System::GetSystemConsoleWindow() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetConsoleWindow();

#else  // !SYSTEM_PLATFORM_WIN32

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::AllocConsole() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::AllocConsole() != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeConsole() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::FreeConsole() != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FReOpenConsole(FILE*& file, const char* path, const char* mode, FILE* stream) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto result = freopen_s(&file, path, mode, stream);

    if (result == 0)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    file = freopen(path, mode, stream);

    if (file != nullptr)
        return true;
    else
        return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FCloseConsole(FILE* file) noexcept
{
    const auto result = fclose(file);

    if (result == 0)
        return true;
    else
        return false;
}

bool System::RemoveConsoleCloseButton() noexcept
{
    auto hwnd = GetSystemConsoleWindow();
    if (hwnd != nullptr)
        return RemoveMenuCloseButton(hwnd);
    else
        return false;
}
