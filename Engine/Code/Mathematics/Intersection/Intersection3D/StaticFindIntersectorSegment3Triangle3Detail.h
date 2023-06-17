///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:28)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H

#include "IntersectorUtility3.h"
#include "StaticFindIntersectorSegment3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::StaticFindIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, const Real epsilon)
    : ParentType{ epsilon }, segment{ segment }, triangle{ triangle }, segmentParameter{}, triBary0{}, triBary1{}, triBary2{ Math::GetValue(1) }, quantity{}, point0{}, point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::Find()
{
    // 计算偏移原点，边和法线。
    auto diff = segment.GetCenterPoint() - triangle.GetVertex(0);
    auto edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
    auto edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
    const auto normal = Vector3Tools::CrossProduct(edge1, edge2);

    // 求解 Q + t*D = b1*E1 + b2*E2 (Q = diff, D = 线段方向,
    // E1 = edge1, E2 = edge2, N = Cross(E1,E2))
    //   |Dot(D,N)|*b1 = sign(Dot(D,N))*Dot(D,Cross(Q,E2))
    //   |Dot(D,N)|*b2 = sign(Dot(D,N))*Dot(D,Cross(E1,Q))
    //   |Dot(D,N)|*t = -sign(Dot(D,N))*Dot(Q,N)
    auto directionDotNormal = Vector3Tools::DotProduct(segment.GetDirection(), normal);
    auto sign = Math::GetValue(0);
    if (Math::GetZeroTolerance() < directionDotNormal)
    {
        sign = Math::GetValue(1);
    }
    else if (directionDotNormal < -Math::GetZeroTolerance())
    {
        sign = Math::GetValue(-1);
        directionDotNormal = -directionDotNormal;
    }
    else
    {
        // 线段和三角形是平行的，即使线段相交也称其为“无交集”。
        this->SetIntersectionType(IntersectionType::Empty);
        quantity = 0;
        return;
    }

    auto value0 = sign * Vector3Tools::DotProduct(segment.GetDirection(), Vector3Tools::CrossProduct(diff, edge2));
    if (Math::GetValue(0) <= value0)
    {
        Real value1 = sign * Vector3Tools::DotProduct(segment.GetDirection(), Vector3Tools::CrossProduct(edge1, diff));
        if (Math::GetValue(0) <= value1)
        {
            if (value0 + value1 <= directionDotNormal)
            {
                // 线与三角形相交，检查线段是否相交。
                auto value2 = -sign * Vector3Tools::DotProduct(diff, normal);
                auto value3 = segment.GetExtent() * directionDotNormal;
                if (-value3 <= value2 && value2 <= value3)
                {
                    // 线段与三角形相交。
                    auto inv = (Math::GetValue(1)) / directionDotNormal;
                    segmentParameter = value2 * inv;
                    triBary1 = value0 * inv;
                    triBary2 = value1 * inv;
                    triBary0 = Math::GetValue(1) - triBary1 - triBary2;

                    this->SetIntersectionType(IntersectionType::Point);
                    quantity = 1;
                    point0 = segment.GetCenterPoint() + segmentParameter * segment.GetDirection();
                    return;
                }
                // else: |t| > extent, 没有交集
            }
            // else: b1+b2 > 1, 没有交集
        }
        // else: b2 < 0, 没有交集
    }
    // else: b1 < 0, 没有交集

    this->SetIntersectionType(IntersectionType::Empty);
    quantity = 0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetSegmentParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segmentParameter;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetTriBary0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triBary0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetTriBary1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triBary1;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetTriBary2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triBary2;
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
const Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_DETAIL_H