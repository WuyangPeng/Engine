///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 16:20)

#ifndef SYSTEM_CONSOLE_CONSOLE_CREATE_H
#define SYSTEM_CONSOLE_CONSOLE_CREATE_H

#include "System/SystemDll.h"

#include "System/Windows/Using/WindowsUsing.h"

#include <cstdio>

// ����̨���ڵĴ��������١�
namespace System
{
    MAYBE_NULLPTR WindowsHWnd SYSTEM_DEFAULT_DECLARE GetSystemConsoleWindow() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AllocConsole() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FreeConsole() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE ReOpenConsole(FILE*& file, const char* path, const char* mode, FILE* stream) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseConsole(FILE* file) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE RemoveConsoleCloseButton() noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_CREATE_H