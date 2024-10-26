/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 15:37)

#ifndef SYSTEM_WINDOWS_WINDOWS_SYSTEM_H
#define SYSTEM_WINDOWS_WINDOWS_SYSTEM_H

#include "System/SystemDll.h"

#include "Fwd/WindowsFlagsFwd.h"
#include "Using/WindowsUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <iostream>

/// 系统相关函数。
namespace System
{
    void SYSTEM_DEFAULT_DECLARE GetWindowSystemInfo(WindowsSystemInfo& systemInfo) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetNumaProcessorNodeNumber(WindowsUChar processor, WindowsUCharPtr nodeNumber) noexcept;

    NODISCARD WindowsDWord SYSTEM_DEFAULT_DECLARE GetSystemCurrentDirectory(WindowsDWord bufferLength, TChar* buffer) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SetSystemCurrentDirectory(const TChar* pathName) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemUserName(TChar* buffer, WindowsDWord* bufferCount) noexcept;

    NODISCARD WindowsBool SYSTEM_DEFAULT_DECLARE BoolConversion(bool input) noexcept;
    void SYSTEM_DEFAULT_DECLARE BoolConversion(WindowsBool input, bool* result) noexcept;

    NODISCARD WindowsHWnd SYSTEM_DEFAULT_DECLARE GetActiveWindow() noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE GetSystemClientRect(WindowsHWnd hWnd, WindowsRect& windowsRect) noexcept;

    /// SystemCommand函数不是线程安全的。
    int SYSTEM_DEFAULT_DECLARE SystemCommand(const char* command) noexcept;

    /// 正式环境禁止调用DebugBreak、Exit和GetSystemInput。
    void SYSTEM_DEFAULT_DECLARE DebugBreak() noexcept;
    void SYSTEM_DEFAULT_DECLARE Exit() noexcept;

    template <typename T>
    NODISCARD T GetSystemInput()
    {
        T value{};
        std::cin >> value;
        return value;
    }
}

#endif  // SYSTEM_WINDOWS_WINDOWS_SYSTEM_H
