// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:47)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h"   
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicTestIntersectorSphere3Sphere3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicTestIntersectorSphere3Sphere3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		 using Math = typename ParentType::Math;

	public:
		DynamicTestIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, Real tmax,
											 const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Sphere3 GetSphere0() const;
                [[nodiscard]] const Sphere3 GetSphere1() const;

	private:
		// Dynamic test-intersection query.
		void Test();

		// The objects to intersect.
		Sphere3 m_Sphere0;
		Sphere3 m_Sphere1;
	};

	using FloatDynamicTestIntersectorSphere3Sphere3 = DynamicTestIntersectorSphere3Sphere3<float>;
	using DoubleDynamicTestIntersectorSphere3Sphere3 = DynamicTestIntersectorSphere3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SPHERE3_SPHERE3_H
