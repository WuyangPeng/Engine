///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/18 19:38)

#ifndef MATHEMATICS_ESTIMATE_TAN_ESTIMATE_DETAIL_H
#define MATHEMATICS_ESTIMATE_TAN_ESTIMATE_DETAIL_H

#include "TanEstimate.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int Degree>
requires((Degree & 1) == 1 && 1 <= ((Degree - 1) / 2) && ((Degree - 1) / 2) <= 6)
T Mathematics::TanEstimate(T x)
{
    constexpr auto select = ((Degree - 3) / 2);
    constexpr auto& coefficient = tanEstimateCoefficient.at(select);
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
requires((Degree & 1) == 1 && 1 <= ((Degree - 1) / 2) && ((Degree - 1) / 2) <= 6)
T Mathematics::TanEstimateReal(T x)
{
    // Map x to r in [-pi,pi].
    // 将x映射到 [-pi,pi]中的r。
    T r = std::remainder(x, Math<T>::GetPI());

    // 用tan(y) = tan(r)将r映射到y在[-pi/2,pi/2]。
    T y{};
    if (r > Math<T>::GetHalfPI())
    {
        y = r - Math<T>::GetPI();
    }
    else if (r < -Math<T>::GetHalfPI())
    {
        y = r + Math<T>::GetPI();
    }
    else
    {
        y = r;
    }

    if (std::fabs(y) <= Math<T>::GetQuarterPI())
    {
        return TanEstimate<T, Degree>(y);
    }
    else if (y > Math<T>::GetQuarterPI())
    {
        T poly = TanEstimate<T, Degree>(y - Math<T>::GetQuarterPI());
        return (Math<T>::GetValue(1) + poly) / (Math<T>::GetValue(1) - poly);
    }
    else
    {
        T poly = TanEstimate<T, Degree>(y + Math<T>::GetQuarterPI());
        return (-Math<T>::GetValue(1) + poly) / (Math<T>::GetValue(1) + poly);
    }
}

#endif  // MATHEMATICS_ESTIMATE_TAN_ESTIMATE_DETAIL_H
