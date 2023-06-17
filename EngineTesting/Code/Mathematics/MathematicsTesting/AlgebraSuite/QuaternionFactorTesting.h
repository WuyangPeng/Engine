///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:13)

#ifndef MATHEMATICS_ALGEBRA_SUITE_QUATERNION_FACTOR_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_QUATERNION_FACTOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class QuaternionFactorTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = QuaternionFactorTesting;
        using ParentType = UnitTest;

    public:
        explicit QuaternionFactorTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void FactorXYZTest();
        void FactorXZYTest();
        void FactorYZXTest();
        void FactorYXZTest();
        void FactorZXYTest();
        void FactorZYXTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_QUATERNION_FACTOR_TESTING_H