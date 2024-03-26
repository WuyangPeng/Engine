/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 13:34)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_ESTIMATE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

/// 对于[0,1]中的t和[0,pi/2]中的A，Chebyshev比为f(t,A) = sin(t*A)/sin(A)。
/// 设x = cos(A) ， y = 1 - cos(A)，都在[0,1]中。作为y的函数， f(t,y)的级数表示为
/// f(t,y) = sum_{i=0}^{infinity} c_{i}(t) y^{i}，
/// 其中c_0(t) = t, c_{i}(t) = c_{i-1}(t)*(i^2 - t^2)/(i*(2*i+1)) for i >= 1。
/// c_{i}(t)是t中阶为 2*i+1的多项式。
/// 导出近似 g(t,y) = sum_{i=0}^{n-1} c_{i}(t) y^{i} + u_n c_{n}(t) y^n。
/// ChebyshevRatioEstimate<T>::Degree实现了该算法。
/// 如果角度A被限制为[0,pi/4]，那么对于相同的计算成本可以获得更好的估计。
/// 所有不同的是u_n值。ChebyshevRatioEstimate<T>::DegreeReal实现了该算法。
/// 函数返回对{f(1-t,A), f(t,A)}，这对于球面线性插值很有用。

namespace Mathematics
{
    // ChebyshevRatio<T>::Degree的常数。
    constexpr std::array chebyshevRatioEstimateU{ 1.5149656562200644050,
                                                  1.6410179946672027729,
                                                  1.7124880779005808851,
                                                  1.7593545031636841358,
                                                  1.7927054757060019163,
                                                  1.8177479632959470113,
                                                  1.8372872973294931409,
                                                  1.8529805143706497006,
                                                  1.8658739107798316681,
                                                  1.8766626700393858052,
                                                  1.8858276947289707159,
                                                  1.8937127486228939599,
                                                  1.9005703533887863266,
                                                  1.9065903281211855624,
                                                  1.9119182032942771965,
                                                  1.9166674811124804201 };

    constexpr std::array chebyshevRatioEstimateMaxError{ 1.8249897492955e-2,
                                                         5.2760601519022e-3,
                                                         1.8055057987877e-3,
                                                         6.7244299646175e-4,
                                                         2.6386437427495e-4,
                                                         1.0731422197408e-4,
                                                         4.4805894183764e-5,
                                                         1.9088088593749e-5,
                                                         8.2629028074211e-6,
                                                         3.6237273527418e-6,
                                                         1.6064797200289e-6,
                                                         7.1872518425665e-7,
                                                         3.2407757655229e-7,
                                                         1.4712279927665e-7,
                                                         6.7187475472075e-8,
                                                         3.0844086507110e-8 };

    template <typename T, int Degree>
    NODISCARD constexpr T GetChebyshevRatioACoefficient(int i)
    {
        return (Degree != (i + 1) ? Math<T>::GetValue(1) : static_cast<T>(chebyshevRatioEstimateU[i])) / (static_cast<T>(i + 1) * static_cast<T>(2 * (i + 1) + 1));
    }

    template <typename T, int Degree>
    NODISCARD constexpr T GetChebyshevRatioBCoefficient(int i)
    {
        return (Degree != (i + 1) ? Math<T>::GetValue(1) : static_cast<T>(chebyshevRatioEstimateU[i])) * static_cast<T>(i + 1) / static_cast<T>(2 * (i + 1) + 1);
    }

    // ChebyshevRatio<T>::DegreeReal的常数。
    constexpr std::array chebyshevRatioEstimateRealU{ 1.1021472152138613865,
                                                      1.1239349540626744073,
                                                      1.1351870374370363059,
                                                      1.1421060160698368602,
                                                      1.1468020192623136211,
                                                      1.1502017494201659531,
                                                      1.1527782928466798751,
                                                      1.1547990001678465344,
                                                      1.1564265502929687024,
                                                      1.1577657226562501069,
                                                      1.1588859375000000185,
                                                      1.1598375000000000767 };

    constexpr std::array chebyshevRatioEstimateRealMaxError{ 8.6832275204274e-4,
                                                             6.6040175097815e-5,
                                                             6.1949661303018e-6,
                                                             6.4578503422564e-7,
                                                             7.1792162659179e-8,
                                                             8.3364721792379e-9,
                                                             9.9903230132981e-10,
                                                             1.2262002524466e-10,
                                                             1.5335510639148e-11,
                                                             1.9472201628901e-12,
                                                             2.5046631435544e-13,
                                                             3.2751579226443e-14 };

    template <typename T, int Degree>
    T constexpr GetChebyshevRatioACoefficientReal(int i)
    {
        return (Degree != (i + 1) ? Math<T>::GetValue(1) : static_cast<T>(chebyshevRatioEstimateRealU[i])) / (static_cast<T>(i + 1) * static_cast<T>(2 * (i + 1) + 1));
    }

    template <typename T, int Degree>
    T constexpr GetChebyshevRatioBCoefficientReal(int i)
    {
        return (Degree != (i + 1) ? Math<T>::GetValue(1) : static_cast<T>(chebyshevRatioEstimateRealU[i])) * static_cast<T>(i + 1) / static_cast<T>(2 * (i + 1) + 1);
    }

    /// 计算f(t,x) = sin(t*A)/sin(A)的估计，
    /// 其中，t在[0,1]中，A在[0,pi/2]中，x = cos(A)在[0,1]中，f0是f(1-t,x)的估计，f1是f(t,x)的估计。
    /// 近似函数是两个变量的多项式。模板参数Degree必须位于{1..16}中。
    /// t中的度数为 2*Degree+1，x中的度数是Degree。
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 16)
    NODISCARD std::array<T, 2> ChebyshevRatioEstimate(T t, T x);

    template <typename T, size_t Degree>
    requires(1 <= Degree && Degree <= 16)
    NODISCARD constexpr T GetChebyshevRatioEstimateMaxError()
    {
        return chebyshevRatioEstimateMaxError[Degree - 1];
    }

    /// 计算f(t,x) = sin(t*A)/sin(A))的估计，
    /// 其中，t在[0,1]中，A在[0,pi/4]中，x = cos(A)在[0,1]中，f0是f(1-t,x)的估计，f1是f(t,x)的估计。
    /// 近似函数是两个变量的多项式。模板参数Degree必须位于{1..12}中。
    /// t中的度数为 2*Degree+1，x中的度数是Degree。
    template <typename T, size_t Degree>
    requires(1 <= Degree && Degree <= 12)
    NODISCARD std::array<T, 2> ChebyshevRatioEstimateReal(T t, T x);

    template <typename T, size_t Degree>
    requires(1 <= Degree && Degree <= 12)
    NODISCARD constexpr T GetChebyshevRatioEstimateRMaxError()
    {
        return static_cast<T>(chebyshevRatioEstimateRealMaxError[Degree - 1]);
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_ESTIMATE_H