///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 14:19)

#ifndef CONCURRENT_TOOLS_TIME_SUITE_MILLISECOND_TIMER_TESTING_H
#define CONCURRENT_TOOLS_TIME_SUITE_MILLISECOND_TIMER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MillisecondTimerTesting : public UnitTest
    {
    public:
        using ClassType = MillisecondTimerTesting;
        using ParentType = UnitTest;

    public:
        explicit MillisecondTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void TimeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CONCURRENT_TOOLS_TIME_SUITE_MILLISECOND_TIMER_TESTING_H