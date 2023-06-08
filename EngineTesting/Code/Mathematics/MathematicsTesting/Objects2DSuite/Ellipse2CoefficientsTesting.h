///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/31 13:46)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_ELLIPSE2_COEFFICIENTS_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_ELLIPSE2_COEFFICIENTS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Ellipse2CoefficientsTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Ellipse2CoefficientsTesting;
        using ParentType = UnitTest;

    public:
        explicit Ellipse2CoefficientsTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void EllipseTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_SUITE_ELLIPSE2_COEFFICIENTS_TESTING_H