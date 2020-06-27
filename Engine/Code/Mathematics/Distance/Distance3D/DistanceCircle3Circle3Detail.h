// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 10:05)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_DETAIL_H
#define MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_DETAIL_H 

#include "DistanceCircle3Circle3.h"
#include "Mathematics/Objects3D/Circle3Detail.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"
#include "Mathematics/NumericalAnalysis/PolynomialRootsDetail.h"

template <typename Real>
Mathematics::DistanceCircle3Circle3<Real>
	::DistanceCircle3Circle3(const Circle3& lhsCircle, const Circle3& rhsCircle)
	:ParentType{}, m_LhsCircle{ lhsCircle }, m_RhsCircle{ rhsCircle }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::DistanceCircle3Circle3<Real>
	::~DistanceCircle3Circle3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DistanceCircle3Circle3<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::DistanceCircle3Circle3<Real>::Circle3 Mathematics::DistanceCircle3Circle3<Real>
	::GetLhsCircle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LhsCircle;
}

template <typename Real>
const typename Mathematics::DistanceCircle3Circle3<Real>::Circle3 Mathematics::DistanceCircle3Circle3<Real>
	::GetRhsCircle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RhsCircle;
}

template <typename Real>
const typename Mathematics::DistanceCircle3Circle3<Real>::DistanceResult Mathematics::DistanceCircle3Circle3<Real>
	::GetSquared() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto difference = m_RhsCircle.GetCenter() - m_LhsCircle.GetCenter();
	auto lhs0DotRhs0 = Vector3DTools::DotProduct(m_LhsCircle.GetDirection0(), m_RhsCircle.GetDirection0());
	auto lhs0DotRhs1 = Vector3DTools::DotProduct(m_LhsCircle.GetDirection0(), m_RhsCircle.GetDirection1());
	auto lhs1DotRhs0 = Vector3DTools::DotProduct(m_LhsCircle.GetDirection1(), m_RhsCircle.GetDirection0());
	auto lhs1DotRhs1 = Vector3DTools::DotProduct(m_LhsCircle.GetDirection1(), m_RhsCircle.GetDirection1());

	auto a0 = -Vector3DTools::DotProduct(difference, m_LhsCircle.GetDirection0());
	auto a1 = -m_RhsCircle.GetRadius() * lhs0DotRhs0;
	auto a2 = -m_RhsCircle.GetRadius() * lhs0DotRhs1;
	auto a3 = Vector3DTools::DotProduct(difference, m_LhsCircle.GetDirection1());
	auto a4 = m_RhsCircle.GetRadius() * lhs1DotRhs0;
	auto a5 = m_RhsCircle.GetRadius() * lhs1DotRhs1;

	auto b0 = -Vector3DTools::DotProduct(difference, m_RhsCircle.GetDirection0());
	auto b1 = m_LhsCircle.GetRadius() * lhs0DotRhs0;
	auto b2 = m_LhsCircle.GetRadius() * lhs1DotRhs0;
	auto b3 = Vector3DTools::DotProduct(difference, m_RhsCircle.GetDirection1());
	auto b4 = -m_LhsCircle.GetRadius() * lhs0DotRhs1;
	auto b5 = -m_LhsCircle.GetRadius() * lhs1DotRhs1;

	// 计算多项式 p0 = p00 + p01 * z + p02 * z^2.
	Polynomial<Real> p0{ 2 };
	p0[0] = a2 * b1 - a5 * b2;
	p0[1] = a0 * b4 - a3 * b5;
	p0[2] = a5 * b2 - a2 * b1 + a1 * b4 - a4 * b5;

	// 计算多项式 p1 = p10 + p11 * z.
	Polynomial<Real> p1{ 1 };
	p1[0] = a0 * b1 - a3 * b2;
	p1[1] = a1 * b1 - a5 * b5 + a2 * b4 - a4 * b2;

	// 计算多项式 q0 = q00 + q01 * z + q02 * z^2.
	Polynomial<Real> q0{ 2 };
	q0[0] = a0 * a0 + a2 * a2 + a3 * a3 + a5 * a5;
	q0[1] = static_cast<Real>(2) * (a0 * a1 + a3 * a4);
	q0[2] = a1 * a1 - a2 * a2 + a4 * a4 - a5 * a5;

	// 计算多项式 q1 = q10 + q11 * z.
	Polynomial<Real> q1{ 1 };
	q1[0] = static_cast<Real>(2) * (a0 * a2 + a3 * a5);
	q1[1] = static_cast<Real>(2) * (a1 * a2 + a4 * a5);

	// 计算系数 r0 = r00+r02*z^2.
	Polynomial<Real> r0{ 2 };
	r0[0] = b0 * b0;
	r0[1] = Math::sm_Zero;
	r0[2] = b3 * b3 - b0 * b0;

	// 计算多项式 r1 = r11 * z.
	Polynomial<Real> r1{ 1 };
	r1[0] = Math::sm_Zero;
	r1[1] = static_cast<Real>(2) * b0 * b3;

	// 计算多项式 g0 = g00 + g01 * z + g02 * z^2 + g03 * z^3 + g04 * z^4.
	Polynomial<Real> g0{ 4 };
	g0[0] = p0[0] * p0[0] + p1[0] * p1[0] - q0[0] * r0[0];
	g0[1] = static_cast<Real>(2) * (p0[0] * p0[1] + p1[0] * p1[1]) - q0[1] * r0[0] - q1[0] * r1[1];
	g0[2] = p0[1] * p0[1] + static_cast<Real>(2) * p0[0] * p0[2] - p1[0] * p1[0] +
		    p1[1] * p1[1] - q0[2] * r0[0] - q0[0] * r0[2] - q1[1] * r1[1];
	g0[3] = static_cast<Real>(2) *(p0[1] * p0[2] - p1[0] * p1[1]) - q0[1] * r0[2] + q1[0] * r1[1];
	g0[4] = p0[2] * p0[2] - p1[1] * p1[1] - q0[2] * r0[2] + q1[1] * r1[1];

	// 计算多项式 g1 = g10 + g11 * z + g12 * z^2 + g13 * z^3.
	Polynomial<Real> g1{ 3 };
	g1[0] = static_cast<Real>(2) * p0[0] * p1[0] - q1[0] * r0[0];
	g1[1] = static_cast<Real>(2) * (p0[1] * p1[0] + p0[0] * p1[1]) - q1[1] * r0[0] - q0[0] * r1[1];
	g1[2] = static_cast<Real>(2) * (p0[2] * p1[0] + p0[1] * p1[1]) - q1[0] * r0[2] - q0[1] * r1[1];
	g1[3] = static_cast<Real>(2) * p0[2] * p1[1] - q1[1] * r0[2] - q0[2] * r1[1];

	// 计算多项式 h = sum_{i=0}^8 h_i z^i.
	Polynomial<Real> h{ 8 };
	h[0] = g0[0] * g0[0] - g1[0] * g1[0];
	h[1] = static_cast<Real>(2)*(g0[0] * g0[1] - g1[0] * g1[1]);
	h[2] = g0[1] * g0[1] + g1[0] * g1[0] - g1[1] * g1[1] +
		   static_cast<Real>(2)*(g0[0] * g0[2] - g1[0] * g1[2]);
	h[3] = static_cast<Real>(2)*(g0[1] * g0[2] + g0[0] * g0[3] + g1[0] * g1[1] -
								 g1[1] * g1[2] - g1[0] * g1[3]);
	h[4] = g0[2] * g0[2] + g1[1] * g1[1] - g1[2] * g1[2] +
		   static_cast<Real>(2)*(g0[1] * g0[3] + g0[0] * g0[4] + g1[0] * g1[2] -
							     g1[1] * g1[3]);
	h[5] = static_cast<Real>(2)*(g0[2] * g0[3] + g0[1] * g0[4] + g1[1] * g1[2] +
								 g1[0] * g1[3] - g1[2] * g1[3]);
	h[6] = g0[3] * g0[3] + g1[2] * g1[2] - g1[3] * g1[3] +
		   static_cast<Real>(2)*(g0[2] * g0[4] + g1[1] * g1[3]);
	h[7] = static_cast<Real>(2)*(g0[3] * g0[4] + g1[2] * g1[3]);
	h[8] = g0[4] * g0[4] + g1[3] * g1[3];

	PolynomialRoots<Real> polyroots{ this->GetZeroThreshold() };
	polyroots.FindBisection(h, static_cast<Real>(-1.01), static_cast<Real>(1.01), 6);
	auto minSquaredDistance = Math::sm_MaxReal;
	Vector3D lhsClosestPoint;
	Vector3D rhsClosestPoint;

	for (auto iter = polyroots.GetBegin(), end = polyroots.GetEnd(); iter != end; ++iter)
	{
		auto rhsCosValue = Math::GetNumericalRoundOff(*iter, static_cast<Real>(-1), static_cast<Real>(1));

		// 你也可以尝试rhsSinValue = -g0（rhsCosValue）/ g1（rhsCosValue）避免sqrt调用，
		// 但要小心g1几乎为零。 现在我使用g0和g1来确定rhsSinValue的符号。
		auto rhsSinValue = Math::Sqrt(Math::FAbs(static_cast<Real>(1) - rhsCosValue * rhsCosValue));

		auto g0cs1 = g0(rhsCosValue);
		auto g1cs1 = g1(rhsCosValue);
		auto product = g0cs1 * g1cs1;
		if (Math::sm_Zero < product)
		{
			rhsSinValue = -rhsSinValue;
		}
		else if (product < Math::sm_Zero)
		{
			// rhsSinValue已经有正确的符号
		}
		else if (!Math::Approximate(g1cs1, Math::sm_Zero, this->GetZeroThreshold()))
		{
			// g0 == 0.0
			// assert( rhsSinValue == 0.0 );
		}
		else // g1 == 0.0
		{
			// 当g1 = 0时，对rhsSinValue没有约束。 
			// 这里应该做什么？ 在这种情况下，rhsSinValue是四次方程g0（rhsSinValue）= 0的根。
			// 是否有几何意义？
			MATHEMATICS_ASSERTION_2(false, "意外情况\n");
		}

		auto m00 = a0 + a1 * rhsCosValue + a2 * rhsSinValue;
		auto m01 = a3 + a4 * rhsCosValue + a5 * rhsSinValue;
		auto m10 = b2 * rhsSinValue + b5 * rhsCosValue;
		auto m11 = b1 * rhsSinValue + b4 * rhsCosValue;
		auto det = m00 * m11 - m01 * m10;
		if (this->GetZeroThreshold() <= Math::FAbs(det))
		{
			auto lambda = -(b0 * rhsSinValue + b3 * rhsCosValue);
			auto lhsCosValue = lambda * m00 / det;
			auto lhsSinValue = -lambda * m01 / det;

			// 在数值错误的情况下单位化。 如果您对lhsCosValue和lhsSinValue的准确性有信心，请删除。
			auto tmp = Math::InvSqrt(lhsCosValue * lhsCosValue + lhsSinValue * lhsSinValue);
			lhsCosValue *= tmp;
			lhsSinValue *= tmp;

			auto closest0 = m_LhsCircle.GetCenter() + m_LhsCircle.GetRadius() * (lhsCosValue * m_LhsCircle.GetDirection0() + lhsSinValue * m_LhsCircle.GetDirection1());

			auto closest1 = m_RhsCircle.GetCenter() + m_RhsCircle.GetRadius() * (rhsCosValue * m_RhsCircle.GetDirection0() + rhsSinValue * m_RhsCircle.GetDirection1());

			difference = closest1 - closest0;

			auto squaredDistance = Vector3DTools::VectorMagnitudeSquared(difference);
			if (squaredDistance < minSquaredDistance)
			{
				minSquaredDistance = squaredDistance;
				lhsClosestPoint = closest0;
				rhsClosestPoint = closest1;
			}
		}
		else
		{
			// 处理这种情况。有几何意义吗？
			MATHEMATICS_ASSERTION_2(false, "意外情况\n");
		}
	}

	return DistanceResult{ minSquaredDistance, Math::sm_Zero, lhsClosestPoint,rhsClosestPoint };
}

template <typename Real>
const typename Mathematics::DistanceCircle3Circle3<Real>::DistanceResult Mathematics::DistanceCircle3Circle3<Real>
	::GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto lhsMovedCircle = m_LhsCircle.GetMove(t, lhsVelocity);
	auto rhsMovedCircle = m_RhsCircle.GetMove(t, rhsVelocity);

	ClassType distance{ lhsMovedCircle, rhsMovedCircle };
	distance.SetZeroThreshold(this->GetZeroThreshold());
	auto distanceResult = distance.GetSquared();
	distanceResult.SetContactTime(t);

	return distanceResult;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_DETAIL_H
