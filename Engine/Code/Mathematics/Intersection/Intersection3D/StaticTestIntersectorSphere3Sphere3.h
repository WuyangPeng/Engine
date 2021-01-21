// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Circle3.h"   
#include "Mathematics/Objects3D/Sphere3.h"  
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorSphere3Sphere3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorSphere3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
                StaticTestIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, const Real epsilon = Math::GetZeroTolerance());

	CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Sphere3 GetSphere0() const;
        [[nodiscard]] const Sphere3 GetSphere1() const;

	private:
		// Static test-intersection query.
		void Test();

		// The objects to intersect.
		Sphere3 m_Sphere0;
		Sphere3 m_Sphere1;
	};

	using FloatStaticTestIntersectorSphere3Sphere3 = StaticTestIntersectorSphere3Sphere3<float>;
	using DoubleStaticTestIntersectorSphere3Sphere3 = StaticTestIntersectorSphere3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H
