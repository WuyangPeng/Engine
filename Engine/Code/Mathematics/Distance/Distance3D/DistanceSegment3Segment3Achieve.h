///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/10 13:02)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_SEGMENT3_ACHIEVE_H

#include "DistanceSegment3Segment3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"

template <typename Real>
Mathematics::DistanceSegment3Segment3<Real>::DistanceSegment3Segment3(const Segment3& lhsSegment, const Segment3& rhsSegment) noexcept
    : ParentType{}, m_LhsSegment{ lhsSegment }, m_RhsSegment{ rhsSegment }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceSegment3Segment3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DistanceSegment3Segment3<Real>::GetLhsSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsSegment;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DistanceSegment3Segment3<Real>::GetRhsSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsSegment;
}

template <typename Real>
const typename Mathematics::DistanceSegment3Segment3<Real>::DistanceResult Mathematics::DistanceSegment3Segment3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine3Line3Tool tool{ m_LhsSegment.GetCenterPoint(), m_LhsSegment.GetDirection(), m_RhsSegment.GetCenterPoint(), m_RhsSegment.GetDirection() };

    auto det = tool.GetDet();
    auto lhsExtent = m_LhsSegment.GetExtent();
    auto rhsExtent = m_RhsSegment.GetExtent();

    if (this->GetZeroThreshold() <= det)
    {
        // �߶β�ƽ�С�
        auto lhsT = tool.GetLhsT();
        auto rhsT = tool.GetRhsT();

        auto lhsExtentMultiplyDet = lhsExtent * det;
        auto rhsExtentMultiplyDet = rhsExtent * det;

        if (-lhsExtentMultiplyDet <= lhsT)
        {
            if (lhsT <= lhsExtentMultiplyDet)
            {
                if (-rhsExtentMultiplyDet <= rhsT)
                {
                    if (rhsT <= rhsExtentMultiplyDet)
                    {
                        // ����0���ڲ���
                        // ��СֵΪ�����߶��ڲ��㡣
                        lhsT /= det;
                        rhsT /= det;

                        auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotLhsDirection()) +
                                               rhsT * (tool.GetDirectionDot() * lhsT + rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                                               tool.GetOriginDifferenceSquaredLength();

                        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance), Math::GetValue(0), m_LhsSegment.GetCenterPoint() + lhsT * m_LhsSegment.GetDirection(),
                                               m_RhsSegment.GetCenterPoint() + rhsT * m_RhsSegment.GetDirection(), lhsT, rhsT };
                    }
                    else
                    {
                        // ����3���ߣ�
                        return GetSquaredWithClosestPointsIsLhsSide(tool, lhsExtent, rhsExtent);
                    }
                }
                else
                {
                    // ����7���ߣ�
                    return GetSquaredWithClosestPointsIsLhsSide(tool, lhsExtent, -rhsExtent);
                }
            }
            else
            {
                if (-rhsExtentMultiplyDet <= rhsT)
                {
                    if (rhsT <= rhsExtentMultiplyDet)
                    {
                        // ����1���ߣ�
                        return GetSquaredWithClosestPointsIsRhsSide(tool, lhsExtent, rhsExtent);
                    }
                    else
                    {
                        // ����2���ǣ�
                        return GetSquaredWithClosestPointsIsLhsCorner(tool, lhsExtent, rhsExtent);
                    }
                }
                else
                {
                    // ����8���ǣ�
                    return GetSquaredWithClosestPointsIsLhsCorner(tool, lhsExtent, -rhsExtent);
                }
            }
        }
        else
        {
            if (-rhsExtentMultiplyDet <= rhsT)
            {
                if (rhsT <= rhsExtentMultiplyDet)
                {
                    // ����5���ߣ�
                    return GetSquaredWithClosestPointsIsRhsSide(tool, -lhsExtent, rhsExtent);
                }
                else
                {
                    // ����4���ǣ�
                    return GetSquaredWithClosestPointsIsRhsCorner(tool, lhsExtent, rhsExtent);
                }
            }
            else
            {
                // ����6���ǣ�
                return GetSquaredWithClosestPointsIsRhsCorner(tool, lhsExtent, -rhsExtent);
            }
        }
    }
    else
    {
        // �߶���ƽ�еġ�
        // ƽ����originDifferenceDotLhsDirection�����Ϊȷ�������ĶԳ��ԡ�
        // Ҳ����˵��DistanceSegment2Segment2��seg0��seg1����DistanceSegment2Segment2��seg1��seg0��Ӧ�ò�����ͬ������
        auto extentSum = lhsExtent + rhsExtent;
        auto sign = (Math::GetValue(0) < tool.GetDirectionDot() ? Math::GetValue(-1) : Math::GetValue(1));
        auto originDifferenceDotLhsDirectionAverage = tool.GetOriginDifferenceDotDirectionAverage();
        auto lambda = -originDifferenceDotLhsDirectionAverage;
        if (lambda < -extentSum)
        {
            lambda = -extentSum;
        }
        else if (extentSum < lambda)
        {
            lambda = extentSum;
        }

        auto rhsT = (-sign * lambda * rhsExtent / extentSum);
        auto lhsT = lambda + sign * rhsT;

        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(lambda * (lambda + Math::GetValue(2) * originDifferenceDotLhsDirectionAverage) + tool.GetOriginDifferenceSquaredLength()),
                               Math::GetValue(0), m_LhsSegment.GetCenterPoint() + lhsT * m_LhsSegment.GetDirection(), m_RhsSegment.GetCenterPoint() + rhsT * m_RhsSegment.GetDirection(), lhsT, rhsT };
    }
}

