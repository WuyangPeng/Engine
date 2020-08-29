// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 10:18)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "CoreTools/DataTypes/Tuple.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
	template <typename Real>
	class Vector3DOrthonormalize
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Vector3DOrthonormalize<Real>;
		using Math = Math<Real>;
		using Vector3D = Vector3D<Real>;
		using Vector3DTools = Vector3DTools<Real>;

	public:
		// Gram-Schmidt正交化. 
		// 以线性无关的向量U、V和W，来计算一个正交组（单位长度，相互垂直）。
		Vector3DOrthonormalize(const Vector3D& lhs, const Vector3D& mhs, const Vector3D& rhs, const Real epsilon = Math::GetZeroTolerance());

		explicit Vector3DOrthonormalize(const std::vector<Vector3D> vectors, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;

		const Vector3D GetUVector() const;
		const Vector3D GetVVector() const;
		const Vector3D GetWVector() const;

	private:
		void Generate();

	private:
		Vector3D m_UVector;
		Vector3D m_VVector;
		Vector3D m_WVector;
		Real m_Epsilon;
	};

	using Vector3DOrthonormalizef = Vector3DOrthonormalize<float>;
	using Vector3DOrthonormalized = Vector3DOrthonormalize<double>;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_3D_ORTHONORMALIZE_H
