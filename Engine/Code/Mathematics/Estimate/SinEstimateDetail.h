///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 09:06)

#ifndef MATHEMATICS_ESTIMATE_SIN_ESTIMATE_DETAIL_H
#define MATHEMATICS_ESTIMATE_SIN_ESTIMATE_DETAIL_H

#include "SinEstimate.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int Degree>
requires((Degree & 1) == 1 && 1 <= ((Degree - 1) / 2) && ((Degree - 1) / 2) <= 5)
T Mathematics::SinEstimate(T x)
{
    constexpr auto select = ((Degree - 3) / 2);
    constexpr auto& coefficient = sinEstimateCoefficient.at(select);
    constexpr auto last = ((Degree - 1) / 2);
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
requires((Degree & 1) == 1 && 1 <= ((Degree - 1) / 2) && ((Degree - 1) / 2) <= 5)
T Mathematics::SinEstimateReal(T x)
{
    // 将x映射到[-pi,pi]中的r。
    const auto r = std::remainder(x, Math<T>::GetTwoPI());

    // 用sin(y) = sin(x)将R映射到y在[-pi/2,pi/2] 中。
    if (Math<T>::GetHalfPI() < r)
    {
        // r在(pi/2,pi]中，所以 y = pi - r在(-pi/2,0]中。
        return SinEstimate<T, Degree>(Math<T>::GetPI() - r);
    }
    else if (r < -Math<T>::GetHalfPI())
    {
        // r在[-pi,-pi/2)中，所以 y = -pi - r 在[0,pi/2)中
        return SinEstimate<T, Degree>(-Math<T>::GetPI() - r);
    }
    else
    {
        // r在 [-pi/2,pi/2]中，y = r
        return SinEstimate<T, Degree>(r);
    }
}

#endif  // MATHEMATICS_ESTIMATE_SIN_ESTIMATE_DETAIL_H
