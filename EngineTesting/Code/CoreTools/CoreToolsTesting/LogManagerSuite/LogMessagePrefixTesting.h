/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 22:40)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_PREFIX_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_PREFIX_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class LogMessagePrefixTesting final : public UnitTest
    {
    public:
        using ClassType = LogMessagePrefixTesting;
        using ParentType = UnitTest;

    public:
        explicit LogMessagePrefixTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void TimestampTest();
        void LogLevelTest();
        void LogFilterTest();
        void NoPrefixTest();
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_SUITE_LOG_MESSAGE_PREFIX_TESTING_H
