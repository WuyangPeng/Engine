///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_ACHIEVE_H

#include "StaticTestIntersectorCapsule3Capsule3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceSegment3Segment3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>::StaticTestIntersectorCapsule3Capsule3(const Capsule3& capsule0, const Capsule3& capsule1, const Real epsilon)
    : ParentType{ epsilon }, capsule0{ capsule0 }, capsule1{ capsule1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>::GetCapsule0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return capsule0;
}

template <typename Real>
Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>::GetCapsule1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return capsule1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorCapsule3Capsule3<Real>::Test()
{
    DistanceSegment3Segment3<Real> distanceSegment3Segment3{ capsule0.GetSegment(), capsule1.GetSegment() };
    auto distance = distanceSegment3Segment3.Get().GetDistance();
    auto radiusSum = capsule0.GetRadius() + capsule1.GetRadius();
    if (distance <= radiusSum)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_ACHIEVE_H