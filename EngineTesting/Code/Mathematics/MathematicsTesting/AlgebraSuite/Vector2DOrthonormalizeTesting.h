///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:09)

#ifndef MATHEMATICS_ALGEBRA_SUITE_Vector2_ORTHONORMALIZE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_Vector2_ORTHONORMALIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Vector2OrthonormalizeTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Vector2OrthonormalizeTesting;
        using ParentType = UnitTest;

    public:
        explicit Vector2OrthonormalizeTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void OrthonormalizeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_Vector2_ORTHONORMALIZE_TESTING_H