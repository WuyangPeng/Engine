// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CONE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Cone3.h" 
#include "Mathematics/Objects3D/Triangle3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorTriangle3Cone3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorTriangle3Cone3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Triangle3 = Triangle3<Real>;
		using Cone3 = Cone3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorTriangle3Cone3(const Triangle3& triangle, const Cone3& cone);

CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Triangle3 GetTriangle() const;
[[nodiscard]] const Cone3 GetCone() const;

	private:
		// Static query.
		void Test();

	private:
		// The objects to intersect.
		Triangle3 m_Triangle;
		Cone3 mCone;
	};

	using FloatStaticTestIntersectorTriangle3Cone3 = StaticTestIntersectorTriangle3Cone3<float>;
	using DoubleStaticTestIntersectorTriangle3Cone3 = StaticTestIntersectorTriangle3Cone3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CONE3_H
