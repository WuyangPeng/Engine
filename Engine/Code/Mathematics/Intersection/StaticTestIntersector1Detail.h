// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 15:18)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_DETAIL_H

#include "StaticTestIntersector1.h"
#include "Intersector1Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersector1<Real>
	::StaticTestIntersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon)
	:ParentType{ u0, u1, v0, v1,epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::StaticTestIntersector1<Real>
	::~StaticTestIntersector1()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersector1<Real>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
bool Mathematics::StaticTestIntersector1<Real>
	::IsIntersection() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return (ParentType::GetU(0) - ParentType::GetEpsilon() <= ParentType::GetV(1)) && (ParentType::GetV(0) - ParentType::GetEpsilon() <= ParentType::GetU(1));
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_DETAIL_H

