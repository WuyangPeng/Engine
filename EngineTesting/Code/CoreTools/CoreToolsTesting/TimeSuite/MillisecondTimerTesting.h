/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 10:11)

#ifndef CONCURRENT_TOOLS_TIME_SUITE_MILLISECOND_TIMER_TESTING_H
#define CONCURRENT_TOOLS_TIME_SUITE_MILLISECOND_TIMER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MillisecondTimerTesting final : public UnitTest
    {
    public:
        using ClassType = MillisecondTimerTesting;
        using ParentType = UnitTest;

    public:
        explicit MillisecondTimerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void TimeTest();
    };
}

#endif  // CONCURRENT_TOOLS_TIME_SUITE_MILLISECOND_TIMER_TESTING_H