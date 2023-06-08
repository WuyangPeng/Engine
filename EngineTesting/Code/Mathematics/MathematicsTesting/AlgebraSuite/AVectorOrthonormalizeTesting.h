///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:04)

#ifndef MATHEMATICS_ALGEBRA_SUITE_AVECTOR_ORTHONORMALIZE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_AVECTOR_ORTHONORMALIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class AVectorOrthonormalizeTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AVectorOrthonormalizeTesting;
        using ParentType = UnitTest;

    public:
        explicit AVectorOrthonormalizeTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void OrthonormalizeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_AVECTOR_ORTHONORMALIZE_TESTING_H