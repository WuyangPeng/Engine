///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:05)

#ifndef MATHEMATICS_ALGEBRA_SUITE_AXES_ALIGN_BOUNDING_BOX_2D_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_AXES_ALIGN_BOUNDING_BOX_2D_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class AxesAlignBoundingBox2DTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AxesAlignBoundingBox2DTesting);

    private:
        void MainTest();
        void ConstructionTest();
        void AccessTest();
        void IntersectionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_AXES_ALIGN_BOUNDING_BOX_2D_TESTING_H