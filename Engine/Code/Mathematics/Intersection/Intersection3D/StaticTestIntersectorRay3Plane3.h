// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:58)

#ifndef MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_H
#define MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	// Find-intersection query.  The point of intersection is
	// P = origin + t*direction, with t >= 0.
	template <typename Real>
	class StaticTestIntersectorRay3Plane3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorRay3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorRay3Plane3(const Ray3& ray, const Plane3& plane, const Real epsilon = Math::GetZeroTolerance());

		virtual ~StaticTestIntersectorRay3Plane3();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const Ray3 GetRay() const;
		const Plane3 GetPlane() const;

	private:
		void Test();

	private:
		// 相交对象
		Ray3 m_Ray;
		Plane3 m_Plane;
	};

	using StaticTestIntersectorRay3Plane3f = StaticTestIntersectorRay3Plane3<float>;
	using StaticTestIntersectorRay3Plane3d = StaticTestIntersectorRay3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_TEST_TEST_INTERSECTOR_RAY3_PLANE3_H
