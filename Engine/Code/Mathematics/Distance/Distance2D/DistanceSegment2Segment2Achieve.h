///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 15:18)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_ACHIEVE_H

#include "DistanceSegment2Segment2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"

template <typename Real>
Mathematics::DistanceSegment2Segment2<Real>::DistanceSegment2Segment2(const Segment2& lhsSegment, const Segment2& rhsSegment) noexcept
    : lhsSegment{ lhsSegment }, rhsSegment{ rhsSegment }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceSegment2Segment2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Segment2<Real> Mathematics::DistanceSegment2Segment2<Real>::GetLhsSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsSegment;
}

template <typename Real>
Mathematics::Segment2<Real> Mathematics::DistanceSegment2Segment2<Real>::GetRhsSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsSegment;
}

template <typename Real>
typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine2Line2Tool tool{ lhsSegment.GetCenterPoint(), lhsSegment.GetDirection(), rhsSegment.GetCenterPoint(), rhsSegment.GetDirection() };

    const auto det = tool.GetDet();
    const auto lhsExtent = lhsSegment.GetExtent();
    const auto rhsExtent = rhsSegment.GetExtent();

    if (this->GetZeroThreshold() <= det)
    {
        // �߶β�ƽ�С�
        const auto lhsT = tool.GetLhsT();
        const auto rhsT = tool.GetRhsT();

        const auto lhsExtentMultiplyDet = lhsExtent * det;
        const auto rhsExtentMultiplyDet = rhsExtent * det;

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
                        return DistanceResult{ MathType::GetValue(0),
                                               MathType::GetValue(0),
                                               lhsSegment.GetCenterPoint() + lhsT / det * lhsSegment.GetDirection(),
                                               rhsSegment.GetCenterPoint() + rhsT / det * rhsSegment.GetDirection() };
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
        const auto extentSum = lhsExtent + rhsExtent;
        const auto sign = (MathType::GetValue(0) < tool.GetDirectionDot() ? MathType::GetValue(-1) : MathType::GetValue(1));
        const auto originDifferenceDotLhsDirectionAverage = tool.GetOriginDifferenceDotDirectionAverage();
        auto lambda = -originDifferenceDotLhsDirectionAverage;
        if (lambda < -extentSum)
        {
            lambda = -extentSum;
        }
        else if (extentSum < lambda)
        {
            lambda = extentSum;
        }

        const auto rhsT = (-sign * lambda * rhsExtent / extentSum);
        const auto lhsT = lambda + sign * rhsT;

        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(lambda * (lambda + MathType::GetValue(2) * originDifferenceDotLhsDirectionAverage) + tool.GetOriginDifferenceSquaredLength()),
                               MathType::GetValue(0),
                               lhsSegment.GetCenterPoint() + lhsT * lhsSegment.GetDirection(),
                               rhsSegment.GetCenterPoint() + rhsT * rhsSegment.GetDirection() };
    }
}

template <typename Real>
typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>::GetSquaredWithClosestPointsIsLhsSide(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const
{
    const auto t = tool.GetLhsT(-rhsExtent);
    const auto rhsSquare = rhsExtent * (rhsExtent + MathType::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                           tool.GetOriginDifferenceSquaredLength();

    if (t < -lhsExtent)
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-lhsExtent * (-lhsExtent - MathType::GetValue(2) * t) + rhsSquare),
                               MathType::GetValue(0),
                               lhsSegment.GetCenterPoint() - lhsExtent * lhsSegment.GetDirection(),
                               rhsSegment.GetCenterPoint() + rhsExtent * rhsSegment.GetDirection() };
    }
    else if (t <= lhsExtent)
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               MathType::GetValue(0),
                               lhsSegment.GetCenterPoint() + t * lhsSegment.GetDirection(),
                               rhsSegment.GetCenterPoint() + rhsExtent * rhsSegment.GetDirection() };
    }
    else
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(lhsExtent * (lhsExtent - MathType::GetValue(2) * t) + rhsSquare),
                               MathType::GetValue(0),
                               lhsSegment.GetCenterPoint() + lhsExtent * lhsSegment.GetDirection(),
                               rhsSegment.GetCenterPoint() + rhsExtent * rhsSegment.GetDirection() };
    }
}

