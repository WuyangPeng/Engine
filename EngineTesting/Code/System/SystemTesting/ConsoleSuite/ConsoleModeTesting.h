///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/15 21:50)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_MODE_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_MODE_TESTING_H

#include "System/Console/Fwd/ConsoleFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class ConsoleModeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConsoleModeTesting;
        using ParentType = UnitTest;

    public:
        explicit ConsoleModeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        void ConsoleInputModeTest();
        void ConsoleOutputModeTest();

    private:
        using StandardHandleFlagsContainer = std::vector<StandardHandle>;
        using ConsoleInputModeFlagsContainer = std::vector<ConsoleInputMode>;
        using ConsoleOutputModeFlagsContainer = std::vector<ConsoleOutputMode>;

    private:
        StandardHandleFlagsContainer standardOutputHandleFlags;
        ConsoleInputModeFlagsContainer consoleInputModeFlags;
        ConsoleOutputModeFlagsContainer consoleOutputModeFlags;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_MODE_TESTING_H