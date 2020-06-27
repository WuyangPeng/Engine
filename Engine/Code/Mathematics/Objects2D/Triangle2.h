// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 16:47)

#ifndef MATHEMATICS_OBJECTS2D_TRIANGLE2_H
#define MATHEMATICS_OBJECTS2D_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"

#include <vector>
#include <type_traits> 

namespace Mathematics
{
	template <typename Real>
	class Triangle2
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = Triangle2<Real>;
		using Vector2D = Vector2D<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		// 三角形表示为三个顶点数组： 
		Triangle2(const Vector2D& firstVector, const Vector2D& secondVector, const Vector2D& thirdVector);

		CLASS_INVARIANT_DECLARE;

		// 从点point到三角形的距离。
		Real DistanceTo(const Vector2D& point) const;

		const std::vector<Vector2D> GetVertex() const;

	private:
		Vector2D m_Vertex[3];
	};

	using Triangle2f = Triangle2<float>;
	using Triangle2d = Triangle2<double>;
}

#endif // MATHEMATICS_OBJECTS2D_TRIANGLE2_H
