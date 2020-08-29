// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:43)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Plane3.h"  
#include "Mathematics/Intersection/DynamicIntersector.h" 

// A halfspace is the set of points on the side of a plane to which the plane
// normal points.  The queries here are for intersection of a box and a
// halfspace.  In the dynamice find query, if the box is already
// intersecting the halfspace, the return value is 'false'.  The idea is to
// find first time of contact.

namespace Mathematics
{
	template <typename Real>
	class DynamicFindIntersectorHalfspace3Box3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicFindIntersectorHalfspace3Box3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Box3 = Box3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		DynamicFindIntersectorHalfspace3Box3(const Plane3& halfspace, const Box3& box,
											 Real tmax, const Vector3D& lhsVelocity,
											 const Vector3D& rhsVelocity,
											 const Real epsilon = Math::GetZeroTolerance());

		// Object access.
		const Plane3 GetHalfspace() const;
		const Box3 GetBox() const;

		// The contact set is empty, a point, a segment, or a rectangle.  The
		// function GetQuantity() returns 0, 1, 2, or 4.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;

	private:
		// Dynamic queries.
		void Find();

		// The objects to intersect.
		Plane3 mHalfspace;
		Box3 mBox;

		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[4];
	};

	using DynamicFindIntersectorHalfspace3Box3f = DynamicFindIntersectorHalfspace3Box3<float>;
	using DynamicFindIntersectorHalfspace3Box3d = DynamicFindIntersectorHalfspace3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_H
