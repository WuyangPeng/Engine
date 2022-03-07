// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:51)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TEST_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TEST_H

#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
    template <typename Real, template <typename> class Vector>
    class StaticIntersectorTest : public StaticIntersector<Real, Vector>
    {
    public:
        using ClassType = StaticIntersectorTest<Real, Vector>;
        using ParentType = StaticIntersector<Real, Vector>;
        using Math = Math<Real>;

    public:
        explicit StaticIntersectorTest(IntersectionType intersectionType, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TEST_H