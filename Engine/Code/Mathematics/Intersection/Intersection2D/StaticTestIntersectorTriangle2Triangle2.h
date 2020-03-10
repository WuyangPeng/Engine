// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 18:20)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"
   
#include "Mathematics/Objects2D/Triangle2.h"   
#include "Mathematics/Intersection/Intersector1.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorTriangle2Triangle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorTriangle2Triangle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>; 
		using Triangle2 = Triangle2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>; 
		
	public:
		StaticTestIntersectorTriangle2Triangle2(const Triangle2& triangle0,const Triangle2& triangle1);
		
		// Object access.
		const Triangle2 GetTriangle0 () const;
		const Triangle2 GetTriangle1 () const;

	private:
		// Static queries.
		void Test ();
		
	private:		
		static int WhichSide (const std::vector<Vector2D>& V, const Vector2D& P, const Vector2D& D);
		
		// The objects to intersect.
		Triangle2 mTriangle0;
		Triangle2 mTriangle1;		
	};

	using StaticTestIntersectorTriangle2Triangle2f = StaticTestIntersectorTriangle2Triangle2<float>;
	using StaticTestIntersectorTriangle2Triangle2d = StaticTestIntersectorTriangle2Triangle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
