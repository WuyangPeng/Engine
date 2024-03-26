/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 18:23)

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
        ConsoleCommonContainer consoleCommons;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_COMMON_TESTING_H