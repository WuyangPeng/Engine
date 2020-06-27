// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:40)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_DETAIL_H

#include "Ellipsoid3.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Ellipsoid3<Real>
	::Ellipsoid3(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
				 const Real extent0, const Real extent1, const Real extent2, const Real epsilon)
	:m_Center{ center }, m_Epsilon{ epsilon }
{
	m_Axis[0] = axis0;
	m_Axis[1] = axis1;
	m_Axis[2] = axis2;
	m_Extent[0] = extent0;
	m_Extent[1] = extent1;
	m_Extent[2] = extent2;

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipsoid3<Real>
	::Ellipsoid3(const Ellipsoid3Coefficients& coefficients, const Real epsilon)
	:m_Center{}, m_Epsilon{ epsilon }
{
	m_Axis[0] = Vector3D::sm_UnitX;
	m_Axis[1] = Vector3D::sm_UnitY;
	m_Axis[2] = Vector3D::sm_UnitZ;
	m_Extent[0] = Math::sm_Zero;
	m_Extent[1] = Math::sm_Zero;
	m_Extent[2] = Math::sm_Zero;

	FromCoefficients(coefficients, m_Epsilon);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipsoid3<Real>
	::IsValid() const noexcept
{
	if (m_Axis[0].IsNormalize(m_Epsilon) && m_Axis[1].IsNormalize(m_Epsilon) &&
		m_Axis[2].IsNormalize(m_Epsilon) && -m_Epsilon <= m_Extent[0] &&
		-m_Epsilon <= m_Extent[1] && -m_Epsilon <= m_Extent[2] &&
		Math::sm_Zero <= m_Epsilon)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Ellipsoid3<Real>::Vector3D Mathematics::Ellipsoid3<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
typename const Mathematics::Ellipsoid3<Real>::Vector3D Mathematics::Ellipsoid3<Real>
	::GetAxis0() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[0];
}

template <typename Real>
typename const Mathematics::Ellipsoid3<Real>::Vector3D Mathematics::Ellipsoid3<Real>
	::GetAxis1() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[1];
}

template <typename Real>
typename const Mathematics::Ellipsoid3<Real>::Vector3D Mathematics::Ellipsoid3<Real>
	::GetAxis2() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[2];
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>
	::GetExtent0() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[0];
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>
	::GetExtent1() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[1];
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>
	::GetExtent2() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[2];
}

template <typename Real>
typename const Mathematics::Ellipsoid3<Real>::Matrix3 Mathematics::Ellipsoid3<Real>
	::GetMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto ratio0 = m_Axis[0] / m_Extent[0];
	auto ratio1 = m_Axis[1] / m_Extent[1];
	auto ratio2 = m_Axis[2] / m_Extent[2];

	return Matrix3{ ratio0, ratio0 } + Matrix3{ ratio1, ratio1 } + Matrix3{ ratio2, ratio2 };
}

template <typename Real>
typename const Mathematics::Ellipsoid3<Real>::Matrix3 Mathematics::Ellipsoid3<Real>
	::GetMatrixInverse() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto ratio0 = m_Axis[0] * m_Extent[0];
	auto ratio1 = m_Axis[1] * m_Extent[1];
	auto ratio2 = m_Axis[2] * m_Extent[2];

	return Matrix3{ ratio0, ratio0 } + Matrix3{ ratio1, ratio1 } + Matrix3{ ratio2, ratio2 };
}

template <typename Real>
typename const Mathematics::Ellipsoid3<Real>::Ellipsoid3Coefficients Mathematics::Ellipsoid3<Real>
	::ToCoefficients() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	Matrix3 matrix{ GetMatrix() };
	Vector3D vector{ static_cast<Real>(-2) * (matrix * m_Center) };
	auto constants = matrix.QuadraticForm(m_Center, m_Center) - static_cast<Real>(1);

	return Ellipsoid3Coefficients{ matrix,vector,constants };
}

