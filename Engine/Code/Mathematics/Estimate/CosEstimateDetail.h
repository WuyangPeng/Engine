///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/14 15:40)

#ifndef MATHEMATICS_BASE_COS_ESTIMATE_DETAIL_H
#define MATHEMATICS_BASE_COS_ESTIMATE_DETAIL_H

#include "CosEstimate.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int Degree>
requires((Degree & 1) == 0 && 1 <= (Degree / 2) && (Degree / 2) <= 5)
T Mathematics::CosEstimate(T x)
{
    constexpr auto select = (Degree - 2) / 2;
    constexpr auto& coefficient = cosEstimateCoefficient.at(select);
    constexpr auto last = (Degree / 2);
    auto xSquare = x * x;
    auto poly = static_cast<T>(coefficient.at(last));
    for (auto i = 0, index = last - 1; i < last; ++i, --index)
    {
        poly = static_cast<T>(coefficient.at(index)) + poly * xSquare;
    }

    return poly;
}

template <typename T, int Degree>
requires((Degree & 1) == 0 && 1 <= (Degree / 2) && (Degree / 2) <= 5)
T Mathematics::CosEstimateReal(T x)
{
    // 将x映射到[-pi，pi]中的r。
    const auto r = std::remainder(x, Math<T>::GetTwoPI());

    // 将r映射到 [-pi/2,pi/2] 中的y，cos(y) = sign * cos(x)。
    if (Math<T>::GetHalfPI() < r)
    {
        // r在(pi/2,pi]中，所以y = pi - r在 (-pi/2,0]中，sign = -1
        return -CosEstimate<T, Degree>(Math<T>::GetPI() - r);
    }
    else if (r < -Math<T>::GetHalfPI())
    {
        // r在[-pi,-pi/2)中，所以 y = -pi - r 在 [0,pi/2)中，sign = -1
        return -CosEstimate<T, Degree>(-Math<T>::GetPI() - r);
    }
    else
    {
        // r 在 [-pi/2,pi/2]中， y = r, sign = +1
        return CosEstimate<T, Degree>(r);
    }
}

#endif  // MATHEMATICS_BASE_COS_ESTIMATE_DETAIL_H
