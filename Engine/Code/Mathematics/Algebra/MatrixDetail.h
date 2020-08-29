// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 13:59)

#ifndef MATHEMATICS_ALGEBRA_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_MATRIX_DETAIL_H
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/ClassInvariant/Noexcept.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26434)
#include SYSTEM_WARNING_DISABLE(26492)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26426) 
#include SYSTEM_WARNING_DISABLE(26456)
#include SYSTEM_WARNING_DISABLE(26440)
#include "Matrix.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <iostream>

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATRIX_DETAIL)

#include "Vector4D.h"
#include "Matrix3.h"
#include "APoint.h"
#include "AVector.h"
#include "AlgebraTraits.h"



template <typename Real>
const Mathematics::Matrix<Real> Mathematics::Matrix<Real>
	::sm_Zero{ MatrixTypeFlags::Zero };

template <typename Real>
const Mathematics::Matrix<Real> Mathematics::Matrix<Real>
	::sm_Identity{ MatrixTypeFlags::Identity };

template <typename Real>
Mathematics::Matrix<Real>
	::Matrix(const Matrix& rhs) noexcept
	:m_Entry{}
{
	memcpy(m_Entry, rhs.m_Entry, 16 * sizeof(Real));

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>
	::Matrix(const Matrix3& rhs)
	:m_Entry{}
{
	m_Entry[0] = rhs(0, 0);
	m_Entry[1] = rhs(0, 1);
	m_Entry[2] = rhs(0, 2);
	m_Entry[3] = Math::GetValue(0);
	m_Entry[4] = rhs(1, 0);
	m_Entry[5] = rhs(1, 1);
	m_Entry[6] = rhs(1, 2);
	m_Entry[7] = Math::GetValue(0);
	m_Entry[8] = rhs(2, 0);
	m_Entry[9] = rhs(2, 1);
	m_Entry[10] = rhs(2, 2);
	m_Entry[11] = Math::GetValue(0);
	m_Entry[12] = Math::GetValue(0);
	m_Entry[13] = Math::GetValue(0);
	m_Entry[14] = Math::GetValue(0);
	m_Entry[15] = Math::GetValue(1);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>
	::Matrix(MatrixTypeFlags flag) noexcept
	:m_Entry{}
{
	if (flag == MatrixTypeFlags::Identity)
	{
		MakeIdentity();
	}
	else
	{
		MakeZero();
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>
	::Matrix(Real member00, Real member01, Real member02, Real member03,
			 Real member10, Real member11, Real member12, Real member13,
			 Real member20, Real member21, Real member22, Real member23,
			 Real member30, Real member31, Real member32, Real member33) noexcept
{
	m_Entry[0] = member00;
	m_Entry[1] = member01;
	m_Entry[2] = member02;
	m_Entry[3] = member03;
	m_Entry[4] = member10;
	m_Entry[5] = member11;
	m_Entry[6] = member12;
	m_Entry[7] = member13;
	m_Entry[8] = member20;
	m_Entry[9] = member21;
	m_Entry[10] = member22;
	m_Entry[11] = member23;
	m_Entry[12] = member30;
	m_Entry[13] = member31;
	m_Entry[14] = member32;
	m_Entry[15] = member33;

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>
	::Matrix(const std::vector<Real>& entry, MatrixMajorFlags majorFlag)
{
	MATHEMATICS_ASSERTION_0(entry.size() == 16, "数据大小错误！");

	if (majorFlag == MatrixMajorFlags::Row)
	{
		m_Entry[0] = entry[0];
		m_Entry[1] = entry[1];
		m_Entry[2] = entry[2];
		m_Entry[3] = entry[3];
		m_Entry[4] = entry[4];
		m_Entry[5] = entry[5];
		m_Entry[6] = entry[6];
		m_Entry[7] = entry[7];
		m_Entry[8] = entry[8];
		m_Entry[9] = entry[9];
		m_Entry[10] = entry[10];
		m_Entry[11] = entry[11];
		m_Entry[12] = entry[12];
		m_Entry[13] = entry[13];
		m_Entry[14] = entry[14];
		m_Entry[15] = entry[15];
	}
	else
	{
		m_Entry[0] = entry[0];
		m_Entry[1] = entry[4];
		m_Entry[2] = entry[8];
		m_Entry[3] = entry[12];
		m_Entry[4] = entry[1];
		m_Entry[5] = entry[5];
		m_Entry[6] = entry[9];
		m_Entry[7] = entry[13];
		m_Entry[8] = entry[2];
		m_Entry[9] = entry[6];
		m_Entry[10] = entry[10];
		m_Entry[11] = entry[14];
		m_Entry[12] = entry[3];
		m_Entry[13] = entry[7];
		m_Entry[14] = entry[11];
		m_Entry[15] = entry[15];
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>
	::Matrix(const Vector4D& firstVector, const Vector4D& secondVector, const Vector4D& thirdVector, const Vector4D& fourthVector, MatrixMajorFlags majorFlag)
{
	if (majorFlag == MatrixMajorFlags::Row)
	{
		m_Entry[0] = firstVector[0];
		m_Entry[1] = firstVector[1];
		m_Entry[2] = firstVector[2];
		m_Entry[3] = firstVector[3];
		m_Entry[4] = secondVector[0];
		m_Entry[5] = secondVector[1];
		m_Entry[6] = secondVector[2];
		m_Entry[7] = secondVector[3];
		m_Entry[8] = thirdVector[0];
		m_Entry[9] = thirdVector[1];
		m_Entry[10] = thirdVector[2];
		m_Entry[11] = thirdVector[3];
		m_Entry[12] = fourthVector[0];
		m_Entry[13] = fourthVector[1];
		m_Entry[14] = fourthVector[2];
		m_Entry[15] = fourthVector[3];
	}
	else
	{
		m_Entry[0] = firstVector[0];
		m_Entry[1] = secondVector[0];
		m_Entry[2] = thirdVector[0];
		m_Entry[3] = fourthVector[0];
		m_Entry[4] = firstVector[1];
		m_Entry[5] = secondVector[1];
		m_Entry[6] = thirdVector[1];
		m_Entry[7] = fourthVector[1];
		m_Entry[8] = firstVector[2];
		m_Entry[9] = secondVector[2];
		m_Entry[10] = thirdVector[2];
		m_Entry[11] = fourthVector[2];
		m_Entry[12] = firstVector[3];
		m_Entry[13] = secondVector[3];
		m_Entry[14] = thirdVector[3];
		m_Entry[15] = fourthVector[3];
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>
	::Matrix(const AVector& firstVector, const AVector& secondVector, const AVector& thirdVector, const APoint& point, MatrixMajorFlags majorFlag)
{
	if (majorFlag == MatrixMajorFlags::Row)
	{
		m_Entry[0] = firstVector[0];
		m_Entry[1] = firstVector[1];
		m_Entry[2] = firstVector[2];
		m_Entry[3] = Math::GetValue(0);
		m_Entry[4] = secondVector[0];
		m_Entry[5] = secondVector[1];
		m_Entry[6] = secondVector[2];
		m_Entry[7] = Math::GetValue(0);
		m_Entry[8] = thirdVector[0];
		m_Entry[9] = thirdVector[1];
		m_Entry[10] = thirdVector[2];
		m_Entry[11] = Math::GetValue(0);
		m_Entry[12] = point[0];
		m_Entry[13] = point[1];
		m_Entry[14] = point[2];
		m_Entry[15] = Math::GetValue(1);
	}
	else
	{
		m_Entry[0] = firstVector[0];
		m_Entry[1] = secondVector[0];
		m_Entry[2] = thirdVector[0];
		m_Entry[3] = point[0];
		m_Entry[4] = firstVector[1];
		m_Entry[5] = secondVector[1];
		m_Entry[6] = thirdVector[1];
		m_Entry[7] = point[1];
		m_Entry[8] = firstVector[2];
		m_Entry[9] = secondVector[2];
		m_Entry[10] = thirdVector[2];
		m_Entry[11] = point[2];
		m_Entry[12] = Math::GetValue(0);
		m_Entry[13] = Math::GetValue(0);
		m_Entry[14] = Math::GetValue(0);
		m_Entry[15] = Math::GetValue(1);
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>
	::Matrix(Real member00, Real member11, Real member22) noexcept
	:m_Entry{}
{
	MakeDiagonal(member00, member11, member22);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>
	::Matrix(const AVector& axis, Real angle)
	:m_Entry{}
{
	MakeRotation(axis, angle);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>
	::operator=(const Matrix& rhs) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	memcpy(m_Entry, rhs.m_Entry, 16 * sizeof(Real));

	return *this;
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>::operator=(Matrix&& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    memcpy(m_Entry, rhs.m_Entry, 16 * sizeof(Real));

    return *this;
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>
	::operator=(const Matrix3& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Entry[0] = rhs(0, 0);
	m_Entry[1] = rhs(0, 1);
	m_Entry[2] = rhs(0, 2);
	m_Entry[3] = Math::GetValue(0);
	m_Entry[4] = rhs(1, 0);
	m_Entry[5] = rhs(1, 1);
	m_Entry[6] = rhs(1, 2);
	m_Entry[7] = Math::GetValue(0);
	m_Entry[8] = rhs(2, 0);
	m_Entry[9] = rhs(2, 1);
	m_Entry[10] = rhs(2, 2);
	m_Entry[11] = Math::GetValue(0);
	m_Entry[12] = Math::GetValue(0);
	m_Entry[13] = Math::GetValue(0);
	m_Entry[14] = Math::GetValue(0);
	m_Entry[15] = Math::GetValue(1);

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Matrix<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Matrix<Real>::Matrix3
Mathematics::Matrix<Real>
	::GetMatrix3() const noexcept
{
	CLASS_IS_VALID;

	return Matrix3{ m_Entry[0], m_Entry[1], m_Entry[2],m_Entry[4], m_Entry[5], m_Entry[6],m_Entry[8], m_Entry[9], m_Entry[10] };
}

template <typename Real>
const Real* Mathematics::Matrix<Real>
	::operator[](int row) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= row && row < 4, "索引错误！");

	return &m_Entry[4 * row];
}

template <typename Real>
Real* Mathematics::Matrix<Real>
	::operator[](int row)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= row && row < 4, "索引错误！");

	return const_cast<Real*>(static_cast<const ClassType&>(*this)[row]);
}

template <typename Real>
const Real& Mathematics::Matrix<Real>
	::operator()(int row, int column) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(0 <= row && row < 4 && 0 <= column && column < 4, "索引错误！");

	return m_Entry[column + 4 * row];
}

template <typename Real>
Real& Mathematics::Matrix<Real>
	::operator()(int row, int column)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= row && row < 4 && 0 <= column && column < 4, "索引错误！");

	return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));
}

template <typename Real>
void Mathematics::Matrix<Real>
	::SetRow(int row, const HomogeneousPoint& point)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if (0 <= row && row < 4)
	{
		m_Entry[4 * row] = point[0];
		m_Entry[4 * row + 1] = point[1];
		m_Entry[4 * row + 2] = point[2];
		m_Entry[4 * row + 3] = point[3];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
	}
}

template <typename Real>
typename const Mathematics::Matrix<Real>::HomogeneousPoint Mathematics::Matrix<Real>
	::GetRow(int row) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (0 <= row && row < 4)
	{
		return HomogeneousPoint{ m_Entry[4 * row],m_Entry[4 * row + 1],m_Entry[4 * row + 2],m_Entry[4 * row + 3] };
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
	}
}

template <typename Real>
void Mathematics::Matrix<Real>
	::SetColumn(int column, const HomogeneousPoint& point)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if (0 <= column && column < 4)
	{
		m_Entry[column] = point[0];
		m_Entry[4 + column] = point[1];
		m_Entry[8 + column] = point[2];
		m_Entry[12 + column] = point[3];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"));
	}
}

template <typename Real>
typename const Mathematics::Matrix<Real>::HomogeneousPoint Mathematics::Matrix<Real>
	::GetColumn(int column) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (0 <= column && column < 4)
	{
		return HomogeneousPoint{ m_Entry[column],m_Entry[4 + column], m_Entry[8 + column],m_Entry[12 + column] };
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"));
	}
}

template <typename Real>
const std::vector<Real> Mathematics::Matrix<Real>
	::GetColumnMajor() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	std::vector<Real> columnMatrix{ m_Entry[0] ,m_Entry[4] ,m_Entry[8],m_Entry[12],
									m_Entry[1] ,m_Entry[5] ,m_Entry[9] ,m_Entry[13] ,
									m_Entry[2] ,m_Entry[6] ,m_Entry[10] ,m_Entry[14] ,
									m_Entry[3] ,m_Entry[7] ,m_Entry[11] ,m_Entry[15] };

	MATHEMATICS_ASSERTION_0(columnMatrix.size() == 16, "数据大小错误！");

	return columnMatrix;
}

template <typename Real>
const  Mathematics::Matrix<Real> Mathematics::Matrix<Real>
	::operator-() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Matrix{ -m_Entry[0],-m_Entry[1],-m_Entry[2],-m_Entry[3],
				   -m_Entry[4],-m_Entry[5],-m_Entry[6],-m_Entry[7],
				   -m_Entry[8],-m_Entry[9],-m_Entry[10],-m_Entry[11],
				   -m_Entry[12],-m_Entry[13],-m_Entry[14],-m_Entry[15] };
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>::operator+=(const Matrix& rhs) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < 16; ++i)
	{
		m_Entry[i] += rhs.m_Entry[i];
	}

	return *this;
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>::operator-=(const Matrix& rhs) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < 16; ++i)
	{
		m_Entry[i] -= rhs.m_Entry[i];
	}
	return *this;
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>::operator*=(Real scalar) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < 16; ++i)
	{
		m_Entry[i] *= scalar;
	}

	return *this;
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>::operator/=(Real scalar) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if (Math::GetZeroTolerance() < Math::FAbs(scalar))
	{
		for (auto i = 0; i < 16; ++i)
		{
			m_Entry[i] /= scalar;
		}
	}
	else
	{
		for (auto i = 0; i < 16; ++i)
		{
			m_Entry[i] = Math::sm_MaxReal;
		}
	}

	return *this;
}

