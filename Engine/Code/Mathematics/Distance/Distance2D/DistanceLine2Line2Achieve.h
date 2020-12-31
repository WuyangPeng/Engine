///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/07 16:02)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_ACHIEVE_H

#include "DistanceLine2Line2.h"
#include "Detail/DistanceLine2Line2ToolDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"

template <typename Real>
Mathematics::DistanceLine2Line2<Real>::DistanceLine2Line2(const Line2& lhsLine, const Line2& rhsLine) noexcept
    : ParentType{}, m_LhsLine{ lhsLine }, m_RhsLine{ rhsLine }
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
const Mathematics::Line2<Real> Mathematics::DistanceLine2Line2<Real>::GetLhsLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LhsLine;
}

template <typename Real>
const Mathematics::Line2<Real> Mathematics::DistanceLine2Line2<Real>::GetRhsLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_RhsLine;
}

template <typename Real>
const typename Mathematics::DistanceLine2Line2<Real>::DistanceResult Mathematics::DistanceLine2Line2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const DistanceLine2Line2Tool<Real> tool{ m_LhsLine.GetOrigin(), m_LhsLine.GetDirection(), m_RhsLine.GetOrigin(), m_RhsLine.GetDirection() };

    auto det = tool.GetDet();

    if (this->GetZeroThreshold() <= det)
    {
        // 线不平行。
        auto lhsT = tool.GetLhsT() / det;
        auto rhsT = tool.GetRhsT() / det;

        return DistanceResult{ Math::GetValue(0), Math::GetValue(0), m_LhsLine.GetOrigin() + lhsT * m_LhsLine.GetDirection(), m_RhsLine.GetOrigin() + rhsT * m_RhsLine.GetDirection() };
    }
    else
    {
        // 线是平行的,选择任何最近点。
        auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();
        auto squaredDistance = tool.GetSquaredDistanceWithParallel();

        return DistanceResult{ squaredDistance, Math::GetValue(0), m_LhsLine.GetOrigin() - originDifferenceDotLhsDirection * m_LhsLine.GetDirection(), m_RhsLine.GetOrigin() };
    }
}

template <typename Real>
const typename Mathematics::DistanceLine2Line2<Real>::DistanceResult Mathematics::DistanceLine2Line2<Real>::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto lhsMovedLine = m_LhsLine.GetMove(t, lhsVelocity);
    const auto rhsMovedLine = m_RhsLine.GetMove(t, rhsVelocity);

    ClassType distance{ lhsMovedLine, rhsMovedLine };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_ACHIEVE_H
