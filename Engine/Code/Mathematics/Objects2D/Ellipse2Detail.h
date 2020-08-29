// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 16:54)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_DETAIL_H

#include "Ellipse2.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Ellipse2<Real>
	::Ellipse2(const Vector2D& center, const Vector2D& axis0, const Vector2D& axis1,
			   const Real extent0, const Real extent1, const Real epsilon)
	:m_Center{ center }, m_Epsilon{ epsilon }
{
	m_Axis[0] = axis0;
	m_Axis[1] = axis1;
	m_Extent[0] = extent0;
	m_Extent[1] = extent1;

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipse2<Real>
	::Ellipse2(const Ellipse2Coefficients& coefficients, const Real epsilon)
	:m_Center{}, m_Epsilon{ epsilon }
{
	m_Axis[0] = Vector2D::sm_UnitX;
	m_Axis[1] = Vector2D::sm_UnitY;
	m_Extent[0] = Math::GetValue(0);
	m_Extent[1] = Math::GetValue(0);

	FromCoefficients(coefficients, m_Epsilon);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipse2<Real>
	::IsValid() const noexcept
{
	if (m_Axis[0].IsNormalize(m_Epsilon) && m_Axis[1].IsNormalize(m_Epsilon) && -m_Epsilon <= m_Extent[0] && -m_Epsilon <= m_Extent[1])
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Ellipse2<Real>::Vector2D Mathematics::Ellipse2<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
typename const Mathematics::Ellipse2<Real>::Vector2D Mathematics::Ellipse2<Real>
	::GetAxis0() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[0];
}

template <typename Real>
typename const Mathematics::Ellipse2<Real>::Vector2D Mathematics::Ellipse2<Real>
	::GetAxis1() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[1];
}

template <typename Real>
Real Mathematics::Ellipse2<Real>
	::GetExtent0() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[0];
}

template <typename Real>
Real Mathematics::Ellipse2<Real>
	::GetExtent1() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[1];
}

template <typename Real>
typename const Mathematics::Ellipse2<Real>::Matrix2 Mathematics::Ellipse2<Real>
	::GetMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto ratio0 = m_Axis[0] / m_Extent[0];
	auto ratio1 = m_Axis[1] / m_Extent[1];

	return Matrix2{ ratio0, ratio0 } + Matrix2{ ratio1, ratio1 };
}

template <typename Real>
typename const Mathematics::Ellipse2<Real>::Matrix2 Mathematics::Ellipse2<Real>
	::GetMatrixInverse() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto ratio0 = m_Axis[0] * m_Extent[0];
	auto ratio1 = m_Axis[1] * m_Extent[1];

	return Matrix2{ ratio0, ratio0 } + Matrix2{ ratio1, ratio1 };
}

template <typename Real>
typename const Mathematics::Ellipse2<Real>::Ellipse2Coefficients Mathematics::Ellipse2<Real>
	::ToCoefficients() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	Matrix2 matrix{ GetMatrix() };
	Vector2D vector{ static_cast<Real>(-2) * (matrix * m_Center) };
	auto constants = matrix.QuadraticForm(m_Center, m_Center) - static_cast<Real>(1);

	return Ellipse2Coefficients{ matrix,vector,constants };
}

template <typename Real>
void Mathematics::Ellipse2<Real>
	::FromCoefficients(const Ellipse2Coefficients& coefficients, const Real epsilon)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	auto matrix = coefficients.GetMatrix();
	auto vector = coefficients.GetVector();
	auto constants = coefficients.GetConstants();

	// 计算的中心 K = -A^{-1}*B/2.
	auto invMatrix = matrix.Inverse(epsilon);

	m_Center = static_cast<Real>(-0.5) * (invMatrix * vector);

	// 计算 B^T*A^{-1}*B/4 - C = K^T*A*K - C = -K^T*B/2 - C.
	auto rightSide = -static_cast<Real>(0.5) * Vector2DTools::DotProduct(m_Center, vector) - constants;
	if (Math::FAbs(rightSide) < epsilon)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"));
	}

	// 计算 M = A/(K^T*A*K - C).
	auto eigenSystemMatrix = matrix / rightSide;

	// 分解因子 M = Real*D*Real^T.
	auto eigenDecomposition = eigenSystemMatrix.EigenDecomposition(epsilon);

	auto diagonal = eigenDecomposition.GetDiagonal();
	auto rotation = eigenDecomposition.GetRotation();

	for (auto i = 0; i < 2; ++i)
	{
		auto eigenValue = diagonal(i, i);

		if (eigenValue <= epsilon)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"));
		}

		m_Extent[i] = Math::InvSqrt(eigenValue);

		m_Axis[i] = Vector2D(rotation(0, i), rotation(1, i));
	}

	m_Epsilon = epsilon;
}

template <typename Real>
Real Mathematics::Ellipse2<Real>
	::Evaluate(const Vector2D& point) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto diff = point - m_Center;
	auto ratio0 = Vector2DTools::DotProduct(m_Axis[0], diff) / m_Extent[0];
	auto ratio1 = Vector2DTools::DotProduct(m_Axis[1], diff) / m_Extent[1];
	auto value = ratio0 * ratio0 + ratio1 * ratio1 - static_cast<Real>(1);

	return value;
}

template <typename Real>
bool Mathematics::Ellipse2<Real>
	::Contains(const Vector2D& point) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Evaluate(point) <= m_Epsilon;
}

template <typename Real>
const Mathematics::Ellipse2<Real> Mathematics::Ellipse2<Real>
	::GetMove(Real t, const Vector2D& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto movedCenter = GetCenter() + t * velocity;
	Ellipse2 movedEllipse{ movedCenter, GetAxis0(), GetAxis1(),GetExtent0(),GetExtent1(),m_Epsilon };

	return movedEllipse;
}

template <typename Real>
bool Mathematics
	::Approximate(const Ellipse2<Real>& lhs, const Ellipse2<Real>& rhs, const Real epsilon)
{
	return Vector2DTools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
		   Vector2DTools<Real>::Approximate(lhs.GetAxis0(), rhs.GetAxis0(), epsilon) &&
		   Vector2DTools<Real>::Approximate(lhs.GetAxis1(), rhs.GetAxis1(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetExtent0(), rhs.GetExtent0(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetExtent1(), rhs.GetExtent1(), epsilon);
}

template <typename Real>
std::ostream& Mathematics
	::operator<<(std::ostream& outFile, const Ellipse2<Real>& ellipse)
{
	outFile << "center=" << ellipse.GetCenter() << ",axis0=" << ellipse.GetAxis0()
			<< ",axis1=" << ellipse.GetAxis1() << "extent0=" << ellipse.GetExtent0()
			<< "extent1=" << ellipse.GetExtent1();

	return outFile;
}

#endif // MATHEMATICS_OBJECTS2D_ELLIPSE2_DETAIL_H
