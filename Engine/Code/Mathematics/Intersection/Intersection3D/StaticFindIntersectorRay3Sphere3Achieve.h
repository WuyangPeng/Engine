///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 19:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_ACHIEVE_H

#include "StaticFindIntersectorRay3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorRay3Sphere3<Real>::StaticFindIntersectorRay3Sphere3(const Ray3& ray, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, m_Ray{ ray }, m_Sphere{ sphere }, m_Quantity{}, m_Point0{}, m_Point1{}, m_RayParameter0{}, m_RayParameter1{}
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
const Mathematics::Ray3<Real> Mathematics::StaticFindIntersectorRay3Sphere3<Real>::GetRay() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ray;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorRay3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
void Mathematics::StaticFindIntersectorRay3Sphere3<Real>::Find()
{
    auto diff = m_Ray.GetOrigin() - m_Sphere.GetCenter();
    auto a0 = Vector3DTools::DotProduct(diff, diff) - m_Sphere.GetRadius() * m_Sphere.GetRadius();

    if (a0 <= Math::GetValue(0))
    {
        // P在球体内
        auto a1 = Vector3DTools::DotProduct(m_Ray.GetDirection(), diff);
        auto discr = a1 * a1 - a0;
        auto root = Math::Sqrt(discr);
        m_RayParameter0 = -a1 + root;
        m_Point0 = m_Ray.GetOrigin() + m_RayParameter0 * m_Ray.GetDirection();
        m_Quantity = 1;
        this->SetIntersectionType(IntersectionType::Point);
        return;
    }
    // 否则：P在范围之外

    auto a1 = Vector3DTools::DotProduct(m_Ray.GetDirection(), diff);
    if (Math::GetValue(0) <= a1)
    {
        m_Quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto discr = a1 * a1 - a0;
    if (discr < Math::GetValue(0))
    {
        m_Quantity = 0;
        this->SetIntersectionType(IntersectionType::Empty);
    }
    else if (Math::GetZeroTolerance() <= discr)
    {
        auto root = Math::Sqrt(discr);
        m_RayParameter0 = -a1 - root;
        m_RayParameter1 = -a1 + root;
        m_Point0 = m_Ray.GetOrigin() + m_RayParameter0 * m_Ray.GetDirection();
        m_Point1 = m_Ray.GetOrigin() + m_RayParameter1 * m_Ray.GetDirection();
        m_Quantity = 2;
        this->SetIntersectionType(IntersectionType::Segment);
    }
    else
    {
        m_RayParameter0 = -a1;
        m_Point0 = m_Ray.GetOrigin() + m_RayParameter0 * m_Ray.GetDirection();
        m_Quantity = 1;
        this->SetIntersectionType(IntersectionType::Point);
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorRay3Sphere3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorRay3Sphere3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

template <typename Real>
Real Mathematics::StaticFindIntersectorRay3Sphere3<Real>::GetRayParameter(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_RayParameter0;
        else
            return m_RayParameter1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_ACHIEVE_H