// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_H

#include "Mathematics/MathematicsDll.h" 

#include "Mathematics/Objects3D/Box3.h" 
#include "Mathematics/Objects3D/Triangle3.h"  
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorTriangle3Box3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorTriangle3Box3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Triangle3 = Triangle3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
                StaticTestIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Triangle3 GetTriangle() const;
                [[nodiscard]] const Box3 GetBox() const;

		// Static test-intersection query.
		void Test();

		// The objects to intersect.
		Triangle3 m_Triangle;
		Box3 m_Box;
	};

	using FloatStaticTestIntersectorTriangle3Box3 = StaticTestIntersectorTriangle3Box3<float>;
	using DoubleStaticTestIntersectorTriangle3Box3 = StaticTestIntersectorTriangle3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_BOX3_H
