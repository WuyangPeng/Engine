// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 15:55)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableMatrix.h"
#include "LinearSystemConstIteratorDetail.h"

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
        using VariableMatrix = VariableMatrix<Real>;
		using OutputConstIterator = LinearSystemConstIterator<Real>;
        
    public:
        explicit LinearSystemInverse (const VariableMatrix& matrix,Real zeroTolerance = Math<Real>::sm_ZeroTolerance,const Real* inputVector = nullptr);
        
		CLASS_INVARIANT_DECLARE;
        
        // 输入:
        //     matrix[iSize][iSize], 项是 matrix[row][col]
        // 输出:
        //     求逆矩阵失败抛出异常，否则返回逆矩阵。
        const VariableMatrix GetInverse () const;   

		const OutputConstIterator GetBegin() const;
		const OutputConstIterator GetEnd() const;
                
    private:
		void Inverse ();
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
        Real m_ZeroTolerance;  // 默认 = Math<Real>::sm_ZeroTolerance
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