template <typename Real>
typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>::GetSquaredWithClosestPointsIsRhsSide(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const
{
    const auto t = tool.GetRhsT(-lhsExtent);
    const auto lhsSquare = lhsExtent * (lhsExtent + MathType::GetValue(2) * tool.GetOriginDifferenceDotLhsDirection()) +
                           tool.GetOriginDifferenceSquaredLength();

    if (t < -rhsExtent)
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-rhsExtent * (-rhsExtent - MathType::GetValue(2) * t) + lhsSquare),
                               MathType::GetValue(0),
                               lhsSegment.GetCenterPoint() + lhsExtent * lhsSegment.GetDirection(),
                               rhsSegment.GetCenterPoint() - rhsExtent * rhsSegment.GetDirection() };
    }
    else if (t <= rhsExtent)
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-t * t + lhsSquare),
                               MathType::GetValue(0),
                               lhsSegment.GetCenterPoint() + lhsExtent * lhsSegment.GetDirection(),
                               rhsSegment.GetCenterPoint() + t * rhsSegment.GetDirection() };
    }
    else
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(rhsExtent * (rhsExtent - MathType::GetValue(2) * t) + lhsSquare),
                               MathType::GetValue(0),
                               lhsSegment.GetCenterPoint() + lhsExtent * lhsSegment.GetDirection(),
                               rhsSegment.GetCenterPoint() + rhsExtent * rhsSegment.GetDirection() };
    }
}

template <typename Real>
typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>::GetSquaredWithClosestPointsIsLhsCorner(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const
{
    const auto t = tool.GetLhsT(-rhsExtent);
    const auto rhsSquare = rhsExtent * (rhsExtent + MathType::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                           tool.GetOriginDifferenceSquaredLength();

    if (t < -lhsExtent)
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-lhsExtent * (-lhsExtent - MathType::GetValue(2) * t) + rhsSquare),
                               MathType::GetValue(0),
                               lhsSegment.GetCenterPoint() - lhsExtent * lhsSegment.GetDirection(),
                               rhsSegment.GetCenterPoint() + rhsExtent * rhsSegment.GetDirection() };
    }
    else if (t <= lhsExtent)
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               MathType::GetValue(0),
                               lhsSegment.GetCenterPoint() + t * lhsSegment.GetDirection(),
                               rhsSegment.GetCenterPoint() + rhsExtent * rhsSegment.GetDirection() };
    }
    else
    {
        return GetSquaredWithClosestPointsIsRhsSide(tool, lhsExtent, MathType::FAbs(rhsExtent));
    }
}

template <typename Real>
typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>::GetSquaredWithClosestPointsIsRhsCorner(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const
{
    const auto t = tool.GetLhsT(-rhsExtent);
    const auto rhsSquare = rhsExtent * (rhsExtent + MathType::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                           tool.GetOriginDifferenceSquaredLength();

    if (lhsExtent < t)
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(lhsExtent * (lhsExtent - MathType::GetValue(2) * t) + rhsSquare),
                               MathType::GetValue(0),
                               lhsSegment.GetCenterPoint() + lhsExtent * lhsSegment.GetDirection(),
                               rhsSegment.GetCenterPoint() + rhsExtent * rhsSegment.GetDirection() };
    }
    else if (-lhsExtent <= t)
    {
        return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                               MathType::GetValue(0),
                               lhsSegment.GetCenterPoint() + t * lhsSegment.GetDirection(),
                               rhsSegment.GetCenterPoint() + rhsExtent * rhsSegment.GetDirection() };
    }
    else
    {
        return GetSquaredWithClosestPointsIsRhsSide(tool, -lhsExtent, MathType::FAbs(rhsExtent));
    }
}

template <typename Real>
typename Mathematics::DistanceSegment2Segment2<Real>::DistanceResult Mathematics::DistanceSegment2Segment2<Real>::GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto lhsMovedSegment = lhsSegment.GetMove(t, lhsVelocity);
    const auto rhsMovedSegment = rhsSegment.GetMove(t, rhsVelocity);

    ClassType distance{ lhsMovedSegment, rhsMovedSegment };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_ACHIEVE_H
