///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:58)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_POLYNOMIAL_ROOTS_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_POLYNOMIAL_ROOTS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class PolynomialRootsTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = PolynomialRootsTesting;
        using ParentType = UnitTest;

    public:
        explicit PolynomialRootsTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void BaseTest();
        void OnceTest();
        void SecondaryTest();
        void ThriceTest();
        void SpecialCubicTest(); 
        void PolynomialTest();
        void AllRealPartsNegativeTest();
        void AllRealPartsPositiveTest();
        void GetRootCountTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_POLYNOMIAL_ROOTS_TESTING_H