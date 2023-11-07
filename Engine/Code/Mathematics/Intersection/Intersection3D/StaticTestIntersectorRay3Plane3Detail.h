///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:28)

#ifndef MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_DETAIL_H

#include "StaticTestIntersectorRay3Plane3.h"
#include "Detail/IntersectorLine3Triangle3DataDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorLine3Plane3Detail.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Plane3<Real>::StaticTestIntersectorRay3Plane3(const Ray3& ray, const Plane3& plane, const Real epsilon) noexcept
    : ParentType{ epsilon }, ray{ ray }, plane{ plane }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorRay3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Plane3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ray;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorRay3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Plane3<Real>::Test() noexcept
{
    const Line3<Real> line{ ray.GetOrigin(), ray.GetDirection() };
    StaticFindIntersectorLine3Plane3<Real> intr{ line, plane };
    if (intr.IsIntersection() && Math::GetValue(0) <= intr.GetLineParameter())
    {
        this->SetIntersectionType(intr.GetIntersectionType());

        return;
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_DETAIL_H