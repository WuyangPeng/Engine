// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:41)

#ifndef MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR_TEST_DETAIL_H
#define MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR_TEST_DETAIL_H

#include "IntersectorTest.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/IntersectorDetail.h"

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)
template <typename Real, template <typename> class Vector>
Mathematics::IntersectorTest<Real, Vector>::IntersectorTest(IntersectionType intersectionType, const Real epsilon) noexcept
    : ParentType{ epsilon }
{
    ParentType::SetIntersectionType(intersectionType);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}
#include STSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, template <typename> class Vector>
bool Mathematics::IntersectorTest<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

#endif  // MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR_TEST_DETAIL_H