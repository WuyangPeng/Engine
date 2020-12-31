// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Segment3.h"   
#include "Mathematics/Objects3D/Ellipsoid3.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorSegment3Ellipsoid3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorSegment3Ellipsoid3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Segment3 = Segment3<Real>;
		using Ellipsoid3 = Ellipsoid3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorSegment3Ellipsoid3(const Segment3& segment, const Ellipsoid3& ellipsoid);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Segment3 GetSegment() const;
                [[nodiscard]] const Ellipsoid3 GetEllipsoid() const;

	private:
		// Static intersection queries.
		void Test();

		// The objects to intersect.
		Segment3 m_Segment;
		Ellipsoid3 mEllipsoid;
	};

	using FloatStaticTestIntersectorSegment3Ellipsoid3 = StaticTestIntersectorSegment3Ellipsoid3<float>;
	using DoubleStaticTestIntersectorSegment3Ellipsoid3 = StaticTestIntersectorSegment3Ellipsoid3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT3_ELLIPSOID3_H
