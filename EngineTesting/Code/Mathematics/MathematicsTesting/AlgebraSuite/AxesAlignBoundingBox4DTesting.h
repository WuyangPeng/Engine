///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:05)

#ifndef MATHEMATICS_BASE_SUITE_AXES_ALIGN_BOUNDING_BOX_4D_TESTING_H
#define MATHEMATICS_BASE_SUITE_AXES_ALIGN_BOUNDING_BOX_4D_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class AxesAlignBoundingBox4DTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AxesAlignBoundingBox4DTesting);

    private:
        void MainTest();
        void ConstructionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_AXES_ALIGN_BOUNDING_BOX_4D_TESTING_H