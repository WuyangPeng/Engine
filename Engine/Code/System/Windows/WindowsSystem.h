///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/12 13:17)

#ifndef SYSTEM_WINDOWS_WINDOWS_SYSTEM_H
#define SYSTEM_WINDOWS_WINDOWS_SYSTEM_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"
#include "Using/WindowsUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <iostream>

namespace System
{
    // ϵͳ��غ�����

    void SYSTEM_DEFAULT_DECLARE GetWindowSystemInfo(WindowsSystemInfo& systemInfo) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetNumaProcessorNodeNumber(WindowsUChar processor, WindowsUCharPtr nodeNumber) noexcept;

    void SYSTEM_DEFAULT_DECLARE DebugBreak() noexcept;
    void SYSTEM_DEFAULT_DECLARE Exit() noexcept;
    int SYSTEM_DEFAULT_DECLARE SystemCommand(const char* command) noexcept;

    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetSystemCurrentDirectory(WindowsDWord bufferLength, TChar* buffer) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemCurrentDirectory(const TChar* pathName) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemUserName(TChar* buffer, WindowsDWord* bufferCount) noexcept;

    NODISCARD WindowsBool SYSTEM_DEFAULT_DECLARE BoolConversion(bool value) noexcept;
    void SYSTEM_DEFAULT_DECLARE BoolConversion(WindowsBool value, bool* result) noexcept;

    NODISCARD WindowsHWnd SYSTEM_DEFAULT_DECLARE GetActiveWindow() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemClientRect(WindowsHWnd hWnd, WindowsRect& windowsRect) noexcept;

    template <typename T>
    NODISCARD T GetSystemInput()
    {
        T value{};
        std::cin >> value;
        return value;
    }
}

#endif  // SYSTEM_WINDOWS_WINDOWS_SYSTEM_H
