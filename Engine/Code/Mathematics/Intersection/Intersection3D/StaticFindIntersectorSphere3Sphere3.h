// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Sphere3.h"  
#include "Mathematics/Objects3D/Circle3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSphere3Sphere3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorSphere3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
		using Circle3 = Circle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1);

		// Object access.
		const Sphere3 GetSphere0() const;
		const Sphere3 GetSphere1() const;

		enum
		{
			// IT_EMPTY:  spheres are disjoint/separated
			// IT_POINT:  spheres touch at point, each sphere outside the other
			IT_CIRCLE = IntersectionType::Other + 1,  // spheres intersect in a circle
			IT_SPHERE0,        // sphere0 strictly contained in sphere1
			IT_SPHERE0_POINT,  // sphere0 contained in sphere1, share common point
			IT_SPHERE1,        // sphere1 strictly contained in sphere0
			IT_SPHERE1_POINT   // sphere1 contained in sphere0, share common point
		};

		// Intersection set for static find-intersection query.
		const Circle3 GetCircle() const;

		// Intersection set for dynamic find-intersection query.
		const Vector3D GetContactPoint() const;

	private:
		void Find();

		// The objects to intersect.
		Sphere3 mSphere0;
		Sphere3 mSphere1;

		// Circle of intersection for static spheres.
		Circle3 mCircle;

		// Point of intersection for dynamic spheres.
		Vector3D mContactPoint;
	};

	using StaticFindIntersectorSphere3Sphere3f = StaticFindIntersectorSphere3Sphere3<float>;
	using StaticFindIntersectorSphere3Sphere3d = StaticFindIntersectorSphere3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
