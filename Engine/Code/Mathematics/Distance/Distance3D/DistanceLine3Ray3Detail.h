// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/11 09:42)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_DETAIL_H 

#include "DistanceLine3Ray3.h"
#include "Detail/DistanceLine3Line3ToolDetail.h"
#include "Mathematics/Objects3D/Ray3Detail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DistanceLine3Ray3<Real>
	::DistanceLine3Ray3(const Line3& line, const Ray3& ray)
	:ParentType{}, m_Line{ line }, m_Ray{ ray }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistanceLine3Ray3<Real>
	::~DistanceLine3Ray3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceLine3Ray3<Real>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else	
		return false;	
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistanceLine3Ray3<Real>::Line3 Mathematics::DistanceLine3Ray3<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Line;
}

template <typename Real>
const typename Mathematics::DistanceLine3Ray3<Real>::Ray3 Mathematics::DistanceLine3Ray3<Real>
	::GetRay() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Ray;
}

template <typename Real>
const typename Mathematics::DistanceLine3Ray3<Real>::DistanceResult Mathematics::DistanceLine3Ray3<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	DistanceLine3Line3Tool tool{ m_Line.GetOrigin(), m_Line.GetDirection(),m_Ray.GetOrigin(),m_Ray.GetDirection() };

	auto det = tool.GetDet();

	if (GetZeroThreshold() <= det)
	{
		auto rhsT = tool.GetRhsT();
	
		if (Real{} <= rhsT)
		{
			// �����ڲ�����ӽ���һ����ֱ���ϣ�һ���������ϡ�
			auto lhsT = tool.GetLhsT() / det;
			rhsT /= det;
			auto squaredDistance = lhsT * (lhsT + tool.GetDirectionDot() * rhsT + static_cast<Real>(2) * tool.GetOriginDifferenceDotLhsDirection()) +
			                       rhsT * (tool.GetDirectionDot() * lhsT + rhsT + static_cast<Real>(2) * tool.GetOriginDifferenceDotRhsDirection()) +
							       tool.GetOriginDifferenceSquaredLength();
	 
			return DistanceResult{ Math::GetNumericalRoundOffNonnegative(squaredDistance), Real{}, m_Line.GetOrigin() + lhsT * m_Line.GetDirection(),
								   m_Ray.GetOrigin() + rhsT * m_Ray.GetDirection(),lhsT,rhsT };
		}
		else
		{		
			// ���ߵ�ԭ��ֱͬ�ߵ�ĳһ����ӽ���
			return GetSquaredWithClosestPoints(tool);
		}
	}
	else
	{
		// ����ƽ�еģ���ӽ���һ�Ե�������ԭ�㡣
		return GetSquaredWithClosestPoints(tool);
	}	
}
	
template <typename Real>
const typename Mathematics::DistanceLine3Ray3<Real>::DistanceResult Mathematics::DistanceLine3Ray3<Real>
	::GetSquaredWithClosestPoints(const DistanceLine3Line3Tool& tool) const
{
	auto squaredDistance = tool.GetSquaredDistanceWithLhs();

	return DistanceResult{ squaredDistance, Real{},
						   m_Line.GetOrigin() - tool.GetOriginDifferenceDotLhsDirection() * m_Line.GetDirection(), m_Ray.GetOrigin(),
						   -tool.GetOriginDifferenceDotLhsDirection(),Real{} };
}

template <typename Real>
const typename Mathematics::DistanceLine3Ray3<Real>::DistanceResult Mathematics::DistanceLine3Ray3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
 
	auto movedLine = m_Line.GetMove(t, lhsVelocity);
	auto movedRay = m_Ray.GetMove(t, rhsVelocity);

	ClassType distance{ movedLine, movedRay };
	distance.SetZeroThreshold(GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}
#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_DETAIL_H
 