///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/04 16:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H

#include "StaticTestIntersectorPlane3Cylinder3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>::StaticTestIntersectorPlane3Cylinder3(const Plane3& plane, const Cylinder3& cylinder, const Real epsilon) noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
    : ParentType{ epsilon }, plane{ plane }, cylinder{ cylinder }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane;
}

template <typename Real>
Mathematics::Cylinder3<Real> Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>::GetCylinder() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cylinder;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>::Test() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    const auto sDist = plane.DistanceTo(cylinder.GetAxis().GetOrigin());
    const auto absNdW = Math::FAbs(Vector3Tools::DotProduct(plane.GetNormal(), cylinder.GetAxis().GetDirection()));
    const auto root = Math::Sqrt(Math::FAbs(Math::GetValue(1) - absNdW * absNdW));
    const auto term = cylinder.GetRadius() * root + Math::GetRational(1, 2) * cylinder.GetHeight() * absNdW;

    if (Math::FAbs(sDist) <= term)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>::CylinderIsCulled() const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto sDist = plane.DistanceTo(cylinder.GetAxis().GetOrigin());
    const auto absNdW = Math::FAbs(Vector3Tools::DotProduct(plane.GetNormal(), cylinder.GetAxis().GetDirection()));
    const auto root = Math::Sqrt(Math::FAbs(Math::GetValue(1) - absNdW * absNdW));
    const auto term = cylinder.GetRadius() * root + Math::GetRational(1, 2) * cylinder.GetHeight() * absNdW;

    return sDist + term <= Math::GetValue(0);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H