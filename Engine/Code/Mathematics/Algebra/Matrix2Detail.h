// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 13:06)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX2_DETAIL_H

#include "Matrix2.h"
#include "AVector.h"
#include "Vector2D.h"
#include "Vector2DTools.h"
#include "AlgebraTraits.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
 
template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>
	::sm_Zero{ MatrixInitType::Zero };

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>
	::sm_Identity{ MatrixInitType::Identity };

template <typename Real>
Mathematics::Matrix2<Real>
	::Matrix2(MatrixInitType flag) noexcept
	:m_Entry{}
{
	if (flag == MatrixInitType::Identity)
	{
		MakeIdentity();
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>
	::Matrix2(Real member00, Real member01, Real member10, Real member11)
	:m_Entry{ member00, member01, member10, member11 }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>
	::Matrix2(const std::vector<Real>& entry, MatrixMajorFlags majorFlag)
	:m_Entry{}
{
	MATHEMATICS_ASSERTION_0(entry.size() == 4, "数据大小错误！");

	if (majorFlag == MatrixMajorFlags::Row)
	{
		m_Entry(0, 0) = entry[0];
		m_Entry(0, 1) = entry[1];
		m_Entry(1, 0) = entry[2];
		m_Entry(1, 1) = entry[3];
	}
	else
	{
		m_Entry(0, 0) = entry[0];
		m_Entry(0, 1) = entry[2];
		m_Entry(1, 0) = entry[1];
		m_Entry(1, 1) = entry[3];
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>
	::Matrix2(const Vector2D& firstVector, const Vector2D& secondVector, MatrixMajorFlags majorFlag)
	:m_Entry{}
{
	if (majorFlag == MatrixMajorFlags::Row)
	{
		m_Entry(0, 0) = firstVector[0];
		m_Entry(0, 1) = firstVector[1];
		m_Entry(1, 0) = secondVector[0];
		m_Entry(1, 1) = secondVector[1];
	}
	else
	{
		m_Entry(0, 0) = firstVector[0];
		m_Entry(0, 1) = secondVector[0];
		m_Entry(1, 0) = firstVector[1];
		m_Entry(1, 1) = secondVector[1];
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>
	::Matrix2(const std::vector<Vector2D>& vectors, MatrixMajorFlags majorFlag)
	:m_Entry{}
{
	MATHEMATICS_ASSERTION_0(vectors.size() == 2, "数据大小错误！");

	if (majorFlag == MatrixMajorFlags::Row)
	{
		m_Entry(0, 0) = vectors[0][0];
		m_Entry(0, 1) = vectors[0][1];
		m_Entry(1, 0) = vectors[1][0];
		m_Entry(1, 1) = vectors[1][1];
	}
	else
	{
		m_Entry(0, 0) = vectors[0][0];
		m_Entry(0, 1) = vectors[1][0];
		m_Entry(1, 0) = vectors[0][1];
		m_Entry(1, 1) = vectors[1][1];
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>
	::Matrix2(Real member00, Real member11)
	:m_Entry{ member00,Math::GetValue(0),Math::GetValue(0),member11 }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>
	::Matrix2(Real angle)
	:m_Entry{}
{
	MakeRotation(angle);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix2<Real>
	::Matrix2(const Vector2D& firstVector, const Vector2D& secondVector)
	:m_Entry{}
{
	MakeTensorProduct(firstVector, secondVector);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Matrix2<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Matrix2<Real>
	::MakeZero()
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Entry(0, 0) = Math::GetValue(0);
	m_Entry(0, 1) = Math::GetValue(0);
	m_Entry(1, 0) = Math::GetValue(0);
	m_Entry(1, 1) = Math::GetValue(0);
}

template <typename Real>
void Mathematics::Matrix2<Real>
	::MakeIdentity() noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Entry(0, 0) = Math::GetValue(1);
	m_Entry(0, 1) = Math::GetValue(0);
	m_Entry(1, 0) = Math::GetValue(0);
	m_Entry(1, 1) = Math::GetValue(1);
}

template <typename Real>
void Mathematics::Matrix2<Real>
	::MakeDiagonal(Real member00, Real member11)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Entry(0, 0) = member00;
	m_Entry(0, 1) = Math::GetValue(0);
	m_Entry(1, 0) = Math::GetValue(0);
	m_Entry(1, 1) = member11;
}

template <typename Real>
void Mathematics::Matrix2<Real>
	::MakeRotation(Real angle)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Entry(0, 0) = Math::Cos(angle);
	m_Entry(0, 1) = -Math::Sin(angle);
	m_Entry(1, 0) = -m_Entry(0, 1);
	m_Entry(1, 1) = m_Entry(0, 0);
}

template <typename Real>
void Mathematics::Matrix2<Real>
	::MakeTensorProduct(const Vector2D& lhs, const Vector2D& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Entry(0, 0) = lhs[0] * rhs[0];
	m_Entry(0, 1) = lhs[0] * rhs[1];
	m_Entry(1, 0) = lhs[1] * rhs[0];
	m_Entry(1, 1) = lhs[1] * rhs[1];
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Matrix2<Real>(-m_Entry(0, 0), -m_Entry(0, 1), -m_Entry(1, 0), -m_Entry(1, 1));
}

template <typename Real>
const Real* Mathematics::Matrix2<Real>
	::operator[](int row) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= row && row < 2, "索引错误！");

	return m_Entry[row];
}

template <typename Real>
Real* Mathematics::Matrix2<Real>
	::operator[](int row)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= row && row < 2, "索引错误！");

	return m_Entry[row];
}

template <typename Real>
const Real& Mathematics::Matrix2<Real>
	::operator()(int row, int column) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= row && row < 2, "row索引错误！");
	MATHEMATICS_ASSERTION_0(0 <= column && column < 2, "column索引错误！");

	return m_Entry(row, column);
}

