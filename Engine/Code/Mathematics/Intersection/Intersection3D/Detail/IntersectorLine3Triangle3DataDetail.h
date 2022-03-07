///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/05 13:25)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_DETAIL_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_DETAIL_H

#include "IntersectorLine3Triangle3Data.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::IntersectorLine3Triangle3Data<Real>::IntersectorLine3Triangle3Data(const Line3& line, const Triangle3& triangle)
    : line{ line }, triangle{ triangle }, origin{}, edge1{}, edge2{}, normal{}, directionDotNormal{}
{
    CalculateDirectionDotNormal();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
void Mathematics::IntersectorLine3Triangle3Data<Real>::CalculateDirectionDotNormal()
{
    // 计算原点、边和法线的偏移量。
    origin = line.GetOrigin() - triangle.GetVertex(0);
    edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
    edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
    normal = Vector3Tools::CrossProduct(edge1, edge2);

    // 求解 Q + t * D = b1 * E1 + b2 * E2
    // (其中Q = m_OriginDifference, D = 线的Direction,
    // E1 = edge1, E2 = edge2, N = Cross(E1,E2)) 对
    //   |Dot(D,N)| * b1 = sign(Dot(D,N)) * Dot(D,Cross(Q,E2))
    //   |Dot(D,N)| * b2 = sign(Dot(D,N)) * Dot(D,Cross(E1,Q))
    //   |Dot(D,N)| * t = -sign(Dot(D,N)) * Dot(Q,N)
    directionDotNormal = Vector3Tools::DotProduct(line.GetDirection(), normal);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IntersectorLine3Triangle3Data<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::IntersectorLine3Triangle3Data<Real>::GetLine() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return line;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::IntersectorLine3Triangle3Data<Real>::GetTriangle() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangle;
}

template <typename Real>
Real Mathematics::IntersectorLine3Triangle3Data<Real>::GetDirectionDotNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return directionDotNormal;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::IntersectorLine3Triangle3Data<Real>::GetOriginCrossEdge2() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3Tools::CrossProduct(origin, edge2);
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::IntersectorLine3Triangle3Data<Real>::GetEdge1CrossOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3Tools::CrossProduct(edge1, origin);
}

template <typename Real>
Real Mathematics::IntersectorLine3Triangle3Data<Real>::GetOriginDotNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return Vector3Tools::DotProduct(origin, normal);
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_DETAIL_H