///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/14 15:40)

#ifndef MATHEMATICS_BASE_ASIN_ESTIMATE_H
#define MATHEMATICS_BASE_ASIN_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

#include <array>

namespace Mathematics
{
    /// 形式为 f(x) = pi/2 - sqrt(1-x)*p(x)的asin(x)近似，
    /// 其中D次多项式 p(x)使所有D次多项式上的量最大值{|acos(x)/sqrt(1-x) - p(x)| : x in [0,1]} 的最小化。
    /// 使用了恒等式asin(x) = pi/2 - acos(x)。

    constexpr std::array aSinEstimateMaxError{
        9.0128265558586e-3,  // degree 1
        8.1851275863202e-4,  // degree 2
        8.8200141836567e-5,  // degree 3
        1.0563052499871e-5,  // degree 4
        1.3535063235066e-6,  // degree 5
        1.8169471743823e-7,  // degree 6
        2.5231622315797e-8,  // degree 7
        3.5952707963527e-9,  // degree 8
    };

    /// 输入约束是[0,1]中的x。例如，3度的估计值是
    /// float x; // in [0,1]
    /// float result = ASinEstimate<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD T ASinEstimate(T x);

    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD constexpr T GetASinEstimateMaxError()
    {
        return static_cast<T>(aSinEstimateMaxError[Degree - 1]);
    }
}

#endif  // MATHEMATICS_BASE_ASIN_ESTIMATE_H
