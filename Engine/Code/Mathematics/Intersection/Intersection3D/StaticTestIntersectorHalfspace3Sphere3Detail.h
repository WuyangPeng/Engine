///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:25)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H

#include "IntersectorUtility3.h"
#include "StaticTestIntersectorHalfspace3Sphere3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorHalfspace3Sphere3<Real>::StaticTestIntersectorHalfspace3Sphere3(const Plane3Type& halfspace, const Sphere3Type& sphere, const Real epsilon) noexcept
    : ParentType{ epsilon }, halfspace{ halfspace }, sphere{ sphere }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorHalfspace3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorHalfspace3Sphere3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return halfspace;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::StaticTestIntersectorHalfspace3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sphere;
}

template <typename Real>
void Mathematics::StaticTestIntersectorHalfspace3Sphere3<Real>::Test() noexcept
{
    const auto distance = Vector3ToolsType::DotProduct(halfspace.GetNormal(), sphere.GetCenter());
    if (distance <= halfspace.GetConstant() + sphere.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H