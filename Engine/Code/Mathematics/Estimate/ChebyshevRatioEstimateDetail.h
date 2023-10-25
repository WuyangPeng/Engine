///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 19:24)

#ifndef MATHEMATICS_ESTIMATE_CHEBYSHEV_RATIO_ESTIMATE_DETAIL_H
#define MATHEMATICS_ESTIMATE_CHEBYSHEV_RATIO_ESTIMATE_DETAIL_H

#include "ChebyshevRatioEstimate.h"

template <typename T, int Degree>
requires(1 <= Degree && Degree <= 16)
std::array<T, 2> Mathematics::ChebyshevRatioEstimate(T t, T x)
{
    // 优化编译器将所需的常量作为文字值加载到寄存器中。
    const std::array<T, 16> a{
        GetChebyshevRatioACoefficient<T, Degree>(0),
        GetChebyshevRatioACoefficient<T, Degree>(1),
        GetChebyshevRatioACoefficient<T, Degree>(2),
        GetChebyshevRatioACoefficient<T, Degree>(3),
        GetChebyshevRatioACoefficient<T, Degree>(4),
        GetChebyshevRatioACoefficient<T, Degree>(5),
        GetChebyshevRatioACoefficient<T, Degree>(6),
        GetChebyshevRatioACoefficient<T, Degree>(7),
        GetChebyshevRatioACoefficient<T, Degree>(8),
        GetChebyshevRatioACoefficient<T, Degree>(9),
        GetChebyshevRatioACoefficient<T, Degree>(10),
        GetChebyshevRatioACoefficient<T, Degree>(11),
        GetChebyshevRatioACoefficient<T, Degree>(12),
        GetChebyshevRatioACoefficient<T, Degree>(13),
        GetChebyshevRatioACoefficient<T, Degree>(14),
        GetChebyshevRatioACoefficient<T, Degree>(15)
    };

    const std::array<T, 16> b{
        GetChebyshevRatioBCoefficient<T, Degree>(0),
        GetChebyshevRatioBCoefficient<T, Degree>(1),
        GetChebyshevRatioBCoefficient<T, Degree>(2),
        GetChebyshevRatioBCoefficient<T, Degree>(3),
        GetChebyshevRatioBCoefficient<T, Degree>(4),
        GetChebyshevRatioBCoefficient<T, Degree>(5),
        GetChebyshevRatioBCoefficient<T, Degree>(6),
        GetChebyshevRatioBCoefficient<T, Degree>(7),
        GetChebyshevRatioBCoefficient<T, Degree>(8),
        GetChebyshevRatioBCoefficient<T, Degree>(9),
        GetChebyshevRatioBCoefficient<T, Degree>(10),
        GetChebyshevRatioBCoefficient<T, Degree>(11),
        GetChebyshevRatioBCoefficient<T, Degree>(12),
        GetChebyshevRatioBCoefficient<T, Degree>(13),
        GetChebyshevRatioBCoefficient<T, Degree>(14),
        GetChebyshevRatioBCoefficient<T, Degree>(15)
    };

    const auto y = Math<T>::GetValue(1) - x;
    auto term0 = Math<T>::GetValue(1) - t;
    auto term1 = t;
    auto sqr0 = term0 * term0;
    auto sqr1 = term1 * term1;

    std::array<T, 2> f{ term0, term1 };
    for (auto i = 0; i < Degree; ++i)
    {
        term0 *= (b[i] - a[i] * sqr0) * y;
        term1 *= (b[i] - a[i] * sqr1) * y;
        f[0] += term0;
        f[1] += term1;
    }

    return f;
}

template <typename T, size_t Degree>
requires(1 <= Degree && Degree <= 12)
std::array<T, 2> Mathematics::ChebyshevRatioEstimateReal(T t, T x)
{
    // 优化编译器将所需的常量作为文字值加载到寄存器中。
    const std::array<T, 12> a{
        GetChebyshevRatioACoefficientReal<T, Degree>(0),
        GetChebyshevRatioACoefficientReal<T, Degree>(1),
        GetChebyshevRatioACoefficientReal<T, Degree>(2),
        GetChebyshevRatioACoefficientReal<T, Degree>(3),
        GetChebyshevRatioACoefficientReal<T, Degree>(4),
        GetChebyshevRatioACoefficientReal<T, Degree>(5),
        GetChebyshevRatioACoefficientReal<T, Degree>(6),
        GetChebyshevRatioACoefficientReal<T, Degree>(7),
        GetChebyshevRatioACoefficientReal<T, Degree>(8),
        GetChebyshevRatioACoefficientReal<T, Degree>(9),
        GetChebyshevRatioACoefficientReal<T, Degree>(10),
        GetChebyshevRatioACoefficientReal<T, Degree>(11)
    };

    const std::array<T, 12> b{
        GetChebyshevRatioBCoefficientReal<T, Degree>(0),
        GetChebyshevRatioBCoefficientReal<T, Degree>(1),
        GetChebyshevRatioBCoefficientReal<T, Degree>(2),
        GetChebyshevRatioBCoefficientReal<T, Degree>(3),
        GetChebyshevRatioBCoefficientReal<T, Degree>(4),
        GetChebyshevRatioBCoefficientReal<T, Degree>(5),
        GetChebyshevRatioBCoefficientReal<T, Degree>(6),
        GetChebyshevRatioBCoefficientReal<T, Degree>(7),
        GetChebyshevRatioBCoefficientReal<T, Degree>(8),
        GetChebyshevRatioBCoefficientReal<T, Degree>(9),
        GetChebyshevRatioBCoefficientReal<T, Degree>(10),
        GetChebyshevRatioBCoefficientReal<T, Degree>(11)
    };

    const auto y = Math<T>::GetValue(1) - x;
    auto term0 = Math<T>::GetValue(1) - t;
    auto term1 = t;
    auto sqr0 = term0 * term0;
    auto sqr1 = term1 * term1;

    std::array<T, 2> f{ term0, term1 };
    for (auto i = 0; i < Degree; ++i)
    {
        term0 *= (b[i] - a[i] * sqr0) * y;
        term1 *= (b[i] - a[i] * sqr1) * y;
        f[0] += term0;
        f[1] += term1;
    }

    return f;
}

#endif  // MATHEMATICS_ESTIMATE_CHEBYSHEV_RATIO_ESTIMATE_DETAIL_H
