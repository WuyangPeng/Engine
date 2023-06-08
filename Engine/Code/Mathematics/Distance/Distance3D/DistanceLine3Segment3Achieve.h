///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 18:04)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_ACHIEVE_H

#include "DistanceLine3Segment3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"

template <typename Real>
Mathematics::DistanceLine3Segment3<Real>::DistanceLine3Segment3(const Line3& line, const Segment3& segment) noexcept
    : ParentType{}, line{ line }, segment{ segment }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine3Segment3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::DistanceLine3Segment3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Segment3<Real> Mathematics::DistanceLine3Segment3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return segment;
}

template <typename Real>
typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine3Line3Tool tool{ line.GetOrigin(), line.GetDirection(), segment.GetCenterPoint(), segment.GetDirection() };

    const auto det = tool.GetDet();

    if (this->GetZeroThreshold() <= det)
    {
        // ֱ�ߺ��߶β�ƽ�С�
        auto rhsT = tool.GetRhsT();
        auto rhsExtent = segment.GetExtent();
        auto rhsExtentMultiplyDet = rhsExtent * det;

        if (-rhsExtentMultiplyDet <= rhsT)
        {
            if (rhsT <= rhsExtentMultiplyDet)
            {
                // �����ڲ�����ӽ���һ����ֱ���ϣ�һ�����߶��ϡ�
                auto lhsT = tool.GetLhsT() / det;
                rhsT /= det;

                auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotLhsDirection()) +
                                       rhsT * (tool.GetDirectionDot() * lhsT + rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                                       tool.GetOriginDifferenceSquaredLength();

                return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance),
                                       Math::GetValue(0),
                                       line.GetOrigin() + lhsT * line.GetDirection(),
                                       segment.GetCenterPoint() + rhsT * segment.GetDirection(),
                                       lhsT,
                                       rhsT };
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
typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>::GetSquaredWithClosestPoints(const DistanceLine3Line3Tool& tool, Real rhsExtent) const
{
    auto t = tool.GetLhsT(-rhsExtent);
    auto rhsSquare = rhsExtent * (rhsExtent + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) + tool.GetOriginDifferenceSquaredLength();

    return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare),
                           Math::GetValue(0),
                           line.GetOrigin() + t * line.GetDirection(),
                           segment.GetCenterPoint() + rhsExtent * segment.GetDirection(),
                           t,
                           rhsExtent };
}

template <typename Real>
typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>::GetSquaredWithClosestPointsIsParallel(const DistanceLine3Line3Tool& tool) const
{
    auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();
    auto squaredDistance = tool.GetSquaredDistanceWithParallel();

    return DistanceResult{ squaredDistance,
                           Math::GetValue(0),
                           line.GetOrigin() - originDifferenceDotLhsDirection * line.GetDirection(),
                           segment.GetCenterPoint(),
                           -originDifferenceDotLhsDirection,
                           Math::GetValue(0) };
}

template <typename Real>
typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
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

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_ACHIEVE_H
