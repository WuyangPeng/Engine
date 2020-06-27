// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h" 
#include "Mathematics/Objects3D/Capsule3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorPlane3Capsule3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorPlane3Capsule3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Capsule3 = Capsule3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorPlane3Capsule3(const Plane3& plane, const Capsule3& capsule);

		// Object access.
		const Plane3 GetPlane() const;
		const Capsule3 GetCapsule() const;

		// Culling support.  The view frustum is assumed to be on the positive
		// side of the plane.  The capsule is culled if it is on the negative
		// side of the plane.
		bool CapsuleIsCulled() const;

	private:
		// Static intersection query.
		void Test();

	private:
		// The objects to intersect.
		Plane3 mPlane;
		Capsule3 mCapsule;
	};

	using StaticTestIntersectorPlane3Capsule3f = StaticTestIntersectorPlane3Capsule3<float>;
	using StaticTestIntersectorPlane3Capsule3d = StaticTestIntersectorPlane3Capsule3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_CAPSULE3_H
