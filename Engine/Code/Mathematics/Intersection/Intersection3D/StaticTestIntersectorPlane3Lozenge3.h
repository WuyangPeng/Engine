// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h" 
#include "Mathematics/Objects3D/Lozenge3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorPlane3Lozenge3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorPlane3Lozenge3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Lozenge3 = Lozenge3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorPlane3Lozenge3(const Plane3& plane, const Lozenge3& lozenge);

		// Object access.
		const Plane3 GetPlane() const;
		const Lozenge3 GetLozenge() const;

		// Culling support.  The view frustum is assumed to be on the positive
		// side of the plane.  The lozenge is culled if it is on the negative
		// side of the plane.
		bool LozengeIsCulled() const;

	private:
		// Static intersection query.
		void Test();

		// The objects to intersect.		
		Plane3 mPlane;
		Lozenge3 mLozenge;
	};

	using StaticTestIntersectorPlane3Lozenge3f = StaticTestIntersectorPlane3Lozenge3<float>;
	using StaticTestIntersectorPlane3Lozenge3d = StaticTestIntersectorPlane3Lozenge3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_H
