// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 13:57)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/DataTypes/Tuple.h"

#include <type_traits>

namespace Mathematics
{
	template <typename Real>
	class Vector2DOrthonormalize
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector2DOrthonormalize<Real>;
		using Math = Math<Real>;
		using Vector2D = Vector2D<Real>;
		using Vector2DTools = Vector2DTools<Real>;

	public:
		// Gram-Schmidt正交化. 
		// 以线性无关的向量U和V，来计算一个正交组（单位长度，相互垂直）。	
		Vector2DOrthonormalize(const Vector2D& lhs,const Vector2D& rhs,const Real epsilon = Math::sm_ZeroTolerance);

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

	using Vector2DOrthonormalizef = Vector2DOrthonormalize<float>;
	using Vector2DOrthonormalized = Vector2DOrthonormalize<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_H
