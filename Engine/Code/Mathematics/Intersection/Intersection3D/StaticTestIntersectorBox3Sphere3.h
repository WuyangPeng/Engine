// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"  
#include "Mathematics/Objects3D/Sphere3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorBox3Sphere3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorBox3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Box3 = Box3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorBox3Sphere3(const Box3& box, const Sphere3& sphere);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Box3 GetBox() const;
                [[nodiscard]] const Sphere3 GetSphere() const;

	private:
		// Test-intersection query.
		void Test();

		// The objects to intersect.
		Box3 m_Box;
		Sphere3 m_Sphere;
	};

	using FloatStaticTestIntersectorBox3Sphere3 = StaticTestIntersectorBox3Sphere3<float>;
	using DoubleStaticTestIntersectorBox3Sphere3 = StaticTestIntersectorBox3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_SPHERE3_H
