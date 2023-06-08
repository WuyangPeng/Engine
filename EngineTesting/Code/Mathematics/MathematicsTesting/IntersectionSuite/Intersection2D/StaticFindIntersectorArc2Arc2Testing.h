///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/06 11:04)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_ARC2_ARC2_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_ARC2_ARC2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Intersection/IntersectionFwd.h"

namespace Mathematics
{
    class StaticFindIntersectorArc2Arc2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = StaticFindIntersectorArc2Arc2Testing;
        using ParentType = UnitTest;

    public:
        explicit StaticFindIntersectorArc2Arc2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void SameTest() noexcept;
        void EmptyTest();
        void PointTest() noexcept;
        void ExceptionTest(const StaticFindIntersectorArc2Arc2<float>& intersector);

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_TESTING_H