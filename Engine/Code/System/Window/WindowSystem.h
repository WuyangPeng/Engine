//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 11:38)

#ifndef SYSTEM_WINDOW_WINDOW_SYSTEM_H
#define SYSTEM_WINDOW_WINDOW_SYSTEM_H

#include "System/SystemDll.h"

#include "Fwd/WindowFlagsFwd.h"
#include "Using/WindowUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <iostream>

namespace System
{
    // 系统相关函数。

    void SYSTEM_DEFAULT_DECLARE GetWindowSystemInfo(WindowSystemInfo& systemInfo) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetNumaProcessorNodeNumber(WindowUChar processor, WindowUCharPtr nodeNumber) noexcept;

    void SYSTEM_DEFAULT_DECLARE DebugBreak() noexcept;
    void SYSTEM_DEFAULT_DECLARE Exit() noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE SystemCommand(const char* command) noexcept;

    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemCurrentDirectory(WindowDWord bufferLength, TChar* buffer) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemCurrentDirectory(const TChar* pathName) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetSystemUserName(TChar* buffer, WindowDWord* bufferCount) noexcept;

    [[nodiscard]] WindowBool SYSTEM_DEFAULT_DECLARE BoolConversion(bool value) noexcept;
    void SYSTEM_DEFAULT_DECLARE BoolConversion(WindowBool value, bool* result) noexcept;

    template <typename T>
    [[nodiscard]] T GetSystemInput()
    {
        T value{};
        std::cin >> value;
        return value;
    }
}

#endif  // SYSTEM_WINDOW_WINDOW_SYSTEM_H
