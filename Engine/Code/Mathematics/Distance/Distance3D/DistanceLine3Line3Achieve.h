///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/21 15:24)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_ACHIEVE_H

#include "DistanceLine3Line3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects3D/Line3Detail.h"

template <typename Real>
Mathematics::DistanceLine3Line3<Real>::DistanceLine3Line3(const Line3& lhsLine, const Line3& rhsLine) noexcept
    : ParentType{}, lhsLine{ lhsLine }, rhsLine{ rhsLine }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceLine3Line3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::DistanceLine3Line3<Real>::GetLhsLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsLine;
}

template <typename Real>
Mathematics::Line3<Real> Mathematics::DistanceLine3Line3<Real>::GetRhsLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsLine;
}

template <typename Real>
typename Mathematics::DistanceLine3Line3<Real>::DistanceResult Mathematics::DistanceLine3Line3<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine3Line3Tool<Real> tool{ lhsLine.GetOrigin(), lhsLine.GetDirection(), rhsLine.GetOrigin(), rhsLine.GetDirection() };

    const auto det = tool.GetDet();

    if (this->GetZeroThreshold() <= det)
    {
        // 线不平行。
        const auto lhsT = tool.GetLhsT() / det;
        const auto rhsT = tool.GetRhsT() / det;
        const auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotLhsDirection()) +
                                     rhsT * (tool.GetDirectionDot() * lhsT + rhsT + Math::GetValue(2) * tool.GetOriginDifferenceDotRhsDirection()) +
                                     tool.GetOriginDifferenceSquaredLength();

        return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance),
                               Math::GetValue(0),
                               lhsLine.GetOrigin() + lhsT * lhsLine.GetDirection(),
                               rhsLine.GetOrigin() + rhsT * rhsLine.GetDirection(),
                               lhsT,
                               rhsT };
    }
    else
    {
        // 线是平行的,选择任何最近点。
        const auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();
        const auto squaredDistance = tool.GetSquaredDistanceWithParallel();

        return DistanceResult{ squaredDistance,
                               Math::GetValue(0),
                               lhsLine.GetOrigin() - originDifferenceDotLhsDirection * lhsLine.GetDirection(),
                               rhsLine.GetOrigin(),
                               -originDifferenceDotLhsDirection,
                               Math::GetValue(0) };
    }
}

template <typename Real>
typename Mathematics::DistanceLine3Line3<Real>::DistanceResult Mathematics::DistanceLine3Line3<Real>::GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto lhsMovedLine = lhsLine.GetMove(t, lhsVelocity);
    const auto rhsMovedLine = rhsLine.GetMove(t, rhsVelocity);

    ClassType distance{ lhsMovedLine, rhsMovedLine };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_ACHIEVE_H