template <typename Real>
void Mathematics::Ellipsoid3<Real>
	::FromCoefficients(const Ellipsoid3Coefficients& coefficients, const Real epsilon)
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto matrix = coefficients.GetMatrix();
	auto vector = coefficients.GetVector();
	auto constants = coefficients.GetConstants();

	// 计算的中心 K = -A^{-1}*B/2.
	auto invMatrix = matrix.Inverse(epsilon);

	m_Center = static_cast<Real>(-0.5) * (invMatrix * vector);

	// 计算 B^T*A^{-1}*B/4 - C = K^T*A*K - C = -K^T*B/2 - C。
	auto rightSide = -static_cast<Real>(0.5) * Vector3DTools::DotProduct(m_Center, vector) - constants;
	if (Math::FAbs(rightSide) < epsilon)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"));
	}

	// 计算 M = A/(K^T*A*K - C)
	auto eigenSystemMatrix = matrix / rightSide;

	// 分解因子 M = Real*D*Real^T.
	auto eigenDecomposition = eigenSystemMatrix.EigenDecomposition(epsilon);

	auto diagonal = eigenDecomposition.GetDiagonal();
	auto rotation = eigenDecomposition.GetRotation();

	for (auto i = 0; i < 3; ++i)
	{
		auto eigenValue = diagonal(i, i);

		if (eigenValue <= epsilon)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"));
		}

		m_Extent[i] = Math::InvSqrt(eigenValue);

		m_Axis[i] = Vector3D{ rotation(0,i), rotation(1,i), rotation(2,i) };
	}

	m_Epsilon = epsilon;
}

template <typename Real>
Real Mathematics::Ellipsoid3<Real>
	::Evaluate(const Vector3D& point) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto diff = point - m_Center;
	auto ratio0 = Vector3DTools::DotProduct(m_Axis[0], diff) / m_Extent[0];
	auto ratio1 = Vector3DTools::DotProduct(m_Axis[1], diff) / m_Extent[1];
	auto ratio2 = Vector3DTools::DotProduct(m_Axis[2], diff) / m_Extent[2];
	auto value = ratio0 * ratio0 + ratio1 * ratio1 + ratio2 * ratio2 - static_cast<Real>(1);

	return value;
}

template <typename Real>
bool Mathematics::Ellipsoid3<Real>
		::Contains(const Vector3D& point) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Evaluate(point) <= m_Epsilon;
}

template <typename Real>
const typename Mathematics::Ellipsoid3<Real>::ClassType Mathematics::Ellipsoid3<Real>
	::GetMove(Real t, const Vector3D& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Ellipsoid3{ m_Center + t * velocity, m_Axis[0],m_Axis[1],m_Axis[2],
					   m_Extent[0],m_Extent[1],m_Extent[2], m_Epsilon };
}

template <typename Real>
bool Mathematics
	::Approximate(const Ellipsoid3<Real>& lhs, const Ellipsoid3<Real>& rhs, const Real epsilon)
{
	return Vector2DTools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
		   Vector2DTools<Real>::Approximate(lhs.GetAxis0(), rhs.GetAxis0(), epsilon) &&
		   Vector2DTools<Real>::Approximate(lhs.GetAxis1(), rhs.GetAxis1(), epsilon) &&
		   Vector2DTools<Real>::Approximate(lhs.GetAxis2(), rhs.GetAxis2(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetExtent0(), rhs.GetExtent0(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetExtent1(), rhs.GetExtent1(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetExtent2(), rhs.GetExtent2(), epsilon);
}

template <typename Real>
std::ostream&  Mathematics
	::operator<<(std::ostream& outFile, const Ellipsoid3<Real>& ellipsoid)
{
	outFile << "center=" << ellipsoid.GetCenter() << ",axis0=" << ellipsoid.GetAxis0()
			<< ",axis1=" << ellipsoid.GetAxis1() << ",axis2=" << ellipsoid.GetAxis2()
			<< ",extent0=" << ellipsoid.GetExtent0() << ",extent1=" << ellipsoid.GetExtent1()
			<< ",extent2=" << ellipsoid.GetExtent2();

	return outFile;
}

#endif // MATHEMATICS_OBJECTS3D_ELLIPSOID3_DETAIL_H
