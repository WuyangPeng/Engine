///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 09:57)

#ifndef MATHEMATICS_BASE_RANDOM_ACHIEVE_H
#define MATHEMATICS_BASE_RANDOM_ACHIEVE_H

#include "MathDetail.h"
#include "Random.h"
#include "CoreTools/Time/CustomTime.h"

#include <algorithm>
#include <chrono>
#include <random>

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::Random<Real>::UnitRandom(uint32_t seed)
{
    if (0 < seed)
    {
        srand(seed);
    }

    const auto currentTime = std::chrono::system_clock::now().time_since_epoch();
    const auto timestamp = boost::numeric_cast<uint32_t>(std::chrono::duration_cast<std::chrono::seconds>(currentTime).count());

    std::default_random_engine generator{ timestamp };
    std::uniform_int_distribution<> randomDistribution{ 0, RAND_MAX };

    const auto ratio = (static_cast<Real>(randomDistribution(generator))) / (static_cast<Real>(RAND_MAX));

    MATHEMATICS_ASSERTION_3(MathType::GetValue(0) <= ratio && ratio <= MathType::GetValue(1), "ratio值必须在区间[0,1]！\n");

    return ratio;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::Random<Real>::SymmetricRandom(uint32_t seed)
{
    const auto ratio = (MathType::GetValue(2) * UnitRandom(seed)) - MathType::GetValue(1);

    MATHEMATICS_ASSERTION_3(MathType::GetValue(-1) <= ratio && ratio <= MathType::GetValue(1), "ratio值必须在区间[-1,1]！\n");

    return ratio;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Real Mathematics::Random<Real>::IntervalRandom(Real min, Real max, uint32_t seed)
{
    MATHEMATICS_ASSERTION_3(min <= max, "设定的最小值大于最大值");

    const auto ratio = min + (max - min) * UnitRandom(seed);

    MATHEMATICS_ASSERTION_3(min <= ratio && ratio <= max, "ratio值必须在区间[min,max]！\n");

    return ratio;
}

#endif  // MATHEMATICS_BASE_RANDOM_ACHIEVE_H