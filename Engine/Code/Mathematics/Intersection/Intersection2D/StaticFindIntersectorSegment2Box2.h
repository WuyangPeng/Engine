// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 17:47)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_BOX2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Box2.h"  
#include "Mathematics/Objects2D/Segment2.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSegment2Box2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorSegment2Box2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Segment2 = Segment2<Real>;
		using Box2 = Box2<Real>;
		using Vector2DTools = Vector2DTools<Real>; 
		using Math = Math<Real>;		
		
	public:
		StaticFindIntersectorSegment2Box2(const Segment2& segment, const Box2& box, bool solid);
		
		// Object access.
		const Segment2 GetSegment () const;
		const Box2 GetBox () const;
		    
		// The intersection set.
		int GetQuantity () const;
		const Vector2D GetPoint (int i) const;
		
	private:
		// Static intersection queries.
		void Find();
		
		// The objects to intersect.
		Segment2 mSegment;
		Box2 mBox;
		bool mSolid;
		
		// Information about the intersection set.
		int mQuantity;
		Vector2D mPoint[2];
	};
	
	using StaticFindIntersectorSegment2Box2f = StaticFindIntersectorSegment2Box2<float>;
	using StaticFindIntersectorSegment2Box2d = StaticFindIntersectorSegment2Box2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT2_BOX2_H
