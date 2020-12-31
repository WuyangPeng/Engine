// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:47)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Sphere3.h" 
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicTestIntersectorSegment3Sphere3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicTestIntersectorSegment3Sphere3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		 using Math = typename ParentType::Math;

	public:
		DynamicTestIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, Real tmax,
											  const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

     CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Segment3 GetSegment() const;
     [[nodiscard]] const Sphere3 GetSphere() const;

	private:
		// Dynamic test-intersection query.
		void Test();

		Real ZeroThreshold;  // default = Math<Real>::GetZeroTolerance()

		// The objects to intersect.
		Segment3 m_Segment;
		Sphere3 m_Sphere;
	};

	using FloatDynamicTestIntersectorSegment3Sphere3 = DynamicTestIntersectorSegment3Sphere3<float>;
	using DoubleDynamicTestIntersectorSegment3Sphere3 = DynamicTestIntersectorSegment3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_SPHERE3_H