template <typename Real>
Real& Mathematics::Matrix2<Real>
	::operator()(int row, int column)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= row && row < 2, "row索引错误！");
	MATHEMATICS_ASSERTION_0(0 <= column && column < 2, "column索引错误！");

	return m_Entry(row, column);
}

template <typename Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>
	::operator+=(const Matrix2& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Entry(0, 0) += rhs.m_Entry(0, 0);
	m_Entry(0, 1) += rhs.m_Entry(0, 1);
	m_Entry(1, 0) += rhs.m_Entry(1, 0);
	m_Entry(1, 1) += rhs.m_Entry(1, 1);

	return *this;
}

template <typename Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>
	::operator-=(const Matrix2& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Entry(0, 0) -= rhs.m_Entry(0, 0);
	m_Entry(0, 1) -= rhs.m_Entry(0, 1);
	m_Entry(1, 0) -= rhs.m_Entry(1, 0);
	m_Entry(1, 1) -= rhs.m_Entry(1, 1);

	return *this;
}

template <typename Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>
	::operator*=(Real scalar)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Entry(0, 0) *= scalar;
	m_Entry(0, 1) *= scalar;
	m_Entry(1, 0) *= scalar;
	m_Entry(1, 1) *= scalar;

	return *this;
}

template <typename Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>
	::operator/=(Real scalar)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if (Math::GetZeroTolerance() < Math::FAbs(scalar))
	{
		m_Entry(0, 0) /= scalar;
		m_Entry(0, 1) /= scalar;
		m_Entry(1, 0) /= scalar;
		m_Entry(1, 1) /= scalar;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "除零错误！");

		m_Entry(0, 0) = Math::sm_MaxReal;
		m_Entry(0, 1) = Math::sm_MaxReal;
		m_Entry(1, 0) = Math::sm_MaxReal;
		m_Entry(1, 1) = Math::sm_MaxReal;
	}

	return *this;
}

template <typename Real>
Real Mathematics::Matrix2<Real>
	::QuadraticForm(const Vector2D& lhs, const Vector2D& rhs) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Vector2DTools::DotProduct(lhs, (*this) * rhs);
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>
	::Transpose() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Matrix2<Real>{ m_Entry(0, 0), m_Entry(1, 0), m_Entry(0, 1), m_Entry(1, 1) };
}

template <typename Real>
Mathematics::Matrix2<Real>& Mathematics::Matrix2<Real>
	::operator*=(const Matrix2& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	*this = *this * rhs;

	return *this;
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>
	::Inverse(const Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto det = Determinant();

	if (epsilon < Math::FAbs(det))
	{
		// 由于除零错误的epsilon和这里的epsilon不同，改由先除后乘。
		return Adjoint() * (1 / det);
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "该矩阵不存在逆矩阵！");

		return sm_Zero;
	}
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Matrix2<Real>
	::Adjoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Matrix2<Real>{m_Entry(1, 1), -m_Entry(0, 1), -m_Entry(1, 0), m_Entry(0, 0)};
}

