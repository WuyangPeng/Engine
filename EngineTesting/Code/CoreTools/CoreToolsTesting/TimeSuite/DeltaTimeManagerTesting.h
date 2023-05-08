///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/25 16:37)

#ifndef CONCURRENT_TOOLS_TIME_SUITE_DELTA_TIME_MANAGER_TESTING_H
#define CONCURRENT_TOOLS_TIME_SUITE_DELTA_TIME_MANAGER_TESTING_H

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
        void MainTest();
        void TimeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CONCURRENT_TOOLS_TIME_SUITE_DELTA_TIME_MANAGER_TESTING_H