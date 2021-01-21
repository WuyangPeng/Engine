///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/14 14:42)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_ACHIEVE_H

#include "DynamicTestIntersectorHalfspace3Triangle3.h"
#include "Detail/TestIntersectorAxisImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorHalfspace3Triangle3<Real>::DynamicTestIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Halfspace{ halfspace }, m_Triangle{ triangle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicTestIntersectorHalfspace3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorHalfspace3Triangle3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Halfspace;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorHalfspace3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorHalfspace3Triangle3<Real>::Test()
{
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    const auto projection = TestIntersectorAxisImpl<Real>::GetProjection(m_Halfspace.GetNormal(), m_Triangle);

    const TestIntersectorAxisImpl<Real> testIntersectorAxis{ m_Halfspace.GetNormal(), relVelocity, -Math::sm_MaxReal, m_Halfspace.GetConstant(), projection.first, projection.second, this->GetTMax() };

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

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_TRIANGLE3_ACHIEVE_H