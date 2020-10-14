// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/18 19:19)

#ifndef MATHEMATICS_BASE_RANDOM_DETAIL_H
#define MATHEMATICS_BASE_RANDOM_DETAIL_H

#include "Random.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_RANDOM_DETAIL)

#include "MathDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <algorithm>
#include "CoreTools/Contract/Noexcept.h"

template <typename Real>
Real Mathematics::Random<Real>
	::UnitRandom(uint32_t seed)
{
    CoreTools::DisableNoexcept();

	if (0 < seed)
		srand(seed);

	auto ratio = (static_cast<Real>(rand())) / (static_cast<Real>(RAND_MAX));

	MATHEMATICS_ASSERTION_3(Math::GetValue(0) <= ratio && ratio <= Math::GetValue(1), "ratioֵ����������[0,1]��\n");

	return ratio;
}

template <typename Real>
Real Mathematics::Random<Real>
	::SymmetricRandom(uint32_t seed)
{
	auto ratio = (Math::GetValue(2) * UnitRandom(seed)) - Math::GetValue(1);

	MATHEMATICS_ASSERTION_3(Math::GetValue(-1) <= ratio && ratio <= Math::GetValue(1), "ratioֵ����������[-1,1]��\n");

	return ratio;
}

template <typename Real>
Real Mathematics::Random<Real>
	::IntervalRandom(Real min, Real max, unsigned int seed)
{
	MATHEMATICS_ASSERTION_3(min <= max, "�趨����Сֵ�������ֵ");

	auto ratio = min + (max - min) * UnitRandom(seed);

	MATHEMATICS_ASSERTION_3(min <= ratio && ratio <= max, "ratioֵ����������[min,max]��\n");

	return ratio;
}

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_RANDOM_DETAIL)

#endif // MATHEMATICS_BASE_RANDOM_DETAIL_H