// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 16:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_H

#include "Mathematics/Algebra/Matrix3.h"

namespace Mathematics
{
    template <typename Real>
	class PolarDecompositionValue
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");
        
		using ClassType = PolarDecompositionValue<Real>;
		using Matrix3 = Matrix3<Real>;
        
    public:
		explicit PolarDecompositionValue(const Matrix3& matrix);
        
		CLASS_INVARIANT_DECLARE;
        
    public:
		const Matrix3 GeOrthogonalMatrix() const;
		const Matrix3 GetSymmetryMatrix() const;
	
	private:
		void Calculate(const Matrix3& matrix);

    private:
		Matrix3 m_Orthogonal;
		Matrix3 m_Symmetry;	
    };

	using PolarDecompositionValuef = PolarDecompositionValue<float>;
	using PolarDecompositionValued = PolarDecompositionValue<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_POLAR_DECOMPOSITION_VALUE_H
