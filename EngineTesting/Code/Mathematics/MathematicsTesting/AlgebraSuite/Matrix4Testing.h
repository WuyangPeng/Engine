///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:11)

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