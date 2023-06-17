///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:14)

#ifndef MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_INFORMATION_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_INFORMATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Vector3InformationTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Vector3InformationTesting;
        using ParentType = UnitTest;

    public:
        explicit Vector3InformationTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DimensionTest();
        void AxesAlignBoundingBoxTest();
        void DirectionTest();
        void ExtremeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_VECTOR_3D_INFORMATION_TESTING_H