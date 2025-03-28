///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H

#include "StaticTestIntersectorSphere3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorSphere3Sphere3<Real>::StaticTestIntersectorSphere3Sphere3(const Sphere3& rkSphere0, const Sphere3& rkSphere1, const Real epsilon)
    : ParentType{ epsilon }, sphere0{ rkSphere0 }, sphere1{ rkSphere1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSphere3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorSphere3Sphere3<Real>::GetSphere0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sphere0;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorSphere3Sphere3<Real>::GetSphere1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sphere1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSphere3Sphere3<Real>::Test()
{
    const auto diff = sphere1.GetCenter() - sphere0.GetCenter();
    const auto rSum = sphere0.GetRadius() + sphere1.GetRadius();
    if (Vector3ToolsType::GetLengthSquared(diff) <= rSum * rSum)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_DETAIL_H