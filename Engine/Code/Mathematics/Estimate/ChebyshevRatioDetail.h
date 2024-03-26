/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 13:26)

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
            // �Ƕ�A��(0,pi)�С�
            return std::sin(t * angle) / std::sin(angle);
        }
    }
    else if (Math<T>::Approximate(angle, Math<T>::GetValue(0)))
    {
        // �Ƕ�AΪ0��ʹ��l'Hospital's����
        // lim_{A->0} sin(t*A)/sin(A) = lim_{A->0} t*cos(t*A)/cos(A) = t.��
        return t;
    }

    // �Ƕ�A���� [0,pi)�С�
    THROW_EXCEPTION(SYSTEM_TEXT("��Ч�Ƕ�"))
}

template <typename T>
T Mathematics::ChebyshevRatioUsingCosAngle(T t, T cosAngle)
{
    if (cosAngle < Math<T>::GetValue(1))
    {
        if (cosAngle > Math<T>::GetValue(-1))
        {
            // �Ƕ�A��(0,pi)�С�
            const auto angle = std::acos(cosAngle);

            return std::sin(t * angle) / std::sin(angle);
        }
        else
        {
            // �Ƕ�A��pi��
            THROW_EXCEPTION(SYSTEM_TEXT("��Ч�Ƕ�"))
        }
    }
    else
    {
        // �Ƕ�AΪ0��ʹ��l'Hospital's����
        // lim_{A->0} sin(t*A)/sin(A) = lim_{A->0} t*cos(t*A)/cos(A) = t��
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
            // �Ƕ�A��(0,pi)�С�
            const auto sinAngle = std::sin(angle);
            const std::array<T, 2> f{ std::sin((Math<T>::GetValue(1) - t) * angle) / sinAngle, std::sin(t * angle) / sinAngle };

            return f;
        }
    }
    else if (Math<T>::Approximate(angle, Math<T>::GetValue(0)))
    {
        // �Ƕ�AΪ0��ʹ��l'Hospital's����
        // lim_{A->0} sin(t*A)/sin(A) = lim_{A->0} t*cos(t*A)/cos(A) = t.
        const std::array<T, 2> f{ Math<T>::GetValue(1) - t, t };

        return f;
    }

    // �Ƕ�A����[0,pi)�С�
    THROW_EXCEPTION(SYSTEM_TEXT("��Ч�Ƕ�"))
}

template <typename T>
std::array<T, 2> Mathematics::ChebyshevRatiosUsingCosAngle(T t, T cosAngle)
{
    if (cosAngle < Math<T>::GetValue(1))
    {
        if (cosAngle > -Math<T>::GetValue(1))
        {
            // �Ƕ�A��(0,pi)�С�
            const auto angle = std::acos(cosAngle);
            const auto sinAngle = std::sin(angle);
            const std::array<T, 2> f{ std::sin((Math<T>::GetValue(1) - t) * angle) / sinAngle, std::sin(t * angle) / sinAngle };

            return f;
        }
        else
        {
            // �Ƕ�A��pi��
            THROW_EXCEPTION(SYSTEM_TEXT("��Ч�Ƕ�"))
        }
    }
    else
    {
        // �Ƕ�AΪ0��ʹ��l'Hospital's����
        // lim_{A->0} sin(t*A)/sin(A) = lim_{A->0} t*cos(t*A)/cos(A) = t.
        const std::array<T, 2> f{ Math<T>::GetValue(1) - t, t };

        return f;
    }
}

#endif  // MATHEMATICS_ESTIMATE_CHEBYSHEV_RATIO_DETAIL_H
