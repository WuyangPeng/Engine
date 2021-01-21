///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 10:15)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_ACHIEVE_H

#include "IntersectorUtility3.h"
#include "StaticFindIntersectorSegment3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::StaticFindIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, const Real epsilon)
    : ParentType{ epsilon }, m_Segment{ segment }, m_Triangle{ triangle }, m_SegmentParameter{}, m_TriBary0{}, m_TriBary1{}, m_TriBary2{ Math::GetValue(1) }, m_Quantity{}, m_Point0{}, m_Point1{}
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

    return m_Segment;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::Find()
{
    // 计算偏移原点，边和法线。
    auto diff = m_Segment.GetCenterPoint() - m_Triangle.GetVertex(0);
    auto edge1 = m_Triangle.GetVertex(1) - m_Triangle.GetVertex(0);
    auto edge2 = m_Triangle.GetVertex(2) - m_Triangle.GetVertex(0);
    const auto normal = Vector3DTools::CrossProduct(edge1, edge2);

    // 求解 Q + t*D = b1*E1 + b2*E2 (Q = diff, D = 线段方向,
    // E1 = edge1, E2 = edge2, N = Cross(E1,E2))
    //   |Dot(D,N)|*b1 = sign(Dot(D,N))*Dot(D,Cross(Q,E2))
    //   |Dot(D,N)|*b2 = sign(Dot(D,N))*Dot(D,Cross(E1,Q))
    //   |Dot(D,N)|*t = -sign(Dot(D,N))*Dot(Q,N)
    auto directionDotNormal = Vector3DTools::DotProduct(m_Segment.GetDirection(), normal);
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
        m_Quantity = 0;
        return;
    }

    auto value0 = sign * Vector3DTools::DotProduct(m_Segment.GetDirection(), Vector3DTools::CrossProduct(diff, edge2));
    if (Math::GetValue(0) <= value0)
    {
        Real value1 = sign * Vector3DTools::DotProduct(m_Segment.GetDirection(), Vector3DTools::CrossProduct(edge1, diff));
        if (Math::GetValue(0) <= value1)
        {
            if (value0 + value1 <= directionDotNormal)
            {
                // 线与三角形相交，检查线段是否相交。
                auto value2 = -sign * Vector3DTools::DotProduct(diff, normal);
                auto value3 = m_Segment.GetExtent() * directionDotNormal;
                if (-value3 <= value2 && value2 <= value3)
                {
                    // 线段与三角形相交。
                    auto inv = (Math::GetValue(1)) / directionDotNormal;
                    m_SegmentParameter = value2 * inv;
                    m_TriBary1 = value0 * inv;
                    m_TriBary2 = value1 * inv;
                    m_TriBary0 = Math::GetValue(1) - m_TriBary1 - m_TriBary2;

                    this->SetIntersectionType(IntersectionType::Point);
                    m_Quantity = 1;
                    m_Point0 = m_Segment.GetCenterPoint() + m_SegmentParameter * m_Segment.GetDirection();
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
    m_Quantity = 0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetSegmentParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_SegmentParameter;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetTriBary0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriBary0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetTriBary1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriBary1;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetTriBary2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriBary2;
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Triangle3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_ACHIEVE_H