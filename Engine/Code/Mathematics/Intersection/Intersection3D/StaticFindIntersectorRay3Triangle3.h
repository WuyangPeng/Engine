// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:51)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	// Find-intersection query.  The point of intersection is
	// P = origin + t*direction = b0*V0 + b1*V1 + b2*V2
	template <typename Real>
	class StaticFindIntersectorRay3Triangle3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorRay3Triangle3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorRay3Triangle3(const Ray3& ray, const Triangle3& triangle, const Real epsilon = Math::sm_ZeroTolerance);

		virtual ~StaticFindIntersectorRay3Triangle3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Ray3 GetRay() const;
		const Triangle3 GetTriangle() const;

		Real GetRayParameter() const;
		Real GetTriangleBary0() const;
		Real GetTriangleBary1() const;
		Real GetTriangleBary2() const;

	private:
		void Find();

	private:
		// 相交对象
		Ray3 m_Ray;
		Triangle3 m_Triangle;

		// 相交对象集信息
		Real m_RayParameter;
		Real m_TriangleBary0;
		Real m_TriangleBary1;
		Real m_TriangleBary2;
	};

	using StaticFindIntersectorRay3Triangle3f = StaticFindIntersectorRay3Triangle3<float>;
	using StaticFindIntersectorRay3Triangle3d = StaticFindIntersectorRay3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_H