// private
template <typename Real>
const typename Mathematics::DistanceSegment3Segment3<Real>::DistanceResult Mathematics::DistanceSegment3Segment3<Real>::GetSquaredWithClosestPointsIsLhsSide(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const
{
    auto t = tool.GetLhsT(-rhsExtent);
    auto rhsSquare = rhsExtent * (rhsExtent + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                     tool.GetOriginDifferenceSquaredLength();

    if (t < -lhsExtent)
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-lhsExtent * (-lhsExtent - Math::GetValue(2) * t) + rhsSquare),
                               Math::GetValue(0), m_LhsSegment.GetCenterPoint() - lhsExtent * m_LhsSegment.GetDirection(),
                               m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection(),
                               -lhsExtent, rhsExtent };
    }
    else if (t <= lhsExtent)
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               Math::GetValue(0), m_LhsSegment.GetCenterPoint() + t * m_LhsSegment.GetDirection(),
                               m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection(),
                               t, rhsExtent };
    }
    else
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(lhsExtent * (lhsExtent - Math::GetValue(2) * t) + rhsSquare),
                               Math::GetValue(0), m_LhsSegment.GetCenterPoint() + lhsExtent * m_LhsSegment.GetDirection(),
                               m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection(),
                               lhsExtent, rhsExtent };
    }
}

// private
template <typename Real>
const typename Mathematics::DistanceSegment3Segment3<Real>::DistanceResult Mathematics::DistanceSegment3Segment3<Real>::GetSquaredWithClosestPointsIsRhsSide(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const
{
    auto t = tool.GetRhsT(-lhsExtent);
    auto lhsSquare = lhsExtent * (lhsExtent + Math::GetValue(2) * tool.GetOriginDifferenceDotLhsDirection()) +
                     tool.GetOriginDifferenceSquaredLength();

    if (t < -rhsExtent)
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-rhsExtent * (-rhsExtent - Math::GetValue(2) * t) + lhsSquare),
                               Math::GetValue(0), m_LhsSegment.GetCenterPoint() + lhsExtent * m_LhsSegment.GetDirection(),
                               m_RhsSegment.GetCenterPoint() - rhsExtent * m_RhsSegment.GetDirection(),
                               lhsExtent, -rhsExtent };
    }
    else if (t <= rhsExtent)
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + lhsSquare),
                               Math::GetValue(0), m_LhsSegment.GetCenterPoint() + lhsExtent * m_LhsSegment.GetDirection(),
                               m_RhsSegment.GetCenterPoint() + t * m_RhsSegment.GetDirection(),
                               lhsExtent, t };
    }
    else
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(rhsExtent * (rhsExtent - Math::GetValue(2) * t) + lhsSquare),
                               Math::GetValue(0), m_LhsSegment.GetCenterPoint() + lhsExtent * m_LhsSegment.GetDirection(),
                               m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection(),
                               lhsExtent, rhsExtent };
    }
}

// private
template <typename Real>
const typename Mathematics::DistanceSegment3Segment3<Real>::DistanceResult Mathematics::DistanceSegment3Segment3<Real>::GetSquaredWithClosestPointsIsLhsCorner(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const
{
    auto t = tool.GetLhsT(-rhsExtent);
    auto rhsSquare = rhsExtent * (rhsExtent + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                     tool.GetOriginDifferenceSquaredLength();

    if (t < -lhsExtent)
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-lhsExtent * (-lhsExtent - Math::GetValue(2) * t) + rhsSquare),
                               Math::GetValue(0), m_LhsSegment.GetCenterPoint() - lhsExtent * m_LhsSegment.GetDirection(),
                               m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection(),
                               -lhsExtent, rhsExtent };
    }
    else if (t <= lhsExtent)
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               Math::GetValue(0), m_LhsSegment.GetCenterPoint() + t * m_LhsSegment.GetDirection(),
                               m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection(),
                               t, rhsExtent };
    }
    else
    {
        return GetSquaredWithClosestPointsIsRhsSide(tool, lhsExtent, Math::FAbs(rhsExtent));
    }
}

// private
template <typename Real>
const typename Mathematics::DistanceSegment3Segment3<Real>::DistanceResult Mathematics::DistanceSegment3Segment3<Real>::GetSquaredWithClosestPointsIsRhsCorner(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const
{
    auto t = tool.GetLhsT(-rhsExtent);
    auto rhsSquare = rhsExtent * (rhsExtent + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                     tool.GetOriginDifferenceSquaredLength();

    if (lhsExtent < t)
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(lhsExtent * (lhsExtent - Math::GetValue(2) * t) + rhsSquare),
                               Math::GetValue(0), m_LhsSegment.GetCenterPoint() + lhsExtent * m_LhsSegment.GetDirection(),
                               m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection(),
                               lhsExtent, rhsExtent };
    }
    else if (-lhsExtent <= t)
    {
        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               Math::GetValue(0), m_LhsSegment.GetCenterPoint() + t * m_LhsSegment.GetDirection(),
                               m_RhsSegment.GetCenterPoint() + rhsExtent * m_RhsSegment.GetDirection(),
                               t, rhsExtent };
    }
    else
    {
        return GetSquaredWithClosestPointsIsRhsSide(tool, -lhsExtent, Math::FAbs(rhsExtent));
    }
}

template <typename Real>
const typename Mathematics::DistanceSegment3Segment3<Real>::DistanceResult Mathematics::DistanceSegment3Segment3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto lhsMovedSegment = m_LhsSegment.GetMove(t, lhsVelocity);
    const auto rhsMovedSegment = m_RhsSegment.GetMove(t, rhsVelocity);

    ClassType distance{ lhsMovedSegment, rhsMovedSegment };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_SEGMENT3_ACHIEVE_H
