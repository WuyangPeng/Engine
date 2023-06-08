///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 18:05)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_DETAIL_H

#include "DistanceLine3Segment3.h"
#include "DistanceLine3Triangle3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceLine3Triangle3<Real>::DistanceLine3Triangle3(const Line3& line, const Triangle3& triangle) noexcept
    : ParentType{}, line{ line }, triangle{ triangle }, triangleBary{}
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
Mathematics::Line3<Real> Mathematics::DistanceLine3Triangle3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Triangle3<Real> Mathematics::DistanceLine3Triangle3<Real>::GetTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return triangle;
}

template <typename Real>
typename Mathematics::DistanceLine3Triangle3<Real>::DistanceResult Mathematics::DistanceLine3Triangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // �������Ƿ����������ཻ�� �������������ƽ������Ϊ�㡣
    const auto edge0 = triangle.GetVertex(1) - triangle.GetVertex(0);
    const auto edge1 = triangle.GetVertex(2) - triangle.GetVertex(0);
    const auto normal = Vector3Tools::UnitCrossProduct(edge0, edge1);
    const auto normalDotDirection = Vector3Tools::DotProduct(normal, line.GetDirection());
    if (Math::GetZeroTolerance() < Math::FAbs(normalDotDirection))
    {
        // ֱ�ߺ������β�ƽ�У����ֱ���������ε�ƽ���ཻ��
        auto diff = line.GetOrigin() - triangle.GetVertex(0);

        const auto Vector3OrthonormalBasis = Vector3Tools::GenerateComplementBasis(line.GetDirection());
        const auto uVector = Vector3OrthonormalBasis.GetUVector();
        const auto vVector = Vector3OrthonormalBasis.GetVVector();

        auto uVectorDotEdge0 = Vector3Tools::DotProduct(uVector, edge0);
        auto uVectorDotEdge1 = Vector3Tools::DotProduct(uVector, edge1);
        auto uVectorDotDiff = Vector3Tools::DotProduct(uVector, diff);
        auto vVectorDotEdge0 = Vector3Tools::DotProduct(vVector, edge0);
        auto vVectorDotEdge1 = Vector3Tools::DotProduct(vVector, edge1);
        auto vVectorDotDiff = Vector3Tools::DotProduct(vVector, diff);
        auto invDet = (Math::GetValue(1)) / (uVectorDotEdge0 * vVectorDotEdge1 - uVectorDotEdge1 * vVectorDotEdge0);

        // �ཻ����������ꡣ
        auto b1 = (vVectorDotEdge1 * uVectorDotDiff - uVectorDotEdge1 * vVectorDotDiff) * invDet;
        auto b2 = (uVectorDotEdge0 * vVectorDotDiff - vVectorDotEdge0 * uVectorDotDiff) * invDet;
        auto b0 = Math::GetValue(1) - b1 - b2;

        if (Math::GetValue(0) <= b0 && Math::GetValue(0) <= b1 && Math::GetValue(0) <= b2)
        {
            // �ཻ����߲�����
            auto directionDotEdge0 = Vector3Tools::DotProduct(line.GetDirection(), edge0);
            auto directionDotEdge1 = Vector3Tools::DotProduct(line.GetDirection(), edge1);
            auto directionDotDiff = Vector3Tools::DotProduct(line.GetDirection(), diff);
            auto lineParameter = b1 * directionDotEdge0 + b2 * directionDotEdge1 - directionDotDiff;

            // �ཻ����������ꡣ
            triangleBary[0] = b0;
            triangleBary[1] = b1;
            triangleBary[2] = b2;

            // �ཻ���������ε��ڲ����Ϸ���
            const auto closestPoint0 = line.GetOrigin() + lineParameter * line.GetDirection();

            const auto closestPoint1 = triangle.GetVertex(0) + b1 * edge0 + b2 * edge1;

            return DistanceResult{ Math::GetValue(0), Math::GetValue(0), closestPoint0, closestPoint1, lineParameter, Math::GetValue(0) };
        }
    }

    Vector3 closestPoint0{};
    Vector3 closestPoint1{};
    auto lineParameter = Math::GetValue(0);

    /// ��1���߲�ƽ���������Σ������ߺ������ε�ƽ��Ľ�����������֮�⣬���ߣ�2���ߺ�������ƽ�С�
    /// ������Σ��������ϵ���ӽ����������εı�Ե�ϡ� �����������ε�����������Ե���бȽϡ�
    auto sqrDist = Math::maxReal;
    constexpr auto size = 3;
    for (auto i0 = 2, i1 = 0; i1 < size; i0 = i1++)
    {
        auto center = (Math::GetRational(1, 2)) * (triangle.GetVertex(i0) + triangle.GetVertex(i1));
        auto direction = triangle.GetVertex(i1) - triangle.GetVertex(i0);

        auto extent = (Math::GetRational(1, 2)) * Vector3Tools::GetLength(direction);
        const Segment3<Real> segment{ extent, center, direction };

        DistanceLine3Segment3<Real> distanceLine3Segment3{ line, segment };
        auto squared = distanceLine3Segment3.GetSquared();
        if (squared.GetDistance() < sqrDist)
        {
            closestPoint0 = squared.GetLhsClosestPoint();
            closestPoint1 = squared.GetRhsClosestPoint();
            sqrDist = squared.GetDistance();

            lineParameter = squared.GetLhsParameter();
            auto ratio = squared.GetRhsParameter() / segment.GetExtent();
            triangleBary[i0] = (Math::GetRational(1, 2)) * (Math::GetValue(1) - ratio);
            triangleBary[i1] = Math::GetValue(1) - triangleBary[i0];
            triangleBary[size - i0 - i1] = Math::GetValue(0);
        }
    }

    return DistanceResult{ sqrDist, Math::GetValue(0), closestPoint0, closestPoint1, lineParameter, Math::GetValue(0) };
}

template <typename Real>
typename Mathematics::DistanceLine3Triangle3<Real>::DistanceResult Mathematics::DistanceLine3Triangle3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLine = line.GetMove(t, lhsVelocity);
    const auto movedTriangle = triangle.GetMove(t, rhsVelocity);

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

    return triangleBary[index];
}

#endif  // MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_DETAIL_H