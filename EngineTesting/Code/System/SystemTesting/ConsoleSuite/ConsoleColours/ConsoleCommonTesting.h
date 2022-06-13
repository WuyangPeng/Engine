///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:01)

#ifndef SYSTEM_CONSOLE_SUITE_CONSOLE_COMMON_TESTING_H
#define SYSTEM_CONSOLE_SUITE_CONSOLE_COMMON_TESTING_H

#include "ConsoleColoursTesting.h"

#include <map>
#include <random>
#include <vector>

namespace System
{
    class ConsoleCommonTesting final : public ConsoleColoursTesting
    {
    public:
        using ClassType = ConsoleCommonTesting;
        using ParentType = ConsoleColoursTesting;

    public:
        explicit ConsoleCommonTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ConsoleCommonTest();
        void SetDefaultTextAttribute();

    private:
        using StandardHandleFlagsCollection = std::vector<StandardHandle>;
        using ConsoleCommonFlagsCollection = std::vector<ConsoleCommon>;

    private:
        StandardHandleFlagsCollection standardHandleFlags;
        ConsoleCommonFlagsCollection consoleCommonFlags;
        std::default_random_engine randomEngine;
    };
}

#endif  // SYSTEM_CONSOLE_SUITE_CONSOLE_COMMON_TESTING_H