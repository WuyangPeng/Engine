// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h" 
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorPlane3Plane3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorPlane3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Line3 = Line3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1);

		// Object access.
		const Plane3 GetPlane0() const;
		const Plane3 GetPlane1() const;

		// Information about the intersection set.  Only get the specific object
		// of intersection corresponding to the intersection type (IT_LINE or
		// IT_PLANE).
		const Line3 GetIntersectionLine() const;
		const Plane3 GetIntersectionPlane() const;

	private:
		void Find();

		// The objects to intersect.
		Plane3 mPlane0;
		Plane3 mPlane1;

		// Information about the intersection set.
		Line3 mIntrLine;
		Plane3 mIntrPlane;
	};

	using StaticFindIntersectorPlane3Plane3f = StaticFindIntersectorPlane3Plane3<float>;
	using StaticFindIntersectorPlane3Plane3d = StaticFindIntersectorPlane3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_H
