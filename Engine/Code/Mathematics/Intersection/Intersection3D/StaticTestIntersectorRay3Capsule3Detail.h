///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:31)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_CAPSULE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_CAPSULE3_DETAIL_H

#include "StaticFindIntersectorLine3Capsule3.h"
#include "StaticTestIntersectorRay3Capsule3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceRay3Segment3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Capsule3<Real>::StaticTestIntersectorRay3Capsule3(const Ray3& ray, const Capsule3& capsule, const Real epsilon)
    : ParentType{ epsilon }, ray{ ray }, capsule{ capsule }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorRay3Capsule3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Capsule3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ray;
}

template <typename Real>
Mathematics::Capsule3<Real> Mathematics::StaticTestIntersectorRay3Capsule3<Real>::GetCapsule() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return capsule;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Capsule3<Real>::Test()
{
    const auto distance = DistanceRay3Segment3<Real>(ray, capsule.GetSegment()).Get().GetDistance();
    if (distance <= capsule.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_CAPSULE3_DETAIL_H