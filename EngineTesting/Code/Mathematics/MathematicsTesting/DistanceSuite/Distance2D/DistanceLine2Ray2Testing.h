///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:31)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_LINE2_RAY2_TESTING_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_LINE2_RAY2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class DistanceLine2Ray2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = DistanceLine2Ray2Testing;
        using ParentType = UnitTest;

    public:
        explicit DistanceLine2Ray2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void BaseTest();
        void StaticTest();
        void DynamicTest();
        void DerivativeTest();
        void IntervalTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_DISTANCE_SUITE_DISTANCE_LINE2_RAY2_TESTING_H