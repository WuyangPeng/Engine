// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:33)

#ifndef MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H

#include "Intersector.h"

namespace Mathematics
{
	// 静态相交查询。默认实现返回“false”。Find查询生成一个相交集合。
	// 派生类负责提供集合,因为集合的性质依赖于对象类型。
	template <typename Real, template <typename> class Vector>
	class StaticIntersector : public Intersector<Real, Vector>
	{
	public:
		using Math = Math<Real>;
		using ClassType = StaticIntersector<Real, Vector>;
		using ParentType = Intersector<Real, Vector>;

	public:
		explicit StaticIntersector(const Real epsilon = Math::sm_ZeroTolerance);
		virtual ~StaticIntersector() = 0;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
	};

	using StaticIntersector2f = StaticIntersector<float, Vector2D>;
	using StaticIntersector3f = StaticIntersector<float, Vector3D>;
	using StaticIntersector2d = StaticIntersector<double, Vector2D>;
	using StaticIntersector3d = StaticIntersector<double, Vector3D>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H
