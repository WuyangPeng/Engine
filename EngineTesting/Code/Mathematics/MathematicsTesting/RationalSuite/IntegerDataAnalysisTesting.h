///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/26 11:28)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_ANALYSIS_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_ANALYSIS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class IntegerDataAnalysisTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = IntegerDataAnalysisTesting;
        using ParentType = UnitTest;

    public:
        explicit IntegerDataAnalysisTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ToUnsignedIntTest();
        void GetLeadingBitTest();
        void GetTrailingBitTest();
        void OperatorTest();
        void DivisionModuloTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_ANALYSIS_TESTING_H