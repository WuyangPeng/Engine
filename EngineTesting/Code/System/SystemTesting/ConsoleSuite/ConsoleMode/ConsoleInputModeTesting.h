///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:30)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_INPUT_MODE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_INPUT_MODE_TESTING_H

#include "ConsoleModeTesting.h"
#include "System/Console/Fwd/ConsoleFlagsFwd.h"

#include <vector>

namespace System
{
    class ConsoleInputModeTesting final : public ConsoleModeTesting
    {
    public:
        using ClassType = ConsoleInputModeTesting;
        using ParentType = ConsoleModeTesting;

    public:
        explicit ConsoleInputModeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

    private:
        void ConsoleInputModeTest();

        void DoConsoleInputModeTest(ConsoleInputMode consoleInputMode);

    private:
        using ConsoleInputModeContainer = std::vector<ConsoleInputMode>;

    private:
        ConsoleInputModeContainer consoleInputModes;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_INPUT_MODE_TESTING_H