///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 18:10)

#ifndef MATHEMATICS_ALGEBRA_SUITE_VECTOR_4D_TOOLS_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_VECTOR_4D_TOOLS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Vector4ToolsTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Vector4ToolsTesting);

    private:
        void MainTest();
        void DistanceTest();
        void ProductTest();
        void ProjectionTest();
        void CompareTest();
        void OtherCalculateTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_VECTOR_4D_TOOLS_TESTING_H