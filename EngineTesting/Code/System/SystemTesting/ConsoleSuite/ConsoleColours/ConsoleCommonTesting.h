///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/03 19:49)

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
        void DoRunUnitTest() final;
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