template <typename Real>
void Mathematics::Matrix<Real>
	::MakeZero() noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	memset(m_Entry, 0, 16 * sizeof(Real));
}

template <typename Real>
void Mathematics::Matrix<Real>
	::MakeIdentity() noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Entry[0] = Math::GetValue(1);
	m_Entry[1] = Math::GetValue(0);
	m_Entry[2] = Math::GetValue(0);
	m_Entry[3] = Math::GetValue(0);
	m_Entry[4] = Math::GetValue(0);
	m_Entry[5] = Math::GetValue(1);
	m_Entry[6] = Math::GetValue(0);
	m_Entry[7] = Math::GetValue(0);
	m_Entry[8] = Math::GetValue(0);
	m_Entry[9] = Math::GetValue(0);
	m_Entry[10] = Math::GetValue(1);
	m_Entry[11] = Math::GetValue(0);
	m_Entry[12] = Math::GetValue(0);
	m_Entry[13] = Math::GetValue(0);
	m_Entry[14] = Math::GetValue(0);
	m_Entry[15] = Math::GetValue(1);
}

template <typename Real>
void Mathematics::Matrix<Real>::MakeDiagonal(Real member00, Real member11, Real member22) noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Entry[0] = member00;
	m_Entry[1] = Math::GetValue(0);
	m_Entry[2] = Math::GetValue(0);
	m_Entry[3] = Math::GetValue(0);
	m_Entry[4] = Math::GetValue(0);
	m_Entry[5] = member11;
	m_Entry[6] = Math::GetValue(0);
	m_Entry[7] = Math::GetValue(0);
	m_Entry[8] = Math::GetValue(0);
	m_Entry[9] = Math::GetValue(0);
	m_Entry[10] = member22;
	m_Entry[11] = Math::GetValue(0);
	m_Entry[12] = Math::GetValue(0);
	m_Entry[13] = Math::GetValue(0);
	m_Entry[14] = Math::GetValue(0);
	m_Entry[15] = Math::GetValue(1);
}

