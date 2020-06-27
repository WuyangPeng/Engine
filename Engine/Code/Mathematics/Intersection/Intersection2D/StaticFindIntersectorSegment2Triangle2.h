// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:38)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Segment2.h"
#include "Mathematics/Objects2D/Triangle2.h"    
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment2Triangle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment2Triangle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Segment2 = Segment2<Real>;
		using Triangle2 = Triangle2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorSegment2Triangle2(const Segment2& segment, const Triangle2& triangle);

		// Object access.
		const Segment2 GetSegment() const;
		const Triangle2 GetTriangle() const;

		// The intersection set.  If the segment and triangle do not intersect,
		// GetQuantity() returns 0, in which case the intersection type is
		// IT_EMPTY.  If the segment and triangle intersect in a single point,
		// GetQuantity() returns 1, in which case the intersection type is
		// IT_POINT and GetPoint() returns the intersection point.  If the segment
		// and triangle intersect in a segment, GetQuantity() returns 2, in which
		// case the intersection type is IT_SEGMENT and GetPoint() returns the
		// segment endpoints.
		int GetQuantity() const;
		const Vector2D GetPoint(int i) const;

	private:
		// Static intersection query.
		void Find();

		// The objects to intersect.
		Segment2 mSegment;
		Triangle2 mTriangle;

		// Information about the intersection set.
		int mQuantity;
		Vector2D mPoint[2];
	};

	using StaticFindIntersectorSegment2Triangle2f = StaticFindIntersectorSegment2Triangle2<float>;
	using StaticFindIntersectorSegment2Triangle2d = StaticFindIntersectorSegment2Triangle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_TRIANGLE2_H
