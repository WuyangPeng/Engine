///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/07 11:13)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_CIRCLE3_CIRCLE3_TESTING_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_CIRCLE3_CIRCLE3_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class DistanceCircle3Circle3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = DistanceCircle3Circle3Testing;
        using ParentType = UnitTest;

    public:
        explicit DistanceCircle3Circle3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void BaseTest();
        void StaticTest() noexcept;
        void DynamicTest() noexcept;
        void DerivativeTest() noexcept;
        void IntervalTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_DISTANCE_SUITE_DISTANCE_CIRCLE3_CIRCLE3_TESTING_H