/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 10:27)

#ifndef MATHEMATICS_ESTIMATE_ACOS_ESTIMATE_DETAIL_H
#define MATHEMATICS_ESTIMATE_ACOS_ESTIMATE_DETAIL_H

#include "ACosEstimate.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int Degree>
requires(1 <= Degree && Degree <= 8)
T Mathematics::ACosEstimate(T x)
{
    constexpr auto select = Degree - 1;
    constexpr auto& coefficient = aCosEstimateCoefficient.at(select);
    constexpr auto last = Degree;
    auto poly = static_cast<T>(coefficient.at(last));
    for (auto i = 0, index = last - 1; i < last; ++i, --index)
    {
        poly = static_cast<T>(coefficient.at(index)) + poly * x;
    }
    poly = poly * std::sqrt(Math<T>::GetValue(1) - x);

    return poly;
}

#endif  // MATHEMATICS_ESTIMATE_ACOS_ESTIMATE_DETAIL_H
