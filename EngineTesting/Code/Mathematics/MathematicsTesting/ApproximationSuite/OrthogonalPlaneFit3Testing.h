///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 11:41)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_ORTHOGONAL_PLANE_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_ORTHOGONAL_PLANE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class OrthogonalPlaneFit3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = OrthogonalPlaneFit3Testing;
        using ParentType = UnitTest;

    public:
        explicit OrthogonalPlaneFit3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void FitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_SUITE_ORTHOGONAL_PLANE_TESTING_H