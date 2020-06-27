// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 10:18)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMA_BASIS_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMA_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "CoreTools/DataTypes/Tuple.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class Vector3DOrthonormalBasis
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector3DOrthonormalBasis<Real>;
		using Vector3D = Vector3D<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		explicit Vector3DOrthonormalBasis(const Vector3D& nonzeroVector, bool isUnit, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetUVector() const;
		const Vector3D GetVVector() const;
		const Vector3D GetWVector() const;

	private:
		void Generate();
		void GenerateOnXOrZIsMax();
		void GenerateOnYOrZIsMax();

	private:
		bool m_IsUnit;
		Vector3D m_UVector;
		Vector3D m_VVector;
		Vector3D m_WVector;
		Real m_Epsilon;
	};

	using Vector3DOrthonormalBasisf = Vector3DOrthonormalBasis<float>;
	using Vector3DOrthonormalBasisd = Vector3DOrthonormalBasis<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMA_BASIS_H
