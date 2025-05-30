///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:17)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H

#include "DynamicTestIntersectorSegment3Triangle3.h"
#include "TestIntersectorAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::DynamicTestIntersectorSegment3Triangle3(const Segment3Type& segment, const Triangle3Type& triangle, Real tMax, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity, const Real epsilon)
    : ParentType{ tMax, lhsVelocity, rhsVelocity, epsilon }, segment{ segment }, triangle{ triangle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::DynamicTestIntersectorSegment3Triangle3<Real>::Test()
{
    // 获取该段的终点。
    using SegmentType = std::array<Vector3Type, 2>;
    SegmentType segmentType{ segment.GetBeginPoint(), segment.GetEndPoint() };

    // 获取三角形的边缘。
    auto edge0 = triangle.GetVertex(1) - triangle.GetVertex(0);
    auto edge1 = triangle.GetVertex(2) - triangle.GetVertex(0);

    // 获取相对于线段的三角形速度
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    // 测试三角形法线.
    const auto edgeNormal = Vector3ToolsType::CrossProduct(edge0, edge1);
    const TestIntersectorAxis<Real> intersector{ edgeNormal, segmentType, triangle, relVelocity, this->GetTMax() };
    auto contactTime = intersector.GetTFirst();

    if (!intersector.GetResult())
    {
        this->SetContactTime(contactTime);
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 测试线段是否平行于三角形，有效地测试： sin(Angle(NormV,DirU)) > 1 - epsilon
    auto directionU = segmentType.at(1) - segmentType.at(0);

    const auto normalU = Vector3ToolsType::CrossProduct(edgeNormal, directionU);
    auto directionUSqrLen = Vector3ToolsType::GetLengthSquared(directionU);
    auto normalUSqrLen = Vector3ToolsType::GetLengthSquared(normalU);
    auto edgeNormalSqrLen = Vector3ToolsType::GetLengthSquared(edgeNormal);
    auto oneMinusEpsilon = MathType::GetValue(1) - MathType::GetZeroTolerance();

    // 平行
    if (oneMinusEpsilon * edgeNormalSqrLen * directionUSqrLen < normalUSqrLen)
    {
        // 测试三角形法线横截线段方向。
        const TestIntersectorAxis<Real> normalUIntersector{ normalU, segmentType, triangle, relVelocity, this->GetTMax() };
        contactTime = normalUIntersector.GetTFirst();

        if (!normalUIntersector.GetResult())
        {
            this->SetContactTime(contactTime);
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }

        //  测试三角形法线横截线段边。
        for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
        {
            const auto axis = Vector3ToolsType::CrossProduct(edgeNormal, (triangle.GetVertex(i1) - triangle.GetVertex(i0)));

            const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segmentType, triangle, relVelocity, this->GetTMax() };
            contactTime = testIntersectorAxis.GetTFirst();

            if (!testIntersectorAxis.GetResult())
            {
                this->SetContactTime(contactTime);
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
    }
    else  // 不平行
    {
        // 测试线段方向横截三角形边。
        for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
        {
            const auto axis = Vector3ToolsType::CrossProduct(directionU, (triangle.GetVertex(i1) - triangle.GetVertex(i0)));

            const TestIntersectorAxis<Real> testIntersectorAxis{ axis, segmentType, triangle, relVelocity, this->GetTMax() };
            contactTime = testIntersectorAxis.GetTFirst();

            if (!testIntersectorAxis.GetResult())
            {
                this->SetContactTime(contactTime);
                this->SetIntersectionType(IntersectionType::Empty);
                return;
            }
        }
    }

    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Point);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H