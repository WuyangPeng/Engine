/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 10:11)

#ifndef CONCURRENT_TOOLS_TIME_SUITE_DELTA_TIME_MANAGER_TESTING_H
#define CONCURRENT_TOOLS_TIME_SUITE_DELTA_TIME_MANAGER_TESTING_H

#include "CoreTools/Time/DeltaTimeManager.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DeltaTimeManagerTesting final : public UnitTest
    {
    public:
        using ClassType = DeltaTimeManagerTesting;
        using ParentType = UnitTest;

    public:
        explicit DeltaTimeManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void TimeTest();
        void TimeBaseTest(const DeltaTimeManager& time);
        void ResetCurrentTimeTest(DeltaTimeManager& time);
    };
}

#endif  // CONCURRENT_TOOLS_TIME_SUITE_DELTA_TIME_MANAGER_TESTING_H