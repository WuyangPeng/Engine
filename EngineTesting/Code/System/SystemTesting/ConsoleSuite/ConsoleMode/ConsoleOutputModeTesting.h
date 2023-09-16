///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 16:30)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_OUTPUT_MODE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_OUTPUT_MODE_TESTING_H

#include "ConsoleModeTesting.h"
#include "System/Console/Fwd/ConsoleFlagsFwd.h"

#include <vector>

namespace System
{
    class ConsoleOutputModeTesting final : public ConsoleModeTesting
    {
    public:
        using ClassType = ConsoleOutputModeTesting;
        using ParentType = ConsoleModeTesting;

    public:
        explicit ConsoleOutputModeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

    private:
        void ConsoleOutputModeTest();

        void DoConsoleOutputModeTest(StandardHandle standardOutput, ConsoleOutputMode consoleOutputMode);

    private:
        using StandardHandleContainer = std::vector<StandardHandle>;
        using ConsoleOutputModeContainer = std::vector<ConsoleOutputMode>;

    private:
        StandardHandleContainer standardOutputs;
        ConsoleOutputModeContainer consoleOutputModes;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_OUTPUT_MODE_TESTING_H