///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/06 10:40)

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