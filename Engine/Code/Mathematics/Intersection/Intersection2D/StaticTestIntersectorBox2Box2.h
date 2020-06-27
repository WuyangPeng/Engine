// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_H 

#include "Mathematics/Objects2D/Box2.h" 
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorBox2Box2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorBox2Box2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Box2 = Box2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorBox2Box2(const Box2& lhsBox, const Box2& rhsBox, const Real epsilon = Math::sm_ZeroTolerance);
		virtual ~StaticTestIntersectorBox2Box2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Box2 GetLhsBox() const;
		const Box2 GetRhsBox() const;

	private:
		// 静态查找相交查询。
		void Test();

	private:
		// 要相交的对象。
		Box2 m_LhsBox;
		Box2 m_RhsBox;
	};

	using StaticTestIntersectorBox2Box2f = StaticTestIntersectorBox2Box2<float>;
	using StaticTestIntersectorBox2Box2d = StaticTestIntersectorBox2Box2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_H
