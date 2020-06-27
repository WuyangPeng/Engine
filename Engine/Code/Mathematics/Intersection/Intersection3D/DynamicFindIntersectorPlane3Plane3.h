// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:43)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"  
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicFindIntersectorPlane3Plane3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicFindIntersectorPlane3Plane3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Line3 = Line3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		DynamicFindIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, Real tmax,
										   const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::sm_ZeroTolerance);

		// Object access.
		const Plane3 GetPlane0() const;
		const Plane3 GetPlane1() const;

		// Information about the intersection set.  Only get the specific object
		// of intersection corresponding to the intersection type (IT_LINE or
		// IT_PLANE).
		const Line3 GetIntersectionLine() const;
		const Plane3 GetIntersectionPlane() const;

	private:
		// Dynamic intersection queries.
		void Find();

		// The objects to intersect.
		Plane3 mPlane0;
		Plane3 mPlane1;

		// Information about the intersection set.
		Line3 mIntrLine;
		Plane3 mIntrPlane;
	};

	using DynamicFindIntersectorPlane3Plane3f = DynamicFindIntersectorPlane3Plane3<float>;
	using DynamicFindIntersectorPlane3Plane3d = DynamicFindIntersectorPlane3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_H
