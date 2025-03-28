///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 13:50)

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
      circle{ Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), MathType::GetValue(0) },
      ellipse{ Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), MathType::GetValue(0), MathType::GetValue(0) }
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
    auto cosTheta = Vector3ToolsType::DotProduct(cylinder.GetAxis().GetDirection(), plane.GetNormal());
    auto absCosTheta = MathType::FAbs(cosTheta);

    if (MathType::GetValue(0) < absCosTheta)
    {
        // 圆柱轴在唯一点上与平面相交。
        if (absCosTheta < MathType::GetValue(1))
        {
            type = CylinderPlaneIntersection::Ellipse;
            auto major = (cylinder.GetAxis().GetDirection() - cosTheta * plane.GetNormal());
            auto minor = Vector3ToolsType::CrossProduct(plane.GetNormal(), major);
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
        // 圆柱体平行于平面。
        auto absDistance = MathType::FAbs(distance);
        if (absDistance < cylinder.GetRadius())
        {
            type = CylinderPlaneIntersection::TwoLines;

            const auto offset = Vector3ToolsType::CrossProduct(cylinder.GetAxis().GetDirection(), plane.GetNormal());
            auto extent = MathType::Sqrt(cylinder.GetRadius() * cylinder.GetRadius() - distance * distance);

            line0 = Line3{ center - extent * offset, cylinder.GetAxis().GetDirection() };
            line1 = Line3{ center + extent * offset, cylinder.GetAxis().GetDirection() };

            this->SetIntersectionType(IntersectionType::Other);
            return;
        }
        else if (MathType::Approximate(absDistance, cylinder.GetRadius()))
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
    // 计算圆柱体上点的符号距离Dot(N,X) - d的极值。 这些是
    //   min = (Dot(N,C)-d) - r*sqrt(1-Dot(N,W)^2) - (h/2)*|Dot(N,W)|
    //   max = (Dot(N,C)-d) + r*sqrt(1-Dot(N,W)^2) + (h/2)*|Dot(N,W)|
    const auto distance = plane.DistanceTo(cylinder.GetAxis().GetOrigin());
    const auto absNormalDotDirection = MathType::FAbs(Vector3ToolsType::DotProduct(plane.GetNormal(), cylinder.GetAxis().GetDirection()));
    const auto root = MathType::Sqrt(MathType::FAbs(MathType::GetValue(1) - absNormalDotDirection * absNormalDotDirection));
    const auto term = cylinder.GetRadius() * root + MathType::GetRational(1, 2) * cylinder.GetHeight() * absNormalDotDirection;

    // 当且仅当max <= 0时才发生剔除。
    return distance + term <= MathType::GetValue(0);
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