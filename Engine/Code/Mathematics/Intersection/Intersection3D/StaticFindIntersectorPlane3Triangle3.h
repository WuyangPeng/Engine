// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"  
#include "Mathematics/Objects3D/Triangle3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorPlane3Triangle3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorPlane3Triangle3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		// If you want a fuzzy determination, set the epsilon value to a small
		// positive number.
		StaticFindIntersectorPlane3Triangle3(const Plane3& plane, const Triangle3& triangle, Real epsilon = Math::sm_Zero);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		// Object access.
                [[nodiscard]] const Plane3 GetPlane() const;
                [[nodiscard]] const Triangle3 GetTriangle() const;

		// The intersection set, which is empty, a point, a line segment, or the
		// entire triangle (GetQuantity returns 0, 1, 2, or 3).
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		// Static intersection queries.
		void Find();

		// The objects to intersect.
		Plane3 m_Plane;
		Triangle3 m_Triangle;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[3];

		// For fuzzy arithmetic.
		Real mEpsilon;
	};

	using FloatStaticFindIntersectorPlane3Triangle3 = StaticFindIntersectorPlane3Triangle3<float>;
	using DoubleStaticFindIntersectorPlane3Triangle3 = StaticFindIntersectorPlane3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H
