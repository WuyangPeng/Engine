// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:51)

#ifndef MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR_TEST_H
#define MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR_TEST_H 

#include "Mathematics/Intersection/Intersector.h"

namespace Mathematics
{
	template <typename Real,template <typename> class Vector>
	class IntersectorTest : public Intersector<Real, Vector>
	{
	public:
		using ClassType = IntersectorTest<Real, Vector> ;
		using ParentType = Intersector<Real, Vector>  ;
		using Math = Math<Real>;

	public:
		explicit IntersectorTest(IntersectionType intersectionType,const Real epsilon = Math::GetZeroTolerance());
		virtual ~IntersectorTest();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR_TEST_H