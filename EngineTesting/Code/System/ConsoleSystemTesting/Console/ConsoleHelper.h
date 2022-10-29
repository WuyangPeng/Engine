///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 21:47)

#ifndef CONSOLE_SYSTEM_TESTING_CONSOLE_HELPER_H
#define CONSOLE_SYSTEM_TESTING_CONSOLE_HELPER_H

#include "CoreTools/Helper/UserMacro.h"

#include <cstdio>

namespace ConsoleSystemTesting
{
    class ConsoleHelper final
    {
    public:
        using ClassType = ConsoleHelper;

    public:
        ConsoleHelper() noexcept;
        ~ConsoleHelper() noexcept;
        ConsoleHelper(const ConsoleHelper& rhs) noexcept = delete;
        ConsoleHelper& operator=(const ConsoleHelper& rhs) noexcept = delete;
        ConsoleHelper(ConsoleHelper&& rhs) noexcept = delete;
        ConsoleHelper& operator=(ConsoleHelper&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsSuccess() const noexcept;

        void PrintConsoleInfo();

    private:
        void AllocConsole() noexcept;
        void FreeConsole() noexcept;

    private:
        FILE* out;
        FILE* in;
        FILE* error;
        bool isSuccess;
    };
}

#endif  // CONSOLE_SYSTEM_TESTING_CONSOLE_HELPER_H