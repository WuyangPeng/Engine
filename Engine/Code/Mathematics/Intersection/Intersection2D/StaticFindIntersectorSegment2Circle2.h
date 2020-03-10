// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 17:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_CIRCLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_CIRCLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Circle2.h"   
#include "Mathematics/Objects2D/Segment2.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment2Circle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment2Circle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Segment2 = Segment2<Real>;
		using Circle2 = Circle2<Real>;
		using Vector2DTools = Vector2DTools<Real>; 
		using Math = Math<Real>;
		
	public:
		StaticFindIntersectorSegment2Circle2(const Segment2& segment, const Circle2& circle);
		
		// Object access.
		const Segment2 GetSegment () const;
		const Circle2 GetCircle () const;

  		// The intersection set.
		int GetQuantity () const;
		const Vector2D GetPoint (int i) const;
		
	private:
		// Static intersection query.
		void Find();
		
		// The objects to intersect.
		Segment2 mSegment;
		Circle2 mCircle;
		
		// Information about the intersection set.
		int mQuantity;
		Vector2D mPoint[2];
	};
	
	using StaticFindIntersectorSegment2Circle2f = StaticFindIntersectorSegment2Circle2<float>;
	using StaticFindIntersectorSegment2Circle2d = StaticFindIntersectorSegment2Circle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_CIRCLE2_H
