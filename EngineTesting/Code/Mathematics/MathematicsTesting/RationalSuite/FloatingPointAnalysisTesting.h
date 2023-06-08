///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/26 11:27)

#ifndef MATHEMATICS_RATIONAL_SUITE_FLOATING_POINT_ANALYSIS_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_FLOATING_POINT_ANALYSIS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class FloatingPointAnalysisTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = FloatingPointAnalysisTesting;
        using ParentType = UnitTest;

    public:
        explicit FloatingPointAnalysisTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void NumericalValueSymbolTest();
        void ExponentTest();
        void MantissaTest();
        void FloatTypeTest();
        void DoubleTypeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_RATIONAL_SUITE_FLOATING_POINT_ANALYSIS_TESTING_H