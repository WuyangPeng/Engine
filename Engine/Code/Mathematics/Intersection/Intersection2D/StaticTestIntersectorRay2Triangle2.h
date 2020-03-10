// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 18:15)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h" 
#include "Mathematics/Objects2D/Ray2.h"   
#include "Mathematics/Objects2D/Triangle2.h"   

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorRay2Triangle2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorRay2Triangle2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Ray2 = Ray2<Real>;
		using Triangle2 = Triangle2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>; 

	public:
		StaticTestIntersectorRay2Triangle2(const Ray2& ray,const Triangle2& triangle);
		
		// Object access.
		const Ray2 GetRay () const;
		const Triangle2 GetTriangle () const;

	private:
		// Static intersection query.
		void Test ();
		
		// The objects to intersect.
		Ray2 mRay;
		Triangle2 mTriangle;
	};
	
	using StaticTestIntersectorRay2Triangle2f = StaticTestIntersectorRay2Triangle2<float>;
	using StaticTestIntersectorRay2Triangle2d = StaticTestIntersectorRay2Triangle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_TRIANGLE2_H
