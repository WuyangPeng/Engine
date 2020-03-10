// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 14:34)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"
 
#include "Mathematics/Objects3D/Sphere3.h" 
#include "Mathematics/Objects3D/Triangle3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorTriangle3Sphere3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorTriangle3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Triangle3 = Triangle3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>; 		
		
	public:
		StaticTestIntersectorTriangle3Sphere3 (const Triangle3& triangle, const Sphere3& sphere);
		
		// Object access.
		const Triangle3 GetTriangle () const;
		const Sphere3 GetSphere () const;

	private:
		// Static test-intersection query.
		void Test ();

		// The objects to intersect.
		Triangle3 mTriangle;
		Sphere3 mSphere;		
	};
	
	using StaticTestIntersectorTriangle3Sphere3f = StaticTestIntersectorTriangle3Sphere3<float>;
	using StaticTestIntersectorTriangle3Sphere3d = StaticTestIntersectorTriangle3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_H
