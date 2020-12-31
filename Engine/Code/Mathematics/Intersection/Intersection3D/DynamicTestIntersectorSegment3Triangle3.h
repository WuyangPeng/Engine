// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:47)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"  
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicTestIntersectorSegment3Triangle3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicTestIntersectorSegment3Triangle3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
	 using Math = typename ParentType::Math;

	public:
		DynamicTestIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, Real tmax,
												const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

	CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Segment3 GetSegment() const;
        [[nodiscard]] const Triangle3 GetTriangle() const;

	private:
		// Dynamic test-intersection query.
		void Test();


		// The objects to intersect.
		Segment3 m_Segment;
		Triangle3 m_Triangle;
	};

	using FloatDynamicTestIntersectorSegment3Triangle3 = DynamicTestIntersectorSegment3Triangle3<float>;
	using DoubleDynamicTestIntersectorSegment3Triangle3 = DynamicTestIntersectorSegment3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_TRIANGLE3_H
