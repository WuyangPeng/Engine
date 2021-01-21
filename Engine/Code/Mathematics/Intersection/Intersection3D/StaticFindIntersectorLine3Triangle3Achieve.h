///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 14:09)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TRIANGLE3_ACHIEVE_H

#include "StaticFindIntersectorLine3Triangle3.h"
#include "Detail/IntersectorLine3Triangle3DataDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Triangle3<Real>::StaticFindIntersectorLine3Triangle3(const Line3& line, const Triangle3& triangle, const Real epsilon)
    : ParentType{ epsilon }, m_Line{ line }, m_Triangle{ triangle }, m_LineParameter{}, m_TriangleBary0{}, m_TriangleBary1{}, m_TriangleBary2{ Math::GetValue(1) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Triangle3<Real>::IsValid() const noexcept
{
    try
    {
        if (ParentType::IsValid() && Math::Approximate(m_TriangleBary0 + m_TriangleBary1 + m_TriangleBary2, Math::GetValue(1)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorLine3Triangle3<Real>::Find()
{
    const IntersectorLine3Triangle3Data<Real> data{ m_Line, m_Triangle };

    auto directionDotNormal = data.GetDirectionDotNormal();
    auto epsilon = this->GetEpsilon();
    auto sign = NumericalValueSymbol::Zero;

    if (epsilon < directionDotNormal)
    {
        sign = NumericalValueSymbol::Positive;
    }
    else if (directionDotNormal < epsilon)
    {
        sign = NumericalValueSymbol::Negative;
        directionDotNormal = -directionDotNormal;
    }
    else
    {
        // 线和三角形是平行的,称之为“没有交集”。
        // 即使线是相交。
        return;
    }

    auto directionDotOriginCrossEdge2 = sign * Vector3DTools::DotProduct(m_Line.GetDirection(), data.GetOriginCrossEdge2());
    if (Math::GetValue(0) <= directionDotOriginCrossEdge2)
    {
        auto directionDotEdge1CrossOrigin = sign * Vector3DTools::DotProduct(m_Line.GetDirection(), data.GetEdge1CrossOrigin());

        if (Math::GetValue(0) <= directionDotEdge1CrossOrigin)
        {
            if (directionDotOriginCrossEdge2 + directionDotEdge1CrossOrigin <= directionDotNormal)
            {
                // 线和三角形相交
                auto originDotNormal = -sign * data.GetOriginDotNormal();

                m_LineParameter = originDotNormal / directionDotNormal;
                m_TriangleBary1 = directionDotOriginCrossEdge2 / directionDotNormal;
                m_TriangleBary2 = directionDotEdge1CrossOrigin / directionDotNormal;
                m_TriangleBary0 = Math::GetValue(1) - m_TriangleBary1 - m_TriangleBary2;

                this->SetIntersectionType(IntersectionType::Point);
            }
            // else: 1 < b1 + b2, 不相交
        }
        // else: b2 < 0, 不相交
    }
    // else: b1 < 0, 不相交
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetLineParameter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LineParameter;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetTriangleBary0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary0;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetTriangleBary1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary1;
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Triangle3<Real>::GetTriangleBary2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary2;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TRIANGLE3_ACHIEVE_H