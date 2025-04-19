///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 15:15)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_DETAIL_H

#include "DistanceLine2Line2Tool.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::DistanceLine2Line2Tool<Real>::DistanceLine2Line2Tool(const Vector2Type& lhsOrigin, const Vector2Type& lhsDirection, const Vector2Type& rhsOrigin, const Vector2Type& rhsDirection)
    : originDifference{ lhsOrigin - rhsOrigin },
      directionDot{ -Vector2ToolsType::DotProduct(lhsDirection, rhsDirection) },
      originDifferenceDotLhsDirection{ Vector2ToolsType::DotProduct(originDifference, lhsDirection) },
      originDifferenceDotRhsDirection{ -Vector2ToolsType::DotProduct(originDifference, rhsDirection) },
      originDifferenceSquaredLength{ Vector2ToolsType::GetLengthSquared(originDifference) },
      det{ MathType::FAbs(MathType::GetValue(1) - directionDot * directionDot) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistanceLine2Line2Tool<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetDet() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return det;
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetLhsT() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (directionDot * originDifferenceDotRhsDirection - originDifferenceDotLhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetRhsT() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (directionDot * originDifferenceDotLhsDirection - originDifferenceDotRhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetLhsT(Real extent) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (directionDot * extent - originDifferenceDotLhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetRhsT(Real extent) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (directionDot * extent - originDifferenceDotRhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetOriginDifferenceDotLhsDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return originDifferenceDotLhsDirection;
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetOriginDifferenceDotRhsDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return originDifferenceDotRhsDirection;
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetSquaredDistanceWithParallel() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetSquaredDistanceWithLhs();
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetSquaredDistanceWithLhs() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto squaredDistance = -originDifferenceDotLhsDirection * originDifferenceDotLhsDirection + originDifferenceSquaredLength;

    // ������ֵ�������
    return MathType::GetNumericalRoundOffNonnegative(squaredDistance);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetSquaredDistanceWithRhs() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto squaredDistance = -originDifferenceDotRhsDirection * originDifferenceDotRhsDirection + originDifferenceSquaredLength;

    // ������ֵ�������
    return MathType::GetNumericalRoundOffNonnegative(squaredDistance);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetOriginDifferenceSquaredLength() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return originDifferenceSquaredLength;
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetDirectionDot() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return directionDot;
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>::GetOriginDifferenceDotDirectionAverage() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto sign = (MathType::GetValue(0) < directionDot ? MathType::GetValue(-1) : MathType::GetValue(1));
    const auto average = MathType::GetRational(1, 2) * (originDifferenceDotLhsDirection - sign * originDifferenceDotRhsDirection);

    return average;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_DETAIL_H