template <typename Real>
void Mathematics::Matrix<Real>
	::MakeRotation(const AVector& axis, Real angle)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto cosValue = Math::Cos(angle);
	auto sinValue = Math::Sin(angle);
	auto oneMinusCos = Math::GetValue(1) - cosValue;

	auto xAxisSquare = axis[0] * axis[0];
	auto yAxisSquare = axis[1] * axis[1];
	auto zAxisSquare = axis[2] * axis[2];

	auto xAxisSquareMultipliedOneMinusCos = xAxisSquare * oneMinusCos;
	auto yAxisSquareMultipliedOneMinusCos = yAxisSquare * oneMinusCos;
	auto zAxisSquareMultipliedOneMinusCos = zAxisSquare * oneMinusCos;

	auto xym = axis[0] * axis[1] * oneMinusCos;
	auto xzm = axis[0] * axis[2] * oneMinusCos;
	auto yzm = axis[1] * axis[2] * oneMinusCos;

	auto xSin = axis[0] * sinValue;
	auto ySin = axis[1] * sinValue;
	auto zSin = axis[2] * sinValue;

	m_Entry[0] = xAxisSquareMultipliedOneMinusCos + cosValue;
	m_Entry[1] = xym - zSin;
	m_Entry[2] = xzm + ySin;
	m_Entry[3] = Math::GetValue(0);
	m_Entry[4] = xym + zSin;
	m_Entry[5] = yAxisSquareMultipliedOneMinusCos + cosValue;
	m_Entry[6] = yzm - xSin;
	m_Entry[7] = Math::GetValue(0);
	m_Entry[8] = xzm - ySin;
	m_Entry[9] = yzm + xSin;
	m_Entry[10] = zAxisSquareMultipliedOneMinusCos + cosValue;
	m_Entry[11] = Math::GetValue(0);
	m_Entry[12] = Math::GetValue(0);
	m_Entry[13] = Math::GetValue(0);
	m_Entry[14] = Math::GetValue(0);
	m_Entry[15] = Math::GetValue(1);
}

template <typename Real>
const Mathematics::Matrix<Real> Mathematics::Matrix<Real>::Transpose() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Matrix{ m_Entry[0],m_Entry[4],m_Entry[8],m_Entry[12],
				   m_Entry[1],m_Entry[5],m_Entry[9],m_Entry[13],
				   m_Entry[2],m_Entry[6],m_Entry[10],m_Entry[14],
				   m_Entry[3],m_Entry[7],m_Entry[11],m_Entry[15] };
}

template <typename Real>
const Mathematics::Matrix<Real> Mathematics::Matrix<Real>::Inverse(const Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	CoreTools::DoNothing();

	auto a0 = m_Entry[0] * m_Entry[5] - m_Entry[1] * m_Entry[4];
	auto a1 = m_Entry[0] * m_Entry[6] - m_Entry[2] * m_Entry[4];
	auto a2 = m_Entry[0] * m_Entry[7] - m_Entry[3] * m_Entry[4];
	auto a3 = m_Entry[1] * m_Entry[6] - m_Entry[2] * m_Entry[5];
	auto a4 = m_Entry[1] * m_Entry[7] - m_Entry[3] * m_Entry[5];
	auto a5 = m_Entry[2] * m_Entry[7] - m_Entry[3] * m_Entry[6];
	auto b0 = m_Entry[8] * m_Entry[13] - m_Entry[9] * m_Entry[12];
	auto b1 = m_Entry[8] * m_Entry[14] - m_Entry[10] * m_Entry[12];
	auto b2 = m_Entry[8] * m_Entry[15] - m_Entry[11] * m_Entry[12];
	auto b3 = m_Entry[9] * m_Entry[14] - m_Entry[10] * m_Entry[13];
	auto b4 = m_Entry[9] * m_Entry[15] - m_Entry[11] * m_Entry[13];
	auto b5 = m_Entry[10] * m_Entry[15] - m_Entry[11] * m_Entry[14];

	auto det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
	if (epsilon < Math::FAbs(det))
	{
		Matrix adjoint{ +m_Entry[5] * b5 - m_Entry[6] * b4 + m_Entry[7] * b3,
						-m_Entry[1] * b5 + m_Entry[2] * b4 - m_Entry[3] * b3,
						+m_Entry[13] * a5 - m_Entry[14] * a4 + m_Entry[15] * a3,
						-m_Entry[9] * a5 + m_Entry[10] * a4 - m_Entry[11] * a3,
						-m_Entry[4] * b5 + m_Entry[6] * b2 - m_Entry[7] * b1,
						+m_Entry[0] * b5 - m_Entry[2] * b2 + m_Entry[3] * b1,
						-m_Entry[12] * a5 + m_Entry[14] * a2 - m_Entry[15] * a1,
						+m_Entry[8] * a5 - m_Entry[10] * a2 + m_Entry[11] * a1,
						+m_Entry[4] * b4 - m_Entry[5] * b2 + m_Entry[7] * b0,
						-m_Entry[0] * b4 + m_Entry[1] * b2 - m_Entry[3] * b0,
						+m_Entry[12] * a4 - m_Entry[13] * a2 + m_Entry[15] * a0,
						-m_Entry[8] * a4 + m_Entry[9] * a2 - m_Entry[11] * a0,
						-m_Entry[4] * b3 + m_Entry[5] * b1 - m_Entry[6] * b0,
						+m_Entry[0] * b3 - m_Entry[1] * b1 + m_Entry[2] * b0,
						-m_Entry[12] * a3 + m_Entry[13] * a1 - m_Entry[14] * a0,
						+m_Entry[8] * a3 - m_Entry[9] * a1 + m_Entry[10] * a0 };

		adjoint /= det;

		return adjoint;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "该矩阵不存在逆矩阵！");

		return sm_Zero;
	}
}

