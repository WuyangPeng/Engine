///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 14:52)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT2_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class PolynomialFit2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = PolynomialFit2Testing;
        using ParentType = UnitTest;

    public:
        explicit PolynomialFit2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void FitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_SUITE_POLYNOMIAL_FIT2_TESTING_H