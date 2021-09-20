// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:50)

#ifndef MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_H
#define MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_H 

#include "Mathematics/Intersection/DynamicIntersector.h"

namespace Mathematics
{
	template <typename Real,
		      template <typename> class Vector>
	class DynamicIntersectorTest : public DynamicIntersector<Real, Vector>
	{
	public:
		using ClassType = DynamicIntersectorTest<Real, Vector> ;
		using ParentType = DynamicIntersector<Real, Vector>  ;
		using VectorType = Vector<Real>;
		using Math = Math<Real>;

	public:
		explicit DynamicIntersectorTest(Real tMax, const VectorType& lhsVelocity,const VectorType& rhsVelocity,
										IntersectionType intersectionType, Real contactTime,const Real epsilon = Math::GetZeroTolerance());
		virtual ~DynamicIntersectorTest();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};
}

#endif // MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_H