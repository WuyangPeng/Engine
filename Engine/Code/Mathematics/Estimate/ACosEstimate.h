/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 10:27)

#ifndef MATHEMATICS_ESTIMATE_ACOS_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_ACOS_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning.h"

#include <array>

namespace Mathematics
{
    /// 形式为f(x) = sqrt(1-x)*p(x)的acos(x)近似，
    /// 其中多项式 p(x)的次数为D，
    /// 最小化了所有次数为D的多项式中的最大值{|acos(x)/sqrt(1-x) - p(x)| : x in [0,1]}。

    constexpr std::array<std::array<double, 9>, 8> aCosEstimateCoefficient{
        {

            { // degree 1
              +1.5707963267948966,
              -1.5658276442180141e-1 },

            { // degree 2
              +1.5707963267948966,
              -2.0347053865798365e-1,
              +4.6887774236182234e-2 },

            { // degree 3
              +1.5707963267948966,
              -2.1253291899190285e-1,
              +7.4773789639484223e-2,
              -1.8823635069382449e-2 },

            { // degree 4
              +1.5707963267948966,
              -2.1422258835275865e-1,
              +8.4936675142844198e-2,
              -3.5991475120957794e-2,
              +8.6946239090712751e-3 },

            { // degree 5
              +1.5707963267948966,
              -2.1453292139805524e-1,
              +8.7973089282889383e-2,
              -4.5130266382166440e-2,
              +1.9467466687281387e-2,
              -4.3601326117634898e-3 },

            { // degree 6
              +1.5707963267948966,
              -2.1458939285677325e-1,
              +8.8784960563641491e-2,
              -4.8887131453156485e-2,
              +2.7011519960012720e-2,
              -1.1210537323478320e-2,
              +2.3078166879102469e-3 },

            { // degree 7
              +1.5707963267948966,
              -2.1459960076929829e-1,
              +8.8986946573346160e-2,
              -5.0207843052845647e-2,
              +3.0961594977611639e-2,
              -1.7162031184398074e-2,
              +6.7072304676685235e-3,
              -1.2690614339589956e-3 },

            { // degree 8
              +1.5707963267948966,
              -2.1460143648688035e-1,
              +8.9034700107934128e-2,
              -5.0625279962389413e-2,
              +3.2683762943179318e-2,
              -2.0949278766238422e-2,
              +1.1272900916992512e-2,
              -4.1160981058965262e-3,
              +7.1796493341480527e-4 }

        }
    };

    constexpr std::array aCosEstimateMaxError{
        9.0128265558585e-3,  // degree 1
        8.1851275863199e-4,  // degree 2
        8.8200141836526e-5,  // degree 3
        1.0563052499802e-5,  // degree 4
        1.3535063234649e-6,  // degree 5
        1.8169471727170e-7,  // degree 6
        2.5231622347022e-8,  // degree 7
        3.5952707477805e-9,  // degree 8
    };

    /// 输入约束是[0,1]中的x。例如，3阶的估计值是
    /// float x; // in [0,1]
    /// float result = ACosEstimate<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD T ACosEstimate(T x);

    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD constexpr T GetACosEstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return static_cast<T>(aCosEstimateMaxError[Degree - 1]);

#include SYSTEM_WARNING_POP
    }
}

#endif  // MATHEMATICS_ESTIMATE_ACOS_ESTIMATE_H
