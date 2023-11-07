///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:17)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H

#include "DynamicTestIntersectorSegment3Box3.h"
#include "TestIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Box3<Real>::DynamicTestIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid, Real tMax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon }, segment{ segment }, box{ box }, solid{ solid }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicTestIntersectorSegment3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Box3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::DynamicTestIntersectorSegment3Box3<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Box3<Real>::Test()
{
    // 获取线段的端点。
    using SegmentType = std::array<Vector3, 2>;
    const SegmentType segmentType{ segment.GetBeginPoint(), segment.GetEndPoint() };

    // 获取相对于线段的框速度。
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    auto contactTime = Math::GetValue(0);

    // 测试盒法线。
    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = box.GetAxis(i);
        const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segmentType, box, relVelocity, this->GetTMax() };
        contactTime = testIntersectorAxis.GetTFirst();

        if (!testIntersectorAxis.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // 测试线段方向的交叉盒边缘。
    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = Vector3Tools::CrossProduct(box.GetAxis(i), segment.GetDirection());

        const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segmentType, box, relVelocity, this->GetTMax() };
        contactTime = testIntersectorAxis.GetTFirst();

        if (!testIntersectorAxis.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // 测试速度穿越盒——面。
    for (auto i = 0; i < 3; i++)
    {
        const auto axis = Vector3Tools::CrossProduct(relVelocity, box.GetAxis(i));
        const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segmentType, box, relVelocity, this->GetTMax() };
        contactTime = testIntersectorAxis.GetTFirst();

        if (!testIntersectorAxis.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Point);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_DETAIL_H