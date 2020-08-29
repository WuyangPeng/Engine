// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX2_CIRCLE2_H 

#include "Mathematics/Objects2D/Box2.h"
#include "Mathematics/Objects2D/Circle2.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorBox2Circle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorBox2Circle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Box2 = Box2<Real>;
		using Circle2 = Circle2<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorBox2Circle2(const Box2& box, const Circle2& circle, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		// Object access.
		const Box2 GetBox() const;
		const Circle2 GetCircle() const;

	private:
		// 静态查找相交查询。
		void Test();

	private:
		// 要相交的对象。
		Box2 m_Box;
		Circle2 m_Circle;
	};

	using StaticTestIntersectorBox2Circle2f = StaticTestIntersectorBox2Circle2<float>;
	using StaticTestIntersectorBox2Circle2d = StaticTestIntersectorBox2Circle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX2_CIRCLE2_H	
