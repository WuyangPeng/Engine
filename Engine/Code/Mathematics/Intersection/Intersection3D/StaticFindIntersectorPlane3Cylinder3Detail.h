///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 13:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H

#include "StaticFindIntersectorPlane3Cylinder3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::StaticFindIntersectorPlane3Cylinder3(const Plane3& plane, const Cylinder3& cylinder, const Real epsilon)
    : ParentType{ epsilon },
      plane{ plane },
      cylinder{ cylinder },
      type{ CylinderPlaneIntersection::EmptySet },
      line0{ Vector3::GetZero(), Vector3::GetZero() },
      line1{ Vector3::GetZero(), Vector3::GetZero() },
      circle{ Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), Math::GetValue(0) },
      ellipse{ Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), Math::GetValue(0), Math::GetValue(0) }
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
Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane;
}

template <typename Real>
Mathematics::Cylinder3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetCylinder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return cylinder;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::Find()
{
    auto distance = plane.DistanceTo(cylinder.GetAxis().GetOrigin());
    auto center = cylinder.GetAxis().GetOrigin() - distance * plane.GetNormal();
    auto cosTheta = Vector3Tools::DotProduct(cylinder.GetAxis().GetDirection(), plane.GetNormal());
    auto absCosTheta = Math::FAbs(cosTheta);

    if (Math::GetValue(0) < absCosTheta)
    {
        // Բ������Ψһ������ƽ���ཻ��
        if (absCosTheta < Math::GetValue(1))
        {
            type = CylinderPlaneIntersection::Ellipse;
            auto major = (cylinder.GetAxis().GetDirection() - cosTheta * plane.GetNormal());
            auto minor = Vector3Tools::CrossProduct(plane.GetNormal(), major);
            major.Normalize();
            minor.Normalize();
            ellipse = Ellipse3{ center - (distance / cosTheta) * cylinder.GetAxis().GetDirection(),
                                plane.GetNormal(),
                                major,
                                minor,
                                cylinder.GetRadius() / absCosTheta,
                                cylinder.GetRadius() };
            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            type = CylinderPlaneIntersection::Circle;
            circle = Circle3{ center, circle.GetDirection0(), circle.GetDirection1(), plane.GetNormal(), cylinder.GetRadius() };

            this->SetIntersectionType(IntersectionType::Other);

            return;
        }
    }
    else
    {
        // Բ����ƽ����ƽ�档
        auto absDistance = Math::FAbs(distance);
        if (absDistance < cylinder.GetRadius())
        {
            type = CylinderPlaneIntersection::TwoLines;

            const auto offset = Vector3Tools::CrossProduct(cylinder.GetAxis().GetDirection(), plane.GetNormal());
            auto extent = Math::Sqrt(cylinder.GetRadius() * cylinder.GetRadius() - distance * distance);

            line0 = Line3{ center - extent * offset, cylinder.GetAxis().GetDirection() };
            line1 = Line3{ center + extent * offset, cylinder.GetAxis().GetDirection() };

            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else if (Math::Approximate(absDistance, cylinder.GetRadius()))
        {
            type = CylinderPlaneIntersection::OneLine;
            line0 = Line3{ center, cylinder.GetAxis().GetDirection() };

            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else
        {
            type = CylinderPlaneIntersection::EmptySet;
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }
}

template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::CylinderIsCulled() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    // ����Բ�����ϵ�ķ��ž���Dot(N,X) - d�ļ�ֵ�� ��Щ��
    //   min = (Dot(N,C)-d) - r*sqrt(1-Dot(N,W)^2) - (h/2)*|Dot(N,W)|
    //   max = (Dot(N,C)-d) + r*sqrt(1-Dot(N,W)^2) + (h/2)*|Dot(N,W)|
    const auto distance = plane.DistanceTo(cylinder.GetAxis().GetOrigin());
    const auto absNormalDotDirection = Math::FAbs(Vector3Tools::DotProduct(plane.GetNormal(), cylinder.GetAxis().GetDirection()));
    const auto root = Math::Sqrt(Math::FAbs(Math::GetValue(1) - absNormalDotDirection * absNormalDotDirection));
    const auto term = cylinder.GetRadius() * root + Math::GetRational(1, 2) * cylinder.GetHeight() * absNormalDotDirection;

    // ���ҽ���max <= 0ʱ�ŷ����޳���
    return distance + term <= Math::GetValue(0);
}

template <typename Real>
typename Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::CylinderPlaneIntersection Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetType() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return type;
}

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetOneLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line0;
}

template <typename Real>
typename Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::TwoLine Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetTwoLines() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return { line0, line1 };
}

template <typename Real>
Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
Mathematics::Ellipse3<Real> Mathematics::StaticFindIntersectorPlane3Cylinder3<Real>::GetEllipse() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ellipse;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H