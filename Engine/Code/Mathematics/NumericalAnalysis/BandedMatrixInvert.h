// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 12:45)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_H

#include "Mathematics/MathematicsDll.h"

#include "LinearSystemConstIteratorDetail.h"
#include "Mathematics/Algebra/BandedMatrix.h"
#include "Mathematics/Algebra/VariableMatrix.h"

#include <vector>

namespace Mathematics
{
	template <typename Real>
	class BandedMatrixInvert
	{
	public:
		using ClassType = BandedMatrixInvert<Real>;
		using Math = Math<Real>;
		using BandedMatrix = BandedMatrix<Real>;
		using VariableMatrix = VariableMatrix<Real>;

	public:
		explicit BandedMatrixInvert(const BandedMatrix& matrix, Real zeroTolerance = Math::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;

		const VariableMatrix GetInvert() const;

	private:
		void Solve();
		void ForwardEliminate(int reduceRow);
		void BackwardEliminate(int reduceRow);

	private:
		Real m_ZeroTolerance;
		BandedMatrix m_Matrix;
		VariableMatrix m_Output;
	};
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_H
