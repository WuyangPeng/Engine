// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 12:49)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_H

#include "Mathematics/MathematicsDll.h"

#include "LinearSystemConstIteratorDetail.h"
#include "Mathematics/Algebra/VariableMatrix.h"

#include <vector>
#include <deque>

namespace Mathematics
{
	template <typename Real>
	class LinearSystemInverse
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = LinearSystemInverse<Real>;
		using Math = Math<Real>;
		using VariableMatrix = VariableMatrix<Real>;
		using OutputConstIterator = LinearSystemConstIterator<Real>;

	public:
		explicit LinearSystemInverse(const VariableMatrix& matrix, Real zeroTolerance = Math::GetZeroTolerance(), const Real* inputVector = nullptr);

		CLASS_INVARIANT_DECLARE;

		// 输入:
		//     matrix[iSize][iSize], 项是 matrix[row][col]
		// 输出:
		//     求逆矩阵失败抛出异常，否则返回逆矩阵。
		const VariableMatrix GetInverse() const;

		const OutputConstIterator GetBegin() const;
		const OutputConstIterator GetEnd() const;

	private:
		void Inverse();
		void CopyInputVector(const Real* inputVector);
		void Inverse(int index);
		void SwapRows();
		void ScaleRow();
		void CalculateCurrentMaxValue();
		void ZeroOutPivotColumnLocations();
		void ZeroOutPivotColumnLocations(int outerIndex);
		void Rearrangement();

	private:
		// 线性系统求解容差。
		Real m_ZeroTolerance;  // 默认 = Math::GetZeroTolerance()
		VariableMatrix m_Inverse;
		int m_Size;
		std::vector<int> m_ColumnsIndex;
		std::vector<int> m_RowIndex;
		std::deque<bool> m_Pivoted;
		int m_CurrentRow;
		int m_CurrentColumn;
		Real m_CurrentMaxValue;
		std::vector<Real> m_OutputVector;
	};

	using LinearSystemInversef = LinearSystemInverse<float>;
	using LinearSystemInversed = LinearSystemInverse<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_H
