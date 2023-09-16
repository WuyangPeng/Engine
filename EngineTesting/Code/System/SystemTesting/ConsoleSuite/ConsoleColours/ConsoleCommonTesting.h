///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 16:29)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_COMMON_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_COMMON_TESTING_H

#include "ConsoleStandardHandlesTesting.h"

namespace System
{
    class ConsoleCommonTesting final : public ConsoleStandardHandlesTesting
    {
    public:
        using ClassType = ConsoleCommonTesting;
        using ParentType = ConsoleStandardHandlesTesting;

    public:
        explicit ConsoleCommonTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ConsoleCommonTest();

        void DoConsoleCommonTest(size_t index);

    private:
        using ConsoleCommonContainer = std::vector<ConsoleCommon>;

    private:
        ConsoleCommonContainer consoleCommonFlags;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_COMMON_TESTING_H