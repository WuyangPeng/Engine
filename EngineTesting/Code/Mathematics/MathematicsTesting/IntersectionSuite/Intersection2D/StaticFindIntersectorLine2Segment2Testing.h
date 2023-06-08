///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/06 11:05)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Intersection/IntersectionFwd.h"

namespace Mathematics
{
    class StaticFindIntersectorLine2Segment2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = StaticFindIntersectorLine2Segment2Testing;
        using ParentType = UnitTest;

    public:
        explicit StaticFindIntersectorLine2Segment2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void SegmentTest();
        void ExceptionTest(const StaticFindIntersectorLine2Segment2<float>& intersector);

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_LINE2_SEGMENT2_TESTING_H