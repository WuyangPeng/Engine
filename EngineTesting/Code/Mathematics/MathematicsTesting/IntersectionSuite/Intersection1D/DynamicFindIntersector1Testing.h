// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:51)

#ifndef MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_FIND_INTERSECTOR1_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_FIND_INTERSECTOR1_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Mathematics/Intersection/IntersectionFwd.h"

namespace Mathematics
{
    class DynamicFindIntersector1Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = DynamicFindIntersector1Testing;
        using ParentType = UnitTest;

    public:
        explicit DynamicFindIntersector1Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void IntersectorTest();
        void GetFirstTimeException(const DynamicFindIntersector1<double>& intersector1);
        void GetLastTimeException(const DynamicFindIntersector1<double>& intersector1);

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_FIND_INTERSECTOR1_TESTING_H