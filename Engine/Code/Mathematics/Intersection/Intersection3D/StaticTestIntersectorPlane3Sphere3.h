// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 14:04)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"  
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorPlane3Sphere3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorPlane3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   		
		
	public:
		StaticTestIntersectorPlane3Sphere3 (const Plane3& plane,const Sphere3& sphere);
		
		// Object access.
		const Plane3 GetPlane () const;
		const Sphere3 GetSphere () const;

		// Culling support.  The view frustum is assumed to be on the positive
		// side of the plane.  The sphere is culled if it is on the negative
		// side of the plane.
		bool SphereIsCulled () const;

	private:
		// Static intersection queries.
		void Test ();
  
		// The objects to intersect.
		Plane3 mPlane;
		Sphere3 mSphere;		
	};
	
	using StaticTestIntersectorPlane3Sphere3f = StaticTestIntersectorPlane3Sphere3<float>;
	using StaticTestIntersectorPlane3Sphere3d = StaticTestIntersectorPlane3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_SPHERE3_H
