// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:40)

#ifndef MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_DETAIL_H
#define MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_DETAIL_H

#include "DynamicIntersectorTest.h"
#include "Mathematics/Intersection/DynamicIntersectorDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersectorTest<Real, Vector>
	::DynamicIntersectorTest(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity,IntersectionType intersectionType, Real contactTime ,const Real epsilon)
	:ParentType{ tMax,lhsVelocity,rhsVelocity,epsilon }
{
	ParentType::SetIntersectionType(intersectionType);
	ParentType::SetContactTime(contactTime);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}


template <typename Real, template <typename> class Vector>
Mathematics::DynamicIntersectorTest<Real, Vector>
	::~DynamicIntersectorTest()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, template <typename> class Vector>
bool Mathematics::DynamicIntersectorTest<Real, Vector>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

#endif // MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_DETAIL_H