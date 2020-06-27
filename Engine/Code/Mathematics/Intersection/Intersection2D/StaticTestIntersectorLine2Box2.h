// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Box2.h"    
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLine2Box2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorLine2Box2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;
		using Box2 = Box2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorLine2Box2(const Line2& line, const Box2& box);

		// Object access.
		const Line2 GetLine() const;
		const Box2 GetBox() const;

	private:
		// Static intersection queries.
		void Test();

		// The objects to intersect.
		Line2 mLine;
		Box2 mBox;
	};

	using StaticTestIntersectorLine2Box2f = StaticTestIntersectorLine2Box2<float>;
	using StaticTestIntersectorLine2Box2d = StaticTestIntersectorLine2Box2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_H
