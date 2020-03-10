// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/12 10:37)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"  
#include "Mathematics/Objects3D/Triangle3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

// A halfspace is the set of points on the side of a plane to which the plane
// normal points.  The queries here are for intersection of a triangle and a
// halfspace.  In the dynamice find query, if the triangle is already
// intersecting the halfspace, the return value is 'false'.  The idea is to
// find first time of contact.

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorHalfspace3Triangle3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorHalfspace3Triangle3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Triangle3 = Triangle3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   		
		
	public:
		StaticFindIntersectorHalfspace3Triangle3 (const Plane3& halfspace,const Triangle3& triangle);
		
		// Object access.
		const Plane3 GetHalfspace () const;
		const Triangle3 GetTriangle () const;

		// The intersection set is empty, a point, a segment, or a triangle.  The
		// function GetQuantity() returns 0, 1, 2, or 3.
		int GetQuantity () const;
		const Vector3D GetPoint (int i) const;

	private:
		// Static queries.
		void Find ();
		 
		// The objects to intersect.
		Plane3 mHalfspace;
		Triangle3 mTriangle;
		
		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[3];
	};
	
	using StaticFindIntersectorHalfspace3Triangle3f = StaticFindIntersectorHalfspace3Triangle3<float>;
	using StaticFindIntersectorHalfspace3Triangle3d = StaticFindIntersectorHalfspace3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_H
