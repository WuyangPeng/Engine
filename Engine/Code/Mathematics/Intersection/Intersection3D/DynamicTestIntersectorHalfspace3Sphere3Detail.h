///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:17)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H

#include "DynamicTestIntersectorHalfspace3Sphere3.h"
#include "TestIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorHalfspace3Sphere3<Real>::DynamicTestIntersectorHalfspace3Sphere3(const Plane3Type& halfspace, const Sphere3Type& sphere, Real tMax, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity, const Real epsilon)
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon }, halfspace{ halfspace }, sphere{ sphere }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicTestIntersectorHalfspace3Sphere3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorHalfspace3Sphere3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return halfspace;
}

template <typename Real>
Mathematics::Sphere3<Real> Mathematics::DynamicTestIntersectorHalfspace3Sphere3<Real>::GetSphere() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sphere;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorHalfspace3Sphere3<Real>::Test()
{
    this->SetContactTime(MathType::GetValue(0));

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    auto distance = Vector3ToolsType::DotProduct(halfspace.GetNormal(), sphere.GetCenter());

    const TestIntersectorAxis<Real> testIntersectorAxis{ halfspace.GetNormal(), relVelocity, -MathType::maxReal, halfspace.GetConstant(), distance - sphere.GetRadius(), distance + sphere.GetRadius(), this->GetTMax() };

    auto contactTime = testIntersectorAxis.GetTFirst();

    if (testIntersectorAxis.GetResult())
    {
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SPHERE3_DETAIL_H