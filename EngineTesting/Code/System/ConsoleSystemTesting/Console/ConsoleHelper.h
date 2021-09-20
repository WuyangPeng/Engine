///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.0 (2021/07/17 23:53)

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