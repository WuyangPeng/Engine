// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 14:03)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"  
#include "Mathematics/Objects3D/Plane3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorPlane3Plane3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorPlane3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;  		
		
	public:
		StaticTestIntersectorPlane3Plane3 (const Plane3& plane0, const Plane3& plane1);
		
		// Object access.
		const Plane3 GetPlane0 () const;
		const Plane3 GetPlane1 () const;
		
	private:
		// Static intersection queries.
		void Test ();   
		
		// The objects to intersect.
		Plane3 mPlane0;
		Plane3 mPlane1;
	};
	
	using StaticTestIntersectorPlane3Plane3f = StaticTestIntersectorPlane3Plane3<float>;
	using StaticTestIntersectorPlane3Plane3d = StaticTestIntersectorPlane3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_PLANE3_H
