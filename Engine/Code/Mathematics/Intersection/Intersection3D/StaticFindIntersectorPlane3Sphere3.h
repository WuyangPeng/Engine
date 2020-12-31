// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"  
#include "Mathematics/Objects3D/Sphere3.h" 
#include "Mathematics/Objects3D/Circle3.h"  
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorPlane3Sphere3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorPlane3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Circle3 = Circle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorPlane3Sphere3(const Plane3& plane, const Sphere3& sphere);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Plane3 GetPlane() const;
                [[nodiscard]] const Sphere3 GetSphere() const;

		// Culling support.  The view frustum is assumed to be on the positive
		// side of the plane.  The sphere is culled if it is on the negative
		// side of the plane.
                [[nodiscard]] bool SphereIsCulled() const;

		// The intersection set.  The circle is valid only when Find() returns
		// 'true'.  If the intersection does not exist, the circle radius is
		// set to -1 as an additional indication that the circle is not valid.
                [[nodiscard]] const Circle3 GetCircle() const;

	private:
		// Static intersection queries.
		void Find();

	private:
		// The objects to intersect.
		Plane3 m_Plane;
		Sphere3 m_Sphere;

		// The intersection set.
		Circle3 m_Circle;
	};

	using FloatStaticFindIntersectorPlane3Sphere3 = StaticFindIntersectorPlane3Sphere3<float>;
	using DoubleStaticFindIntersectorPlane3Sphere3 = StaticFindIntersectorPlane3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_H
