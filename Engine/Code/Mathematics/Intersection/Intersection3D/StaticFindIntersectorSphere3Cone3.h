// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h" 
#include "Mathematics/Objects3D/Sphere3.h"  
#include "Mathematics/Objects3D/Cone3.h"  

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorSphere3Cone3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorSphere3Cone3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
		using Cone3 = Cone3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorSphere3Cone3(const Sphere3& sphere, const Cone3& cone);

		// Object access.
		const Sphere3 GetSphere() const;
		const Cone3 GetCone() const;

		// In the static find-intersection query, if an intersection occurs
		// between the sphere and cone, it is potentially an infinite set.  The
		// intersection point closest to the cone vertex is returned by this
		// function.
		const Vector3D GetPoint() const;

	private:
		// Static intersection queries.	
		void Find();

	private:
		// The objects to intersect.
		Sphere3 mSphere;
		Cone3 mCone;

		// Closest intersection point to cone vertex.
		Vector3D mPoint;
	};

	using StaticFindIntersectorSphere3Cone3f = StaticFindIntersectorSphere3Cone3<float>;
	using StaticFindIntersectorSphere3Cone3d = StaticFindIntersectorSphere3Cone3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SPHERE3_CONE3_H
