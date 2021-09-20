// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/30 15:41)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TEST_DETAIL_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TEST_DETAIL_H

#include "StaticIntersectorTest.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, template <typename> class Vector>
Mathematics::StaticIntersectorTest<Real, Vector>
	::StaticIntersectorTest(IntersectionType intersectionType,const Real epsilon)
	:ParentType{ epsilon }
{
	ParentType::SetIntersectionType(intersectionType);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real, template <typename> class Vector>
Mathematics::StaticIntersectorTest<Real, Vector>
	::~StaticIntersectorTest()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real, template <typename> class Vector>
bool Mathematics::StaticIntersectorTest<Real, Vector>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

#endif // MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TEST_DETAIL_H