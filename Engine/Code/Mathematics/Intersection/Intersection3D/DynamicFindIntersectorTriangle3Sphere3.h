// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Sphere3.h" 
#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicFindIntersectorTriangle3Sphere3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicFindIntersectorTriangle3Sphere3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Triangle3 = Triangle3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		DynamicFindIntersectorTriangle3Sphere3(const Triangle3& triangle, const Sphere3& sphere, Real tmax,
											   const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

		// Object access.
		const Triangle3 GetTriangle() const;
		const Sphere3 GetSphere() const;

		// The contact point.
		const Vector3D GetPoint() const;

	private:
		// Dynamic find-intersection query.  If the query returns 'true', use
		// GetContactTime() to obtain the first time of contact.  If this time
		// is zero, the triangle is already intersecting the sphere and no
		// contact set is computed.  If this time is positive, obtain the
		// first point of contact using GetPoint().
		void Find();

	private:

		// Support for the dynamic query.
		bool FindTriangleSphereCoplanarIntersection(int vertex, std::vector<Vector3D>& V, const Vector3D& sideNorm, const Vector3D& side, Real tmax, const Vector3D& velocity0, const Vector3D& velocity1);

		bool FindSphereVertexIntersection(const Vector3D& vertex, Real tmax, const Vector3D& velocity0, const Vector3D& velocity1);

		// The objects to intersect.
		Triangle3 mTriangle;
		Sphere3 mSphere;

		// The point of contact for dynamic queries.
		Vector3D mPoint;
	};

	using DynamicFindIntersectorTriangle3Sphere3f = DynamicFindIntersectorTriangle3Sphere3<float>;
	using DynamicFindIntersectorTriangle3Sphere3d = DynamicFindIntersectorTriangle3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H
