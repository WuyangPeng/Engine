// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 18:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_H

#include "Mathematics/MathematicsDll.h"
  
#include "Mathematics/Objects2D/Box2.h"  
#include "Mathematics/Objects2D/Segment2.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorSegment2Box2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorSegment2Box2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Segment2 = Segment2<Real>;
		using Box2 = Box2<Real>;
		using Vector2DTools = Vector2DTools<Real>; 
		using Math = Math<Real>;		
		
	public:
		StaticTestIntersectorSegment2Box2(const Segment2& segment,const Box2& box, bool solid);
		
		// Object access.
		const Segment2 GetSegment () const;
		const Box2 GetBox () const;
		
	private:
		// Static intersection queries.
		void Test ();		
		
		// The objects to intersect.
		Segment2 mSegment;
		Box2 mBox;
		bool mSolid;
		
	};
	
	using StaticTestIntersectorSegment2Box2f = StaticTestIntersectorSegment2Box2<float>;
	using StaticTestIntersectorSegment2Box2d = StaticTestIntersectorSegment2Box2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_H
