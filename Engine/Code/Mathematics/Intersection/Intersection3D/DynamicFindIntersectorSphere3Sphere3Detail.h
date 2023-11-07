///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:13)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H

#include "DynamicFindIntersectorSphere3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::DynamicFindIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, Real tMax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon },
      sphere0{ sphere0 },
      sphere1{ sphere1 },
      circle{ Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), 0 },
      contactPoint{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::GetSphere0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere0;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::GetSphere1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere1;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::Find()
{
    const auto rhsVelocity = this->GetRhsVelocity();
    const auto lhsVelocity = this->GetLhsVelocity();
    auto tMax = this->GetTMax();

    auto relVelocity = rhsVelocity - lhsVelocity;
    auto relVelocitySquared = Vector3Tools::GetLengthSquared(relVelocity);
    auto diff = sphere1.GetCenter() - sphere0.GetCenter();
    auto diffSqr = Vector3Tools::GetLengthSquared(diff);
    auto radiusSum = sphere0.GetRadius() + sphere1.GetRadius();
    auto radiusSumSqr = radiusSum * radiusSum;

    if (Math::GetValue(0) < relVelocitySquared)
    {
        auto dot = Vector3Tools::DotProduct(diff, relVelocity);
        if (dot <= Math::GetValue(0))
        {
            if (-tMax * relVelocitySquared <= dot || tMax * (tMax * relVelocitySquared + Math::GetValue(2) * dot) + diffSqr <= radiusSumSqr)
            {
                auto minus = diffSqr - radiusSumSqr;
                auto discr = dot * dot - relVelocitySquared * minus;
                if (Math::GetValue(0) <= discr)
                {
                    if (minus <= Math::GetValue(0))
                    {
                        // 球体最初是相交的。 通过使用连接球体中心的线段的中点来估计接触点。
                        this->SetContactTime(Math::GetValue(0));
                        contactPoint = Math::GetRational(1, 2) * (sphere0.GetCenter() + sphere1.GetCenter());
                    }
                    else
                    {
                        // 第一次接触是在[0,tmax]中。
                        this->SetContactTime(-(dot + Math::Sqrt(discr)) / relVelocitySquared);
                        if (this->GetContactTime() < Math::GetValue(0))
                        {
                            this->SetContactTime(Math::GetValue(0));
                        }
                        else if (this->GetContactTime() > tMax)
                        {
                            this->SetContactTime(tMax);
                        }

                        auto newDiff = diff + this->GetContactTime() * relVelocity;

                        contactPoint = sphere0.GetCenter() + this->GetContactTime() * lhsVelocity + (sphere0.GetRadius() / radiusSum) * newDiff;
                    }

                    this->SetIntersectionType(IntersectionType::Other);
                    return;
                }
            }
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    if (diffSqr <= radiusSumSqr)
    {
        // 球体最初是相交的。 通过使用连接球心的线段的中点来估计接触点。
        this->SetContactTime(Math::GetValue(0));
        contactPoint = (Math::GetRational(1, 2)) * (sphere0.GetCenter() + sphere1.GetCenter());
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
Mathematics::Circle3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::GetContactPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return contactPoint;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H