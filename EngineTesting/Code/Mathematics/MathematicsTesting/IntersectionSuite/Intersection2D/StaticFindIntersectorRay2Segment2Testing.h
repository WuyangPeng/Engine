///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:50)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class StaticFindIntersectorRay2Segment2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = StaticFindIntersectorRay2Segment2Testing;
        using ParentType = UnitTest;

    public:
        explicit StaticFindIntersectorRay2Segment2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void SegmentTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_RAY2_SEGMENT2_TESTING_H