/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 13:26)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_H

#include "Mathematics/MathematicsDll.h"

#include <array>

/// ����[0,1]�е�t��[0,pi)�е�A��Chebyshev����Ϊf(t,A) = sin(t*A)/sin(A)��
/// ʵ��ChebyshevRatio�������������
/// ChebyshevRatios��ʵ�ּ���� {f(1-t,A), f(t,A)}��������������Բ�ֵ�����õġ�
/// ���ڽӽ�0��pi��A��������Ҫ�����Ƚ�������0������A��sin(t*A)/sin(A)���п��Ƴ�����㡣
/// ʹ��RAEFGC�е�˼����н������������ԡ�
/// ����pi������A���������ǲ����Ƴ��ģ���˱���ʹ��һЩ���ƣ�����ChebyshevRatioEstimate.h�еĽ��ơ�
namespace Mathematics
{
    /// �Ƕȱ�����[0,pi)Ϊ��λ��
    template <typename T>
    NODISCARD T ChebyshevRatio(T t, T angle);

    /// ��cosAngle����ȡ�ĽǶ��� [0,pi)�С�
    template <typename T>
    NODISCARD T ChebyshevRatioUsingCosAngle(T t, T cosAngle);

    /// �Ƕȱ�����[0,pi)�С���Ȼ���Լ���invSin = 1/sin(angle)���Ƕȣ�����f[0]��f[1]ִ�����γ˷����㣬
    /// ���õ��ı���ͨ����ChebyshevRatioAngle�ı��ʲ�ƥ�䡣��ˣ��ڸú�����ִ��������������ȷ���õ��ı�����ͬ��
    template <typename T>
    NODISCARD std::array<T, 2> ChebyshevRatios(T t, T angle);

    /// ��cosAngle����ȡ�ĽǶ�Ϊ[0,pi)����Ȼ���Լ���invSin = 1/sin(angle)����f[0]��f[1]�������γ˷����㣬
    /// ���õ��ı���ͨ����ChebyshevRatioAngle�еı��ʲ�ƥ�䡣��ˣ��ڸú�����ִ��������������ȷ���õ��ı�����ͬ��
    template <typename T>
    NODISCARD std::array<T, 2> ChebyshevRatiosUsingCosAngle(T t, T cosAngle);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_H