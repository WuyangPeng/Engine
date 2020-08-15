// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/18 19:19)

#ifndef MATHEMATICS_BASE_RANDOM_DETAIL_H
#define MATHEMATICS_BASE_RANDOM_DETAIL_H

#include "Random.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_RANDOM_DETAIL)

#include "MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <algorithm>
#include "CoreTools/ClassInvariant/Noexcept.h"

template <typename Real>
Real Mathematics::Random<Real>
	::UnitRandom(uint32_t seed)
{
    CoreTools::DoNothing();

	if (0 < seed)
		srand(seed);

	auto ratio = (static_cast<Real>(rand())) / (static_cast<Real>(RAND_MAX));

	MATHEMATICS_ASSERTION_3(Math::sm_Zero <= ratio && ratio <= Math::sm_One, "ratio值必须在区间[0,1]！\n");

	return ratio;
}

template <typename Real>
Real Mathematics::Random<Real>
	::SymmetricRandom(uint32_t seed)
{
	auto ratio = (Math::sm_Two * UnitRandom(seed)) - Math::sm_One;

	MATHEMATICS_ASSERTION_3(Math::sm_NegativeOne <= ratio && ratio <= Math::sm_One, "ratio值必须在区间[-1,1]！\n");

	return ratio;
}

template <typename Real>
Real Mathematics::Random<Real>
	::IntervalRandom(Real min, Real max, unsigned int seed)
{
	MATHEMATICS_ASSERTION_3(min <= max, "设定的最小值大于最大值");

	auto ratio = min + (max - min) * UnitRandom(seed);

	MATHEMATICS_ASSERTION_3(min <= ratio && ratio <= max, "ratio值必须在区间[min,max]！\n");

	return ratio;
}

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_RANDOM_DETAIL)

#endif // MATHEMATICS_BASE_RANDOM_DETAIL_H