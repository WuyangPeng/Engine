// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/04 11:01)

#ifndef MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_H
#define MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_H

#include "Mathematics/MathematicsFwd.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class Matrix2EigenDecomposition  
	{
	public:		
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Matrix2EigenDecomposition<Real>;
		using Matrix2 = Matrix2<Real>;
		using Math = Math<Real>;	
		using AlgebraTraits = AlgebraTraits<Real>;

	public:
		Matrix2EigenDecomposition (const Matrix2& rotation,const Matrix2& diagonal,const Real epsilon);
	
		CLASS_INVARIANT_DECLARE;

		const Matrix2 GetRotation() const;
		const Matrix2 GetDiagonal() const;

	private:
		Matrix2 m_Rotation;
		Matrix2 m_Diagonal;
		Real m_Epsilon;
	};

	using Matrix2EigenDecompositionf = Matrix2EigenDecomposition<float>;
	using Matrix2EigenDecompositiond = Matrix2EigenDecomposition<double>;
}

#endif // MATHEMATICS_ALGEBRA_MATRIX2_EIGEN_DECOMPOSITION_H
