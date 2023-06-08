///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:04)

#ifndef MATHEMATICS_ALGEBRA_SUITE_HQUATERNION_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_HQUATERNION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class AQuaternionTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AQuaternionTesting;
        using ParentType = UnitTest;

    public:
        explicit AQuaternionTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructionTest();
        void AccessTest();
        void OperatorCalculateTest();
        void ArithmeticCalculateTest();
        void CompareTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_HQUATERNION_TESTING_H