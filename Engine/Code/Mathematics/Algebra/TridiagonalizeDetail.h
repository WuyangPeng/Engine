// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 14:53)

#ifndef MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_DETAIL_H
#define MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_DETAIL_H

#include "Tridiagonalize.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Tridiagonalize<Real>
	::Tridiagonalize(const Matrix3& matrix)
	:m_InputMatrix{ matrix }, m_OutputMatrix{ MatrixInitType::Identity }, m_Reflection{ false }, m_Diagonal{}, m_Subdiagonal{}
{
	MATHEMATICS_ASSERTION_1(Math::FAbs(m_InputMatrix(0, 1) - m_InputMatrix(1, 0)) <= Math::GetZeroTolerance() &&
							Math::FAbs(m_InputMatrix(0, 2) - m_InputMatrix(2, 0)) <= Math::GetZeroTolerance() &&
							Math::FAbs(m_InputMatrix(1, 2) - m_InputMatrix(2, 1)) <= Math::GetZeroTolerance(),
							"矩阵必须是对称矩阵。");
	Init();

	if (!QLAlgorithm())
	{
		MATHEMATICS_ASSERTION_1(false, "QLAlgorithm不收敛！");
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Tridiagonalize<Real>
	::IsValid() const noexcept
{
	return true;

}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Tridiagonalize<Real>
	::Init()
{
	// Householder reduction T = Q^t M Q
	//   输入:   
	//     m_InputMatrix, 对称 3x3 矩阵 M
	//   输出:  
	//     m_OutputMatrix, 正交矩阵 Q (反射)
	//     m_Diagonal, T的对角线 T
	//     m_Subdiagonal,T的次对角项 T (T 是对称的)

	auto m00 = m_InputMatrix(0, 0);
	auto m01 = m_InputMatrix(0, 1);
	auto m02 = m_InputMatrix(0, 2);
	auto m11 = m_InputMatrix(1, 1);
	auto m12 = m_InputMatrix(1, 2);
	auto m22 = m_InputMatrix(2, 2);

	m_Diagonal[0] = m00;
	m_Diagonal[1] = Math::GetValue(0);
	m_Diagonal[2] = Math::GetValue(0);

	m_Subdiagonal[0] = Math::GetValue(0);
	m_Subdiagonal[0] = Math::GetValue(0);

	if (Math::GetZeroTolerance() <= Math::FAbs(m02))
	{
		m_Subdiagonal[0] = Math::Sqrt(m01 * m01 + m02 * m02);
		auto invLength = Math::GetValue(1) / m_Subdiagonal[0];
		m01 *= invLength;
		m02 *= invLength;
		auto temp = Math::GetValue(2) * m01 * m12 + m02 * (m22 - m11);
		m_Diagonal[1] = m11 + m02 * temp;
		m_Diagonal[2] = m22 - m02 * temp;
		m_Subdiagonal[1] = m12 - m01 * temp;

		m_OutputMatrix(0, 0) = Math::GetValue(1);
		m_OutputMatrix(0, 1) = Math::GetValue(0);
		m_OutputMatrix(0, 2) = Math::GetValue(0);
		m_OutputMatrix(1, 0) = Math::GetValue(0);
		m_OutputMatrix(1, 1) = m01;
		m_OutputMatrix(1, 2) = m02;
		m_OutputMatrix(2, 0) = Math::GetValue(0);
		m_OutputMatrix(2, 1) = m02;
		m_OutputMatrix(2, 2) = -m01;

		m_Reflection = true;
	}
	else
	{
		m_Diagonal[1] = m11;
		m_Diagonal[2] = m22;
		m_Subdiagonal[0] = m01;
		m_Subdiagonal[1] = m12;

		m_OutputMatrix.MakeIdentity();

		m_Reflection = false;
	}
}

template <typename Real>
bool Mathematics::Tridiagonalize<Real>
	::IsValueNear(Real subdiagonal, Real lhsDiagonal, Real rhsDiagonal)
{
	auto sum = Math::FAbs(lhsDiagonal) + Math::FAbs(rhsDiagonal);

	if (Math::FAbs(Math::FAbs(subdiagonal) + sum - sum) <= Math::sm_Epsilon)
		return true;
	else
		return false;
}

template <typename Real>
void Mathematics::Tridiagonalize<Real>
	::UpdateDiagonal(int lhsIndex, int rhsIndex)
{
	// 计算特征值的一元二次方程的根。
	auto sum = m_Diagonal[lhsIndex] + m_Diagonal[rhsIndex];
	auto difference = m_Diagonal[lhsIndex] - m_Diagonal[rhsIndex];
	auto discr = Math::Sqrt(difference * difference + (static_cast<Real>(4) * m_Subdiagonal[lhsIndex] * m_Subdiagonal[lhsIndex]));
	auto eigenvalue0 = static_cast<Real>(0.5) * (sum - discr);
	auto eigenvalue1 = static_cast<Real>(0.5) * (sum + discr);

	auto cosValue = Math::GetValue(0);
	auto sinValue = Math::GetValue(0);

	// 计算Givens旋转。
	if (Math::GetValue(0) <= difference)
	{
		cosValue = m_Subdiagonal[lhsIndex];
		sinValue = m_Diagonal[lhsIndex] - eigenvalue0;
	}
	else
	{
		cosValue = m_Diagonal[rhsIndex] - eigenvalue0;
		sinValue = m_Subdiagonal[lhsIndex];
	}

	auto invSqrt = Math::InvSqrt(cosValue * cosValue + sinValue * sinValue);

	cosValue *= invSqrt;
	sinValue *= invSqrt;

	// 右乘当前正交矩阵使用Givens旋转
	GivensRotation(lhsIndex, rhsIndex, cosValue, sinValue);

	// 更新三角矩阵。
	m_Diagonal[lhsIndex] = eigenvalue0;
	m_Diagonal[rhsIndex] = eigenvalue1;
	m_Subdiagonal[0] = Math::GetValue(0);
	m_Subdiagonal[1] = Math::GetValue(0);
}

template <typename Real>
void Mathematics::Tridiagonalize<Real>
	::GivensRotation(int lhsIndex, int rhsIndex, Real cosValue, Real sinValue)
{
	for (auto row = 0; row < 3; ++row)
	{
		auto tmp = m_OutputMatrix(row, rhsIndex);
		m_OutputMatrix(row, rhsIndex) = sinValue * m_OutputMatrix(row, lhsIndex) + cosValue * tmp;
		m_OutputMatrix(row, lhsIndex) = cosValue * m_OutputMatrix(row, lhsIndex) - sinValue * tmp;
	}
}

template <typename Real>
bool Mathematics::Tridiagonalize<Real>
	::QLAlgorithm()
{
	// 这是基于书“矩阵计算”第二版（Gene H. Golub 和 Charles F. Van Loan）
	// 实现的对称QR算法。该算法在8.2.3。
	// 实施有轻微的变化，以使之实际成为QL算法，
	// 并将其捕获任一次对角项S0或S1是零的情况下，直接降低为2×2的子块。

	constexpr auto indexMax = 32;
	for (auto i = 0; i < indexMax; ++i)
	{
		if (IsValueNear(m_Subdiagonal[0], m_Diagonal[0], m_Diagonal[1]))
		{
			// 该矩阵是有效的
			//       +-        -+
			//   M = | d0  0  0 |
			//       | 0  d1 s1 |
			//       | 0  s1 d2 |
			//       +-        -+
			// Init函数将矩阵初始化为这种形式，所以下面的其他逻辑不会涉及。

			// 测试M是否是对角线矩阵（数字四舍五入）。
			if (IsValueNear(m_Subdiagonal[1], m_Diagonal[1], m_Diagonal[2]))
			{
				return true;
			}

			UpdateDiagonal(1, 2);

			return true;
		}

		if (IsValueNear(m_Subdiagonal[1], m_Diagonal[1], m_Diagonal[2]))
		{
			// 该矩阵是有效
			//       +-         -+
			//   M = | d0  s0  0 |
			//       | s0  d1  0 |
			//       | 0   0  d2 |
			//       +-         -+

			// 测试M是否是对角线矩阵（数字四舍五入）。	
			if (IsValueNear(m_Subdiagonal[0], m_Diagonal[0], m_Diagonal[1]))
			{
				return true;
			}

			UpdateDiagonal(0, 1);

			return true;
		}

		// 矩阵是
		//       +-        -+
		//   M = | d0 s0  0 |
		//       | s0 d1 s1 |
		//       | 0  s1 d2 |
		//       +-        -+

		// 设置参数为QL步骤的第一阶段中。 
		// 对于A的值是在对角项D[2]和隐式移位的差由Wilkinson建议。
		auto ratio = (m_Diagonal[1] - m_Diagonal[0]) / (Math::GetValue(2) * m_Subdiagonal[0]);
		auto root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
		auto b = m_Subdiagonal[1];
		auto a = m_Diagonal[2] - m_Diagonal[0];
		if (Math::GetValue(0) <= ratio)
		{
			a += m_Subdiagonal[0] / (ratio + root);
		}
		else
		{
			a += m_Subdiagonal[0] / (ratio - root);
		}

		auto cosValue = Math::GetValue(0);
		auto sinValue = Math::GetValue(0);

		// 计算Givens旋转的第一遍。
		if (Math::FAbs(a) <= Math::FAbs(b))
		{
			ratio = a / b;
			sinValue = Math::InvSqrt((Math::GetValue(1) + ratio * ratio));
			cosValue = ratio * sinValue;
		}
		else
		{
			ratio = b / a;
			cosValue = Math::InvSqrt(Math::GetValue(1) + ratio * ratio);
			sinValue = ratio * cosValue;
		}

		// 右乘当前正交矩阵使用Givens旋转
		GivensRotation(1, 2, cosValue, sinValue);

		// 设置参数为QL步骤的第二步。
		// 值tmp0和tmp1需要在第二阶段结束时，才能全面更新三对角矩阵。
		auto tmp0 = (m_Diagonal[1] - m_Diagonal[2]) * sinValue + Math::GetValue(2) * m_Subdiagonal[1] * cosValue;
		auto tmp1 = cosValue * m_Subdiagonal[0];
		b = sinValue * m_Subdiagonal[0];
		a = cosValue * tmp0 - m_Subdiagonal[1];
		tmp0 *= sinValue;

		// 计算Givens旋转的第二遍。m_Subdiagonal的项S[1]在三对角矩阵，此时被更新。
		if (Math::FAbs(a) <= Math::FAbs(b))
		{
			ratio = a / b;
			root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
			m_Subdiagonal[1] = b * root;
			sinValue = Math::GetValue(1) / root;
			cosValue = ratio * sinValue;
		}
		else
		{
			ratio = b / a;
			root = Math::Sqrt(Math::GetValue(1) + ratio * ratio);
			m_Subdiagonal[1] = a * root;
			cosValue = Math::GetValue(1) / root;
			sinValue = ratio * cosValue;
		}

		// 右乘当前正交矩阵使用Givens旋转
		GivensRotation(0, 1, cosValue, sinValue);

		// 完成三对角矩阵的更新。
		auto tmp2 = m_Diagonal[1] - tmp0;
		m_Diagonal[2] += tmp0;
		tmp0 = (m_Diagonal[0] - tmp2) * sinValue + Math::GetValue(2) *  tmp1 * cosValue;
		m_Subdiagonal[0] = cosValue * tmp0 - tmp1;
		tmp0 *= sinValue;
		m_Diagonal[1] = tmp2 + tmp0;
		m_Diagonal[0] -= tmp0;
	}

	return false;
}

template <typename Real>
bool Mathematics::Tridiagonalize<Real>
	::IsReflection() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Reflection;
}

template <typename Real>
typename const Mathematics::Tridiagonalize<Real>::Matrix3 Mathematics::Tridiagonalize<Real>
	::GetRotation() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_OutputMatrix;
}

template <typename Real>
typename const Mathematics::Tridiagonalize<Real>::Vector3D Mathematics::Tridiagonalize<Real>
	::GetDiagonal() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Vector3D{ m_Diagonal[0],m_Diagonal[1],m_Diagonal[2] };
}

#endif // MATHEMATICS_ALGEBRA_TRIDIAGONALIZE_DETAIL_H

