///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:13)

#ifndef MATHEMATICS_ALGEBRA_SUITE_POLYNOMIAL_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_POLYNOMIAL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class PolynomialTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = PolynomialTesting;
        using ParentType = UnitTest;

    public:
        explicit PolynomialTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructionTest();
        void AccessTest();
        void UpdateOperatorTest();
        void OperationTest();
        void CalculateTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_POLYNOMIAL_TESTING_H