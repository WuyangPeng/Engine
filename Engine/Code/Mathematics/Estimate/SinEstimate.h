///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 09:03)

#ifndef MATHEMATICS_ESTIMATE_SIN_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_SIN_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning.h"

#include <array>

/// sin(x)的极小极大多项式近似。
/// 次数为D的多项式p(x)只有奇数次幂项，要求具有线性项x，并且p(pi/2) = sin(pi/2) = 1。
/// 在上述约束条件下，最小化了所有次数为D的多项式中的最大值{|sin(x) - p(x)| : x in [-pi/2,pi/2]}。

namespace Mathematics
{
    constexpr std::array<std::array<double, 6>, 5> sinEstimateCoefficient{
        {

            { // degree 3
              +1.0,
              -1.4727245910375519e-1 },

            { // degree 5
              +1.0,
              -1.6600599923812209e-1,
              +7.5924178409012000e-3 },

            { // degree 7
              +1.0,
              -1.6665578084732124e-1,
              +8.3109378830028557e-3,
              -1.8447486103462252e-4 },

            { // degree 9
              +1.0,
              -1.6666656235308897e-1,
              +8.3329962509886002e-3,
              -1.9805100675274190e-4,
              +2.5967200279475300e-6 },

            { // degree 11
              +1.0,
              -1.6666666601721269e-1,
              +8.3333303183525942e-3,
              -1.9840782426250314e-4,
              +2.7521557770526783e-6,
              -2.3828544692960918e-8 }

        }
    };

    constexpr std::array sinEstimateMaxError{
        1.3481903639146e-2,  // degree 3
        1.4001209384651e-4,  // degree 5
        1.0205878939740e-6,  // degree 7
        5.2010783457846e-9,  // degree 9
        1.9323431743601e-11  // degree 11
    };

    /// 输入约束是[-pi/2,pi/2]中的x。例如，3阶的估计值是
    /// float x; // in [-pi/2,pi/2]
    /// float result = SinEstimate<float, 3>(x);
    template <typename T, int Degree>
    requires((Degree & 1) == 1 && 1 <= ((Degree - 1) / 2) && ((Degree - 1) / 2) <= 5)
    NODISCARD T SinEstimate(T x);

    /// 输入x可以是任何实数。范围缩小用于生成[-pi/2,pi/2]中的值y，其中sin(y) = sin(x)。例如，3阶的估计值是
    /// float x;  // x any real number
    /// float result = SinEstimateReal<float, 3>(x);
    template <typename T, int Degree>
    requires((Degree & 1) == 1 && 1 <= ((Degree - 1) / 2) && ((Degree - 1) / 2) <= 5)
    NODISCARD T SinEstimateReal(T x);

    template <typename T, int Degree>
    requires((Degree & 1) == 1 && 1 <= ((Degree - 1) / 2) && ((Degree - 1) / 2) <= 5)
    NODISCARD T constexpr GetSinEstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return static_cast<T>(sinEstimateMaxError[(Degree - 3) / 2]);

#include SYSTEM_WARNING_POP
    }
}

#endif  // MATHEMATICS_ESTIMATE_SIN_ESTIMATE_H
