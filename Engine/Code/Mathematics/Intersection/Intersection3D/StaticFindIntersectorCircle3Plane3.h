// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:49)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h" 
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorCircle3Plane3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorCircle3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Circle3 = Circle3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorCircle3Plane3(const Circle3& circle, const Plane3& plane);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Circle3 GetCircle() const;
                [[nodiscard]] const Plane3 GetPlane() const;

		// Information about the intersection set.  Only get the specific object
		// of intersection corresponding to the intersection type.  If the type
		// is IT_POINT, use GetPoint(i).  If the type is IT_OTHER, the set is a
		// circle, so use GetIntersectionCircle(), which returns the circle
		// object.
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;
                [[nodiscard]] const Circle3 GetIntersectionCircle() const;

	private:
		// Static intersection queries.		
		void Find();

		// The objects to intersect.
		Circle3 m_Circle;
		Plane3 m_Plane;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[2];
	};

	using FloatStaticFindIntersectorCircle3Plane3 = StaticFindIntersectorCircle3Plane3<float>;
	using DoubleStaticFindIntersectorCircle3Plane3 = StaticFindIntersectorCircle3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE3_PLANE3_H
