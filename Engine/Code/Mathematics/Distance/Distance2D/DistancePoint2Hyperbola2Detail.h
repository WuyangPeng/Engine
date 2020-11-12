// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/23 19:21)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_DETAIL_H

#include "DistancePoint2Hyperbola2.h"

#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h" 
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint2Hyperbola2<Real>
	::DistancePoint2Hyperbola2(const Vector2D& point, const Vector2D& extent)
	:ParentType{}, m_Point{ point }, m_Extent{ extent }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistancePoint2Hyperbola2<Real>
	::~DistancePoint2Hyperbola2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistancePoint2Hyperbola2<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && Math::GetValue(0) < m_Extent.GetX() && Math::GetValue(0) < m_Extent.GetY())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistancePoint2Hyperbola2<Real>::Vector2D Mathematics::DistancePoint2Hyperbola2<Real>
	::GetPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Point;
}

template <typename Real>
const typename Mathematics::DistancePoint2Hyperbola2<Real>::Vector2D Mathematics::DistancePoint2Hyperbola2<Real>
	::GetExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent;
}

template <typename Real>
const typename Mathematics::DistancePoint2Hyperbola2<Real>::DistanceResult Mathematics::DistancePoint2Hyperbola2<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	Vector2D extentSquared{ m_Extent[0] * m_Extent[0], m_Extent[1] * m_Extent[1] };
	Vector2D reciprocalExtentSquared{ static_cast<Real>(1) / extentSquared[0],static_cast<Real>(1) / extentSquared[1] };

	// ��ʼ�����ַ��� ��H(-a^2)= +������H(b^2)= -infinity����أ�
	// �������ֻ��Ҫ����Ӧ���з������ֳ�ʼ������ֵ��
	auto t0 = -extentSquared[0];
	auto t1 = extentSquared[1];
	auto tRoot = static_cast<Real>(0.5) * (t0 + t1);
	auto hyperbolaRoot = GetHyperbola(tRoot, reciprocalExtentSquared);

	// ����ֱ�� H(troot)����Ϊ���ֱ��һ������˵㲻�ٸı䡣 
	// ��һ��������IEEE�����������ʣ����ѭ�����������������Ĳ�����ֹ��
	auto maximumIterations = this->GetMaximumIterations();
	for (auto loop = 0; loop < maximumIterations; ++loop)
	{
		if (!Math::Approximate(hyperbolaRoot, Math::GetValue(0), this->GetZeroThreshold()) &&
			!Math::Approximate(tRoot, t0, this->GetZeroThreshold()) &&
			!Math::Approximate(tRoot, t1, this->GetZeroThreshold()))
		{
			break;
		}

		if (Math::GetValue(0) < hyperbolaRoot)
		{
			t0 = tRoot;
			tRoot = static_cast<Real>(0.5) * (t0 + t1);
		}
		else // hyperbolaRoot < Math<Real>::sm_Zero
		{
			t1 = tRoot;
		}

		tRoot = static_cast<Real>(0.5) * (t0 + t1);
		hyperbolaRoot = GetHyperbola(tRoot, reciprocalExtentSquared);

		if (loop + 1 == maximumIterations)
		{
			MATHEMATICS_ASSERTION_2(false, "δ�ܵ����������������");
		}
	}

	Vector2D closest{ m_Point[0] / (static_cast<Real>(1) + tRoot * reciprocalExtentSquared[0]),
					  m_Point[1] / (static_cast<Real>(1) - tRoot * reciprocalExtentSquared[1]) };

	auto diff = m_Point - closest;

	return DistanceResult{ Vector2DTools::VectorMagnitudeSquared(diff), Math::GetValue(0), m_Point, closest };
}

// private
template <typename Real>
Real Mathematics::DistancePoint2Hyperbola2<Real>
	::GetHyperbola(Real t, const Vector2D& reciprocalExtentSquared) const
{
	auto ratio0 = m_Point[0] / (static_cast<Real>(1) + t * reciprocalExtentSquared[0]);
	auto ratio1 = m_Point[1] / (static_cast<Real>(1) - t * reciprocalExtentSquared[1]);

	return ratio0 * ratio0 - ratio1 * ratio1 - static_cast<Real>(1);
}

template <typename Real>
const typename Mathematics::DistancePoint2Hyperbola2<Real>::DistanceResult Mathematics::DistancePoint2Hyperbola2<Real>
	::GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto movePoint = m_Point.GetMove(t, lhsVelocity);

	ClassType distance{ movePoint, m_Extent };
	distance.SetZeroThreshold(this->GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_DETAIL_H
