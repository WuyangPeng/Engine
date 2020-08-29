// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 14:52)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_DETAIL_H

#include "NoniterativeEigen3x3.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::NoniterativeEigen3x3<Real>
	::NoniterativeEigen3x3(const Matrix3& matrix)
	:m_Eigenvalue{ }, m_Eigenvector{ }
{
	Compute(matrix);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
Real Mathematics::NoniterativeEigen3x3<Real>
	::GetMaxValue(const Matrix3& matrix) const
{
	auto maxValue = Math<Real>::FAbs(matrix(0, 0));
	auto absValue = Math<Real>::FAbs(matrix(0, 1));
	if (maxValue < absValue)
	{
		maxValue = absValue;
	}
	absValue = Math<Real>::FAbs(matrix(0, 2));
	if (maxValue < absValue)
	{
		maxValue = absValue;
	}
	absValue = Math<Real>::FAbs(matrix(1, 1));
	if (maxValue < absValue)
	{
		maxValue = absValue;
	}
	absValue = Math<Real>::FAbs(matrix(1, 2));
	if (maxValue < absValue)
	{
		maxValue = absValue;
	}
	absValue = Math<Real>::FAbs(matrix(2, 2));
	if (maxValue < absValue)
	{
		maxValue = absValue;
	}

	return maxValue;
}

// private
template <typename Real>
void Mathematics::NoniterativeEigen3x3<Real>
	::Compute(const Matrix3& matrix)
{
	// 缩放矩阵，让它的条目都在[-1,1]。
	// 缩放应用于当至少一个矩阵条目具有大小大于1。

	Matrix3 scaledEntry{ matrix };
	auto maxValue = GetMaxValue(scaledEntry);

	if (static_cast<Real>(1) < maxValue)
	{
		scaledEntry /= maxValue;
	}

	// 计算特征值采用双精度运算。
	ComputeRoots(scaledEntry);

	Real maxEntry[sm_EigenMax];
	Vector3D maxRow[sm_EigenMax];
	for (int i = 0; i < sm_EigenMax; ++i)
	{
		Matrix3 computeMatrix{ scaledEntry };
		computeMatrix(0, 0) -= m_Eigenvalue[i];
		computeMatrix(1, 1) -= m_Eigenvalue[i];
		computeMatrix(2, 1) -= m_Eigenvalue[i];
		if (!PositiveRank(computeMatrix, maxEntry[i], maxRow[i]))
		{
			// 重新缩放回原来的大小。
			RescaleBack(maxValue);

			m_Eigenvector[0] = Vector3D::sm_UnitX;
			m_Eigenvector[1] = Vector3D::sm_UnitY;
			m_Eigenvector[2] = Vector3D::sm_UnitZ;
			return;
		}
	}

	auto totalMax = maxEntry[0];
	int maxIndex{ 0 };
	if (totalMax < maxEntry[1])
	{
		totalMax = maxEntry[1];
		maxIndex = 1;
	}
	if (totalMax < maxEntry[2])
	{
		maxIndex = 2;
	}

	maxRow[maxIndex].Normalize();
	ComputeVectors(scaledEntry, maxRow[maxIndex], (maxIndex + 1) % 3, (maxIndex + 2) % 3, maxIndex);

	// 重新缩放回原来的大小。
	RescaleBack(maxValue);
}

template <typename Real>
void Mathematics::NoniterativeEigen3x3<Real>
	::RescaleBack(Real maxValue)
{
	if (static_cast<Real>(1) < maxValue)
	{
		for (auto i = 0; i < sm_EigenMax; ++i)
		{
			m_Eigenvalue[i] *= maxValue;
		}
	}
}

// private
template <typename Real>
void Mathematics::NoniterativeEigen3x3<Real>
	::ComputeRoots(const Matrix3& matrix)
{
	static constexpr double s_Inverse3(1.0 / 3.0);
	static const double s_Sqrt3(Mathd::Sqrt(3.0));

	// 转换的唯一的矩阵元素为双精度
	auto a00 = static_cast<double>(matrix(0, 0));
	auto a01 = static_cast<double>(matrix(0, 1));
	auto a02 = static_cast<double>(matrix(0, 2));
	auto a11 = static_cast<double>(matrix(1, 1));
	auto a12 = static_cast<double>(matrix(1, 2));
	auto a22 = static_cast<double>(matrix(2, 2));

	// 特征方程为x^3 - c2 * x^2 + c1 * x - c0 = 0。
	// 特征值是这个方程的根，保证都是实数值，因为矩阵是对称的。
	auto c0 = a00 * a11 * a22 + 2.0 * a01 * a02 * a12 -
			  a00 * a12 * a12 - a11 * a02 * a02 -
			  a22 * a01 * a01;

	auto c1 = a00 * a11 - a01 * a01 +
			  a00 * a22 - a02 * a02 +
			  a11 * a22 - a12 * a12;

	auto c2 = a00 + a11 + a22;

	// 构造参数使用在方程的根进行分类，并以闭合形式根部方程求解。
	auto c2Divided3 = c2 * s_Inverse3;
	auto aDivided3 = (c1 - c2 * c2Divided3) * s_Inverse3;
	if (0.0 < aDivided3)
	{
		aDivided3 = 0.0;
	}

	auto halfMB = 0.5 * (c0 + c2Divided3 * (2.0 * c2Divided3 * c2Divided3 - c1));

	auto q = halfMB * halfMB + aDivided3 * aDivided3 * aDivided3;
	if (0.0 < q)
	{
		q = 0.0;
	}

	// 通过求解该多项式的根，计算特征值。
	auto magnitude = Mathd::Sqrt(-aDivided3);
	auto angle = Mathd::ATan2(Mathd::Sqrt(-q), halfMB) * s_Inverse3;
	auto cosValue = Mathd::Cos(angle);
	auto sinValue = Mathd::Sin(angle);
	auto root0 = static_cast<Real>(c2Divided3 + 2.0 * magnitude * cosValue);
	auto root1 = static_cast<Real>(c2Divided3 - magnitude * (cosValue + s_Sqrt3 * sinValue));
	auto root2 = static_cast<Real>(c2Divided3 - magnitude * (cosValue - s_Sqrt3 * sinValue));

	// 排序按升序排列。
	if (root0 <= root1)
	{
		m_Eigenvalue[0] = root0;
		m_Eigenvalue[1] = root1;
	}
	else
	{
		m_Eigenvalue[0] = root1;
		m_Eigenvalue[1] = root0;
	}

	if (m_Eigenvalue[1] <= root2)
	{
		m_Eigenvalue[2] = root2;
	}
	else
	{
		m_Eigenvalue[2] = m_Eigenvalue[1];
		if (m_Eigenvalue[0] <= root2)
		{
			m_Eigenvalue[1] = root2;
		}
		else
		{
			m_Eigenvalue[1] = m_Eigenvalue[0];
			m_Eigenvalue[0] = root2;
		}
	}
}

template <typename Real>
bool Mathematics::NoniterativeEigen3x3<Real>
	::PositiveRank(Matrix3& matrix, Real& maxEntry, Vector3D& maxRow) const
{
	// Locate the maximum-magnitude entry of the matrix.
	maxEntry = static_cast<Real>(-1);
	auto maxRowIndex = -1;
	for (auto row = 0; row < sm_EigenMax; ++row)
	{
		for (auto column = row; column < sm_EigenMax; ++column)
		{
			auto absValue = Math<Real>::FAbs(matrix(row, column));
			if (maxEntry < absValue)
			{
				maxEntry = absValue;
				maxRowIndex = row;
			}
		}
	}

	// 返回包含最大值的行，要用于特征向量构造。
	maxRow = Vector3D{ matrix(maxRowIndex, 0),matrix(maxRowIndex,1),matrix(maxRowIndex, 2) };

	return Math<Real>::GetZeroTolerance() <= maxEntry;
}

template <typename Real>
void Mathematics::NoniterativeEigen3x3<Real>
	::ComputeVectors(const Matrix3& matrix, Vector3D& vector, int firstIndex, int secondIndex, int thirdIndex)
{
	auto basis = Vector3DTools<Real>::GenerateComplementBasis(vector);
	auto uVector = basis.GetUVector();
	auto vVector = basis.GetVVector();
	auto wVector = basis.GetWVector();

	// V[i2] = c0 * U0 + c1 * U1,  c0^2 + c1^2 = 1
	// e2 * V[i2] = c0 * A * U0 + c1 * A * U1
	// e2 * c0 = c0 * U0.Dot(A * U0) + c1 * U0.Dot(A * U1) = d00 * c0 + d01 * c1
	// e2 * c1 = c0 * U1.Dot(A * U0) + c1 * U1.Dot(A * U1) = d01 * c0 + d11 * c1
	auto uVectorTransition = matrix * uVector;
	auto vVectorTransition = matrix * vVector;

	auto p00 = m_Eigenvalue[thirdIndex] - Vector3DTools<Real>::DotProduct(uVector, uVectorTransition);
	auto p01 = Vector3DTools<Real>::DotProduct(vVector, uVectorTransition);
	auto p11 = m_Eigenvalue[thirdIndex] - Vector3DTools<Real>::DotProduct(vVector, vVectorTransition);
	auto maxValue = Math<Real>::FAbs(p00);
	auto row = 0;
	auto absValue = Math<Real>::FAbs(p01);
	if (maxValue < absValue)
	{
		maxValue = absValue;
	}
	absValue = Math<Real>::FAbs(p11);
	if (maxValue < absValue)
	{
		maxValue = absValue;
		row = 1;
	}

	if (Math<Real>::GetZeroTolerance() <= maxValue)
	{
		if (row == 0)
		{
			auto invLength = Math<Real>::InvSqrt(p00 * p00 + p01 * p01);
			p00 *= invLength;
			p01 *= invLength;
			m_Eigenvector[thirdIndex] = p01 * uVector + p00 * vVector;
		}
		else
		{
			auto invLength = Math<Real>::InvSqrt(p11 * p11 + p01 * p01);
			p11 *= invLength;
			p01 *= invLength;
			m_Eigenvector[thirdIndex] = p11 * uVector + p01 * vVector;
		}
	}
	else
	{
		if (row == 0)
		{
			m_Eigenvector[thirdIndex] = vVector;
		}
		else
		{
			m_Eigenvector[thirdIndex] = uVector;
		}
	}

	// V[i0] = c0 * U2 + c1 * Cross(U2,V[i2]) = c0 * Real + c1 * S
	// e0 * V[i0] = c0 * A * Real + c1 * A * S
	// e0 * c0 = c0 * Real.Dot(A * Real) + c1 * Real.Dot(A * S) = d00 * c0 + d01 * c1
	// e0 * c1 = c0 * S.Dot(A * Real) + c1 * S.Dot(A * S) = d01 * c0 + d11 * c1
	auto wVectorCross = Vector3DTools<Real>::CrossProduct(wVector, m_Eigenvector[thirdIndex]);
	auto wVectorTransition = matrix * wVector;
	p00 = m_Eigenvalue[firstIndex] - Vector3DTools<Real>::DotProduct(wVector, wVectorTransition);
	p01 = Vector3DTools<Real>::DotProduct(wVectorCross, wVectorTransition);
	p11 = m_Eigenvalue[firstIndex] - Vector3DTools<Real>::DotProduct(wVectorCross, matrix * wVectorCross);
	maxValue = Math<Real>::FAbs(p00);
	row = 0;
	absValue = Math<Real>::FAbs(p01);
	if (maxValue < absValue)
	{
		maxValue = absValue;
	}
	absValue = Math<Real>::FAbs(p11);
	if (maxValue < absValue)
	{
		maxValue = absValue;
		row = 1;
	}

	if (Math<Real>::GetZeroTolerance() <= maxValue)
	{
		if (row == 0)
		{
			auto invLength = Math<Real>::InvSqrt(p00 * p00 + p01 * p01);
			p00 *= invLength;
			p01 *= invLength;
			m_Eigenvector[firstIndex] = p01 * wVector + p00 * wVectorCross;
		}
		else
		{
			auto invLength = Math<Real>::InvSqrt(p11 * p11 + p01 * p01);
			p11 *= invLength;
			p01 *= invLength;
			m_Eigenvector[firstIndex] = p11 * wVector + p01 * wVectorCross;
		}
	}
	else
	{
		if (row == 0)
		{
			m_Eigenvector[firstIndex] = wVectorCross;
		}
		else
		{
			m_Eigenvector[firstIndex] = wVector;
		}
	}

	// V[i1] = Cross(V[i2],V[i0])
	m_Eigenvector[secondIndex] = Vector3DTools<Real>::CrossProduct(m_Eigenvector[thirdIndex], m_Eigenvector[firstIndex]);
}

template <typename Real>
Mathematics::NoniterativeEigen3x3<Real>
	::~NoniterativeEigen3x3()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::NoniterativeEigen3x3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::NoniterativeEigen3x3<Real>
	::GetEigenvalue(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (0 <= index && index < sm_EigenMax)
	{
		return m_Eigenvalue[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("无效索引\n"));
	}
}

template <typename Real>
typename const Mathematics::NoniterativeEigen3x3<Real>::Vector3D Mathematics::NoniterativeEigen3x3<Real>
	::GetEigenvector(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (0 <= index && index < sm_EigenMax)
	{
		return m_Eigenvector[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("无效索引\n"));
	}
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_NONITERATIVE_EIGEN3X3_DETAIL_H
