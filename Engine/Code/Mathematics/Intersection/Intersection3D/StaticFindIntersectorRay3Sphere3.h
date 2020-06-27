// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:51)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"  
#include "Mathematics/Objects3D/Sphere3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorRay3Sphere3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorRay3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorRay3Sphere3(const Ray3& ray, const Sphere3& sphere);

		// Object access.
		const Ray3 GetRay() const;
		const Sphere3 GetSphere() const;

		// The intersection set.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;
		Real GetRayParameter(int i) const;

	private:
		// Static intersection queries.
		void Find();

		// The objects to intersect.
		Ray3 mRay;
		Sphere3 mSphere;

		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
		Real mRayParameter[2];
	};

	using StaticFindIntersectorRay3Sphere3f = StaticFindIntersectorRay3Sphere3<float>;
	using StaticFindIntersectorRay3Sphere3d = StaticFindIntersectorRay3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_SPHERE3_H