template <typename Real>
const Mathematics::Matrix<Real> Mathematics::Matrix<Real>
	::Invert3x3(const Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	// 计算M (3x3)的伴随矩阵。
	Matrix adjoint{ (*this)(1,1) * (*this)(2,2) - (*this)(1,2) * (*this)(2,1),
					(*this)(0,2) * (*this)(2,1) - (*this)(0,1) * (*this)(2,2),
					(*this)(0,1) * (*this)(1,2) - (*this)(0,2) * (*this)(1,1),
					(*this)(0,3),
					(*this)(1,2) * (*this)(2,0) - (*this)(1,0) * (*this)(2,2),
					(*this)(0,0) * (*this)(2,2) - (*this)(0,2) * (*this)(2,0),
					(*this)(0,2) * (*this)(1,0) - (*this)(0,0) * (*this)(1,2),
					(*this)(1,3),
					(*this)(1,0) * (*this)(2,1) - (*this)(1,1) * (*this)(2,0),
					(*this)(0,1) * (*this)(2,0) - (*this)(0,0) * (*this)(2,1),
					(*this)(0,0) * (*this)(1,1) - (*this)(0,1) * (*this)(1,0),
					(*this)(2,3),
					(*this)(3,0),
					(*this)(3,1),
					(*this)(3,2),
					(*this)(3,3) };

	// 计算M的行列式。
	auto det = (*this)(0, 0) * adjoint(0, 0) + (*this)(0, 1) * adjoint(1, 0) + (*this)(0, 2) * adjoint(2, 0);

	if (epsilon < Math::FAbs(det))
	{
		// inverse(M) = adjoint(M) / determinant(M).
		adjoint(0, 0) /= det;
		adjoint(0, 1) /= det;
		adjoint(0, 2) /= det;
		adjoint(1, 0) /= det;
		adjoint(1, 1) /= det;
		adjoint(1, 2) /= det;
		adjoint(2, 0) /= det;
		adjoint(2, 1) /= det;
		adjoint(2, 2) /= det;

		return adjoint;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "该矩阵不存在逆矩阵！");

		return sm_Zero;
	}
}

template <typename Real>
const Mathematics::Matrix<Real> Mathematics::Matrix<Real>::Adjoint() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto a0 = m_Entry[0] * m_Entry[5] - m_Entry[1] * m_Entry[4];
	auto a1 = m_Entry[0] * m_Entry[6] - m_Entry[2] * m_Entry[4];
	auto a2 = m_Entry[0] * m_Entry[7] - m_Entry[3] * m_Entry[4];
	auto a3 = m_Entry[1] * m_Entry[6] - m_Entry[2] * m_Entry[5];
	auto a4 = m_Entry[1] * m_Entry[7] - m_Entry[3] * m_Entry[5];
	auto a5 = m_Entry[2] * m_Entry[7] - m_Entry[3] * m_Entry[6];
	auto b0 = m_Entry[8] * m_Entry[13] - m_Entry[9] * m_Entry[12];
	auto b1 = m_Entry[8] * m_Entry[14] - m_Entry[10] * m_Entry[12];
	auto b2 = m_Entry[8] * m_Entry[15] - m_Entry[11] * m_Entry[12];
	auto b3 = m_Entry[9] * m_Entry[14] - m_Entry[10] * m_Entry[13];
	auto b4 = m_Entry[9] * m_Entry[15] - m_Entry[11] * m_Entry[13];
	auto b5 = m_Entry[10] * m_Entry[15] - m_Entry[11] * m_Entry[14];

	return Matrix{ +m_Entry[5] * b5 - m_Entry[6] * b4 + m_Entry[7] * b3,
				   -m_Entry[1] * b5 + m_Entry[2] * b4 - m_Entry[3] * b3,
				   +m_Entry[13] * a5 - m_Entry[14] * a4 + m_Entry[15] * a3,
				   -m_Entry[9] * a5 + m_Entry[10] * a4 - m_Entry[11] * a3,
				   -m_Entry[4] * b5 + m_Entry[6] * b2 - m_Entry[7] * b1,
				   +m_Entry[0] * b5 - m_Entry[2] * b2 + m_Entry[3] * b1,
				   -m_Entry[12] * a5 + m_Entry[14] * a2 - m_Entry[15] * a1,
				   +m_Entry[8] * a5 - m_Entry[10] * a2 + m_Entry[11] * a1,
				   +m_Entry[4] * b4 - m_Entry[5] * b2 + m_Entry[7] * b0,
				   -m_Entry[0] * b4 + m_Entry[1] * b2 - m_Entry[3] * b0,
				   +m_Entry[12] * a4 - m_Entry[13] * a2 + m_Entry[15] * a0,
				   -m_Entry[8] * a4 + m_Entry[9] * a2 - m_Entry[11] * a0,
				   -m_Entry[4] * b3 + m_Entry[5] * b1 - m_Entry[6] * b0,
				   +m_Entry[0] * b3 - m_Entry[1] * b1 + m_Entry[2] * b0,
				   -m_Entry[12] * a3 + m_Entry[13] * a1 - m_Entry[14] * a0,
				   +m_Entry[8] * a3 - m_Entry[9] * a1 + m_Entry[10] * a0 };
}

template <typename Real>
Real Mathematics::Matrix<Real>::Determinant() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto a0 = m_Entry[0] * m_Entry[5] - m_Entry[1] * m_Entry[4];
	auto a1 = m_Entry[0] * m_Entry[6] - m_Entry[2] * m_Entry[4];
	auto a2 = m_Entry[0] * m_Entry[7] - m_Entry[3] * m_Entry[4];
	auto a3 = m_Entry[1] * m_Entry[6] - m_Entry[2] * m_Entry[5];
	auto a4 = m_Entry[1] * m_Entry[7] - m_Entry[3] * m_Entry[5];
	auto a5 = m_Entry[2] * m_Entry[7] - m_Entry[3] * m_Entry[6];
	auto b0 = m_Entry[8] * m_Entry[13] - m_Entry[9] * m_Entry[12];
	auto b1 = m_Entry[8] * m_Entry[14] - m_Entry[10] * m_Entry[12];
	auto b2 = m_Entry[8] * m_Entry[15] - m_Entry[11] * m_Entry[12];
	auto b3 = m_Entry[9] * m_Entry[14] - m_Entry[10] * m_Entry[13];
	auto b4 = m_Entry[9] * m_Entry[15] - m_Entry[11] * m_Entry[13];
	auto b5 = m_Entry[10] * m_Entry[15] - m_Entry[11] * m_Entry[14];

	auto det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

	return det;
}

template <typename Real>
Mathematics::Matrix<Real>& Mathematics::Matrix<Real>
	::operator*=(const Matrix& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	*this = *this * rhs;

	return *this;
}

template <typename Real>
const Mathematics::Matrix<Real> Mathematics::Matrix<Real>
	::TimesDiagonal(const APoint& diag) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Matrix{ m_Entry[0] * diag[0], m_Entry[1] * diag[1],
				   m_Entry[2] * diag[2], m_Entry[3],
				   m_Entry[4] * diag[0], m_Entry[5] * diag[1],
				   m_Entry[6] * diag[2], m_Entry[7],
				   m_Entry[8] * diag[0], m_Entry[9] * diag[1],
				   m_Entry[10] * diag[2],m_Entry[11],
				   m_Entry[12] * diag[0],m_Entry[13] * diag[1],
				   m_Entry[14] * diag[2],m_Entry[15] };
}

