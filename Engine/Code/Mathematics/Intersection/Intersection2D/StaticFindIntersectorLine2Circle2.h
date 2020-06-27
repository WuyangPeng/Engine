// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:35)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h" 
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Circle2.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorLine2Circle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorLine2Circle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Line2 = Line2<Real>;
		using Circle2 = Circle2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorLine2Circle2(const Line2& line, const Circle2& circle);

		// Object access.
		const Line2 GetLine() const;
		const Circle2 GetCircle() const;

		// The intersection set.
		int GetQuantity() const;
		const Vector2D& GetPoint(int i) const;

	private:
		// Static intersection query.
		void Find();

		// The objects to intersect.
		Line2 mLine;
		Circle2 mCircle;

		// Information about the intersection set.
		int mQuantity;
		Vector2D mPoint[2];

	public:
		// Shared by IntrRay2Circle2, IntrSegment2Circle2, IntrLine2Arc2,
		// IntrRay2Arc2, and IntrSegment2Arc2.
		static bool Find(const Vector2D& origin, const Vector2D& direction, const Vector2D& center,
						 Real radius, int& rootCount, Real t[2]);
	};

	using StaticFindIntersectorLine2Circle2f = StaticFindIntersectorLine2Circle2<float>;
	using StaticFindIntersectorLine2Circle2d = StaticFindIntersectorLine2Circle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE2_CIRCLE2_H
