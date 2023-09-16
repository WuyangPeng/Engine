///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:48)

#ifndef MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_DETAIL_H
#define MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_DETAIL_H

#include "DynamicIntersectorTest.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/DynamicIntersectorDetail.h"

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersectorTest<Real, Vector>::DynamicIntersectorTest(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity, IntersectionType intersectionType, Real contactTime, const Real epsilon) noexcept
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon }
{
    ParentType::SetIntersectionType(intersectionType);
    ParentType::SetContactTime(contactTime);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, template <typename> class Vector>
bool Mathematics::DynamicIntersectorTest<Real, Vector>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

#endif  // MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_DETAIL_H