template <typename Real>
const Mathematics::Matrix<Real> Mathematics::Matrix<Real>
	::DiagonalTimes(const APoint& diag) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Matrix{ diag[0] * m_Entry[0], diag[0] * m_Entry[1],diag[0] * m_Entry[2],	m_Entry[3],
				   diag[1] * m_Entry[4], diag[1] * m_Entry[5],diag[1] * m_Entry[6],	m_Entry[7],
				   diag[2] * m_Entry[8], diag[2] * m_Entry[9],diag[2] * m_Entry[10],m_Entry[11],
				   m_Entry[12], m_Entry[13],m_Entry[14], m_Entry[15] };
}

template <typename Real>
void Mathematics::Matrix<Real>
	::Orthonormalize()
{
	MATHEMATICS_CLASS_IS_VALID_9;

	// 算法采用Gram-Schmidt正交。
	// 如果'this'矩阵的左上3x3块M = [m0|m1|m2]，然后输出正交矩阵Q = [q0|q1|q2]
	//
	//   q0 = m0 / |m0|
	//   q1 = (m1-(q0*m1)q0) / |m1-(q0*m1)q0|
	//   q2 = (m2-(q0*m2)q0-(q1*m2)q1) / |m2-(q0*m2)q0-(q1*m2)q1|
	// 其中|V|表示向量V的长度和A * B表示向量A和B的点积	

	// 计算 q0.
	auto invLength = Math::InvSqrt(m_Entry[0] * m_Entry[0] + m_Entry[4] * m_Entry[4] + m_Entry[8] * m_Entry[8]);

	m_Entry[0] *= invLength;
	m_Entry[4] *= invLength;
	m_Entry[8] *= invLength;

	// 计算 q1.
	auto dot0 = m_Entry[0] * m_Entry[1] + m_Entry[4] * m_Entry[5] + m_Entry[8] * m_Entry[9];

	m_Entry[1] -= dot0 * m_Entry[0];
	m_Entry[5] -= dot0 * m_Entry[4];
	m_Entry[9] -= dot0 * m_Entry[8];

	invLength = Math::InvSqrt(m_Entry[1] * m_Entry[1] + m_Entry[5] * m_Entry[5] + m_Entry[9] * m_Entry[9]);

	m_Entry[1] *= invLength;
	m_Entry[5] *= invLength;
	m_Entry[9] *= invLength;

	// 计算 q2.
	auto dot1 = m_Entry[1] * m_Entry[2] + m_Entry[5] * m_Entry[6] + m_Entry[9] * m_Entry[10];

	dot0 = m_Entry[0] * m_Entry[2] + m_Entry[4] * m_Entry[6] + m_Entry[8] * m_Entry[10];

	m_Entry[2] -= dot0 * m_Entry[0] + dot1 * m_Entry[1];
	m_Entry[6] -= dot0 * m_Entry[4] + dot1 * m_Entry[5];
	m_Entry[10] -= dot0 * m_Entry[8] + dot1 * m_Entry[9];

	invLength = Math::InvSqrt(m_Entry[2] * m_Entry[2] + m_Entry[6] * m_Entry[6] + m_Entry[10] * m_Entry[10]);

	m_Entry[2] *= invLength;
	m_Entry[6] *= invLength;
	m_Entry[10] *= invLength;
}

template <typename Real>
Real Mathematics::Matrix<Real>
	::QuadraticForm(const HomogeneousPoint& firstPoint, const HomogeneousPoint& secondPoint) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	HomogeneousPoint secondPointTransform{ m_Entry[0] * secondPoint[0] + m_Entry[1] * secondPoint[1] + m_Entry[2] * secondPoint[2] + m_Entry[3] * secondPoint[3],
										   m_Entry[4] * secondPoint[0] + m_Entry[5] * secondPoint[1] + m_Entry[6] * secondPoint[2] + m_Entry[7] * secondPoint[3],
										   m_Entry[8] * secondPoint[0] + m_Entry[9] * secondPoint[1] + m_Entry[10] * secondPoint[2] + m_Entry[11] * secondPoint[3],
										   m_Entry[12] * secondPoint[0] + m_Entry[13] * secondPoint[1] + m_Entry[14] * secondPoint[2] + m_Entry[15] * secondPoint[3] };

	auto dot = firstPoint[0] * secondPointTransform[0] + firstPoint[1] * secondPointTransform[1] + firstPoint[2] * secondPointTransform[2] + firstPoint[3] * secondPointTransform[3];

	return dot;
}

template <typename Real>
void Mathematics::Matrix<Real>
	::MakeObliqueProjection(const APoint& origin, const AVector& normal, const AVector& direction)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(normal.IsNormalize() && direction.IsNormalize(), "normal和direction必须是单位向量！");

	// 投影平面是Dot(N,X-P) = 0 ，
	// 其中N是一个3×1个单位长度的法线向量，
	// P是一个3×1点在平面。
	// 投影是倾斜的平面，3×1向量D方向。
	// 必定Dot(N,D)不是零，此投影有意义。
	// 给定一个3×1点U，计算线 U+t*D和平面的交叉点t = -Dot(N,U-P)/Dot(N,D)。
	// 然后，
	//
	//   projection(U) = P + [I - D*N^T/Dot(N,D)]*(U-P)
	//
	// 一个4×4的齐次变换矩阵是
	//
	//       +-                               -+
	//   M = | D*N^T - Dot(N,D)*I   -Dot(N,P)D |
	//       |          0^T          -Dot(N,D) |
	//       +-                               -+
	//
	// 其中M适用于[U^T 1]^T 为  M*[U^T 1]^T。
	// 该矩阵被选择为每当Dot(N,D) < 0使得M[3][3] > 0
	// （投影到平面上的“正面侧”）。

	auto dotNormalDirection = Dot(normal, direction);
	auto dotNormalOrigin = Dot(origin, normal);

	m_Entry[0] = direction[0] * normal[0] - dotNormalDirection;
	m_Entry[1] = direction[0] * normal[1];
	m_Entry[2] = direction[0] * normal[2];
	m_Entry[3] = -dotNormalOrigin * direction[0];
	m_Entry[4] = direction[1] * normal[0];
	m_Entry[5] = direction[1] * normal[1] - dotNormalDirection;
	m_Entry[6] = direction[1] * normal[2];
	m_Entry[7] = -dotNormalOrigin * direction[1];
	m_Entry[8] = direction[2] * normal[0];
	m_Entry[9] = direction[2] * normal[1];
	m_Entry[10] = direction[2] * normal[2] - dotNormalDirection;
	m_Entry[11] = -dotNormalOrigin * direction[2];
	m_Entry[12] = Math::GetValue(0);
	m_Entry[13] = Math::GetValue(0);
	m_Entry[14] = Math::GetValue(0);
	m_Entry[15] = -dotNormalDirection;
}

template <typename Real>
void Mathematics::Matrix<Real>
	::MakePerspectiveProjection(const APoint& origin, const AVector& normal, const APoint& eye)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(normal.IsNormalize(), "normal必须是单位向量！");
	//     +-                                                 -+
	// M = | Dot(N,E-P)*I - E*N^T    -(Dot(N,E-P)*I - E*N^T)*E |
	//     |        -N^t                      Dot(N,E)         |
	//     +-                                                 -+
	//
	// 其中E为眼点，P为平面上的一个点，而N是单位长度的平面法线。

	auto dotNormalDirection = Dot(normal, eye - origin);

	m_Entry[0] = dotNormalDirection - eye[0] * normal[0];
	m_Entry[1] = -eye[0] * normal[1];
	m_Entry[2] = -eye[0] * normal[2];
	m_Entry[3] = -(m_Entry[0] * eye[0] + m_Entry[1] * eye[1] + m_Entry[2] * eye[2]);
	m_Entry[4] = -eye[1] * normal[0];
	m_Entry[5] = dotNormalDirection - eye[1] * normal[1];
	m_Entry[6] = -eye[1] * normal[2];
	m_Entry[7] = -(m_Entry[4] * eye[0] + m_Entry[5] * eye[1] + m_Entry[6] * eye[2]);
	m_Entry[8] = -eye[2] * normal[0];
	m_Entry[9] = -eye[2] * normal[1];
	m_Entry[10] = dotNormalDirection - eye[2] * normal[2];
	m_Entry[11] = -(m_Entry[8] * eye[0] + m_Entry[9] * eye[1] + m_Entry[10] * eye[2]);
	m_Entry[12] = -normal[0];
	m_Entry[13] = -normal[1];
	m_Entry[14] = -normal[2];
	m_Entry[15] = Dot(eye, normal);
}

