// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 16:29)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_H

#include "Mathematics/Algebra/Matrix3.h"

namespace Mathematics
{
    template <typename Real>
	class SingularValue
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");
        
		using ClassType = SingularValue<Real>;
		using Matrix3 = Matrix3<Real>;
        
    public:
		explicit SingularValue(const Matrix3& matrix);
        
		CLASS_INVARIANT_DECLARE;
        
    public:
		const Matrix3 GetLeftMatrix() const;
		const Matrix3 GetDiagonalMatrix() const;
		const Matrix3 GetRightTransposeMatrix() const;

	private:
		void Calculate(const Matrix3& matrix);

    private:
		Matrix3 m_Left;
		Matrix3 m_Diagonal;
		Matrix3 m_RightTranspose;
    };

	using SingularValuef = SingularValue<float>;
	using SingularValued = SingularValue<double>;
}

#endif // MATHEMATICS_ALGEBRA_MATRIX3_TOOLS_H
