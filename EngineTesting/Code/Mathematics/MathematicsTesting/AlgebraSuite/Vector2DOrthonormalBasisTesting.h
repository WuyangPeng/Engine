///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:09)

#ifndef MATHEMATICS_ALGEBRA_SUITE_Vector2_ORTHONORMAL_BASIS_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_Vector2_ORTHONORMAL_BASIS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Vector2OrthonormalBasisTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Vector2OrthonormalBasisTesting;
        using ParentType = UnitTest;

    public:
        explicit Vector2OrthonormalBasisTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void OrthonormalBasisTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_Vector2_ORTHONORMAL_BASIS_TESTING_H