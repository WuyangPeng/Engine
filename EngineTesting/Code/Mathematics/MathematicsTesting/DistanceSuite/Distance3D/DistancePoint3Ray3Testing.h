///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/07 11:13)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT3_RAY3_TESTING_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT3_RAY3_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class DistancePoint3Ray3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = DistancePoint3Ray3Testing;
        using ParentType = UnitTest;

    public:
        explicit DistancePoint3Ray3Testing(const OStreamShared& streamShared);

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

#endif  // MATHEMATICS_DISTANCE_SUITE_DISTANCE_POINT3_RAY3_TESTING_H