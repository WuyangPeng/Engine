///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/04 13:17)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_ACHIEVE_H

#include "DynamicFindIntersectorHalfspace3Sphere3.h"
#include "Detail/TestIntersectorAxisImpl.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>::DynamicFindIntersectorHalfspace3Sphere3(const Plane3& halfspace, const Sphere3& sphere, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Halfspace{ halfspace }, m_Sphere{ sphere }, m_Point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Halfspace;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>::Find()
{
    this->SetContactTime(Math::GetValue(0));

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto distance = Vector3DTools::DotProduct(m_Halfspace.GetNormal(), m_Sphere.GetCenter());

    const TestIntersectorAxisImpl<Real> testIntersectorAxis{ m_Halfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, m_Halfspace.GetConstant(), distance - m_Sphere.GetRadius(), distance + m_Sphere.GetRadius(), this->GetTMax() };
    auto contactTime = testIntersectorAxis.GetTFirst();

    if (!testIntersectorAxis.GetResult())
    {
        // 永不相交。
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (Math::Approximate(contactTime, Math::GetValue(0)))
    {
        // 现在相交。
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    m_Point = m_Sphere.GetCenter() + contactTime * this->GetRhsVelocity() - m_Sphere.GetRadius() * m_Halfspace.GetNormal();

    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Point);
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Point;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_ACHIEVE_H