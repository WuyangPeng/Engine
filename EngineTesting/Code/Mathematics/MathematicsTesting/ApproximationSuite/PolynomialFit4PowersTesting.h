///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 11:42)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT4_POWERS_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT4_POWERS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class PolynomialFit4PowersTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = PolynomialFit4PowersTesting;
        using ParentType = UnitTest;

    public:
        explicit PolynomialFit4PowersTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void FitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT4_POWERS_TESTING_H