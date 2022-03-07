///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/28 11:38)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorHalfspace3Sphere3.h"
#include "TestIntersectorAxis.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>::DynamicFindIntersectorHalfspace3Sphere3(const Plane3& halfspace, const Sphere3& sphere, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, halfspace{ halfspace }, sphere{ sphere }, point{}
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
Mathematics::Plane3<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return halfspace;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>::Find()
{
    this->SetContactTime(Math::GetValue(0));

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto distance = Vector3Tools::DotProduct(halfspace.GetNormal(), sphere.GetCenter());

    const TestIntersectorAxis<Real> testIntersectorAxis{ halfspace.GetNormal(), relVelocity, -Math::maxReal, halfspace.GetConstant(), distance - sphere.GetRadius(), distance + sphere.GetRadius(), this->GetTMax() };
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

    point = sphere.GetCenter() + contactTime * this->GetRhsVelocity() - sphere.GetRadius() * halfspace.GetNormal();

    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Point);
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorHalfspace3Sphere3<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H