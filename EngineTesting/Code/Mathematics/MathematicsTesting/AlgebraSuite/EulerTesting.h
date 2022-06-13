///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:05)

#ifndef MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EULER_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EULER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class EulerTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(EulerTesting);

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