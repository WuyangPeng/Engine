///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/07 11:13)

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