template <typename Real>
void Mathematics::Matrix<Real>
	::MakeReflection(const APoint& origin, const AVector& normal)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_1(normal.IsNormalize(), "normal必须是单位向量！");

	//     +-                         -+
	// M = | I-2*N*N^T    2*Dot(N,P)*N |
	//     |     0^T            1      |
	//     +-                         -+
	//
	// 其中P是平面上的点，N是一个单位长度的平面法线。

	auto twoDotNormalOrigin = Math::GetValue(2) * Dot(origin, normal);

	m_Entry[0] = Math::GetValue(1) - Math::GetValue(2) * normal[0] * normal[0];
	m_Entry[1] = -Math::GetValue(2) * normal[0] * normal[1];
	m_Entry[2] = -Math::GetValue(2) * normal[0] * normal[2];
	m_Entry[3] = twoDotNormalOrigin * normal[0];
	m_Entry[4] = -Math::GetValue(2) * normal[1] * normal[0];
	m_Entry[5] = Math::GetValue(1) - Math::GetValue(2) * normal[1] * normal[1];
	m_Entry[6] = -Math::GetValue(2) * normal[1] * normal[2];
	m_Entry[7] = twoDotNormalOrigin * normal[1];
	m_Entry[8] = -Math::GetValue(2) * normal[2] * normal[0];
	m_Entry[9] = -Math::GetValue(2) * normal[2] * normal[1];
	m_Entry[10] = Math::GetValue(1) - Math::GetValue(2) * normal[2] * normal[2];
	m_Entry[11] = twoDotNormalOrigin * normal[2];
	m_Entry[12] = Math::GetValue(0);
	m_Entry[13] = Math::GetValue(0);
	m_Entry[14] = Math::GetValue(0);
	m_Entry[15] = Math::GetValue(1);
}



#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_MATRIX_DETAIL)

template <typename Real>
bool Mathematics
	::operator==(const Matrix<Real>& lhs, const Matrix<Real>& rhs)
{
	return memcmp(lhs[0], rhs[0], 16 * sizeof(Real)) == 0;
}

template <typename Real>
bool Mathematics
	::operator<(const Matrix<Real>& lhs, const Matrix<Real>& rhs)
{
	return  memcmp(lhs[0], rhs[0], 16 * sizeof(Real)) < 0;
}

template <typename Real>
const Mathematics::Matrix<Real>	Mathematics
	::operator*(const Matrix<Real>& lhs, const Matrix<Real>& rhs)
{
	return Matrix<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(0, 1) * rhs(1, 0) + lhs(0, 2) * rhs(2, 0) + lhs(0, 3) * rhs(3, 0),
					     lhs(0, 0) * rhs(0, 1) + lhs(0, 1) * rhs(1, 1) + lhs(0, 2) * rhs(2, 1) + lhs(0, 3) * rhs(3, 1),
						 lhs(0, 0) * rhs(0, 2) + lhs(0, 1) * rhs(1, 2) + lhs(0, 2) * rhs(2, 2) + lhs(0, 3) * rhs(3, 2),
						 lhs(0, 0) * rhs(0, 3) + lhs(0, 1) * rhs(1, 3) + lhs(0, 2) * rhs(2, 3) + lhs(0, 3) * rhs(3, 3),
						 lhs(1, 0) * rhs(0, 0) + lhs(1, 1) * rhs(1, 0) + lhs(1, 2) * rhs(2, 0) + lhs(1, 3) * rhs(3, 0),
						 lhs(1, 0) * rhs(0, 1) + lhs(1, 1) * rhs(1, 1) + lhs(1, 2) * rhs(2, 1) + lhs(1, 3) * rhs(3, 1),
						 lhs(1, 0) * rhs(0, 2) + lhs(1, 1) * rhs(1, 2) + lhs(1, 2) * rhs(2, 2) + lhs(1, 3) * rhs(3, 2),
						 lhs(1, 0) * rhs(0, 3) + lhs(1, 1) * rhs(1, 3) + lhs(1, 2) * rhs(2, 3) + lhs(1, 3) * rhs(3, 3),
						 lhs(2, 0) * rhs(0, 0) + lhs(2, 1) * rhs(1, 0) + lhs(2, 2) * rhs(2, 0) + lhs(2, 3) * rhs(3, 0),
						 lhs(2, 0) * rhs(0, 1) + lhs(2, 1) * rhs(1, 1) + lhs(2, 2) * rhs(2, 1) + lhs(2, 3) * rhs(3, 1),
						 lhs(2, 0) * rhs(0, 2) + lhs(2, 1) * rhs(1, 2) + lhs(2, 2) * rhs(2, 2) + lhs(2, 3) * rhs(3, 2),
						 lhs(2, 0) * rhs(0, 3) + lhs(2, 1) * rhs(1, 3) + lhs(2, 2) * rhs(2, 3) + lhs(2, 3) * rhs(3, 3),
						 lhs(3, 0) * rhs(0, 0) + lhs(3, 1) * rhs(1, 0) + lhs(3, 2) * rhs(2, 0) + lhs(3, 3) * rhs(3, 0),
						 lhs(3, 0) * rhs(0, 1) + lhs(3, 1) * rhs(1, 1) + lhs(3, 2) * rhs(2, 1) + lhs(3, 3) * rhs(3, 1),
						 lhs(3, 0) * rhs(0, 2) + lhs(3, 1) * rhs(1, 2) + lhs(3, 2) * rhs(2, 2) + lhs(3, 3) * rhs(3, 2),
						 lhs(3, 0) * rhs(0, 3) + lhs(3, 1) * rhs(1, 3) + lhs(3, 2) * rhs(2, 3) + lhs(3, 3) * rhs(3, 3) };
}

