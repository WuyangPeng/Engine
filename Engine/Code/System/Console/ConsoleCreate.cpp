/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:00)

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

    return ::AllocConsole() != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::FreeConsole() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FreeConsole() != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReOpenConsole(FILE*& file, const char* path, const char* mode, FILE* stream) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return freopen_s(&file, path, mode, stream) == 0;

#else  // !SYSTEM_PLATFORM_WIN32

    file = freopen(path, mode, stream);

    return file != nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseConsole(FILE* file) noexcept
{
    return fclose(file) == 0;
}

bool System::RemoveConsoleCloseButton() noexcept
{
    if (const auto hWnd = GetSystemConsoleWindow();
        hWnd != nullptr)
    {
        return RemoveMenuCloseButton(hWnd);
    }
    else
    {
        return false;
    }
}
