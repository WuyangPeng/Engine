// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:50)

#ifndef MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_H
#define MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_H 

#include "Mathematics/Intersection/Intersector1.h"

namespace Mathematics
{
	template <typename Real>
	class Intersector1Test : public Intersector1<Real>
	{
	public:
		using ClassType = Intersector1Test<Real> ;
		using ParentType = Intersector1<Real>  ;

	public:
		explicit Intersector1Test(Real u0, Real u1, Real v0, Real v1);
		virtual ~Intersector1Test();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		virtual bool IsIntersection() const;
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_H