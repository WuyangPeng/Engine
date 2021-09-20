///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/09 13:07)

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