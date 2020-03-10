// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 09:36)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h"  
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicFindIntersectorSphere3Sphere3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicFindIntersectorSphere3Sphere3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
		using Circle3 = Circle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>; 

	public:
		DynamicFindIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, Real tmax, 
											 const Vector3D& lhsVelocity,const Vector3D& rhsVelocity, const Real epsilon = Math::sm_ZeroTolerance);

		// Object access.
		const Sphere3 GetSphere0() const;
		const Sphere3 GetSphere1() const;

		// Intersection set for static find-intersection query.
		const Circle3 GetCircle() const;

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

		// Intersection set for dynamic find-intersection query.
		const Vector3D GetContactPoint() const;

	private:
		// Dynamic find-intersection query.
		void Find();

		// The objects to intersect.
		Sphere3 mSphere0;
		Sphere3 mSphere1;

		// Circle of intersection for static spheres.
		Circle3 mCircle;

		// Point of intersection for dynamic spheres.
		Vector3D mContactPoint;
	};

	using DynamicFindIntersectorSphere3Sphere3f = DynamicFindIntersectorSphere3Sphere3<float>;
	using DynamicFindIntersectorSphere3Sphere3d = DynamicFindIntersectorSphere3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
