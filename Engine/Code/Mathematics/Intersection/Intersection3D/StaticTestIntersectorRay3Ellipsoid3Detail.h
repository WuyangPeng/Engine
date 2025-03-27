///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:28)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H

#include "StaticTestIntersectorRay3Ellipsoid3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Ellipsoid3<Real>::StaticTestIntersectorRay3Ellipsoid3(const Ray3& ray, const Ellipsoid3& ellipsoid, const Real epsilon)
    : ParentType{ epsilon }, ray{ ray }, ellipsoid{ ellipsoid }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorRay3Ellipsoid3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Ellipsoid3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ray;
}

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorRay3Ellipsoid3<Real>::GetEllipsoid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ellipsoid;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Ellipsoid3<Real>::Test()
{
    const auto matrix = ellipsoid.GetMatrix();

    const auto diff = ray.GetOrigin() - ellipsoid.GetCenter();
    const auto matDir = matrix * ray.GetDirection();
    const auto matDiff = matrix * diff;
    const auto a2 = Vector3Tools::DotProduct(ray.GetDirection(), matDir);
    const auto a1 = Vector3Tools::DotProduct(ray.GetDirection(), matDiff);
    const auto a0 = Vector3Tools::DotProduct(diff, matDiff) - MathType::GetValue(1);

    const auto discr = a1 * a1 - a0 * a2;
    if (discr < MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (a0 <= MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Point);
        return;
    }

    if (a1 < MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_DETAIL_H