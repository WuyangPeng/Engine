// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 14:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"  
#include "Mathematics/Objects3D/Triangle3.h"   
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorPlane3Triangle3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorPlane3Triangle3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;  		
		
	public:
		// If you want a fuzzy determination, set the epsilon value to a small
		// positive number.
		StaticTestIntersectorPlane3Triangle3 (const Plane3& plane,const Triangle3& triangle, Real epsilon = Real{});
		
		// Object access.
		const Plane3 GetPlane () const;
		const Triangle3 GetTriangle () const;
		
	private:
		// Static intersection queries.
		void Test ();
		
		// The objects to intersect.
		Plane3 mPlane;
		Triangle3 mTriangle;		
		
		// For fuzzy arithmetic.
		Real mEpsilon;
	};
	
	using StaticTestIntersectorPlane3Triangle3f = StaticTestIntersectorPlane3Triangle3<float>;
	using StaticTestIntersectorPlane3Triangle3d = StaticTestIntersectorPlane3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_H
