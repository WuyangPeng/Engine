// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Capsule3.h" 
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLine3Capsule3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorLine3Capsule3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Capsule3 = Capsule3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorLine3Capsule3(const Line3& line, const Capsule3& capsule);

	CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Line3 GetLine() const;
        [[nodiscard]] const Capsule3 GetCapsule() const;

	private:
		// Static intersection queries.
		void Test();

		// The objects to intersect.
		Line3 mLine;
		Capsule3 mCapsule;
	};

	using FloatStaticTestIntersectorLine3Capsule3 = StaticTestIntersectorLine3Capsule3<float>;
	using DoubleStaticTestIntersectorLine3Capsule3 = StaticTestIntersectorLine3Capsule3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_CAPSULE3_H
