///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:48)

#ifndef MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_DETAIL_H
#define MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_DETAIL_H

#include "Intersector1Test.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Intersector1Detail.h"

template <typename Real>
Mathematics::Intersector1Test<Real>::Intersector1Test(Real u0, Real u1, Real v0, Real v1) noexcept
    : ParentType{ u0, u1, v0, v1 }
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
bool Mathematics::Intersector1Test<Real>::IsIntersection() const noexcept
{
    return false;
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_DETAIL_H