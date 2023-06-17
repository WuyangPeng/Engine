///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:12)

#ifndef MATHEMATICS_ALGEBRA_SUITE_POLYNOMIAL_DIVIDE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_POLYNOMIAL_DIVIDE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class PolynomialDivideTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = PolynomialDivideTesting;
        using ParentType = UnitTest;

    public:
        explicit PolynomialDivideTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_POLYNOMIAL_DIVIDE_TESTING_H