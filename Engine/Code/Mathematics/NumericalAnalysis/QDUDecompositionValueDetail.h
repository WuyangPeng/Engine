// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 15:18)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_DETAIL_H

#include "QDUDecompositionValue.h"
#include "SingularValueDetail.h"
#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::QDUDecompositionValue<Real>
	::QDUDecompositionValue(const Matrix3& matrix)
	:m_Orthogonal{}, m_Diagonal{}, m_UpperTriangular{}
{
	Calculate(matrix);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::QDUDecompositionValue<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

// private
template <typename Real>
void Mathematics::QDUDecompositionValue<Real>
	::Calculate(const Matrix3& matrix)
{
	// 因子M = QR = QDU其中Q是正交（旋转），
	// D是对角（缩放），并且U是与那些在它的对角线（剪切）上三角。
	// 算法采用施密特正交（QR的算法）。
	//
	// 如果 M = [ m0 | m1 | m2 ] 和 Q = [ q0 | q1 | q2 ], 则
	//
	//   q0 = m0/|m0|
	//   q1 = (m1-(q0*m1)q0)/|m1-(q0*m1)q0|
	//   q2 = (m2-(q0*m2)q0-(q1*m2)q1)/|m2-(q0*m2)q0-(q1*m2)q1|
	//
	// 其中|V|表示矢量V的长度和A*B表示向量A和B的点积
	//  矩阵Real具有项
	//
	//   r00 = q0*m0  r01 = q0*m1  r02 = q0*m2
	//   r10 = 0      r11 = q1*m1  r12 = q1*m2
	//   r20 = 0      r21 = 0      r22 = q2*m2
	//
	// 所以 D = diag(r00,r11,r22) 和 U 具有项 u01 = r01/r00,
	// u02 = r02/r00, 和 u12 = r12/r11. 		 

	// 构建正交矩阵Q.
	auto invLength = Math<Real>::InvSqrt(matrix(0, 0) * matrix(0, 0) + matrix(1, 0) * matrix(1, 0) + matrix(2, 0) * matrix(2, 0));

	m_Orthogonal(0, 0) = matrix(0, 0) * invLength;
	m_Orthogonal(1, 0) = matrix(1, 0) * invLength;
	m_Orthogonal(2, 0) = matrix(2, 0) * invLength;

	auto fDot = m_Orthogonal(0, 0) * matrix(0, 1) + m_Orthogonal(1, 0) * matrix(1, 1) + m_Orthogonal(2, 0) * matrix(2, 1);

	m_Orthogonal(0, 1) = matrix(0, 1) - fDot * m_Orthogonal(0, 0);
	m_Orthogonal(1, 1) = matrix(1, 1) - fDot * m_Orthogonal(1, 0);
	m_Orthogonal(2, 1) = matrix(2, 1) - fDot * m_Orthogonal(2, 0);
	invLength = Math<Real>::InvSqrt(m_Orthogonal(0, 1) * m_Orthogonal(0, 1) + m_Orthogonal(1, 1) * m_Orthogonal(1, 1) + m_Orthogonal(2, 1) * m_Orthogonal(2, 1));
	m_Orthogonal(0, 1) *= invLength;
	m_Orthogonal(1, 1) *= invLength;
	m_Orthogonal(2, 1) *= invLength;

	fDot = m_Orthogonal(0, 0) * matrix(0, 2) + m_Orthogonal(1, 0) * matrix(1, 2) + m_Orthogonal(2, 0) * matrix(2, 2);

	m_Orthogonal(0, 2) = matrix(0, 2) - fDot * m_Orthogonal(0, 0);
	m_Orthogonal(1, 2) = matrix(1, 2) - fDot * m_Orthogonal(1, 0);
	m_Orthogonal(2, 2) = matrix(2, 2) - fDot * m_Orthogonal(2, 0);
	fDot = m_Orthogonal(0, 1) * matrix(0, 2) + m_Orthogonal(1, 1) * matrix(1, 2) + m_Orthogonal(2, 1) * matrix(2, 2);

	m_Orthogonal(0, 2) -= fDot * m_Orthogonal(0, 1);
	m_Orthogonal(1, 2) -= fDot * m_Orthogonal(1, 1);
	m_Orthogonal(2, 2) -= fDot * m_Orthogonal(2, 1);

	invLength = Math<Real>::InvSqrt(m_Orthogonal(0, 2) * m_Orthogonal(0, 2) + m_Orthogonal(1, 2) * m_Orthogonal(1, 2) + m_Orthogonal(2, 2) * m_Orthogonal(2, 2));
	m_Orthogonal(0, 2) *= invLength;
	m_Orthogonal(1, 2) *= invLength;
	m_Orthogonal(2, 2) *= invLength;

	// 保证正交矩阵行列式1（无反射）
	auto det = m_Orthogonal.Determinant();

	if (det < Math<Real>::sm_Zero)
	{
		for (auto row = 0; row < 3; ++row)
		{
			for (auto col = 0; col < 3; ++col)
			{
				m_Orthogonal(row, col) = -m_Orthogonal(row, col);
			}
		}
	}

	// 建立“右边”的矩阵Real.
	Matrix3 right;
	right(0, 0) = m_Orthogonal(0, 0) * matrix(0, 0) + m_Orthogonal(1, 0) * matrix(1, 0) + m_Orthogonal(2, 0) * matrix(2, 0);

	right(0, 1) = m_Orthogonal(0, 0) * matrix(0, 1) + m_Orthogonal(1, 0) * matrix(1, 1) + m_Orthogonal(2, 0) * matrix(2, 1);

	right(1, 1) = m_Orthogonal(0, 1) * matrix(0, 1) + m_Orthogonal(1, 1) * matrix(1, 1) + m_Orthogonal(2, 1) * matrix(2, 1);

	right(0, 2) = m_Orthogonal(0, 0) * matrix(0, 2) + m_Orthogonal(1, 0) * matrix(1, 2) + m_Orthogonal(2, 0) * matrix(2, 2);

	right(1, 2) = m_Orthogonal(0, 1) * matrix(0, 2) + m_Orthogonal(1, 1) * matrix(1, 2) + m_Orthogonal(2, 1) * matrix(2, 2);

	right(2, 2) = m_Orthogonal(0, 2) * matrix(0, 2) + m_Orthogonal(1, 2) * matrix(1, 2) + m_Orthogonal(2, 2) * matrix(2, 2);

	// 缩放组件。
	m_Diagonal.MakeDiagonal(right(0, 0), right(1, 1), right(2, 2));

	// 剪切组件。	
	auto invD00 = static_cast<Real>(1) / m_Diagonal(0, 0);
	m_UpperTriangular(0, 0) = static_cast<Real>(1);
	m_UpperTriangular(0, 1) = right(0, 1) * invD00;
	m_UpperTriangular(0, 2) = right(0, 2) * invD00;
	m_UpperTriangular(1, 0) = Math<Real>::sm_Zero;
	m_UpperTriangular(1, 1) = static_cast<Real>(1);
	m_UpperTriangular(1, 2) = right(1, 2) / m_Diagonal(1, 1);
	m_UpperTriangular(2, 0) = Math<Real>::sm_Zero;
	m_UpperTriangular(2, 1) = Math<Real>::sm_Zero;
	m_UpperTriangular(2, 2) = static_cast<Real>(1);
}

template <typename Real>
typename const Mathematics::QDUDecompositionValue<Real>::Matrix3 Mathematics::QDUDecompositionValue<Real>
	::GeOrthogonalMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Orthogonal;
}

template <typename Real>
typename const Mathematics::QDUDecompositionValue<Real>::Matrix3 Mathematics::QDUDecompositionValue<Real>
	::GetDiagonalMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Diagonal;
}

template <typename Real>
typename const Mathematics::QDUDecompositionValue<Real>::Matrix3 Mathematics::QDUDecompositionValue<Real>
	::GetUpperTriangularMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_UpperTriangular;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_QDU_DECOMPOSITION_VALUE_DETAIL_H
