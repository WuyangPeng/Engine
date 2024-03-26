/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 13:26)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_H

#include "Mathematics/MathematicsDll.h"

#include <array>

/// 对于[0,1]中的t和[0,pi)中的A，Chebyshev比率为f(t,A) = sin(t*A)/sin(A)。
/// 实现ChebyshevRatio计算这个函数。
/// ChebyshevRatios的实现计算对 {f(1-t,A), f(t,A)}，这对于球面线性插值是有用的。
/// 对于接近0或pi的A的评估需要更加稳健。对于0附近的A，sin(t*A)/sin(A)具有可移除的奇点。
/// 使用RAEFGC中的思想进行近似消除奇异性。
/// 对于pi附近的A，奇异性是不可移除的，因此必须使用一些近似，例如ChebyshevRatioEstimate.h中的近似。
namespace Mathematics
{
    /// 角度必须以[0,pi)为单位。
    template <typename T>
    NODISCARD T ChebyshevRatio(T t, T angle);

    /// 从cosAngle中提取的角度在 [0,pi)中。
    template <typename T>
    NODISCARD T ChebyshevRatioUsingCosAngle(T t, T cosAngle);

    /// 角度必须在[0,pi)中。虽然可以计算invSin = 1/sin(angle)（角度）并对f[0]和f[1]执行两次乘法运算，
    /// 但得到的比率通常与ChebyshevRatioAngle的比率不匹配。因此，在该函数中执行两个除法，以确保得到的比率相同。
    template <typename T>
    NODISCARD std::array<T, 2> ChebyshevRatios(T t, T angle);

    /// 从cosAngle中提取的角度为[0,pi)。虽然可以计算invSin = 1/sin(angle)并对f[0]和f[1]进行两次乘法运算，
    /// 但得到的比率通常与ChebyshevRatioAngle中的比率不匹配。因此，在该函数中执行两个除法，以确保得到的比率相同。
    template <typename T>
    NODISCARD std::array<T, 2> ChebyshevRatiosUsingCosAngle(T t, T cosAngle);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_CHEBYSHEV_RATIO_H