template <typename Real>
const Mathematics::Matrix<Real>	Mathematics
	::TransposeTimes(const Matrix<Real>& lhs, const Matrix<Real>& rhs)
{
	return Matrix<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(1, 0) * rhs(1, 0) + lhs(2, 0) * rhs(2, 0) + lhs(3, 0) * rhs(3, 0),
						 lhs(0, 0) * rhs(0, 1) + lhs(1, 0) * rhs(1, 1) + lhs(2, 0) * rhs(2, 1) + lhs(3, 0) * rhs(3, 1),
						 lhs(0, 0) * rhs(0, 2) + lhs(1, 0) * rhs(1, 2) + lhs(2, 0) * rhs(2, 2) + lhs(3, 0) * rhs(3, 2),
						 lhs(0, 0) * rhs(0, 3) + lhs(1, 0) * rhs(1, 3) + lhs(2, 0) * rhs(2, 3) + lhs(3, 0) * rhs(3, 3),
						 lhs(0, 1) * rhs(0, 0) + lhs(1, 1) * rhs(1, 0) + lhs(2, 1) * rhs(2, 0) + lhs(3, 1) * rhs(3, 0),
						 lhs(0, 1) * rhs(0, 1) + lhs(1, 1) * rhs(1, 1) + lhs(2, 1) * rhs(2, 1) + lhs(3, 1) * rhs(3, 1),
						 lhs(0, 1) * rhs(0, 2) + lhs(1, 1) * rhs(1, 2) + lhs(2, 1) * rhs(2, 2) + lhs(3, 1) * rhs(3, 2),
						 lhs(0, 1) * rhs(0, 3) + lhs(1, 1) * rhs(1, 3) + lhs(2, 1) * rhs(2, 3) + lhs(3, 1) * rhs(3, 3),
						 lhs(0, 2) * rhs(0, 0) + lhs(1, 2) * rhs(1, 0) + lhs(2, 2) * rhs(2, 0) + lhs(3, 2) * rhs(3, 0),
						 lhs(0, 2) * rhs(0, 1) + lhs(1, 2) * rhs(1, 1) + lhs(2, 2) * rhs(2, 1) + lhs(3, 2) * rhs(3, 1),
						 lhs(0, 2) * rhs(0, 2) + lhs(1, 2) * rhs(1, 2) + lhs(2, 2) * rhs(2, 2) + lhs(3, 2) * rhs(3, 2),
						 lhs(0, 2) * rhs(0, 3) + lhs(1, 2) * rhs(1, 3) + lhs(2, 2) * rhs(2, 3) + lhs(3, 2) * rhs(3, 3),
						 lhs(0, 3) * rhs(0, 0) + lhs(1, 3) * rhs(1, 0) + lhs(2, 3) * rhs(2, 0) + lhs(3, 3) * rhs(3, 0),
						 lhs(0, 3) * rhs(0, 1) + lhs(1, 3) * rhs(1, 1) + lhs(2, 3) * rhs(2, 1) + lhs(3, 3) * rhs(3, 1),
						 lhs(0, 3) * rhs(0, 2) + lhs(1, 3) * rhs(1, 2) + lhs(2, 3) * rhs(2, 2) + lhs(3, 3) * rhs(3, 2),
						 lhs(0, 3) * rhs(0, 3) + lhs(1, 3) * rhs(1, 3) + lhs(2, 3) * rhs(2, 3) + lhs(3, 3) * rhs(3, 3) };
}

template <typename Real>
const Mathematics::Matrix<Real> Mathematics
	::TimesTranspose(const Matrix<Real>& lhs, const Matrix<Real>& rhs)
{
	return Matrix<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(0, 1) * rhs(0, 1) + lhs(0, 2) * rhs(0, 2) + lhs(0, 3) * rhs(0, 3),
						 lhs(0, 0) * rhs(1, 0) + lhs(0, 1) * rhs(1, 1) + lhs(0, 2) * rhs(1, 2) + lhs(0, 3) * rhs(1, 3),
						 lhs(0, 0) * rhs(2, 0) + lhs(0, 1) * rhs(2, 1) + lhs(0, 2) * rhs(2, 2) + lhs(0, 3) * rhs(2, 3),
						 lhs(0, 0) * rhs(3, 0) + lhs(0, 1) * rhs(3, 1) + lhs(0, 2) * rhs(3, 2) + lhs(0, 3) * rhs(3, 3),
						 lhs(1, 0) * rhs(0, 0) + lhs(1, 1) * rhs(0, 1) + lhs(1, 2) * rhs(0, 2) + lhs(1, 3) * rhs(0, 3),
						 lhs(1, 0) * rhs(1, 0) + lhs(1, 1) * rhs(1, 1) + lhs(1, 2) * rhs(1, 2) + lhs(1, 3) * rhs(1, 3),
						 lhs(1, 0) * rhs(2, 0) + lhs(1, 1) * rhs(2, 1) + lhs(1, 2) * rhs(2, 2) + lhs(1, 3) * rhs(2, 3),
						 lhs(1, 0) * rhs(3, 0) + lhs(1, 1) * rhs(3, 1) + lhs(1, 2) * rhs(3, 2) + lhs(1, 3) * rhs(3, 3),
						 lhs(2, 0) * rhs(0, 0) + lhs(2, 1) * rhs(0, 1) + lhs(2, 2) * rhs(0, 2) + lhs(2, 3) * rhs(0, 3),
						 lhs(2, 0) * rhs(1, 0) + lhs(2, 1) * rhs(1, 1) + lhs(2, 2) * rhs(1, 2) + lhs(2, 3) * rhs(1, 3),
						 lhs(2, 0) * rhs(2, 0) + lhs(2, 1) * rhs(2, 1) + lhs(2, 2) * rhs(2, 2) + lhs(2, 3) * rhs(2, 3),
						 lhs(2, 0) * rhs(3, 0) + lhs(2, 1) * rhs(3, 1) + lhs(2, 2) * rhs(3, 2) + lhs(2, 3) * rhs(3, 3),
						 lhs(3, 0) * rhs(0, 0) + lhs(3, 1) * rhs(0, 1) + lhs(3, 2) * rhs(0, 2) + lhs(3, 3) * rhs(0, 3),
						 lhs(3, 0) * rhs(1, 0) + lhs(3, 1) * rhs(1, 1) + lhs(3, 2) * rhs(1, 2) + lhs(3, 3) * rhs(1, 3),
						 lhs(3, 0) * rhs(2, 0) + lhs(3, 1) * rhs(2, 1) + lhs(3, 2) * rhs(2, 2) + lhs(3, 3) * rhs(2, 3),
						 lhs(3, 0) * rhs(3, 0) + lhs(3, 1) * rhs(3, 1) + lhs(3, 2) * rhs(3, 2) + lhs(3, 3) * rhs(3, 3) };
}

