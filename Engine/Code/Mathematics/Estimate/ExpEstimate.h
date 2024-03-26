/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 09:58)

#ifndef MATHEMATICS_ESTIMATE_EXP_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_EXP_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

#include "Exp2Estimate.h"

/// 形式为f(x) =p(x/log(2))的exp(x) 的极小极大多项式近似，
/// 其中log(2)是2的自然对数，并且D次的多项式p(y)最小化了所有D次多项式{|2^y - p(y)| : y in [0,1]}上的最大数量
/// 使用了标识exp(x) = 2^{x/log(2)}。

namespace Mathematics
{
    constexpr std::array expEstimateMaxError{
        8.6071332055935e-2,  // degree 1
        3.8132476831059e-3,  // degree 2
        1.4694877755229e-4,  // degree 3
        4.7617792662269e-6,  // degree 4
        1.3162098766451e-7,  // degree 5
        3.1590550175765e-9,  // degree 6
        6.7157168714971e-11  // degree 7
    };

    /// 输入约束是[0,log(2)]中的x，其中log(2) 是2的自然对数。例如，3阶的估计值是
    /// float x; // in [0,log(2)]
    /// float result = ExpEstimate<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 7)
    NODISCARD T ExpEstimate(T x);

    /// 输入x可以是任何实数。范围缩减用于在[0,log(2)]中生成值y，
    /// 调用ExpEstimate(y) ，然后将输出与适当的指数组合以获得近似值。例如
    /// float x;  // x >= 0
    /// float result = ExpEstimateReal<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 7)
    NODISCARD T ExpEstimateReal(T x);

    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 7)
    NODISCARD T constexpr GetExpEstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return static_cast<T>(expEstimateMaxError[Degree - 1]);

#include SYSTEM_WARNING_POP
    }
}

#endif  // MATHEMATICS_ESTIMATE_EXP_ESTIMATE_H
