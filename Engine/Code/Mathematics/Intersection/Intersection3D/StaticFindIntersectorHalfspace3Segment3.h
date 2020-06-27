// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:49)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"  
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

// A halfspace is the set of points on the side of a plane to which the plane
// normal points.  The queries here are for intersection of a line segment and
// a halfspace.  In the dynamice find query, if the segment is already
// intersecting the halfspace, the return value is 'false'.  The idea is to
// find first time of contact.

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorHalfspace3Segment3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorHalfspace3Segment3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment);

		// Object access.
		const Plane3 GetHalfspace() const;
		const Segment3 GetSegment() const;

		// The intersection set is empty, a point, or a segment.  The function
		// GetQuantity() returns 0, 1, or 2.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;

	private:
		// Static queries.
		void Find();

		// The objects to intersect.
		Plane3 mHalfspace;
		Segment3 mSegment;

		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
	};

	using StaticFindIntersectorHalfspace3Segment3f = StaticFindIntersectorHalfspace3Segment3<float>;
	using StaticFindIntersectorHalfspace3Segment3d = StaticFindIntersectorHalfspace3Segment3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_H
