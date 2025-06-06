///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:29)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorSegment3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment3Triangle3<Real>::StaticTestIntersectorSegment3Triangle3(const Segment3Type& segment, const Triangle3Type& triangle, const Real epsilon)
    : ParentType{ epsilon }, segment{ segment }, triangle{ triangle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorSegment3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment3<Real> Mathematics::StaticTestIntersectorSegment3Triangle3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return segment;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::StaticTestIntersectorSegment3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangle;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment3Triangle3<Real>::Test()
{
    const auto diff = segment.GetCenterPoint() - triangle.GetVertex(0);
    const auto edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
    const auto edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
    const auto normal = Vector3ToolsType::CrossProduct(edge1, edge2);

    auto ddn = Vector3ToolsType::DotProduct(segment.GetDirection(), normal);
    Real sign{};
    if (ddn > MathType::GetZeroTolerance())
    {
        sign = MathType::GetValue(1);
    }
    else if (ddn < -MathType::GetZeroTolerance())
    {
        sign = MathType::GetValue(-1);
        ddn = -ddn;
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);

        return;
    }

    auto ddqxe2 = sign * Vector3ToolsType::DotProduct(segment.GetDirection(), Vector3ToolsType::CrossProduct(diff, edge2));
    if (MathType::GetValue(0) <= ddqxe2)
    {
        auto dde1xq = sign * Vector3ToolsType::DotProduct(segment.GetDirection(), Vector3ToolsType::CrossProduct(edge1, diff));
        if (MathType::GetValue(0) <= dde1xq)
        {
            if (ddqxe2 + dde1xq <= ddn)
            {
                auto qdn = -sign * Vector3ToolsType::DotProduct(diff, normal);
                auto extDdN = segment.GetExtent() * ddn;
                if (-extDdN <= qdn && qdn <= extDdN)
                {
                    this->SetIntersectionType(IntersectionType::Point);

                    return;
                }
            }
        }
    }

    this->SetIntersectionType(IntersectionType::Empty);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H