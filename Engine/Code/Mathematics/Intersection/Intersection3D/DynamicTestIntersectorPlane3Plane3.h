// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h" 
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicTestIntersectorPlane3Plane3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicTestIntersectorPlane3Plane3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		DynamicTestIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, Real tmax,
										   const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::sm_ZeroTolerance);

		// Object access.
		const Plane3 GetPlane0() const;
		const Plane3 GetPlane1() const;

	private:
		// Dynamic intersection queries.
		void Test();

		// The objects to intersect.
		Plane3 mPlane0;
		Plane3 mPlane1;
	};

	using DynamicTestIntersectorPlane3Plane3f = DynamicTestIntersectorPlane3Plane3<float>;
	using DynamicTestIntersectorPlane3Plane3d = DynamicTestIntersectorPlane3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_PLANE3_PLANE3_H
