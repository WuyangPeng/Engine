﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/09 17:04)

#ifndef MATHEMATICS_ESTIMATE_SLERP_DETAIL_H
#define MATHEMATICS_ESTIMATE_SLERP_DETAIL_H

#include "ChebyshevRatioDetail.h"
#include "Slerp.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T, int N>
requires(N >= 2)
NODISCARD std::array<T, N> Mathematics::Slerp(T t, const std::array<T, N>& q0, const std::array<T, N>& q1)
{
    T cosA{};
    for (auto i = 0; i < N; ++i)
    {
        cosA += q0[i] * q1[i];
    }

    auto f = ChebyshevRatiosUsingCosAngle<T>(t, cosA);
    std::array<T, N> result{};
    std::fill(result.begin(), result.end(), T{});
    for (auto i = 0; i < N; ++i)
    {
        result[i] += f[0] * q0[i] + f[1] * q1[i];
    }
    return result;
}

template <typename T, int N>
requires(N >= 2)
NODISCARD std::array<T, N> Mathematics::Slerp(T t, const std::array<T, N>& q0, const std::array<T, N>& q1, T cosA)
{
    auto f = ChebyshevRatiosUsingCosAngle<T>(t, cosA);

    std::array<T, N> result{};
    result.fill(T{});
    for (auto i = 0; i < N; ++i)
    {
        result[i] += f[0] * q0[i] + f[1] * q1[i];
    }
    return result;
}

template <typename T, int N>
requires(N >= 2)
NODISCARD std::array<T, N> Mathematics::Slerp(T t, const std::array<T, N>& q0, const std::array<T, N>& q1, const std::array<T, N>& qh, T cosAH)
{
    std::array<T, 2> f{};
    std::array<T, N> result{};
    result.fill(Math<T>::GetValue(0));

    auto twoT = Math<T>::GetValue(2) * t;
    if (twoT <= Math<T>::GetValue(1))
    {
        f = ChebyshevRatiosUsingCosAngle<T>(twoT, cosAH);
        for (auto i = 0; i < N; ++i)
        {
            result[i] += f[0] * q0[i] + f[1] * qh[i];
        }
    }
    else
    {
        f = ChebyshevRatiosUsingCosAngle<T>(twoT - C_<T>(1), cosAH);
        for (auto i = 0; i < N; ++i)
        {
            result[i] += f[0] * qh[i] + f[1] * q1[i];
        }
    }
    return result;
}

#endif  // MATHEMATICS_ESTIMATE_SLERP_DETAIL_H
