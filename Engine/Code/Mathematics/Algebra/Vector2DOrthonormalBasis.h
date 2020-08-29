// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 10:16)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMA_BASIS_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMA_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/DataTypes/Tuple.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class Vector2DOrthonormalBasis
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector2DOrthonormalBasis<Real>;
		using Math = Math<Real>;
		using Vector2D = Vector2D<Real>;
		using Vector2DTools = Vector2DTools<Real>;

	public:
		explicit Vector2DOrthonormalBasis(const Vector2D& nonzeroVector, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;

		const Vector2D GetUVector() const;
		const Vector2D GetVVector() const;

	private:
		void Generate();

	private:
		Vector2D m_UVector;
		Vector2D m_VVector;
		Real m_Epsilon;
	};

	using Vector2DOrthonormalBasisf = Vector2DOrthonormalBasis<float>;
	using Vector2DOrthonormalBasisd = Vector2DOrthonormalBasis<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMA_BASIS_H
