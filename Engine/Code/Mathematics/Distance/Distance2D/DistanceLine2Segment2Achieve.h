///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 15:16)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_ACHIEVE_H

#include "DistanceLine2Segment2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"
#include "Mathematics/Objects2D/Segment2Detail.h"

template <typename Real>
Mathematics::DistanceLine2Segment2<Real>::DistanceLine2Segment2(const Line2& line, const Segment2& segment) noexcept
    : ParentType{}, line{ line }, segment{ segment }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceLine2Segment2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::DistanceLine2Segment2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Segment2<Real> Mathematics::DistanceLine2Segment2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
typename Mathematics::DistanceLine2Segment2<Real>::DistanceResult Mathematics::DistanceLine2Segment2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine2Line2Tool tool{ line.GetOrigin(), line.GetDirection(), segment.GetCenterPoint(), segment.GetDirection() };

    const auto det = tool.GetDet();

    if (this->GetZeroThreshold() <= det)
    {
        // ֱ�ߺ��߶β�ƽ�С�
        const auto rhsT = tool.GetRhsT();
        const auto rhsExtent = segment.GetExtent();
        const auto rhsExtentMultiplyDet = rhsExtent * det;

        if (-rhsExtentMultiplyDet <= rhsT)
        {
            if (rhsT <= rhsExtentMultiplyDet)
            {
                // �����ڲ�����ӽ���һ����ֱ���ϣ�һ�����߶��ϡ�
                const auto lhsT = tool.GetLhsT();

                return DistanceResult{ MathType::GetValue(0),
                                       MathType::GetValue(0),
                                       line.GetOrigin() + lhsT / det * line.GetDirection(),
                                       segment.GetCenterPoint() + rhsT / det * segment.GetDirection() };
            }
            else
            {
                // �߶ε��յ��ֱ�ߵ��ڲ�����ӽ���
                return GetSquaredWithClosestPoints(tool, rhsExtent);
            }
        }
        else
        {
            // �߶ε�����ֱ�ߵ��ڲ�����ӽ���
            return GetSquaredWithClosestPoints(tool, -rhsExtent);
        }
    }
    else
    {
        // ֱ�ߺ��߶���ƽ�еġ� ѡ�������һ�ԣ�ʹ��һ�������߶��е㡣
        return GetSquaredWithClosestPointsIsParallel(tool);
    }
}

template <typename Real>
typename Mathematics::DistanceLine2Segment2<Real>::DistanceResult Mathematics::DistanceLine2Segment2<Real>::GetSquaredWithClosestPoints(const DistanceLine2Line2Tool& tool, Real rhsExtent) const
{
    const auto t = tool.GetLhsT(-rhsExtent);
    const auto rhsSquare = rhsExtent * (rhsExtent + MathType::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) + tool.GetOriginDifferenceSquaredLength();

    return DistanceResult{ MathType::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                           MathType::GetValue(0),
                           line.GetOrigin() + t * line.GetDirection(),
                           segment.GetCenterPoint() + rhsExtent * segment.GetDirection() };
}

template <typename Real>
typename Mathematics::DistanceLine2Segment2<Real>::DistanceResult Mathematics::DistanceLine2Segment2<Real>::GetSquaredWithClosestPointsIsParallel(const DistanceLine2Line2Tool& tool) const
{
    const auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();
    const auto squaredDistance = tool.GetSquaredDistanceWithParallel();

    return DistanceResult{ squaredDistance,
                           MathType::GetValue(0),
                           line.GetOrigin() - originDifferenceDotLhsDirection * line.GetDirection(),
                           segment.GetCenterPoint() };
}

template <typename Real>
typename Mathematics::DistanceLine2Segment2<Real>::DistanceResult Mathematics::DistanceLine2Segment2<Real>::GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLine = line.GetMove(t, lhsVelocity);
    const auto movedSegment = segment.GetMove(t, rhsVelocity);

    ClassType distance{ movedLine, movedSegment };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_ACHIEVE_H
