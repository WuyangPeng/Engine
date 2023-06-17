///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:14)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_ELLIPSOID2_COEFFICIENTS_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_ELLIPSOID2_COEFFICIENTS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Ellipsoid3CoefficientsTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Ellipsoid3CoefficientsTesting;
        using ParentType = UnitTest;

    public:
        explicit Ellipsoid3CoefficientsTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void EllipsoidTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_SUITE_ELLIPSOID2_COEFFICIENTS_TESTING_H