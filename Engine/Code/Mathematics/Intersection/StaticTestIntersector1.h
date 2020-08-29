// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:33)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_H

#include "Intersector1.h"

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersector1 : public Intersector1<Real>
	{
	public:
		using ClassType = StaticTestIntersector1<Real>;
		using ParentType = Intersector1<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon = Math::GetZeroTolerance());
		virtual ~StaticTestIntersector1();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		virtual bool IsIntersection() const;
	};

	using StaticTestIntersector1f = StaticTestIntersector1<float>;
	using StaticTestIntersector1d = StaticTestIntersector1<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_H
