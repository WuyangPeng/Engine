// Copyright (c) 2010-2020
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
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorHalfspace3Segment3(const Plane3& halfspace, const Segment3& segment);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Plane3 GetHalfspace() const;
                [[nodiscard]] const Segment3 GetSegment() const;

		// The intersection set is empty, a point, or a segment.  The function
		// GetQuantity() returns 0, 1, or 2.
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		// Static queries.
		void Find();

		// The objects to intersect.
		Plane3 m_Halfspace;
		Segment3 m_Segment;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[2];
	};

	using FloatStaticFindIntersectorHalfspace3Segment3 = StaticFindIntersectorHalfspace3Segment3<float>;
	using DoubleStaticFindIntersectorHalfspace3Segment3 = StaticFindIntersectorHalfspace3Segment3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_SEGMENT3_H
