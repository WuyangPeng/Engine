///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:09)

#ifndef MATHEMATICS_BASE_SUITE_VECTOR_2D_TOOLS_TESTING_H
#define MATHEMATICS_BASE_SUITE_VECTOR_2D_TOOLS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Vector2ToolsTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Vector2ToolsTesting);

    private:
        void MainTest();
        void DistanceTest();
        void ProductTest();
        void ProjectionTest();
        void PerpTest();
        void CompareTest();
        void OtherCalculateTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_VECTOR_2D_TOOLS_TESTING_H