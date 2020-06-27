// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"  
#include "Mathematics/Objects3D/Cylinder3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorRay3Cylinder3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorRay3Cylinder3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		typedef Cylinder3<Real> Cylinder3;
		typedef Vector3DTools<Real> Vector3DTools;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorRay3Cylinder3(const Ray3& ray, const Cylinder3& cylinder);

		// Object access.
		const Ray3 GetRay() const;
		const Cylinder3 GetCylinder() const;

		// The intersection set.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;

		// Static intersection query.
		void Find();

	private:
		// The objects to intersect.
		Ray3 mRay;
		Cylinder3 mCylinder;

		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
	};

	using StaticFindIntersectorRay3Cylinder3f = StaticFindIntersectorRay3Cylinder3<float>;
	using StaticFindIntersectorRay3Cylinder3d = StaticFindIntersectorRay3Cylinder3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CYLINDER3_H
