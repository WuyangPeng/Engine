/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 10:37)

#ifndef MATHEMATICS_ESTIMATE_ATAN_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_ATAN_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning.h"

#include <array>

namespace Mathematics
{
    /// atan(x)的极小极大多项式近似。
    /// 次数为D的多项式p(x)只有奇数幂项，要求具有线性项x，并且 p(1) = atan(1) = pi/4。
    /// 在上述约束条件下，它最小化了所有D次多项式上的最大数量{|atan(x) - p(x)| : x in [-1,1]}。

    constexpr std::array<std::array<double, 7>, 6> aTanEstimateCoefficient{
        { { // degree 3
            +1.0,
            -2.1460183660255172e-1 },

          { // degree 5
            +1.0,
            -3.0189478312144946e-1,
            +8.7292946518897740e-2 },

          { // degree 7
            +1.0,
            -3.2570157599356531e-1,
            +1.5342994884206673e-1,
            -4.2330209451053591e-2 },

          { // degree 9
            +1.0,
            -3.3157878236439586e-1,
            +1.8383034738018011e-1,
            -8.9253037587244677e-2,
            +2.2399635968909593e-2 },

          { // degree 11
            +1.0,
            -3.3294527685374087e-1,
            +1.9498657165383548e-1,
            -1.1921576270475498e-1,
            +5.5063351366968050e-2,
            -1.2490720064867844e-2 },

          { // degree 13
            +1.0,
            -3.3324998579202170e-1,
            +1.9856563505717162e-1,
            -1.3374657325451267e-1,
            +8.1675882859940430e-2,
            -3.5059680836411644e-2,
            +7.2128853633444123e-3 }

        }
    };

    constexpr std::array aTanEstimateMaxError{
        1.5970326392625e-2,  // degree 3
        1.3509832247375e-3,  // degree 5
        1.5051227215525e-4,  // degree 7
        1.8921598624725e-5,  // degree 9
        2.5477725020825e-6,  // degree 11
        3.5859106295450e-7,  // degree 13
    };

    /// 输入约束是[-1,1]中的x。例如，3阶的估计值是
    /// float x; // in [-1,1]
    /// float result = ATanEstimate<float, 3>(x);
    template <typename T, int Degree>
    requires((Degree & 1) == 1 && 1 <= (Degree - 1) / 2 && (Degree - 1) / 2 <= 6)
    NODISCARD T ATanEstimate(T x);

    /// 输入x可以是任何实数。对于x > 0，通过等式atan(x) = pi/2 - atan(1/x)和对于x<0，通过等式atan(x) = -pi/2 - atan(1/x)。例如
    /// float x;  // x any real number
    /// float result = ATanEstimateReal<float, 3>(x);
    template <typename T, int Degree>
    requires((Degree & 1) == 1 && 1 <= (Degree - 1) / 2 && (Degree - 1) / 2 <= 6)
    NODISCARD T ATanEstimateReal(T x);

    template <typename T, int Degree>
    requires((Degree & 1) == 1 && 1 <= (Degree - 1) / 2 && (Degree - 1) / 2 <= 6)
    NODISCARD constexpr T GetATanEstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return static_cast<T>(aTanEstimateMaxError[(Degree - 3) / 2]);

#include SYSTEM_WARNING_POP
    }
}

#endif  // MATHEMATICS_ESTIMATE_ATAN_ESTIMATE_H
