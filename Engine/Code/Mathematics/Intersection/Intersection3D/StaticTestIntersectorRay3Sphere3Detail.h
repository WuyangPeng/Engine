///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:28)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorRay3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorRay3Sphere3<Real>::StaticTestIntersectorRay3Sphere3(const Ray3Type& ray, const Sphere3Type& sphere, const Real epsilon)
    : ParentType{ epsilon }, ray{ ray }, sphere{ sphere }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorRay3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::StaticTestIntersectorRay3Sphere3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ray;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorRay3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorRay3Sphere3<Real>::Test()
{
    const auto diff = ray.GetOrigin() - sphere.GetCenter();
    const auto a0 = Vector3ToolsType::DotProduct(diff, diff) - sphere.GetRadius() * sphere.GetRadius();
    if (a0 <= MathType ::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    const auto a1 = Vector3ToolsType::DotProduct(ray.GetDirection(), diff);
    if (MathType ::GetValue(0) <= a1)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (a0 <= a1 * a1)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_SPHERE3_DETAIL_H