///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:49)

#ifndef MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_TEST_INTERSECTOR1_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_TEST_INTERSECTOR1_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Intersection/IntersectionFwd.h"

namespace Mathematics
{
    class DynamicTestIntersector1Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = DynamicTestIntersector1Testing;
        using ParentType = UnitTest;

    public:
        explicit DynamicTestIntersector1Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void IntersectorTest();
        void GetFirstTimeException(const DynamicTestIntersector1<double>& intersector1);
        void GetLastTimeException(const DynamicTestIntersector1<double>& intersector1);

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_TEST_INTERSECTOR1_TESTING_H