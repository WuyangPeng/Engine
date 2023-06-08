///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 11:40)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_HEIGHT_PLANE_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_HEIGHT_PLANE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class HeightPlaneFit3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = HeightPlaneFit3Testing;
        using ParentType = UnitTest;

    public:
        explicit HeightPlaneFit3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void FitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_SUITE_HEIGHT_PLANE_TESTING_H