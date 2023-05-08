///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/25 16:37)

#ifndef CONCURRENT_TOOLS_TIME_SUITE_SECOND_TIMER_TESTING_H
#define CONCURRENT_TOOLS_TIME_SUITE_SECOND_TIMER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SecondTimerTesting final : public UnitTest
    {
    public:
        using ClassType = SecondTimerTesting;
        using ParentType = UnitTest;

    public:
        explicit SecondTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void TimeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CONCURRENT_TOOLS_TIME_SUITE_SECOND_TIMER_TESTING_H