///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H

#include "StaticTestIntersectorPlane3Cylinder3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>::StaticTestIntersectorPlane3Cylinder3(const Plane3Type& plane, const Cylinder3Type& cylinder, const Real epsilon) noexcept(gAssert < 3 || gMathematicsAssert < 3)
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
void Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>::Test() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    const auto sDist = plane.DistanceTo(cylinder.GetAxis().GetOrigin());
    const auto absNdW = MathType::FAbs(Vector3ToolsType::DotProduct(plane.GetNormal(), cylinder.GetAxis().GetDirection()));
    const auto root = MathType::Sqrt(MathType::FAbs(MathType::GetValue(1) - absNdW * absNdW));
    const auto term = cylinder.GetRadius() * root + MathType::GetRational(1, 2) * cylinder.GetHeight() * absNdW;

    if (MathType::FAbs(sDist) <= term)
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Cylinder3<Real>::CylinderIsCulled() const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto sDist = plane.DistanceTo(cylinder.GetAxis().GetOrigin());
    const auto absNdW = MathType::FAbs(Vector3ToolsType::DotProduct(plane.GetNormal(), cylinder.GetAxis().GetDirection()));
    const auto root = MathType::Sqrt(MathType::FAbs(MathType::GetValue(1) - absNdW * absNdW));
    const auto term = cylinder.GetRadius() * root + MathType::GetRational(1, 2) * cylinder.GetHeight() * absNdW;

    return sDist + term <= MathType::GetValue(0);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_DETAIL_H