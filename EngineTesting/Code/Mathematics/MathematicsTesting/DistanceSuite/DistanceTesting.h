///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:30)

#ifndef MATHEMATICS_DISTANCE_SUITE_DISTANCE_TESTING_H
#define MATHEMATICS_DISTANCE_SUITE_DISTANCE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class DistanceTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = DistanceTesting;
        using ParentType = UnitTest;

    public:
        explicit DistanceTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void BaseTest();
        void StaticTest();
        void DynamicTest();
        void DerivativeTest();
        void IntervalTest();
        void BeginIntervalTest();
        void EndIntervalTest();
        void IterationIntervalTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_DISTANCE_SUITE_DISTANCE_TESTING_H