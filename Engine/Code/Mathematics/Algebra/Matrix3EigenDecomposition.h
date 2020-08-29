// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 10:12)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_H
#define MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class Matrix3EigenDecomposition
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Matrix3EigenDecomposition <Real>;
		using Matrix3 = Matrix3<Real>;
		using Math = Math<Real>;
		using AlgebraTraits = AlgebraTraits<Real>;

	public:
		Matrix3EigenDecomposition(const Matrix3& rotation, const Matrix3& diagonal, const Real epsilon);

		CLASS_INVARIANT_DECLARE;

		const Matrix3 GetRotation() const;
		const Matrix3 GetDiagonal() const;

	private:
		Matrix3 m_Rotation;
		Matrix3 m_Diagonal;
		Real m_Epsilon;
	};

	using Matrix3EigenDecompositionf = Matrix3EigenDecomposition<float>;
	using Matrix3EigenDecompositiond = Matrix3EigenDecomposition<double>;
}

#endif // MATHEMATICS_ALGEBRA_MATRIX3_EIGEN_DECOMPOSITION_H
