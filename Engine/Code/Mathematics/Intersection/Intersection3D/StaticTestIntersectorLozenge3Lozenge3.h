// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:54)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Lozenge3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorLozenge3Lozenge3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorLozenge3Lozenge3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Lozenge3 = Lozenge3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
                StaticTestIntersectorLozenge3Lozenge3(const Lozenge3& lozenge0, const Lozenge3& lozenge1, const Real epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Lozenge3 GetLozenge0() const;
                [[nodiscard]] const Lozenge3 GetLozenge1() const;

		// Static intersection query.
		void Test();

	private:
		// The objects to intersect.
		Lozenge3 mLozenge0;
		Lozenge3 mLozenge1;
	};

	using FloatStaticTestIntersectorLozenge3Lozenge3 = StaticTestIntersectorLozenge3Lozenge3<float>;
	using DoubleStaticTestIntersectorLozenge3Lozenge3 = StaticTestIntersectorLozenge3Lozenge3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_H
