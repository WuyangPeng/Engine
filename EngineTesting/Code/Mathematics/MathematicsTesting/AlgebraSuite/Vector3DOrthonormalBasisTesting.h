///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:14)

#ifndef MATHEMATICS_ALGEBRA_SUITE_Vector3_ORTHONORMAL_BASIS_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_Vector3_ORTHONORMAL_BASIS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Vector3OrthonormalBasisTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Vector3OrthonormalBasisTesting;
        using ParentType = UnitTest;

    public:
        explicit Vector3OrthonormalBasisTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void OrthonormalBasisTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_Vector3_ORTHONORMAL_BASIS_TESTING_H