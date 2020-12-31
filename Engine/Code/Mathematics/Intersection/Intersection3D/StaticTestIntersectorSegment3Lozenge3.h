// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_LOZENGE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Segment3.h"   
#include "Mathematics/Objects3D/Lozenge3.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorSegment3Lozenge3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorSegment3Lozenge3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Lozenge3 = Lozenge3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorSegment3Lozenge3(const Segment3& segment, const Lozenge3& lozenge);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Segment3 GetSegment() const;
                [[nodiscard]] const Lozenge3 GetLozenge() const;

	private:
		// Static intersection query.
		void Test();

	private:
		// The objects to intersect.
		Segment3 m_Segment;
		Lozenge3 mLozenge;
	};

	using FloatStaticTestIntersectorSegment3Lozenge3 = StaticTestIntersectorSegment3Lozenge3<float>;
	using DoubleStaticTestIntersectorSegment3Lozenge3 = StaticTestIntersectorSegment3Lozenge3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_LOZENGE3_H
