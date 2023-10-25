///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/18 16:59)

#ifndef MATHEMATICS_ESTIMATE_EXP2_ESTIMATE_DETAIL_H
#define MATHEMATICS_ESTIMATE_EXP2_ESTIMATE_DETAIL_H

#include "Exp2Estimate.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int Degree>
requires(1 <= Degree && Degree <= 7)
T Mathematics::Exp2Estimate(T x)
{
    constexpr auto select = Degree - 1;
    constexpr auto& coefficient = exp2EstimateCoefficient.at(select);
    constexpr auto last = Degree;
    auto poly = static_cast<T>(coefficient.at(last));
    for (auto i = 0, index = last - 1; i < last; ++i, --index)
    {
        poly = static_cast<T>(coefficient.at(index)) + poly * x;
    }

    return poly;
}

template <typename T, int Degree>
requires(1 <= Degree && Degree <= 7)
T Mathematics::Exp2EstimateReal(T x)
{
    auto p = std::floor(x);
    auto y = x - p;
    auto poly = Exp2Estimate<T, Degree>(y);
    auto power = static_cast<int32_t>(static_cast<double>(p));
    auto result = std::ldexp(poly, power);

    return result;
}

#endif  // MATHEMATICS_ESTIMATE_EXP2_ESTIMATE_DETAIL_H
