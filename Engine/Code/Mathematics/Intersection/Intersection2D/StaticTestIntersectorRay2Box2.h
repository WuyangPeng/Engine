// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 18:10)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Ray2.h"   
#include "Mathematics/Objects2D/Box2.h"   
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorRay2Box2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticTestIntersectorRay2Box2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Ray2 = Ray2<Real>;
		using Box2 = Box2<Real>;
		using Vector2DTools = Vector2DTools<Real>;	
		using Math = Math<Real>; 
		
	public:
		StaticTestIntersectorRay2Box2(const Ray2& ray, const Box2& box);
		
		// Object access.
		const Ray2 GetRay () const;
		const Box2 GetBox () const;
		
	private:
		// Static intersection queries.
		void Test ();		
		
		// The objects to intersect.
		Ray2 mRay;
		Box2 mBox;		
	};

	using StaticTestIntersectorRay2Box2f = StaticTestIntersectorRay2Box2<float>;
	using StaticTestIntersectorRay2Box2d = StaticTestIntersectorRay2Box2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY2_BOX2_H
