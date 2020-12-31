///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/09 16:41)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_DETAIL_H

#include "DistanceLine3Line3Tool.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistanceLine3Line3Tool<Real>::DistanceLine3Line3Tool(const Vector3D& lhsOrigin, const Vector3D& lhsDirection, const Vector3D& rhsOrigin, const Vector3D& rhsDirection)
    : m_OriginDifference{ lhsOrigin - rhsOrigin },
      m_DirectionDot{ -Vector3DTools::DotProduct(lhsDirection, rhsDirection) },
      m_OriginDifferenceDotLhsDirection{ Vector3DTools::DotProduct(m_OriginDifference, lhsDirection) },
      m_OriginDifferenceDotRhsDirection{ -Vector3DTools::DotProduct(m_OriginDifference, rhsDirection) },
      m_OriginDifferenceSquaredLength{ Vector3DTools::VectorMagnitudeSquared(m_OriginDifference) },
      m_Det{ Math::FAbs(Math::GetValue(1) - m_DirectionDot * m_DirectionDot) }
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

    return m_Det;
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetLhsT() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (m_DirectionDot * m_OriginDifferenceDotRhsDirection - m_OriginDifferenceDotLhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetRhsT() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (m_DirectionDot * m_OriginDifferenceDotLhsDirection - m_OriginDifferenceDotRhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetLhsT(Real extent) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (m_DirectionDot * extent - m_OriginDifferenceDotLhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetRhsT(Real extent) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (m_DirectionDot * extent - m_OriginDifferenceDotRhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetOriginDifferenceDotLhsDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_OriginDifferenceDotLhsDirection;
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetOriginDifferenceDotRhsDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_OriginDifferenceDotRhsDirection;
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

    auto squaredDistance = -m_OriginDifferenceDotLhsDirection * m_OriginDifferenceDotLhsDirection + m_OriginDifferenceSquaredLength;

    // 计算数值舍入误差
    return Math::GetNumericalRoundOffNonnegative(squaredDistance);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetSquaredDistanceWithRhs() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto squaredDistance = -m_OriginDifferenceDotRhsDirection * m_OriginDifferenceDotRhsDirection + m_OriginDifferenceSquaredLength;

    // 计算数值舍入误差
    return Math::GetNumericalRoundOffNonnegative(squaredDistance);
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetOriginDifferenceSquaredLength() const noexcept
{ 
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_OriginDifferenceSquaredLength;
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetDirectionDot() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_DirectionDot;
}

template <typename Real>
Real Mathematics::DistanceLine3Line3Tool<Real>::GetOriginDifferenceDotDirectionAverage() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto sign = (Math::GetValue(0) < m_DirectionDot ? Math::GetValue(-1) : Math::GetValue(1));
    auto average = Math::GetRational(1, 2) * (m_OriginDifferenceDotLhsDirection - sign * m_OriginDifferenceDotRhsDirection);

    return average;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_DETAIL_H
