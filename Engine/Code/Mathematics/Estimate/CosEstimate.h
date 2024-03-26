/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 17:11)

#ifndef MATHEMATICS_ESTIMATE_COS_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_COS_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning.h"

#include <array>

/// cos(x)的极小极大多项式近似。
/// 次数为D的多项式p(x)只有偶数幂项，要求具有常数项1，并且p(pi/2) = cos(pi/2) = 0。
/// 在上述约束条件下，它最小化了所有D次多项式上{|cos(x) - p(x)| : x in [-pi/2,pi/2]}中的最大数量。
namespace Mathematics
{
    constexpr std::array<std::array<double, 6>, 5> cosEstimateCoefficient{
        {

            { // degree 2
              +1.0,
              -4.0528473456935105e-1 },

            { // degree 4
              +1.0,
              -4.9607181958647262e-1,
              +3.6794619653489236e-2 },

            { // degree 6
              +1.0,
              -4.9992746217057404e-1,
              +4.1493920348353308e-2,
              -1.2712435011987822e-3 },

            { // degree 8
              +1.0,
              -4.9999925121358291e-1,
              +4.1663780117805693e-2,
              -1.3854239405310942e-3,
              +2.3154171575501259e-5 },

            { // degree 10
              +1.0,
              -4.9999999508695869e-1,
              +4.1666638865338612e-2,
              -1.3888377661039897e-3,
              +2.4760495088926859e-5,
              -2.6051615464872668e-7 }

        }
    };

    constexpr std::array cosEstimateMaxError{
        5.6009595954128e-2,  // degree 2
        9.1879932449727e-4,  // degree 4
        9.2028470144446e-6,  // degree 6
        5.9804535233743e-8,  // degree 8
        2.7008567604626e-10  // degree 10
    };

    /// 输入约束是 [-pi/2,pi/2]中的x。例如，4阶的估计值是
    /// float x; // in [-pi/2,pi/2]
    /// float result = CosEstimate<float, 4>(x);
    template <typename T, int Degree>
    requires((Degree & 1) == 0 && 1 <= (Degree / 2) && (Degree / 2) <= 5)
    NODISCARD T CosEstimate(T x);

    /// 输入x可以是任何实数。范围缩小用于生成 [-pi/2,pi/2]中的值y和 cos(y) = s * cos(x)的符号s。例如，4阶的估计值是
    /// float x;  // x any real number
    /// float result = CosEstimateReal<float, 4>(x);
    template <typename T, int Degree>
    requires((Degree & 1) == 0 && 1 <= (Degree / 2) && (Degree / 2) <= 5)
    NODISCARD T CosEstimateReal(T x);

    template <typename T, int Degree>
    requires((Degree & 1) == 0 && 1 <= (Degree / 2) && (Degree / 2) <= 5)
    NODISCARD constexpr T GetCosEstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return static_cast<T>(cosEstimateMaxError[(Degree - 2) / 2]);

#include SYSTEM_WARNING_POP
    }
}

#endif  // MATHEMATICS_ESTIMATE_COS_ESTIMATE_H
