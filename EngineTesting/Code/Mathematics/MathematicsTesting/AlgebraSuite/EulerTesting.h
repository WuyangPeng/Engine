///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:11)

#ifndef MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EULER_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EULER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class EulerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = EulerTesting;
        using ParentType = UnitTest;

    public:
        explicit EulerTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void EulerXYZTest();
        void EulerXZYTest();
        void EulerYXZTest();
        void EulerYZXTest();
        void EulerZXYTest();
        void EulerZYXTest();
        void EulerXYXTest();
        void EulerXZXTest();
        void EulerYXYTest();
        void EulerYZYTest();
        void EulerZXZTest();
        void EulerZYZTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EULER_TESTING_H