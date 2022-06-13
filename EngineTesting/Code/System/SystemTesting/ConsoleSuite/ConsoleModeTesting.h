///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 13:03)

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
        using StandardHandleFlagsCollection = std::vector<StandardHandle>;
        using ConsoleInputModeFlagsCollection = std::vector<ConsoleInputMode>;
        using ConsoleOutputModeFlagsCollection = std::vector<ConsoleOutputMode>;

    private:
        StandardHandleFlagsCollection standardOutputHandleFlags;
        ConsoleInputModeFlagsCollection consoleInputModeFlags;
        ConsoleOutputModeFlagsCollection consoleOutputModeFlags;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_MODE_TESTING_H