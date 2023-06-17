///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:11)

#ifndef MATHEMATICS_ALGEBRA_SUITE_AXES_ALIGN_BOUNDING_BOX_3D_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_AXES_ALIGN_BOUNDING_BOX_3D_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class AxesAlignBoundingBox3DTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AxesAlignBoundingBox3DTesting;
        using ParentType = UnitTest;

    public:
        explicit AxesAlignBoundingBox3DTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructionTest();
        void AccessTest();
        void IntersectionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_AXES_ALIGN_BOUNDING_BOX_3D_TESTING_H