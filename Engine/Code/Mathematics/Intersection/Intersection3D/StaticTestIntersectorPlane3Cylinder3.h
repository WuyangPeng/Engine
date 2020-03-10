// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 13:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h" 
#include "Mathematics/Objects3D/Plane3.h" 
#include "Mathematics/Objects3D/Circle3.h" 
#include "Mathematics/Objects3D/Ellipse3.h" 
#include "Mathematics/Objects3D/Cylinder3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorPlane3Cylinder3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorPlane3Cylinder3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Cylinder3 = Cylinder3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;		
		
	public:
		StaticTestIntersectorPlane3Cylinder3 (const Plane3& plane,const Cylinder3& cylinder);
		
		// Object access.
		const Plane3 GetPlane () const;
		const Cylinder3 GetCylinder () const;

		// Culling support.  The view frustum is assumed to be on the positive
		// side of the plane.  The cylinder is culled if it is on the negative
		// side of the plane.
		bool CylinderIsCulled () const;	

	private:
		// Static intersection query for a *finite* cylinder.
		void Test ();		
		
		// The objects to intersect.
		Plane3 mPlane;
		Cylinder3 mCylinder;		
	};
	
	using StaticTestIntersectorPlane3Cylinder3f = StaticTestIntersectorPlane3Cylinder3<float>;
	using StaticTestIntersectorPlane3Cylinder3d = StaticTestIntersectorPlane3Cylinder3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CYLINDER3_H
