///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:08)

#ifndef MATHEMATICS_ALGEBRA_SUITE_VARIABLE_LENGTH_VECTOR_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_VARIABLE_LENGTH_VECTOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class VariableLengthVectorTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = VariableLengthVectorTesting;
        using ParentType = UnitTest;

    public:
        explicit VariableLengthVectorTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructionTest();
        void AccessTest();
        void ArithmeticCalculateTest();
        void VectorCalculateTest();
        void CompareTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_VARIABLE_LENGTH_VECTOR_TESTING_H