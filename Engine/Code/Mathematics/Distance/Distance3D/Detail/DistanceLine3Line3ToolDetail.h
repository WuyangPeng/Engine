///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/22 15:52)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_DETAIL_H

#include "DistanceLine3Line3Tool.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::DistanceLine3Line3Tool<Real>::DistanceLine3Line3Tool(const Vector3& lhsOrigin, const Vector3& lhsDirection, const Vector3& rhsOrigin, const Vector3& rhsDirection)
    : originDifference{ lhsOrigin - rhsOrigin },
      directionDot{ -Vector3Tools::DotProduct(lhsDirection, rhsDirection) },
      originDifferenceDotLhsDirection{ Vector3Tools::DotProduct(originDifference, lhsDirection) },
      originDifferenceDotRhsDirection{ -Vector3Tools::DotProduct(originDifference, rhsDirection) },
      originDifferenceSquaredLength{ Vector3Tools::GetLengthSquared(originDifference) },
      det{ Math::FAbs(Math::GetValue(1) - directionDot * directionDot) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceLine3Line3Tool<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetDet() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return det;
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetLhsT() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (directionDot * originDifferenceDotRhsDirection - originDifferenceDotLhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetRhsT() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (directionDot * originDifferenceDotLhsDirection - originDifferenceDotRhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetLhsT(Real extent) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (directionDot * extent - originDifferenceDotLhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetRhsT(Real extent) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (directionDot * extent - originDifferenceDotRhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetOriginDifferenceDotLhsDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return originDifferenceDotLhsDirection;
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetOriginDifferenceDotRhsDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return originDifferenceDotRhsDirection;
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetSquaredDistanceWithParallel() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetSquaredDistanceWithLhs();
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetSquaredDistanceWithLhs() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto squaredDistance = -originDifferenceDotLhsDirection * originDifferenceDotLhsDirection + originDifferenceSquaredLength;

    // 计算数值舍入误差
    return Math::GetNumericalRoundOffNonnegative(squaredDistance);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetSquaredDistanceWithRhs() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto squaredDistance = -originDifferenceDotRhsDirection * originDifferenceDotRhsDirection + originDifferenceSquaredLength;

    // 计算数值舍入误差
    return Math::GetNumericalRoundOffNonnegative(squaredDistance);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetOriginDifferenceSquaredLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return originDifferenceSquaredLength;
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetDirectionDot() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return directionDot;
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetOriginDifferenceDotDirectionAverage() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto sign = (Math::GetValue(0) < directionDot ? Math::GetValue(-1) : Math::GetValue(1));
    const auto average = Math::GetRational(1, 2) * (originDifferenceDotLhsDirection - sign * originDifferenceDotRhsDirection);

    return average;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_DETAIL_H
