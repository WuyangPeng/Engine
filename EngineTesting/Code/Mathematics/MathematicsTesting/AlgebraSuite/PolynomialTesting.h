///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:06)

#ifndef MATHEMATICS_ALGEBRA_UITE_POLYNOMIAL_TESTING_H
#define MATHEMATICS_ALGEBRA_UITE_POLYNOMIAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class PolynomialTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PolynomialTesting);

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

#endif  // MATHEMATICS_ALGEBRA_UITE_POLYNOMIAL_TESTING_H