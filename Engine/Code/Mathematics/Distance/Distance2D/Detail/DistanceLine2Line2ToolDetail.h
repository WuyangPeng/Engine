// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 19:05)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_DETAIL_H 

#include "DistanceLine2Line2Tool.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::DistanceLine2Line2Tool<Real>
	::DistanceLine2Line2Tool(const Vector2D& lhsOrigin, const Vector2D& lhsDirection, const Vector2D& rhsOrigin, const Vector2D& rhsDirection)
	:m_OriginDifference{ lhsOrigin - rhsOrigin },
	 m_DirectionDot{ -Vector2DTools::DotProduct(lhsDirection, rhsDirection) },
	 m_OriginDifferenceDotLhsDirection{ Vector2DTools::DotProduct(m_OriginDifference, lhsDirection) },
	 m_OriginDifferenceDotRhsDirection{ -Vector2DTools::DotProduct(m_OriginDifference, rhsDirection) },
	 m_OriginDifferenceSquaredLength{ Vector2DTools::VectorMagnitudeSquared(m_OriginDifference) },
	 m_Det{ Math::FAbs(static_cast<Real>(1) - m_DirectionDot * m_DirectionDot) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine2Line2Tool<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT 

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetDet() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Det;
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetLhsT() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return (m_DirectionDot * m_OriginDifferenceDotRhsDirection - m_OriginDifferenceDotLhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetRhsT() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return (m_DirectionDot * m_OriginDifferenceDotLhsDirection - m_OriginDifferenceDotRhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetLhsT(Real extent) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return (m_DirectionDot * extent - m_OriginDifferenceDotLhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetRhsT(Real extent) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return (m_DirectionDot * extent - m_OriginDifferenceDotRhsDirection);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetOriginDifferenceDotLhsDirection() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_OriginDifferenceDotLhsDirection;
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetOriginDifferenceDotRhsDirection() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_OriginDifferenceDotRhsDirection;
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetSquaredDistanceWithParallel() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return GetSquaredDistanceWithLhs();
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetSquaredDistanceWithLhs() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto squaredDistance = -m_OriginDifferenceDotLhsDirection * m_OriginDifferenceDotLhsDirection + m_OriginDifferenceSquaredLength;

	// 计算数值舍入误差
	return Math::GetNumericalRoundOffNonnegative(squaredDistance);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetSquaredDistanceWithRhs() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto squaredDistance = -m_OriginDifferenceDotRhsDirection * m_OriginDifferenceDotRhsDirection + m_OriginDifferenceSquaredLength;

	// 计算数值舍入误差
	return Math::GetNumericalRoundOffNonnegative(squaredDistance);
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetOriginDifferenceSquaredLength() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_OriginDifferenceSquaredLength;
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetDirectionDot() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_DirectionDot;
}

template <typename Real>
Real Mathematics::DistanceLine2Line2Tool<Real>
	::GetOriginDifferenceDotDirectionAverage() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto sign = (Math::GetValue(0) < m_DirectionDot ? static_cast<Real>(-1) : static_cast<Real>(1));
	auto average = static_cast<Real>(0.5) * (m_OriginDifferenceDotLhsDirection - sign * m_OriginDifferenceDotRhsDirection);

	return average;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_DETAIL_H
