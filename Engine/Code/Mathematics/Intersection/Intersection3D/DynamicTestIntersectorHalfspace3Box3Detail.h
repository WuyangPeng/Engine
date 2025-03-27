///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:16)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H

#include "DynamicTestIntersectorHalfspace3Box3.h"
#include "TestIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorHalfspace3Box3<Real>::DynamicTestIntersectorHalfspace3Box3(const Plane3& halfspace, const Box3& box, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, halfspace{ halfspace }, box{ box }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicTestIntersectorHalfspace3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorHalfspace3Box3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return halfspace;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorHalfspace3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorHalfspace3Box3<Real>::Test()
{
    this->SetContactTime(MathType::GetValue(0));

    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();
    const auto projection = TestIntersectorAxis<Real>::GetProjection(halfspace.GetNormal(), box);

    const TestIntersectorAxis<Real> testIntersectorAxis{ halfspace.GetNormal(), relVelocity, -MathType::maxReal, halfspace.GetConstant(), projection.first, projection.second, this->GetTMax() };

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

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_DETAIL_H