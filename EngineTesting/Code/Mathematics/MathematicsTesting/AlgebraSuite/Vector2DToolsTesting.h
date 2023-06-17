///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 11:14)

#ifndef MATHEMATICS_BASE_SUITE_VECTOR_2D_TOOLS_TESTING_H
#define MATHEMATICS_BASE_SUITE_VECTOR_2D_TOOLS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Vector2ToolsTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Vector2ToolsTesting;
        using ParentType = UnitTest;

    public:
        explicit Vector2ToolsTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

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