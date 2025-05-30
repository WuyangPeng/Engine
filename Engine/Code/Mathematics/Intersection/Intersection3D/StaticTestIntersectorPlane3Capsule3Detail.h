///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_DETAIL_H

#include "StaticTestIntersectorPlane3Capsule3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Capsule3<Real>::StaticTestIntersectorPlane3Capsule3(const Plane3Type& plane, const Capsule3Type& capsule, const Real epsilon) noexcept
    : ParentType{ epsilon }, plane{ plane }, capsule{ capsule }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Capsule3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Capsule3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane;
}

template <typename Real>
Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorPlane3Capsule3<Real>::GetCapsule() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return capsule;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Capsule3<Real>::Test() noexcept
{
    auto pDist = plane.DistanceTo(capsule.GetSegment().GetEndPoint());
    auto nDist = plane.DistanceTo(capsule.GetSegment().GetBeginPoint());
    if (pDist * nDist <= MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    if (MathType::FAbs(pDist) <= capsule.GetRadius() || MathType::FAbs(nDist) <= capsule.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Capsule3<Real>::CapsuleIsCulled() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto pDist = plane.DistanceTo(capsule.GetSegment().GetEndPoint());
    if (pDist < MathType::GetValue(0))
    {
        auto nDist = plane.DistanceTo(capsule.GetSegment().GetBeginPoint());
        if (nDist < MathType::GetValue(0))
        {
            if (pDist <= nDist)
            {
                return (pDist <= -capsule.GetRadius());
            }
            else
            {
                return (nDist <= -capsule.GetRadius());
            }
        }
    }

    return false;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_DETAIL_H