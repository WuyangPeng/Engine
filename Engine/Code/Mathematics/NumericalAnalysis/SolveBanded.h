// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/09 10:52)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_H

#include "Mathematics/MathematicsDll.h"

#include "LinearSystemConstIteratorDetail.h"
#include "Mathematics/Algebra/BandedMatrix.h"

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class SolveBanded  
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = SolveBanded<Real>;
		using BandedMatrix = BandedMatrix<Real>;
		using OutputConstIterator = LinearSystemConstIterator<Real>;
		 
    public:
		explicit SolveBanded(const BandedMatrix& matrix, const Real* inputVector,Real zeroTolerance =  Math<Real>::sm_ZeroTolerance );
        
		CLASS_INVARIANT_DECLARE;
      
		const OutputConstIterator GetBegin() const;
		const OutputConstIterator GetEnd() const;

    private:
		using RealVector = std::vector<Real>;

	private:
		void Solve();
		void ForwardEliminate(int reduceRow);

	private:
		Real m_ZeroTolerance;
		BandedMatrix m_Matrix;		
		RealVector m_Output;		
    };	     
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_H
