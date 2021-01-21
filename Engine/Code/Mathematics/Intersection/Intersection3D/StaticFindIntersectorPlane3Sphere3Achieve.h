///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 18:04)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_ACHIEVE_H

#include "StaticFindIntersectorPlane3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::StaticFindIntersectorPlane3Sphere3(const Plane3& plane, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, m_Plane{ plane }, m_Sphere{ sphere }, m_Circle{ Vector3D::GetZero(), Vector3D::GetZero(), Vector3D::GetZero(), Vector3D::GetZero(), Math::GetValue(0) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Plane;
}

template <typename Real>
const Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Sphere;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::Find()
{
    auto signedDistance = m_Plane.DistanceTo(m_Sphere.GetCenter());
    auto distance = Math::FAbs(signedDistance);
    auto center = m_Sphere.GetCenter() - signedDistance * m_Plane.GetNormal();
    const auto normal = m_Plane.GetNormal();
    if (distance <= m_Sphere.GetRadius())
    {
        // 球体与平面相交成一个圆。 当距离等于m_Sphere.GetRadius()时，圆会退化，在这种情况下，圆半径为零。
        auto radius = Math::Sqrt(Math::FAbs(m_Sphere.GetRadius() * m_Sphere.GetRadius() - distance * distance));
        this->SetIntersectionType(IntersectionType::Point);
        m_Circle = Circle3{ center, Vector3D::GetZero(), Vector3D::GetZero(), normal, radius };
        return;
    }

    // 圆的附加指示。
    auto radius = Math::GetValue(-1);
    m_Circle = Circle3{ center, Vector3D::GetZero(), Vector3D::GetZero(), normal, radius };
    this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::SphereIsCulled() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto signedDistance = m_Plane.DistanceTo(m_Sphere.GetCenter());
    return signedDistance <= -m_Sphere.GetRadius();
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Circle;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_ACHIEVE_H