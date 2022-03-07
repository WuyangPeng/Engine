///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/21 10:53)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_ACHIEVE_H

#include "DistanceLine2Line2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"

template <typename Real>
Mathematics::DistanceLine2Line2<Real>::DistanceLine2Line2(const Line2& lhsLine, const Line2& rhsLine) noexcept
    : ParentType{}, lhsLine{ lhsLine }, rhsLine{ rhsLine }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceLine2Line2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::DistanceLine2Line2<Real>::GetLhsLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsLine;
}

template <typename Real>
Mathematics::Line2<Real> Mathematics::DistanceLine2Line2<Real>::GetRhsLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsLine;
}

template <typename Real>
typename Mathematics::DistanceLine2Line2<Real>::DistanceResult Mathematics::DistanceLine2Line2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine2Line2Tool<Real> tool{ lhsLine.GetOrigin(), lhsLine.GetDirection(), rhsLine.GetOrigin(), rhsLine.GetDirection() };

    const auto det = tool.GetDet();

    if (this->GetZeroThreshold() <= det)
    {
        // 线不平行。
        auto lhsT = tool.GetLhsT() / det;
        auto rhsT = tool.GetRhsT() / det;

        return DistanceResult{ Math::GetValue(0), Math::GetValue(0), lhsLine.GetOrigin() + lhsT * lhsLine.GetDirection(), rhsLine.GetOrigin() + rhsT * rhsLine.GetDirection() };
    }
    else
    {
        // 线是平行的,选择任何最近点。
        const auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();
        const auto squaredDistance = tool.GetSquaredDistanceWithParallel();

        return DistanceResult{ squaredDistance, Math::GetValue(0), lhsLine.GetOrigin() - originDifferenceDotLhsDirection * lhsLine.GetDirection(), rhsLine.GetOrigin() };
    }
}

template <typename Real>
typename Mathematics::DistanceLine2Line2<Real>::DistanceResult Mathematics::DistanceLine2Line2<Real>::GetSquared(Real t, const Vector2& lhsVelocity, const Vector2& rhsVelocity) const
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

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_ACHIEVE_H
