// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:54)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Lozenge3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLine3Lozenge3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorLine3Lozenge3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Lozenge3 = Lozenge3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticTestIntersectorLine3Lozenge3(const Line3& line, const Lozenge3& lozenge);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	 [[nodiscard]] const Line3 GetLine() const;
                [[nodiscard]] const Lozenge3 GetLozenge() const;

	private:
		// Static intersection query.
		void Test();

	private:
		// The objects to intersect.
		Line3 mLine;
		Lozenge3 mLozenge;
	};

	using FloatStaticTestIntersectorLine3Lozenge3 = StaticTestIntersectorLine3Lozenge3<float>;
	using DoubleStaticTestIntersectorLine3Lozenge3 = StaticTestIntersectorLine3Lozenge3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_H
