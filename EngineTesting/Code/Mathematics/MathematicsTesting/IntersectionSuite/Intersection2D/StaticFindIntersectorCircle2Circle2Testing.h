// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:53)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Mathematics/Intersection/Intersection2D/StaticFindIntersectorCircle2Circle2.h"

namespace Mathematics
{
    class StaticFindIntersectorCircle2Circle2Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StaticFindIntersectorCircle2Circle2Testing);

    private:
        void MainTest();
        void SameTest();
        void EmptyTest();
        void TangentTest();
        void PointTest();
        void ExceptionTest(const StaticFindIntersectorCircle2Circle2<float>& intersector);

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_TESTING_H