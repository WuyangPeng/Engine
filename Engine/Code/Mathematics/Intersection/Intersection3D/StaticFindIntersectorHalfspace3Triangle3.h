// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:49)

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
	class StaticFindIntersectorHalfspace3Triangle3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorHalfspace3Triangle3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Triangle3 = Triangle3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Plane3 GetHalfspace() const;
                [[nodiscard]] const Triangle3 GetTriangle() const;

		// The intersection set is empty, a point, a segment, or a triangle.  The
		// function GetQuantity() returns 0, 1, 2, or 3.
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		// Static queries.
		void Find();

		// The objects to intersect.
		Plane3 m_Halfspace;
		Triangle3 m_Triangle;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[3];
	};

	using FloatStaticFindIntersectorHalfspace3Triangle3 = StaticFindIntersectorHalfspace3Triangle3<float>;
	using DoubleStaticFindIntersectorHalfspace3Triangle3 = StaticFindIntersectorHalfspace3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_H
