///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/09 18:56)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_ACHIEVE_H

#include "DistanceLine3Segment3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Objects3D/Segment3Detail.h"

template <typename Real>
Mathematics::DistanceLine3Segment3<Real>::DistanceLine3Segment3(const Line3& line, const Segment3& segment) noexcept
    : ParentType{}, m_Line{ line }, m_Segment{ segment }
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
const Mathematics::Line3<Real> Mathematics::DistanceLine3Segment3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::DistanceLine3Segment3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine3Line3Tool tool{ m_Line.GetOrigin(), m_Line.GetDirection(), m_Segment.GetCenterPoint(), m_Segment.GetDirection() };

    auto det = tool.GetDet();

    if (this->GetZeroThreshold() <= det)
    {
        // 直线和线段不平行。
        auto rhsT = tool.GetRhsT();
        auto rhsExtent = m_Segment.GetExtent();
        auto rhsExtentMultiplyDet = rhsExtent * det;

        if (-rhsExtentMultiplyDet <= rhsT)
        {
            if (rhsT <= rhsExtentMultiplyDet)
            {
                // 两个内部点最接近，一个在直线上，一个在线段上。
                auto lhsT = tool.GetLhsT() / det;
                rhsT /= det;

                auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotLhsDirection()) +
                                       rhsT * (tool.GetDirectionDot() * lhsT + rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                                       tool.GetOriginDifferenceSquaredLength();

                return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance), Math::GetValue(0), m_Line.GetOrigin() + lhsT * m_Line.GetDirection(),
                                       m_Segment.GetCenterPoint() + rhsT * m_Segment.GetDirection(), lhsT, rhsT };
            }
            else
            {
                // 线段的终点和直线的内部点最接近。
                return GetSquaredWithClosestPoints(tool, rhsExtent);
            }
        }
        else
        {
            // 线段的起点和直线的内部点最接近。
            return GetSquaredWithClosestPoints(tool, -rhsExtent);
        }
    }
    else
    {
        // 直线和线段是平行的。 选择最近的一对，使得一个点在线段中点。
        return GetSquaredWithClosestPointsIsParallel(tool);
    }
}

template <typename Real>
const typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>::GetSquaredWithClosestPoints(const DistanceLine3Line3Tool& tool, Real rhsExtent) const
{
    auto t = tool.GetLhsT(-rhsExtent);
    auto rhsSquare = rhsExtent * (rhsExtent + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) + tool.GetOriginDifferenceSquaredLength();

    return DistanceResult{ Math::GetNumericalRoundOffNonnegative(-t * t + rhsSquare), Math::GetValue(0), m_Line.GetOrigin() + t * m_Line.GetDirection(),
                           m_Segment.GetCenterPoint() + rhsExtent * m_Segment.GetDirection(), t, rhsExtent };
}

template <typename Real>
const typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>::GetSquaredWithClosestPointsIsParallel(const DistanceLine3Line3Tool& tool) const
{
    auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();
    auto squaredDistance = tool.GetSquaredDistanceWithParallel();

    return DistanceResult{ squaredDistance, Math::GetValue(0), m_Line.GetOrigin() - originDifferenceDotLhsDirection * m_Line.GetDirection(),
                           m_Segment.GetCenterPoint(), -originDifferenceDotLhsDirection, Math::GetValue(0) };
}

template <typename Real>
const typename Mathematics::DistanceLine3Segment3<Real>::DistanceResult Mathematics::DistanceLine3Segment3<Real>::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedLine = m_Line.GetMove(t, lhsVelocity);
    const auto movedSegment = m_Segment.GetMove(t, rhsVelocity);

    ClassType distance{ movedLine, movedSegment };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_ACHIEVE_H
