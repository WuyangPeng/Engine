///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/11 14:23)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_ACHIEVE_H

#include "DistanceLine3Rectangle3.h"
#include "DistanceLine3Segment3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistanceLine3Rectangle3<Real>::DistanceLine3Rectangle3(const Line3& line, const Rectangle3& rectangle) noexcept
    : ParentType{}, m_Line{ line }, m_Rectangle{ rectangle }, m_RectCoord{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine3Rectangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line3<Real> Mathematics::DistanceLine3Rectangle3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Rectangle3<Real> Mathematics::DistanceLine3Rectangle3<Real>::GetRectangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Rectangle;
}

template <typename Real>
typename const Mathematics::DistanceLine3Rectangle3<Real>::DistanceResult Mathematics::DistanceLine3Rectangle3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    // �������Ƿ�������ཻ�� �������������ƽ������Ϊ�㡣
    const auto crossProduct = Vector3DTools::CrossProduct(m_Rectangle.GetAxis0(), m_Rectangle.GetAxis1());
    auto dot = Vector3DTools::DotProduct(crossProduct, m_Line.GetDirection());
    if (Math::GetZeroTolerance() < Math::FAbs(dot))
    {
        // �ߺ;��β�ƽ�У����������ε�ƽ���ཻ��
        auto diff = m_Line.GetOrigin() - m_Rectangle.GetCenter();

        const auto vector3DOrthonormalBasis = Vector3DTools::GenerateComplementBasis(m_Line.GetDirection());
        const auto uVector = vector3DOrthonormalBasis.GetUVector();
        const auto vVector = vector3DOrthonormalBasis.GetVVector();
        auto uVectorDotAxis0 = Vector3DTools::DotProduct(uVector, m_Rectangle.GetAxis0());
        auto uVectorDotAxis1 = Vector3DTools::DotProduct(uVector, m_Rectangle.GetAxis1());
        auto uVectorDotDiff = Vector3DTools::DotProduct(uVector, diff);
        auto vVectorDotAxis0 = Vector3DTools::DotProduct(vVector, m_Rectangle.GetAxis0());
        auto vVectorDotAxis1 = Vector3DTools::DotProduct(vVector, m_Rectangle.GetAxis1());
        auto vVectorDotDiff = Vector3DTools::DotProduct(vVector, diff);
        auto invDet = (Math::GetValue(1)) / (uVectorDotAxis0 * vVectorDotAxis1 - uVectorDotAxis1 * vVectorDotAxis0);

        // �ཻ��ľ������ꡣ
        auto s0 = (vVectorDotAxis1 * uVectorDotDiff - uVectorDotAxis1 * vVectorDotDiff) * invDet;
        auto s1 = (uVectorDotAxis0 * vVectorDotDiff - vVectorDotAxis0 * uVectorDotDiff) * invDet;

        if (Math::FAbs(s0) <= m_Rectangle.GetExtent0() && Math::FAbs(s1) <= m_Rectangle.GetExtent1())
        {
            // �ཻ����߲�����
            auto directionDotAxis0 = Vector3DTools::DotProduct(m_Line.GetDirection(), m_Rectangle.GetAxis0());
            auto directionDotAxis1 = Vector3DTools::DotProduct(m_Line.GetDirection(), m_Rectangle.GetAxis1());
            auto directionDotDiff = Vector3DTools::DotProduct(m_Line.GetDirection(), diff);
            auto lineParameter = s0 * directionDotAxis0 + s1 * directionDotAxis1 - directionDotDiff;

            // �ཻ��ľ������ꡣ
            m_RectCoord[0] = s0;
            m_RectCoord[1] = s1;

            // �ཻ���ھ��ε��ڲ����Ϸ���
            auto closestPoint0 = m_Line.GetOrigin() + lineParameter * m_Line.GetDirection();

            auto closestPoint1 = m_Rectangle.GetCenter() + s0 * m_Rectangle.GetAxis0() + s1 * m_Rectangle.GetAxis1();

            return DistanceResult{ Math::GetValue(0), Math::GetValue(0), closestPoint0, closestPoint1, lineParameter, Math::GetValue(0) };
        }
    }

    Vector3D closestPoint0{};
    Vector3D closestPoint1{};
    auto lineParameter = Math::Math::GetValue(0);

    /// ��1���߲������ƽ�У����ߺ;���ƽ��Ľ����ھ����ⲿ�����ߣ�2���ߺ;���ƽ�С�
    /// ������Σ������ϵ���ӽ����ھ��εı�Ե�ϡ� ��������ε������ĸ���Ե���бȽϡ�

    auto sqrDist = Math::sm_MaxReal;
    constexpr auto size = 2;
    std::array<Vector3D, size> scaledDir{ m_Rectangle.GetExtent0() * m_Rectangle.GetAxis0(), m_Rectangle.GetExtent1() * m_Rectangle.GetAxis1() };

    for (auto outerIndex = 0; outerIndex < size; ++outerIndex)
    {
        for (auto innerIndex = 0; innerIndex < size; ++innerIndex)
        {
            auto extent = m_Rectangle.GetExtent(1 - outerIndex);
            const auto index = 2 * innerIndex - 1;
            auto center = m_Rectangle.GetCenter() + static_cast<Real>(index) * scaledDir.at(outerIndex);
            const auto direction = m_Rectangle.GetAxis(1 - outerIndex);
            const Segment3<Real> segment{ extent, center, direction };

            DistanceLine3Segment3<Real> distanceLine3Segment3{ m_Line, segment };
            auto squaredDistance = distanceLine3Segment3.GetSquared();
            if (squaredDistance.GetDistance() < sqrDist)
            {
                closestPoint0 = squaredDistance.GetLhsClosestPoint();
                closestPoint1 = squaredDistance.GetRhsClosestPoint();
                sqrDist = squaredDistance.GetDistance();

                lineParameter = squaredDistance.GetLhsParameter();
                auto ratio = squaredDistance.GetRhsParameter() / segment.GetExtent();
                const auto extentIndex0 = (1 - outerIndex) * (2 * innerIndex - 1);
                const auto extentIndex1 = (1 - innerIndex) * (2 * outerIndex - 1);
                m_RectCoord[0] = m_Rectangle.GetExtent0() * (extentIndex0 + outerIndex * ratio);
                m_RectCoord[1] = m_Rectangle.GetExtent1() * (extentIndex1 + innerIndex * ratio);
            }
        }
    }

    return DistanceResult{ sqrDist, Math::GetValue(0), closestPoint0, closestPoint1, lineParameter, Math::GetValue(0) };
}

template <typename Real>
typename const Mathematics::DistanceLine3Rectangle3<Real>::DistanceResult Mathematics::DistanceLine3Rectangle3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLine = m_Line.GetMove(t, lhsVelocity);
    const auto movedRectangle = m_Rectangle.GetMove(t, rhsVelocity);

    ClassType distance{ movedLine, movedRectangle };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

template <typename Real>
Real Mathematics::DistanceLine3Rectangle3<Real>::GetRectangleCoordinate(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RectCoord[index];
}

#endif  // MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_ACHIEVE_H