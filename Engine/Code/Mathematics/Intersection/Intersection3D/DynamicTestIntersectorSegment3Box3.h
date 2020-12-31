// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"  
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicTestIntersectorSegment3Box3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicTestIntersectorSegment3Box3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		 using Math = typename ParentType::Math;

	public:
		DynamicTestIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid, Real tmax,
										   const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Segment3 GetSegment() const;
                [[nodiscard]] const Box3 GetBox() const;

	private:
		// Dynamic test-intersection query.
		void Test();

		// The objects to intersect.
		Segment3 m_Segment;
		Box3 m_Box;
		bool m_Solid;
	};

	using FloatDynamicTestIntersectorSegment3Box3 = DynamicTestIntersectorSegment3Box3<float>;
	using DoubleDynamicTestIntersectorSegment3Box3 = DynamicTestIntersectorSegment3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H
