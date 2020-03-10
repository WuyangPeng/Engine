// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 14:01)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h" 
#include "Mathematics/Objects3D/Ellipsoid3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorPlane3Ellipsoid3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorPlane3Ellipsoid3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Ellipsoid3 = Ellipsoid3<Real>;
		using Vector3DTools = Vector3DTools<Real>;  
		using Math = Math<Real>;		
		
	public: 
		StaticTestIntersectorPlane3Ellipsoid3 (const Plane3& plane,const Ellipsoid3& ellipsoid);
		
		// Object access.
		const Plane3 GetPlane () const;
		const Ellipsoid3 GetEllipsoid () const;

		// Culling support.  The view frustum is assumed to be on the positive
		// side of the plane.  The ellipsoid is culled if it is on the negative
		// side of the plane.
		bool EllipsoidIsCulled () const;

	private:
		// Static intersection query.
		void Test ();

		// The objects to intersect.
		Plane3 mPlane;
		Ellipsoid3 mEllipsoid;
	};
	
	using StaticTestIntersectorPlane3Ellipsoid3f = StaticTestIntersectorPlane3Ellipsoid3<float>;
	using StaticTestIntersectorPlane3Ellipsoid3d = StaticTestIntersectorPlane3Ellipsoid3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_ELLIPSOID3_H