template <typename Real>
Real Mathematics::Matrix2<Real>
	::Determinant() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Entry(0, 0) * m_Entry(1, 1) - m_Entry(0, 1) * m_Entry(1, 0);
}

template <typename Real>
Real Mathematics::Matrix2<Real>
	::ExtractAngle() const
{
	// 矩阵必须是旋转矩阵！
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	MATHEMATICS_ASSERTION_1(Math::FAbs(m_Entry(0, 0) - m_Entry(1, 1)) <= Math::GetZeroTolerance() &&
							Math::FAbs(m_Entry(0, 1) + m_Entry(1, 0)) <= Math::GetZeroTolerance() &&
							Math::FAbs(m_Entry(0, 1) * (-m_Entry(1, 0)) + m_Entry(0, 0) * m_Entry(1, 1) - Math::GetValue(1)) <= Math::GetZeroTolerance(),
							"该矩阵不是旋转矩阵！");

	return Math::ATan2(m_Entry(1, 0), m_Entry(0, 0));
}

template <typename Real>
void Mathematics::Matrix2<Real>
	::Orthonormalize()
{
	// 算法采用Gram-Schmidt正交。
	// 如果'this'矩阵为M = [m0|m1]，然后输出正交矩阵Q = [q0|q1]
	//
	//   q0 = m0 / |m0|
	//   q1 = (m1 - (q0 * m1)q0) / |m1 - (q0 * m1)q0|
	// 其中|V|表示向量V的长度和A * B表示向量A和B的点积

	// 矩阵必须是旋转矩阵！
	MATHEMATICS_ASSERTION_1(Math::FAbs(m_Entry(0, 0) - m_Entry(1, 1)) <= Math::GetZeroTolerance() &&
							Math::FAbs(m_Entry(0, 1) + m_Entry(1, 0)) <= Math::GetZeroTolerance() &&
							Math::FAbs(m_Entry(0, 1) * (-m_Entry(1, 0)) + m_Entry(0, 0) * m_Entry(1, 1) - Math::GetValue(1)) <= Math::GetZeroTolerance(),
							"该矩阵不是旋转矩阵！");

	MATHEMATICS_CLASS_IS_VALID_9;

	// 计算 q0.
	auto invLength = Math::InvSqrt(m_Entry(0, 0) * m_Entry(0, 0) + m_Entry(1, 0) * m_Entry(1, 0));

	m_Entry(0, 0) *= invLength;
	m_Entry(1, 0) *= invLength;

	// 计算 q1.
	auto dot = m_Entry(0, 0) * m_Entry(0, 1) + m_Entry(1, 0) * m_Entry(1, 1);

	m_Entry(0, 1) -= dot * m_Entry(0, 0);
	m_Entry(1, 1) -= dot * m_Entry(1, 0);

	invLength = Math::InvSqrt(m_Entry(0, 1) * m_Entry(0, 1) + m_Entry(1, 1) * m_Entry(1, 1));

	m_Entry(0, 1) *= invLength;
	m_Entry(1, 1) *= invLength;
}

