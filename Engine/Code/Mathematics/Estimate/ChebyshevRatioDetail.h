/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 13:26)

#ifndef MATHEMATICS_ESTIMATE_CHEBYSHEV_RATIO_DETAIL_H
#define MATHEMATICS_ESTIMATE_CHEBYSHEV_RATIO_DETAIL_H

#include "ChebyshevRatio.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename T>
T Mathematics::ChebyshevRatio(T t, T angle)
{
    if (angle > Math<T>::GetValue(0))
    {
        if (angle < Math<T>::GetPI())
        {
            // 角度A在(0,pi)中。
            return std::sin(t * angle) / std::sin(angle);
        }
    }
    else if (Math<T>::Approximate(angle, Math<T>::GetValue(0)))
    {
        // 角度A为0。使用l'Hospital's规则，
        // lim_{A->0} sin(t*A)/sin(A) = lim_{A->0} t*cos(t*A)/cos(A) = t.。
        return t;
    }

    // 角度A不在 [0,pi)中。
    THROW_EXCEPTION(SYSTEM_TEXT("无效角度"))
}

template <typename T>
T Mathematics::ChebyshevRatioUsingCosAngle(T t, T cosAngle)
{
    if (cosAngle < Math<T>::GetValue(1))
    {
        if (cosAngle > Math<T>::GetValue(-1))
        {
            // 角度A在(0,pi)中。
            const auto angle = std::acos(cosAngle);

            return std::sin(t * angle) / std::sin(angle);
        }
        else
        {
            // 角度A是pi。
            THROW_EXCEPTION(SYSTEM_TEXT("无效角度"))
        }
    }
    else
    {
        // 角度A为0。使用l'Hospital's规则，
        // lim_{A->0} sin(t*A)/sin(A) = lim_{A->0} t*cos(t*A)/cos(A) = t。
        return t;
    }
}

template <typename T>
std::array<T, 2> Mathematics::ChebyshevRatios(T t, T angle)
{
    if (angle > Math<T>::GetValue(0))
    {
        if (angle < Math<T>::GetPI())
        {
            // 角度A在(0,pi)中。
            const auto sinAngle = std::sin(angle);
            const std::array<T, 2> f{ std::sin((Math<T>::GetValue(1) - t) * angle) / sinAngle, std::sin(t * angle) / sinAngle };

            return f;
        }
    }
    else if (Math<T>::Approximate(angle, Math<T>::GetValue(0)))
    {
        // 角度A为0。使用l'Hospital's规则，
        // lim_{A->0} sin(t*A)/sin(A) = lim_{A->0} t*cos(t*A)/cos(A) = t.
        const std::array<T, 2> f{ Math<T>::GetValue(1) - t, t };

        return f;
    }

    // 角度A不在[0,pi)中。
    THROW_EXCEPTION(SYSTEM_TEXT("无效角度"))
}

template <typename T>
std::array<T, 2> Mathematics::ChebyshevRatiosUsingCosAngle(T t, T cosAngle)
{
    if (cosAngle < Math<T>::GetValue(1))
    {
        if (cosAngle > -Math<T>::GetValue(1))
        {
            // 角度A在(0,pi)中。
            const auto angle = std::acos(cosAngle);
            const auto sinAngle = std::sin(angle);
            const std::array<T, 2> f{ std::sin((Math<T>::GetValue(1) - t) * angle) / sinAngle, std::sin(t * angle) / sinAngle };

            return f;
        }
        else
        {
            // 角度A是pi。
            THROW_EXCEPTION(SYSTEM_TEXT("无效角度"))
        }
    }
    else
    {
        // 角度A为0。使用l'Hospital's规则，
        // lim_{A->0} sin(t*A)/sin(A) = lim_{A->0} t*cos(t*A)/cos(A) = t.
        const std::array<T, 2> f{ Math<T>::GetValue(1) - t, t };

        return f;
    }
}

#endif  // MATHEMATICS_ESTIMATE_CHEBYSHEV_RATIO_DETAIL_H