template <typename Real>
const Mathematics::Matrix<Real>	Mathematics
	::TransposeTimesTranspose(const Matrix<Real>& lhs, const Matrix<Real>& rhs)
{
	// A^T * B^T
	return Matrix<Real>{ lhs(0, 0) * rhs(0, 0) + lhs(1, 0) * rhs(0, 1) + lhs(2, 0) * rhs(0, 2) + lhs(3, 0) * rhs(0, 3),
						 lhs(0, 0) * rhs(1, 0) + lhs(1, 0) * rhs(1, 1) + lhs(2, 0) * rhs(1, 2) + lhs(3, 0) * rhs(1, 3),
						 lhs(0, 0) * rhs(2, 0) + lhs(1, 0) * rhs(2, 1) + lhs(2, 0) * rhs(2, 2) + lhs(3, 0) * rhs(2, 3),
						 lhs(0, 0) * rhs(3, 0) + lhs(1, 0) * rhs(3, 1) + lhs(2, 0) * rhs(3, 2) + lhs(3, 0) * rhs(3, 3),
						 lhs(0, 1) * rhs(0, 0) + lhs(1, 1) * rhs(0, 1) + lhs(2, 1) * rhs(0, 2) + lhs(3, 1) * rhs(0, 3),
						 lhs(0, 1) * rhs(1, 0) + lhs(1, 1) * rhs(1, 1) + lhs(2, 1) * rhs(1, 2) + lhs(3, 1) * rhs(1, 3),
						 lhs(0, 1) * rhs(2, 0) + lhs(1, 1) * rhs(2, 1) + lhs(2, 1) * rhs(2, 2) + lhs(3, 1) * rhs(2, 3),
						 lhs(0, 1) * rhs(3, 0) + lhs(1, 1) * rhs(3, 1) + lhs(2, 1) * rhs(3, 2) + lhs(3, 1) * rhs(3, 3),
						 lhs(0, 2) * rhs(0, 0) + lhs(1, 2) * rhs(0, 1) + lhs(2, 2) * rhs(0, 2) + lhs(3, 2) * rhs(0, 3),
						 lhs(0, 2) * rhs(1, 0) + lhs(1, 2) * rhs(1, 1) + lhs(2, 2) * rhs(1, 2) + lhs(3, 2) * rhs(1, 3),
						 lhs(0, 2) * rhs(2, 0) + lhs(1, 2) * rhs(2, 1) + lhs(2, 2) * rhs(2, 2) + lhs(3, 2) * rhs(2, 3),
						 lhs(0, 2) * rhs(3, 0) + lhs(1, 2) * rhs(3, 1) + lhs(2, 2) * rhs(3, 2) + lhs(3, 2) * rhs(3, 3),
						 lhs(0, 3) * rhs(0, 0) + lhs(1, 3) * rhs(0, 1) + lhs(2, 3) * rhs(0, 2) + lhs(3, 3) * rhs(0, 3),
						 lhs(0, 3) * rhs(1, 0) + lhs(1, 3) * rhs(1, 1) + lhs(2, 3) * rhs(1, 2) + lhs(3, 3) * rhs(1, 3),
						 lhs(0, 3) * rhs(2, 0) + lhs(1, 3) * rhs(2, 1) + lhs(2, 3) * rhs(2, 2) + lhs(3, 3) * rhs(2, 3),
						 lhs(0, 3) * rhs(3, 0) + lhs(1, 3) * rhs(3, 1) + lhs(2, 3) * rhs(3, 2) + lhs(3, 3) * rhs(3, 3) };
}

template <typename Real>
const Mathematics::HomogeneousPoint<Real> Mathematics
	::operator*(const Matrix<Real>& matrix, const HomogeneousPoint<Real>& point)
{
	return HomogeneousPoint<Real>{ matrix(0, 0) * point[0] + matrix(0, 1) * point[1] + matrix(0, 2) * point[2] + matrix(0, 3) * point[3],
								   matrix(1, 0) * point[0] + matrix(1, 1) * point[1] + matrix(1, 2) * point[2] + matrix(1, 3) * point[3],
								   matrix(2, 0) * point[0] + matrix(2, 1) * point[1] + matrix(2, 2) * point[2] + matrix(2, 3) * point[3],
								   matrix(3, 0) * point[0] + matrix(3, 1) * point[1] + matrix(3, 2) * point[2] + matrix(3, 3) * point[3] };
}

template <typename Real>
const Mathematics::HomogeneousPoint<Real> Mathematics
	::operator*(const HomogeneousPoint<Real>& point, const Matrix<Real>& matrix)
{
	return HomogeneousPoint<Real>{ point[0] * matrix(0, 0) + point[1] * matrix(1, 0) + point[2] * matrix(2, 0) + point[3] * matrix(3, 0),
								   point[0] * matrix(0, 1) + point[1] * matrix(1, 1) + point[2] * matrix(2, 1) + point[3] * matrix(3, 1),
								   point[0] * matrix(0, 2) + point[1] * matrix(1, 2) + point[2] * matrix(2, 2) + point[3] * matrix(3, 2),
								   point[0] * matrix(0, 3) + point[1] * matrix(1, 3) + point[2] * matrix(2, 3) + point[3] * matrix(3, 3) };
}

template <typename Real>
const std::vector<Mathematics::HomogeneousPoint<Real>> Mathematics
	::BatchMultiply(const Matrix<Real>& matrix, const std::vector<HomogeneousPoint<Real> >& inputPoints)
{
	std::vector<HomogeneousPoint<Real>> outputPoints;

	for (const auto& point : inputPoints)
	{
		outputPoints.push_back(matrix * point);
	}

	MATHEMATICS_ASSERTION_1(outputPoints.size() == inputPoints.size(), "输入和输出数组大小不相等！");

	return outputPoints;
}

template <typename Real>
const Mathematics::APoint<Real>	Mathematics
	::operator*(const Matrix<Real>& matrix, const APoint<Real>& point)
{
	return APoint<Real>{ matrix(0, 0) * point[0] + matrix(0, 1) * point[1] + matrix(0, 2) * point[2] + matrix(0, 3),
						 matrix(1, 0) * point[0] + matrix(1, 1) * point[1] + matrix(1, 2) * point[2] + matrix(1, 3),
						 matrix(2, 0) * point[0] + matrix(2, 1) * point[1] + matrix(2, 2) * point[2] + matrix(2, 3) };
}

template <typename Real>
const std::vector<Mathematics::APoint<Real>> Mathematics
	::BatchMultiply(const Matrix<Real>& matrix, const std::vector<APoint<Real>>& inputPoints)
{
	std::vector<APoint<Real>> outputPoints;

	for (const auto& point : inputPoints)
	{
		outputPoints.push_back(matrix * point);
	}

	MATHEMATICS_ASSERTION_1(outputPoints.size() == inputPoints.size(), "输入和输出数组大小不相等！");

	return outputPoints;
}

template <typename Real>
const Mathematics::AVector<Real> Mathematics
	::operator*(const Matrix<Real>& matrix, const AVector<Real>& point)
{
	return AVector<Real>{ matrix(0, 0) * point[0] + matrix(0, 1) * point[1] + matrix(0, 2) * point[2],
						  matrix(1, 0) * point[0] + matrix(1, 1) * point[1] + matrix(1, 2) * point[2],
						  matrix(2, 0) * point[0] + matrix(2, 1) * point[1] + matrix(2, 2) * point[2] };
}

template <typename Real>
const std::vector<Mathematics::AVector<Real>> Mathematics
	::BatchMultiply(const Matrix<Real>& matrix, const std::vector<AVector<Real> >& inputPoints)
{
	std::vector<AVector<Real> > outputPoints;

	for (const auto& point : inputPoints)
	{
		outputPoints.push_back(matrix * point);
	}

	MATHEMATICS_ASSERTION_1(outputPoints.size() == inputPoints.size(), "输入和输出数组大小不相等！");

	return outputPoints;
}

template <typename Real>
bool Mathematics
	::Approximate(const Matrix<Real>& lhs, const Matrix<Real>& rhs, const Real epsilon)
{
	for (int row = 0; row < 4; ++row)
	{
		for (int column = 0; column < 4; ++column)
		{
			if (epsilon < Math<Real>::FAbs(lhs(row, column) - rhs(row, column)))
			{
				return false;
			}
		}
	}

	return true;
}

template <typename Real>
bool Mathematics
	::Approximate(const Matrix<Real>& lhs, const Matrix<Real>& rhs)
{
	return Approximate(lhs, rhs, Math<Real>::GetZeroTolerance());
}

template <typename Real>
std::ostream& Mathematics
	::operator<<(std::ostream& outFile, const Matrix<Real>& matrix)
{
	for (int row = 0; row < 4; ++row)
	{
		for (int column = 0; column < 4; ++column)
		{
			outFile << "(" << row << "," << column << ")　=　" << matrix(row, column) << "　";
		}
	}

	return outFile;
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_ALGEBRA_MATRIX_DETAIL_H