template <typename Real>
typename const Mathematics::Matrix2<Real>::Matrix2EigenDecomposition Mathematics::Matrix2<Real>
	::EigenDecomposition(const Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_1(Math::FAbs(m_Entry(0, 1) - m_Entry(1, 0)) <= epsilon, "矩阵必须是对称矩阵。");

	auto sum = Math::FAbs(m_Entry(0, 0)) + Math::FAbs(m_Entry(1, 1));

	if (Math::FAbs(Math::FAbs(m_Entry(0, 1)) + sum - sum) < epsilon)
	{
		// 矩阵 M 是对角矩阵（数字四舍五入）。
		Matrix2<Real> rotation{ MatrixInitType::Identity };
		Matrix2<Real> diagonal{ m_Entry(0,0),m_Entry(1,1) };

		return Matrix2EigenDecomposition{ rotation, diagonal, epsilon };
	}

	auto trace = m_Entry(0, 0) + m_Entry(1, 1);
	auto difference = m_Entry(0, 0) - m_Entry(1, 1);
	auto discr = Math::Sqrt(difference * difference + (static_cast<Real>(4) * m_Entry(0, 1) * m_Entry(0, 1)));

	auto eigenvalue0 = static_cast<Real>(0.5) * (trace - discr);
	auto eigenvalue1 = static_cast<Real>(0.5) * (trace + discr);
	Matrix2<Real> diagonal{ eigenvalue0, eigenvalue1 };

	Real cosValue{ };
	Real sinValue{ };
	if (Math::GetValue(0) <= difference)
	{
		cosValue = m_Entry(0, 1);
		sinValue = eigenvalue0 - m_Entry(0, 0);
	}
	else
	{
		cosValue = eigenvalue0 - m_Entry(1, 1);
		sinValue = m_Entry(0, 1);
	}

	auto invLength = Math::InvSqrt(cosValue * cosValue + sinValue * sinValue);
	cosValue *= invLength;
	sinValue *= invLength;

	Matrix2<Real> rotation{ cosValue,-sinValue,sinValue,cosValue };

	return Matrix2EigenDecomposition{ rotation, diagonal, epsilon };
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics
	::operator* (const Matrix2<Real>& lhs, const Matrix2<Real>& rhs)
{
	// A * B
	return Matrix2<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(0, 1) * rhs(1, 0),
						  lhs(0, 0) * rhs(0, 1) + lhs(0, 1) * rhs(1, 1),
						  lhs(1, 0) * rhs(0, 0) + lhs(1, 1) * rhs(1, 0),
						  lhs(1, 0) * rhs(0, 1) + lhs(1, 1) * rhs(1, 1) };
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics
	::operator* (const Matrix2<Real>& matrix, const Vector2D<Real>& vector)
{
	return Vector2D<Real>{ matrix(0, 0) * vector[0] + matrix(0, 1) * vector[1], matrix(1, 0) * vector[0] + matrix(1, 1) * vector[1] };
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics
	::operator* (const Vector2D<Real>& vector, const Matrix2<Real>& matrix)
{
	return Vector2D<Real>{ vector[0] * matrix(0, 0) + vector[1] * matrix(1, 0), vector[0] * matrix(0, 1) + vector[1] * matrix(1, 1) };
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics
	::TransposeTimes(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs)
{
	// lhs^T * rhs
	return Matrix2<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(1, 0) * rhs(1, 0),
						  lhs(0, 0) * rhs(0, 1) + lhs(1, 0) * rhs(1, 1),
						  lhs(0, 1) * rhs(0, 0) + lhs(1, 1) * rhs(1, 0),
						  lhs(0, 1) * rhs(0, 1) + lhs(1, 1) * rhs(1, 1) };
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics
	::TimesTranspose(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs)
{
	// lhs * rhs^T
	return Matrix2<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(0, 1) * rhs(0, 1),
						  lhs(0, 0) * rhs(1, 0) + lhs(0, 1) * rhs(1, 1),
						  lhs(1, 0) * rhs(0, 0) + lhs(1, 1) * rhs(0, 1),
						  lhs(1, 0) * rhs(1, 0) + lhs(1, 1) * rhs(1, 1) };
}

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics
	::TransposeTimesTranspose(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs)
{
	// lhs^T * rhs^T

	return Matrix2<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(1, 0) * rhs(0, 1),
						  lhs(0, 0) * rhs(1, 0) + lhs(1, 0) * rhs(1, 1),
						  lhs(0, 1) * rhs(0, 0) + lhs(1, 1) * rhs(0, 1),
						  lhs(0, 1) * rhs(1, 0) + lhs(1, 1) * rhs(1, 1) };
}

template <typename Real>
bool Mathematics
	::Approximate(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs, const Real epsilon)
{
	return Math<Real>::FAbs(lhs(0, 0) - rhs(0, 0)) <= epsilon &&
		   Math<Real>::FAbs(lhs(0, 1) - rhs(0, 1)) <= epsilon &&
		   Math<Real>::FAbs(lhs(1, 0) - rhs(1, 0)) <= epsilon &&
		   Math<Real>::FAbs(lhs(1, 1) - rhs(1, 1)) <= epsilon;
}

template <typename Real>
bool Mathematics
	::Approximate(const Matrix2<Real>& lhs, const Matrix2<Real>& rhs)
{
	return Approximate(lhs, rhs, Math::GetZeroTolerance());
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_ALGEBRA_MATRIX2_DETAIL_H