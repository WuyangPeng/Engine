///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/19 17:08)

#ifndef MATHEMATICS_ESTIMATE_LOG_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_LOG_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

#include "Log2Estimate.h"

/// 形式为f(x) = p(x)*log(2)的log(x)的极小极大多项式近似，
/// 其中log(2)是2的自然对数，
/// 其中多项式 p(x)的次数为D，
/// 最小化了所有次数为D的多项式中的最大值{|log2(x) - p(x)| : x in [1,2]}。
/// 使用标识log(x) = log2(x)*log(2)。

namespace Mathematics
{
    /// 输入约束是[1,2]中的x。例如，3阶的估计值是
    /// float x; // in [1,2]
    /// float result = LogEstimate<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD T LogEstimate(T x);

    /// 输入约束是x > 0。范围缩减用于在[1,2]中生成一个值y，调用LogEstimate(y)，然后将x的二进制科学表示中的二次幂指数相加。例如，3阶估计为
    /// float x;  // x > 0
    /// float result = LogEstimateReal<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD T LogEstimateReal(T x);

    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD constexpr T GetLogEstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return GetLog2EstimateMaxError<T, Degree>();

#include SYSTEM_WARNING_POP
    }
}

#endif  // MATHEMATICS_ESTIMATE_LOG_ESTIMATE_H
