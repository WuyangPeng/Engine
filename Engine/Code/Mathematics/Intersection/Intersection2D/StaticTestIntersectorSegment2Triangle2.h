// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Segment2.h"   
#include "Mathematics/Objects2D/Triangle2.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorSegment2Triangle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorSegment2Triangle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Segment2 = Segment2<Real>;
		using Triangle2 = Triangle2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorSegment2Triangle2(const Segment2& segment, const Triangle2& triangle);

		// Object access.
		const Segment2 GetSegment() const;
		const Triangle2 GetTriangle() const;

	private:
		// Static intersection query.
		void Test();

		// The objects to intersect.
		Segment2 mSegment;
		Triangle2 mTriangle;
	};

	using StaticTestIntersectorSegment2Triangle2f = StaticTestIntersectorSegment2Triangle2<float>;
	using StaticTestIntersectorSegment2Triangle2d = StaticTestIntersectorSegment2Triangle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_TRIANGLE2_H
