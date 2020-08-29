// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:34)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Box2.h"
#include "Mathematics/Objects2D/Circle2.h" 
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicFindIntersectorBox2Circle2 : public DynamicIntersector<Real, Vector2D>
	{
	public:
		using ClassType = DynamicFindIntersectorBox2Circle2<Real>;
		using ParentType = DynamicIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Box2 = Box2<Real>;
		using Circle2 = Circle2<Real>;
		using Math = Math<Real>;

	public:
		DynamicFindIntersectorBox2Circle2(const Box2& box, const Circle2& circle, Real tmax,
										  const Vector2D& lhsVelocity, const Vector2D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

		// Object access.
		const Box2 GetBox() const;
		const Circle2 GetCircle() const;

		// Intersection set for dynamic find-intersection query.
		const Vector2D& GetContactPoint() const;

	private:
		// Dynamic find-intersection query.
		void Find();

		// Support for dynamic Find.  Both functions return -1 if the objects are
		// initially intersecting, 0 if no intersection, or +1 if they intersect
		// at some positive time.
		int TestVertexRegion(Real cx, Real cy, Real vx, Real vy, Real ex, Real ey, Real& ix, Real& iy);

		int TestEdgeRegion(Real cx, Real cy, Real vx, Real vy, Real ex, Real ey, Real& ix, Real& iy);

	private:
		// 要相交的对象。
		Box2 m_Box;
		Circle2 m_Circle;

		// Point of intersection.
		Vector2D m_ContactPoint;
	};

	using DynamicFindIntersectorBox2Circle2f = DynamicFindIntersectorBox2Circle2<float>;
	using DynamicFindIntersectorBox2Circle2d = DynamicFindIntersectorBox2Circle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX2_CIRCLE2_H	
