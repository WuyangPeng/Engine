// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 13:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h" 
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

// A halfspace is the set of points on the side of a plane to which the plane
// normal points.  The queries here are for intersection of a box and a
// halfspace.  In the dynamice find query, if the box is already
// intersecting the halfspace, the return value is 'false'.  The idea is to
// find first time of contact.

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorHalfspace3Box3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorHalfspace3Box3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   
		
	public:
		StaticTestIntersectorHalfspace3Box3 (const Plane3& halfspace, const Box3& box);
		
		// Object access.
		const Plane3 GetHalfspace () const;
		const Box3 GetBox () const;

	private:
		// Static queries.
		void Test ();
		
		// The objects to intersect.
		Plane3 mHalfspace;
		Box3 mBox;		
	};
	
	using StaticTestIntersectorHalfspace3Box3f = StaticTestIntersectorHalfspace3Box3<float>;
	using StaticTestIntersectorHalfspace3Box3d = StaticTestIntersectorHalfspace3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_BOX3_H
