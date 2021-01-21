// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/24 16:33)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_ACHIEVE_H

#include "DynamicFindIntersectorSphere3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::DynamicFindIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon },
      m_Sphere0{ sphere0 },
      m_Sphere1{ sphere1 },
      m_Circle{ Vector3D::GetZero(), Vector3D::GetZero(), Vector3D::GetZero(), Vector3D::GetZero(), 0 },
      m_ContactPoint{}
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
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::GetSphere0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere0;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::GetSphere1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere1;
}

template <typename Real>
void Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::Find()
{
    const auto rhsVelocity = this->GetRhsVelocity();
    const auto lhsVelocity = this->GetLhsVelocity();
    auto tMax = this->GetTMax();

    auto relVelocity = rhsVelocity - lhsVelocity;
    auto relVelocitySquared = Vector3DTools::VectorMagnitudeSquared(relVelocity);
    auto diff = m_Sphere1.GetCenter() - m_Sphere0.GetCenter();
    auto diffSqr = Vector3DTools::VectorMagnitudeSquared(diff);
    auto radiusSum = m_Sphere0.GetRadius() + m_Sphere1.GetRadius();
    auto radiusSumSqr = radiusSum * radiusSum;

    if (Math::GetValue(0) < relVelocitySquared)
    {
        auto dot = Vector3DTools::DotProduct(diff, relVelocity);
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
                        m_ContactPoint = Math::GetRational(1, 2) * (m_Sphere0.GetCenter() + m_Sphere1.GetCenter());
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

                        m_ContactPoint = m_Sphere0.GetCenter() + this->GetContactTime() * lhsVelocity + (m_Sphere0.GetRadius() / radiusSum) * newDiff;
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
        m_ContactPoint = (Math::GetRational(1, 2)) * (m_Sphere0.GetCenter() + m_Sphere1.GetCenter());
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorSphere3Sphere3<Real>::GetContactPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_ContactPoint;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H