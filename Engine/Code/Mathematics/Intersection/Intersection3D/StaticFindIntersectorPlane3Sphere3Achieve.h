///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 13:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_ACHIEVE_H

#include "StaticFindIntersectorPlane3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::StaticFindIntersectorPlane3Sphere3(const Plane3& plane, const Sphere3& sphere, const Real epsilon)
    : ParentType{ epsilon }, plane{ plane }, sphere{ sphere }, circle{ Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), Vector3::GetZero(), MathType::GetValue(0) }
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
Mathematics::Plane3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return plane;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
void Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::Find()
{
    auto signedDistance = plane.DistanceTo(sphere.GetCenter());
    auto distance = MathType::FAbs(signedDistance);
    auto center = sphere.GetCenter() - signedDistance * plane.GetNormal();
    const auto normal = plane.GetNormal();
    if (distance <= sphere.GetRadius())
    {
        // ������ƽ���ཻ��һ��Բ�� ���������m_Sphere.GetRadius()ʱ��Բ���˻�������������£�Բ�뾶Ϊ�㡣
        auto radius = MathType::Sqrt(MathType::FAbs(sphere.GetRadius() * sphere.GetRadius() - distance * distance));
        this->SetIntersectionType(IntersectionType::Point);
        circle = Circle3{ center, Vector3::GetZero(), Vector3::GetZero(), normal, radius };
        return;
    }

    // Բ�ĸ���ָʾ��
    auto radius = MathType::GetValue(-1);
    circle = Circle3{ center, Vector3::GetZero(), Vector3::GetZero(), normal, radius };
    this->SetIntersectionType(IntersectionType::Empty);
}

template <typename Real>
bool Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::SphereIsCulled() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto signedDistance = plane.DistanceTo(sphere.GetCenter());
    return signedDistance <= -sphere.GetRadius();
}

template <typename Real>
Mathematics::Circle3<Real> Mathematics::StaticFindIntersectorPlane3Sphere3<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_ACHIEVE_H