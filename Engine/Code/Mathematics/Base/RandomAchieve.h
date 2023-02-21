///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/01/29 11:20)

#ifndef MATHEMATICS_BASE_RANDOM_ACHIEVE_H
#define MATHEMATICS_BASE_RANDOM_ACHIEVE_H

#include "MathDetail.h"
#include "Random.h"

#include <algorithm>

template <typename Real>
Real Mathematics::Random<Real>::UnitRandom(uint32_t seed) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    if (0 < seed)
    {
        srand(seed);
    }

    auto ratio = (static_cast<Real>(rand())) / (static_cast<Real>(RAND_MAX));

    MATHEMATICS_ASSERTION_3(Math::GetValue(0) <= ratio && ratio <= Math::GetValue(1), "ratio值必须在区间[0,1]！\n");

    return ratio;
}

template <typename Real>
Real Mathematics::Random<Real>::SymmetricRandom(uint32_t seed) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    auto ratio = (Math::GetValue(2) * UnitRandom(seed)) - Math::GetValue(1);

    MATHEMATICS_ASSERTION_3(Math::GetValue(-1) <= ratio && ratio <= Math::GetValue(1), "ratio值必须在区间[-1,1]！\n");

    return ratio;
}

template <typename Real>
Real Mathematics::Random<Real>::IntervalRandom(Real min, Real max, uint32_t seed) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_ASSERTION_3(min <= max, "设定的最小值大于最大值");

    auto ratio = min + (max - min) * UnitRandom(seed);

    MATHEMATICS_ASSERTION_3(min <= ratio && ratio <= max, "ratio值必须在区间[min,max]！\n");

    return ratio;
}

#endif  // MATHEMATICS_BASE_RANDOM_ACHIEVE_H