///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.2 (2023/02/12 16:01)

#ifndef CORE_TOOLS_HELPER_SUITE_LOG_CONSOLE_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_LOG_CONSOLE_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogConsoleMacroTesting final : public UnitTest
    {
    public:
        using ClassType = LogConsoleMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit LogConsoleMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ConsoleLogTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_LOG_CONSOLE_MACRO_TESTING_H
