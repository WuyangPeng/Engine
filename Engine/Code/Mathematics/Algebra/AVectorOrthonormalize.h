// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:08)

#ifndef MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "CoreTools/DataTypes/Tuple.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class AVectorOrthonormalize
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = AVectorOrthonormalize<Real>;
		using AVector = AVector<Real>;
		using Math = Math<Real>;

	public:
		// Gram-Schmidt正交化。
		// 以线性无关的向量U、V和W，来计算一个正交组（单位长度，相互垂直）。
		AVectorOrthonormalize(const AVector& lhs, const AVector& mhs, const AVector& rhs, const Real epsilon = Math::sm_ZeroTolerance);

		explicit AVectorOrthonormalize(const std::vector<AVector> vectors, const Real epsilon = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		const AVector GetUVector() const noexcept;
                const AVector GetVVector() const noexcept;
                const AVector GetWVector() const noexcept;

	private:
		void Generate();

	private:
		AVector m_UVector;
		AVector m_VVector;
		AVector m_WVector;
		Real m_Epsilon;
	};

	using AVectorOrthonormalizef = AVectorOrthonormalize<float>;
	using AVectorOrthonormalized = AVectorOrthonormalize<double>;
}

#endif // MATHEMATICS_ALGEBRA_AVECTOR_ORTHONORMALIZE_H
