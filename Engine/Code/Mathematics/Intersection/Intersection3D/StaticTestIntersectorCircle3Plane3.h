// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h" 
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorCircle3Plane3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorCircle3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Circle3 = Circle3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorCircle3Plane3(const Circle3& circle, const Plane3& plane);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Circle3 GetCircle() const;
                [[nodiscard]] const Plane3 GetPlane() const;

	private:
		// Static intersection queries.
		void Test();

		// The objects to intersect.
		Circle3 m_Circle;
		Plane3 m_Plane;
	};

	using FloatStaticTestIntersectorCircle3Plane3 = StaticTestIntersectorCircle3Plane3<float>;
	using DoubleStaticTestIntersectorCircle3Plane3 = StaticTestIntersectorCircle3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CIRCLE3_PLANE3_H
