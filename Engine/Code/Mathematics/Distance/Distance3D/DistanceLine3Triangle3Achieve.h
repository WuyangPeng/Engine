///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/11 16:31)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_ACHIEVE_H

#include "DistanceLine3Segment3.h"
#include "DistanceLine3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceLine3Triangle3<Real>::DistanceLine3Triangle3(const Line3& line, const Triangle3& triangle) noexcept
    : ParentType{}, m_Line{ line }, m_Triangle{ triangle }, m_TriangleBary{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line3<Real> Mathematics::DistanceLine3Triangle3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::DistanceLine3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Triangle;
}

template <typename Real>
typename const Mathematics::DistanceLine3Triangle3<Real>::DistanceResult Mathematics::DistanceLine3Triangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // 测试线是否与三角形相交。 如果是这样，则平方距离为零。
    auto edge0 = m_Triangle.GetVertex(1) - m_Triangle.GetVertex(0);
    auto edge1 = m_Triangle.GetVertex(2) - m_Triangle.GetVertex(0);
    const auto normal = Vector3DTools::UnitCrossProduct(edge0, edge1);
    auto normalDotDirection = Vector3DTools::DotProduct(normal, m_Line.GetDirection());
    if (Math::GetZeroTolerance() < Math::FAbs(normalDotDirection))
    {
        // 直线和三角形不平行，因此直线与三角形的平面相交。
        auto diff = m_Line.GetOrigin() - m_Triangle.GetVertex(0);

        const auto vector3DOrthonormalBasis = Vector3DTools::GenerateComplementBasis(m_Line.GetDirection());
        const auto uVector = vector3DOrthonormalBasis.GetUVector();
        const auto vVector = vector3DOrthonormalBasis.GetVVector();

        auto uVectorDotEdge0 = Vector3DTools::DotProduct(uVector, edge0);
        auto uVectorDotEdge1 = Vector3DTools::DotProduct(uVector, edge1);
        auto uVectorDotDiff = Vector3DTools::DotProduct(uVector, diff);
        auto vVectorDotEdge0 = Vector3DTools::DotProduct(vVector, edge0);
        auto vVectorDotEdge1 = Vector3DTools::DotProduct(vVector, edge1);
        auto vVectorDotDiff = Vector3DTools::DotProduct(vVector, diff);
        auto invDet = (Math::GetValue(1)) / (uVectorDotEdge0 * vVectorDotEdge1 - uVectorDotEdge1 * vVectorDotEdge0);

        // 相交点的重心坐标。
        auto b1 = (vVectorDotEdge1 * uVectorDotDiff - uVectorDotEdge1 * vVectorDotDiff) * invDet;
        auto b2 = (uVectorDotEdge0 * vVectorDotDiff - vVectorDotEdge0 * uVectorDotDiff) * invDet;
        auto b0 = Math::GetValue(1) - b1 - b2;

        if (b0 >= Math::GetValue(0) && b1 >= Math::GetValue(0) && b2 >= Math::GetValue(0))
        {
            // 相交点的线参数。
            auto directionDotEdge0 = Vector3DTools::DotProduct(m_Line.GetDirection(), edge0);
            auto directionDotEdge1 = Vector3DTools::DotProduct(m_Line.GetDirection(), edge1);
            auto directionDotDiff = Vector3DTools::DotProduct(m_Line.GetDirection(), diff);
            auto lineParameter = b1 * directionDotEdge0 + b2 * directionDotEdge1 - directionDotDiff;

            // 相交点的重心坐标。
            m_TriangleBary[0] = b0;
            m_TriangleBary[1] = b1;
            m_TriangleBary[2] = b2;

            // 相交点在三角形的内部或上方。
            const auto closestPoint0 = m_Line.GetOrigin() + lineParameter * m_Line.GetDirection();

            const auto closestPoint1 = m_Triangle.GetVertex(0) + b1 * edge0 + b2 * edge1;

            return DistanceResult{ Math::GetValue(0), Math::GetValue(0), closestPoint0, closestPoint1, lineParameter, Math::GetValue(0) };
        }
    }

    Vector3D closestPoint0{};
    Vector3D closestPoint1{};
    auto lineParameter = Math::GetValue(0);

    /// （1）线不平行于三角形，并且线和三角形的平面的交点在三角形之外，或者（2）线和三角形平行。
    /// 无论如何，三角形上的最接近点在三角形的边缘上。 将线与三角形的所有三个边缘进行比较。
    auto sqrDist = Math::sm_MaxReal;
    constexpr auto size = 3;
    for (auto i0 = 2, i1 = 0; i1 < size; i0 = i1++)
    {
        auto center = (Math::GetRational(1, 2)) * (m_Triangle.GetVertex(i0) + m_Triangle.GetVertex(i1));
        auto direction = m_Triangle.GetVertex(i1) - m_Triangle.GetVertex(i0);

        auto extent = (Math::GetRational(1, 2)) * Vector3DTools::VectorMagnitude(direction);
        const Segment3<Real> segment{ extent, center, direction };

        DistanceLine3Segment3<Real> distanceLine3Segment3{ m_Line, segment };
        auto squared = distanceLine3Segment3.GetSquared();
        if (squared.GetDistance() < sqrDist)
        {
            closestPoint0 = squared.GetLhsClosestPoint();
            closestPoint1 = squared.GetRhsClosestPoint();
            sqrDist = squared.GetDistance();

            lineParameter = squared.GetLhsParameter();
            auto ratio = squared.GetRhsParameter() / segment.GetExtent();
            m_TriangleBary[i0] = (Math::GetRational(1, 2)) * (Math::GetValue(1) - ratio);
            m_TriangleBary[i1] = Math::GetValue(1) - m_TriangleBary[i0];
            m_TriangleBary[size - i0 - i1] = Math::GetValue(0);
        }
    }

    return DistanceResult{ sqrDist, Math::GetValue(0), closestPoint0, closestPoint1, lineParameter, Math::GetValue(0) };
}

template <typename Real>
typename const Mathematics::DistanceLine3Triangle3<Real>::DistanceResult Mathematics::DistanceLine3Triangle3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLine = m_Line.GetMove(t, lhsVelocity);
    const auto movedTriangle = m_Triangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedLine, movedTriangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistanceLine3Triangle3<Real>::GetTriangleBary(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_TriangleBary[index];
}

#endif  // MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_ACHIEVE_H