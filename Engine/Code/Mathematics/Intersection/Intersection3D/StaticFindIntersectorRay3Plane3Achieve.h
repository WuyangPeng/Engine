///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:27)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Plane3Detail.h"
#include "StaticFindIntersectorRay3Plane3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Objects3D/Line3Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Plane3<Real>::StaticFindIntersectorRay3Plane3(const Ray3& ray, const Plane3& plane, const Real epsilon) noexcept
    : ParentType{ epsilon }, ray{ ray }, plane{ plane }, rayParameter{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorRay3Plane3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Plane3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorRay3Plane3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorRay3Plane3<Real>::Find() noexcept
{
    const Line3<Real> line{ ray.GetOrigin(), ray.GetDirection() };
    StaticFindIntersectorLine3Plane3<Real> intr{ line, plane };
    rayParameter = intr.GetLineParameter();
    if (intr.IsIntersection() && Math::GetValue(0) <= rayParameter)
    {
        // 线与平面相交，但可能与射线不在同一点。
        this->SetIntersectionType(intr.GetIntersectionType());

        return;
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Plane3<Real>::GetRayParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rayParameter;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_ACHIEVE_H