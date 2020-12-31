// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:58)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"  
#include "Mathematics/Objects3D/Triangle3.h"   
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorPlane3Triangle3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorPlane3Triangle3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Plane3 = Plane3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		// If you want a fuzzy determination, set the epsilon value to a small
		// positive number.
		StaticTestIntersectorPlane3Triangle3(const Plane3& plane, const Triangle3& triangle, Real epsilon = Math::sm_Zero);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Plane3 GetPlane() const;
                [[nodiscard]] const Triangle3 GetTriangle() const;

	private:
		// Static intersection queries.
		void Test();

		// The objects to intersect.
		Plane3 m_Plane;
		Triangle3 m_Triangle;

		// For fuzzy arithmetic.
		Real mEpsilon;
	};

	using FloatStaticTestIntersectorPlane3Triangle3 = StaticTestIntersectorPlane3Triangle3<float>;
	using DoubleStaticTestIntersectorPlane3Triangle3 = StaticTestIntersectorPlane3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_TRIANGLE3_H
