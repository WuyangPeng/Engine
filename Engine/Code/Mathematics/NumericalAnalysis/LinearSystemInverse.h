// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:49)

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

		// ����:
		//     matrix[iSize][iSize], ���� matrix[row][col]
		// ���:
		//     �������ʧ���׳��쳣�����򷵻������
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
		// ����ϵͳ����ݲ
		Real m_ZeroTolerance;  // Ĭ�� = Math::GetZeroTolerance()
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
