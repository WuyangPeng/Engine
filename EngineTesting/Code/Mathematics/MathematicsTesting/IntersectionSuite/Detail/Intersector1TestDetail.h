// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:41)

#ifndef MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_DETAIL_H
#define MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_DETAIL_H

#include "Intersector1Test.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersector1Detail.h"

template <typename Real>
Mathematics::Intersector1Test<Real>::Intersector1Test(Real u0, Real u1, Real v0, Real v1)
    : ParentType{ u0, u1, v0, v1 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Intersector1Test<Real>::~Intersector1Test()
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Intersector1Test<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Intersector1Test<Real>::IsIntersection() const
{
    return false;
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_DETAIL_H