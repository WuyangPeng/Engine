///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.2 (2021/04/07 19:52)

#ifndef SYSTEM_CONSOLE_CONSOLE_CREATE_H
#define SYSTEM_CONSOLE_CONSOLE_CREATE_H

#include "System/SystemDll.h"

#include "System/Windows/Using/WindowsUsing.h"

#include <cstdio>

namespace System
{
    // ����̨���ڵĴ��������١�
    MAYBE_NULLPTR WindowsHWnd SYSTEM_DEFAULT_DECLARE GetSystemConsoleWindow() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE AllocConsole() noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FreeConsole() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE FReOpenConsole(FILE*& file, const char* path, const char* mode, FILE* stream) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE FCloseConsole(FILE* file) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE RemoveConsoleCloseButton() noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_CREATE_H