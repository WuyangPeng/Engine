///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:06)

#ifndef MATHEMATICS_BASE_SUITE_MATRIX4_TESTING_H
#define MATHEMATICS_BASE_SUITE_MATRIX4_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Matrix4Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Matrix4Testing;
        using ParentType = UnitTest;

    public:
        explicit Matrix4Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructionTest();
        void AccessTest();
        void OperatorCalculateTest();
        void ArithmeticCalculateTest();
        void ProjectionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_MATRIX4_TESTING_H