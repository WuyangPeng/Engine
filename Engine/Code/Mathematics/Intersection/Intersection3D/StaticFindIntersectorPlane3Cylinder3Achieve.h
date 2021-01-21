///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 14:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_ACHIEVE_H

#include "StaticFindIntersectorPlane3Cylinder3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::StaticFindIntersectorPlane3Cylinder3(const Plane3& plane, const Cylinder3& cylinder, const Real epsilon)
    : ParentType{ epsilon },
      m_Plane{ plane },
      m_Cylinder{ cylinder },
      m_Type{ CylinderPlaneIntersection::EmptySet },
      m_Line0{ Vector3D::GetZero(), Vector3D::GetZero() },
      m_Line1{ Vector3D::GetZero(), Vector3D::GetZero() },
      m_Circle{ Vector3D::GetZero(), Vector3D::GetZero(), Vector3D::GetZero(), Vector3D::GetZero(), Math::GetValue(0) },
      m_Ellipse{ Vector3D::GetZero(), Vector3D::GetZero(), Vector3D::GetZero(), Vector3D::GetZero(), Math::GetValue(0), Math::GetValue(0) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane;
}

template <typename Real>
const Mathematics::Cylinder3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetCylinder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Cylinder;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::Find()
{
    auto distance = m_Plane.DistanceTo(m_Cylinder.GetAxis().GetOrigin());
    auto center = m_Cylinder.GetAxis().GetOrigin() - distance * m_Plane.GetNormal();
    auto cosTheta = Vector3DTools::DotProduct(m_Cylinder.GetAxis().GetDirection(), m_Plane.GetNormal());
    auto absCosTheta = Math::FAbs(cosTheta);

    if (Math::GetValue(0) < absCosTheta)
    {
        // 圆柱轴在唯一点上与平面相交。
        if (absCosTheta < Math::GetValue(1))
        {
            m_Type = CylinderPlaneIntersection::Ellipse;
            auto major = (m_Cylinder.GetAxis().GetDirection() - cosTheta * m_Plane.GetNormal());
            auto minor = Vector3DTools::CrossProduct(m_Plane.GetNormal(), major);
            major.Normalize();
            minor.Normalize();
            m_Ellipse = Ellipse3{ center - (distance / cosTheta) * m_Cylinder.GetAxis().GetDirection(),
                                  m_Plane.GetNormal(), major, minor,
                                  m_Cylinder.GetRadius() / absCosTheta,
                                  m_Cylinder.GetRadius() };
            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            m_Type = CylinderPlaneIntersection::Circle;
            m_Circle = Circle3{ center, m_Circle.GetDirection0(), m_Circle.GetDirection1(), m_Plane.GetNormal(), m_Cylinder.GetRadius() };

            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
    }
    else
    {
        // 圆柱体平行于平面。
        auto absDistance = Math::FAbs(distance);
        if (absDistance < m_Cylinder.GetRadius())
        {
            m_Type = CylinderPlaneIntersection::TwoLines;

            const auto offset = Vector3DTools::CrossProduct(m_Cylinder.GetAxis().GetDirection(), m_Plane.GetNormal());
            auto extent = Math::Sqrt(m_Cylinder.GetRadius() * m_Cylinder.GetRadius() - distance * distance);

            m_Line0 = Line3{ center - extent * offset, m_Cylinder.GetAxis().GetDirection() };
            m_Line1 = Line3{ center + extent * offset, m_Cylinder.GetAxis().GetDirection() };

            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else if (Math::Approximate(absDistance, m_Cylinder.GetRadius()))
        {
            m_Type = CylinderPlaneIntersection::OneLine;
            m_Line0 = Line3{ center, m_Cylinder.GetAxis().GetDirection() };

            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            m_Type = CylinderPlaneIntersection::EmptySet;
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }
}

template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::CylinderIsCulled() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    // 计算圆柱体上点的符号距离Dot(N,X) - d的极值。 这些是
    //   min = (Dot(N,C)-d) - r*sqrt(1-Dot(N,W)^2) - (h/2)*|Dot(N,W)|
    //   max = (Dot(N,C)-d) + r*sqrt(1-Dot(N,W)^2) + (h/2)*|Dot(N,W)|
    auto distance = m_Plane.DistanceTo(m_Cylinder.GetAxis().GetOrigin());
    auto absNormalDotDirection = Math::FAbs(Vector3DTools::DotProduct(m_Plane.GetNormal(), m_Cylinder.GetAxis().GetDirection()));
    auto root = Math::Sqrt(Math::FAbs(Math::GetValue(1) - absNormalDotDirection * absNormalDotDirection));
    auto term = m_Cylinder.GetRadius() * root + Math::GetRational(1, 2) * m_Cylinder.GetHeight() * absNormalDotDirection;

    // 当且仅当max <= 0时才发生剔除。
    return distance + term <= Math::GetValue(0);
}

template <typename Real>
typename Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::CylinderPlaneIntersection Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Type;
}

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetOneLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line0;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::TwoLine Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetTwoLines() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return { m_Line0, m_Line1 };
}

template <typename Real>
Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

template <typename Real>
Mathematics::Ellipse3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetEllipse() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ellipse;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_ACHIEVE_H