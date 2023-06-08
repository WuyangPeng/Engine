///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:10)

#ifndef MATHEMATICS_BASE_SUITE_VECTOR_3D_TESTING_H
#define MATHEMATICS_BASE_SUITE_VECTOR_3D_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Vector3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Vector3Testing;
        using ParentType = UnitTest;

    public:
        explicit Vector3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructionTest() noexcept;
        void AccessTest();
        void CalculateTest();
        void BarycentricsTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_VECTOR_3D_TESTING_H