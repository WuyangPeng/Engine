// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 10:10)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_DETAIL_H

#include "DistanceLine3Line3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistanceLine3Line3<Real>
	::DistanceLine3Line3(const Line3& lhsLine, const Line3& rhsLine)
	:ParentType{}, m_LhsLine{ lhsLine }, m_RhsLine{ rhsLine }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistanceLine3Line3<Real>
	::~DistanceLine3Line3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine3Line3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistanceLine3Line3<Real>::Line3 Mathematics::DistanceLine3Line3<Real>
	::GetLhsLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LhsLine;
}

template <typename Real>
const typename Mathematics::DistanceLine3Line3<Real>::Line3 Mathematics::DistanceLine3Line3<Real>
	::GetRhsLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RhsLine;
}

template <typename Real>
const typename Mathematics::DistanceLine3Line3<Real>::DistanceResult Mathematics::DistanceLine3Line3<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	DistanceLine3Line3Tool<Real> tool{ m_LhsLine.GetOrigin(),m_LhsLine.GetDirection(),m_RhsLine.GetOrigin(),m_RhsLine.GetDirection() };

	auto det = tool.GetDet();

	if (this->GetZeroThreshold() <= det)
	{
		// 线不平行。	
		auto lhsT = tool.GetLhsT() / det;
		auto rhsT = tool.GetRhsT() / det;
		auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + static_cast<Real>(2) * tool.GetOriginDifferenceDotLhsDirection()) +
							   rhsT * (tool.GetDirectionDot() * lhsT + rhsT + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) +
							   tool.GetOriginDifferenceSquaredLength();

		return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance), Math::sm_Zero, m_LhsLine.GetOrigin() + lhsT * m_LhsLine.GetDirection(),
							   m_RhsLine.GetOrigin() + rhsT * m_RhsLine.GetDirection(),lhsT,rhsT };
	}
	else
	{
		// 线是平行的,选择任何最近点。	
		auto originDifferenceDotLhsDirection = tool.GetOriginDifferenceDotLhsDirection();
		auto squaredDistance = tool.GetSquaredDistanceWithParallel();

		return DistanceResult{ squaredDistance, Math::sm_Zero,
							   m_LhsLine.GetOrigin() - originDifferenceDotLhsDirection * m_LhsLine.GetDirection(),
							   m_RhsLine.GetOrigin(), -originDifferenceDotLhsDirection,Math::sm_Zero };
	}
}

template <typename Real>
const typename Mathematics::DistanceLine3Line3<Real>::DistanceResult Mathematics::DistanceLine3Line3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto lhsMovedLine = m_LhsLine.GetMove(t, lhsVelocity);
	auto rhsMovedLine = m_RhsLine.GetMove(t, rhsVelocity);

	ClassType distance{ lhsMovedLine, rhsMovedLine };
	distance.SetZeroThreshold(this->GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}
#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_DETAIL_H
