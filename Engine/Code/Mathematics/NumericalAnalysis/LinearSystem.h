// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:48)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H

#include "Mathematics/MathematicsDll.h"

#include "SparseMatrix.h"
#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/BandedMatrix.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

#include <map>

namespace Mathematics
{
	template <typename Real>
	class LinearSystem
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = LinearSystem<Real>;
		using RealVector = std::vector<Real>;
		using VariableMatrixType = VariableMatrix<Real>;
		using SparseMatrixType = SparseMatrix<Real>;
		using VariableLengthVector = VariableLengthVector<Real>;
		using BandedMatrix = BandedMatrix<Real>;
		using Math = Math<Real>;

	public:
		explicit LinearSystem(Real zeroTolerance = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		void SetZeroTolerance(Real zeroTolerance);

		// 2×2和3x3系统（避免了高斯消元的开销）

		// 必须保证matrix大小为2x2的二维数组。
		// inputVector和outputVector为大小为2的一维数组。
		void Solve2(const Real matrix[2][2], const Real* inputVector, Real* outputVector) const;

		// 必须保证matrix大小为3x3的二维数组。
		// inputVector和outputVector为大小为3的一维数组。
		void Solve3(const Real matrix[3][3], const Real* inputVector, Real* outputVector) const;

		// 输入:
		//     matrix[iSize][iSize], 项是 matrix[row][col]
		// 输出:
		//     求逆矩阵失败抛出异常，否则返回逆矩阵。
		const VariableMatrixType Inverse(const VariableMatrixType& matrix) const;

		// 输入:
		//     A[iSize][iSize] 系数矩阵，项是 A[row][col]
		//     B[iSize] 向量, 项是 B[row]
		// 输出:
		//     求逆矩阵失败抛出异常，否则返回X[iSize]。
		//     X[iSize] 是解X 在 AX = B

		// 必须保证inputVector和outputVector大小为iSize的一维数组。
		void Solve(const VariableMatrixType& matrix, const Real* inputVector, Real* outputVector) const;

		// 输入:
		//     矩阵是三对角矩阵。
		//     下对角线 lower[size - 1]
		//     主对角线 main[size]
		//     上对角线 upper[size - 1]
		//     右手边 right[size]
		// 输出:
		//     求解失败抛出异常，否则返回U[size]，是解。

		// 必须保证lower和upper大小为size - 1的一维数组。
		// main、right和output大小为size的一维数组。
		void SolveTridiagonal(int size, const Real* lower, const Real* main1, const Real* upper, const Real* right, Real* output) const;

		// 输入:
		//     矩阵是三对角矩阵。
		//     下对角线是常数lower
		//     主对角线是常数main
		//     上对角线是常数upper
		//     右手边 right[size]
		// 输出:
		//     求解失败抛出异常，否则返回U[size]，是解。

		// 必须保证right和output大小为size的一维数组。
		void SolveConstTridiagonal(int size, Real lower, Real main1, Real upper, const Real* right, Real* output) const;

		// 解决方案采用共轭梯度法。
		// 输入:
		//    A[size][size] Symmetrix矩阵，项是 A[row][col]
		//    B[size] 向量, 项是 B[row]
		// 输出:
		//    X[size] 是解 x 为 Ax = B

		// 必须保证inputVector和outputVector为大小为size的一维数组。
		void  SolveSymmetricConjugateGradient(const VariableMatrixType& matrix, const Real* inputVector, Real* outputVector) const;

		// 稀疏对称矩阵共轭梯度法。
		// 输入:
		// 在Symmetrix矩阵matrix的非零条目存储在一个映射，其键对(i,j)，其值是实数。
		// 一对(i,j)为所述数组中的值的位置。
		// 只有(i,j) 和(j,i)应存放，因为matrix是对称的。
		// 该代码假定你知道怎么设置matrix.
		// 列矢量vector被存储为连续值的数组。
		// 输出:
		//    X[size] 是解 x 为 Ax = B

		// 必须保证inputVector和outputVector为大小为size的一维数组。
		void SolveSymmetricConjugateGradient(const SparseMatrixType& matrix, const Real* inputVector, Real* outputVector) const;


		// 求解带状矩阵系统。
		// 输入:
		//     matrix, 一个带状矩阵
		//     vector[size] 向量,项是 vector[row]
		// 输出:
		//     求解失败抛出异常，
		//     返回X[size] 是解 X 在 AX = B

		// 必须保证inputVector和outputVector为大小为size的一维数组。
		void SolveBanded(const BandedMatrix& matrix, const Real* inputVector, Real* outputVector) const;

		// 求带状矩阵的逆
		// 输入:
		//     matrix, 带状矩阵
		// 输出:
		//     求逆失败抛出异常，否则返回逆矩阵   
		const VariableMatrixType Invert(const BandedMatrix& matrix) const;

	private:
		// 线性系统求解容差。
		// 默认 = Math<Real>::sm_ZeroTolerance
		Real m_ZeroTolerance;
	};

	using LinearSystemf = LinearSystem<float>;
	using LinearSystemd = LinearSystem<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
