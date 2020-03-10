// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/04 10:21)

#ifndef MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_H
#define MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "AVector.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class  AVectorOrthonormalBasis
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = AVectorOrthonormalBasis<Real>;
		using AVector = AVector<Real>;
		using Math = Math<Real>;

	public:
		explicit AVectorOrthonormalBasis(const AVector& nonzeroVector,bool isUnit, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

	    const AVector GetUVector() const;
	    const AVector GetVVector() const;
	    const AVector GetWVector() const;

	private:
	    void Generate();
	    void GenerateOnXOrZIsMax();
	    void GenerateOnYOrZIsMax();

	private:
        bool m_IsUnit;
	    AVector m_UVector;
	    AVector m_VVector; 
	    AVector m_WVector; 
		Real m_Epsilon;			
	};		 	

	using AVectorOrthonormalBasisf = AVectorOrthonormalBasis<float>;
	using AVectorOrthonormalBasisd = AVectorOrthonormalBasis<double>;
}

#endif // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMA_BASIS_H
