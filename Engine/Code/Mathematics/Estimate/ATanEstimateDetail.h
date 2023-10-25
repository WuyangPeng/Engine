///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/14 15:40)

#ifndef MATHEMATICS_ESTIMATE_ATAN_ESTIMATE_DETAIL_H
#define MATHEMATICS_ESTIMATE_ATAN_ESTIMATE_DETAIL_H

#include "ATanEstimate.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int Degree>
requires((Degree & 1) == 1 && 1 <= (Degree - 1) / 2 && (Degree - 1) / 2 <= 6)
T Mathematics::ATanEstimate(T x)
{
    constexpr auto select = (Degree - 3) / 2;
    constexpr auto& coefficient = aTanEstimateCoefficient.at(select);
    constexpr auto last = (Degree - 1) / 2;
    auto xSquare = x * x;
    auto poly = static_cast<T>(coefficient.at(last));
    for (auto i = 0, index = last - 1; i < last; ++i, --index)
    {
        poly = static_cast<T>(coefficient.at(index)) + poly * xSquare;
    }
    poly = poly * x;

    return poly;
}

template <typename T, int Degree>
requires((Degree & 1) == 1 && 1 <= (Degree - 1) / 2 && (Degree - 1) / 2 <= 6)
T Mathematics::ATanEstimateReal(T x)
{
    if (std::fabs(x) <= Math<T>::GetValue(1))
    {
        return ATanEstimate<T, Degree>(x);
    }
    else if (Math<T>::GetValue(1) < x)
    {
        return Math<T>::GetHalfPI() - ATanEstimate<T, Degree>(Math<T>::GetValue(1) / x);
    }
    else
    {
        return -Math<T>::GetHalfPI() - ATanEstimate<T, Degree>(Math<T>::GetValue(1) / x);
    }
}

#endif  // MATHEMATICS_ESTIMATE_ATAN_ESTIMATE_DETAIL_H
