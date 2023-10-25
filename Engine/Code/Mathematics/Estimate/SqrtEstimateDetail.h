///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/18 19:38)

#ifndef MATHEMATICS_ESTIMATE_SQRT_ESTIMATE_DETAIL_H
#define MATHEMATICS_ESTIMATE_SQRT_ESTIMATE_DETAIL_H

#include "SqrtEstimate.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int Degree>
requires(1 <= Degree && Degree <= 8)
T Mathematics::SqrtEstimate(T x)
{
    constexpr auto select = Degree - 1;
    constexpr auto& coefficient = sqrtEstimateCoefficient.at(select);
    constexpr auto last = Degree;
    auto t = x - Math<T>::GetValue(1);  // t 在 [0,1]
    auto poly = static_cast<T>(coefficient.at(last));
    for (auto i = 0, index = last - 1; i < last; ++i, --index)
    {
        poly = static_cast<T>(coefficient.at(index)) + poly * t;
    }

    return poly;
}

template <typename T, int Degree>
requires(1 <= Degree && Degree <= 8)
T Mathematics::SqrtEstimateReal(T x)
{
    // 应用减少。
    auto p = 0;
    auto y = std::frexp(x, &p);  // y 在 [1/2,1)
    y = Math<T>::GetValue(2) * y;  // y 在 [1,2)
    --p;
    auto adj = static_cast<T>(1 & p) * Math<T>::GetSqrt2() + static_cast<T>(1 & ~p) * Math<T>::GetValue(1);
    p >>= 1;

    /// 评估缩小范围上的多项式。
    auto poly = SqrtEstimate<T, Degree>(y);

    // 合并输出。
    auto result = adj * std::ldexp(poly, p);

    return result;
}

#endif  // MATHEMATICS_ESTIMATE_SQRT_ESTIMATE_DETAIL_H
