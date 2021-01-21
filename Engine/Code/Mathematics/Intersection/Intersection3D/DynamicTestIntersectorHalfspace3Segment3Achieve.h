///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/13 13:54)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H

#include "DynamicTestIntersectorHalfspace3Segment3.h"
#include "Detail/TestIntersectorAxisImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>::DynamicTestIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Halfspace{ halfspace }, m_Segment{ segment }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Plane3<Real> Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>::GetHalfspace() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Halfspace;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorHalfspace3Segment3<Real>::Test()
{
    this->SetContactTime(Math::GetValue(0));
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    using SegmentType = std::array<Vector3D, 2>;
    SegmentType segment{ m_Segment.GetBeginPoint(), m_Segment.GetEndPoint() };

    const auto projection = TestIntersectorAxisImpl<Real>::GetProjection(m_Halfspace.GetNormal(), segment);

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

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_ACHIEVE_H