///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/19 15:54)

#ifndef MATHEMATICS_ESTIMATE_INV_SQRT_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_INV_SQRT_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning.h"

#include <array>

/// 1/sqrt(x)的极小极大多项式近似。
/// 其中多项式 p(x)的次数为D，
/// 最小化了所有次数为D的多项式中的最大值{|1/sqrt(x) - p(x)| : x in [1,2]} 。
namespace Mathematics
{
    constexpr std::array<std::array<double, 9>, 8> inv2SqrtEstimateCoefficient{
        {

            { // degree 1
              +1.0,
              -2.9289321881345254e-1 },

            { // degree 2
              +1.0,
              -4.4539812104566801e-1,
              +1.5250490223221547e-1 },

            { // degree 3
              +1.0,
              -4.8703230993068791e-1,
              +2.8163710486669835e-1,
              -8.7498013749463421e-2 },

            { // degree 4
              +1.0,
              -4.9710061558048779e-1,
              +3.4266247597676802e-1,
              -1.9106356536293490e-1,
              +5.2608486153198797e-2 },

            { // degree 5
              +1.0,
              -4.9937760586004143e-1,
              +3.6508741295133973e-1,
              -2.5884890281853501e-1,
              +1.3275782221320753e-1,
              -3.2511945299404488e-2 },

            { // degree 6
              +1.0,
              -4.9987029229547453e-1,
              +3.7220923604495226e-1,
              -2.9193067713256937e-1,
              +1.9937605991094642e-1,
              -9.3135712130901993e-2,
              +2.0458166789566690e-2 },

            { // degree 7
              +1.0,
              -4.9997357250704977e-1,
              +3.7426216884998809e-1,
              -3.0539882498248971e-1,
              +2.3976005607005391e-1,
              -1.5410326351684489e-1,
              +6.5598809723041995e-2,
              -1.3038592450470787e-2 },

            { // degree 8
              +1.0,
              -4.9999471066120371e-1,
              +3.7481415745794067e-1,
              -3.1023804387422160e-1,
              +2.5977002682930106e-1,
              -1.9818790717727097e-1,
              +1.1882414252613671e-1,
              -4.6270038088550791e-2,
              +8.3891541755747312e-3 }

        }
    };

    constexpr std::array inv2SqrtEstimateMaxError{
        3.7814314552702e-2,  // degree 1
        4.1953446330581e-3,  // degree 2
        5.6307702007275e-4,  // degree 3
        8.1513919990229e-5,  // degree 4
        1.2289367490981e-5,  // degree 5
        1.9001451476708e-6,  // degree 6
        2.9887737629242e-7,  // degree 7
        4.7597402907940e-8  // degree 8
    };

    /// 输入约束是[1,2]中的x。例如，3阶的估计值是
    /// float x; // in [1,2]
    /// float result = InvSqrtEstimate<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD T InvSqrtEstimate(T x);

    /// 输入约束是x > 0。范围缩减用于在[1,2]中生成一个值y，调用InvSqrtEstimate(y) ，然后将输出与适当的指数组合以获得近似值。例如，3阶的估计值是
    /// float x;  // x > 0
    /// float result = InvSqrtEstimateReal<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD T InvSqrtEstimateReal(T x);

    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD constexpr T GetInvSqrtEstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return static_cast<T>(inv2SqrtEstimateMaxError[Degree - 1]);

#include SYSTEM_WARNING_POP
    }
}

#endif  // MATHEMATICS_ESTIMATE_INV_SQRT_ESTIMATE_H
