///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 16:22)

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

bool System::ReOpenConsole(FILE*& file, const char* path, const char* mode, FILE* stream) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (const auto result = freopen_s(&file, path, mode, stream);
        result == 0)
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

bool System::CloseConsole(FILE* file) noexcept
{
    if (const auto result = fclose(file);
        result == 0)
        return true;
    else
        return false;
}

bool System::RemoveConsoleCloseButton() noexcept
{
    if (const auto hWnd = GetSystemConsoleWindow();
        hWnd != nullptr)
        return RemoveMenuCloseButton(hWnd);
    else
        return false;
}
