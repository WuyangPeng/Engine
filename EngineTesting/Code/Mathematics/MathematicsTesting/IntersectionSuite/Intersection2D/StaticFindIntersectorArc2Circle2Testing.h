///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:50)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Intersection/IntersectionFwd.h"

namespace Mathematics
{
    class StaticFindIntersectorArc2Circle2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = StaticFindIntersectorArc2Circle2Testing;
        using ParentType = UnitTest;

    public:
        explicit StaticFindIntersectorArc2Circle2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void SameTest() noexcept;
        void EmptyTest();
        void PointTest() noexcept;
        void ExceptionTest(const StaticFindIntersectorArc2Circle2<float>& intersector);

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_TESTING_H