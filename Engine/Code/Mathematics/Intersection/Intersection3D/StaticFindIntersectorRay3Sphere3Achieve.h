///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/02 17:44)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_ACHIEVE_H

#include "StaticFindIntersectorRay3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Sphere3<Real>::StaticFindIntersectorRay3Sphere3(const Ray3& ray, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, ray{ ray }, sphere{ sphere }, quantity{}, point0{}, point1{}, rayParameter0{}, rayParameter1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorRay3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Sphere3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ray;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorRay3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay3Sphere3<Real>::Find()
{
    auto diff = ray.GetOrigin() - sphere.GetCenter();
    auto a0 = Vector3Tools::DotProduct(diff, diff) - sphere.GetRadius() * sphere.GetRadius();

    if (a0 <= Math::GetValue(0))
    {
        // P在球体内
        auto a1 = Vector3Tools::DotProduct(ray.GetDirection(), diff);
        auto discr = a1 * a1 - a0;
        auto root = Math::Sqrt(discr);
        rayParameter0 = -a1 + root;
        point0 = ray.GetOrigin() + rayParameter0 * ray.GetDirection();
        quantity = 1;
        this->SetIntersectionType(IntersectionType::Point);
        return;
    }
    // 否则：P在范围之外

    auto a1 = Vector3Tools::DotProduct(ray.GetDirection(), diff);
    if (Math::GetValue(0) <= a1)
    {
        quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto discr = a1 * a1 - a0;
    if (discr < Math::GetValue(0))
    {
        quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else if (Math::GetZeroTolerance() <= discr)
    {
        auto root = Math::Sqrt(discr);
        rayParameter0 = -a1 - root;
        rayParameter1 = -a1 + root;
        point0 = ray.GetOrigin() + rayParameter0 * ray.GetDirection();
        point1 = ray.GetOrigin() + rayParameter1 * ray.GetDirection();
        quantity = 2;
        this->SetIntersectionType(IntersectionType::Segment);
    }
    else
    {
        rayParameter0 = -a1;
        point0 = ray.GetOrigin() + rayParameter0 * ray.GetDirection();
        quantity = 1;
        this->SetIntersectionType(IntersectionType::Point);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay3Sphere3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorRay3Sphere3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Sphere3<Real>::GetRayParameter(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return rayParameter0;
        else
            return rayParameter1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_ACHIEVE_H