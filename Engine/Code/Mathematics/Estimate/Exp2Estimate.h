///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/18 16:54)

#ifndef MATHEMATICS_ESTIMATE_EXP2_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_EXP2_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

#include <array>

/// 2^x的极小极大多项式近似。
/// 其中多项式 p(x)的次数为D，
/// 最小化了所有次数为D的多项式中的最大值{|2^x - p(x)| : x in [0,1]} 。
namespace Mathematics
{
    constexpr std::array<std::array<double, 8>, 7> exp2EstimateCoefficient{
        {

            { // degree 1
              1.0,
              1.0 },

            { // degree 2
              1.0,
              6.5571332605741528e-1,
              3.4428667394258472e-1 },

            { // degree 3
              1.0,
              6.9589012084456225e-1,
              2.2486494900110188e-1,
              7.9244930154334980e-2 },

            { // degree 4
              1.0,
              6.9300392358459195e-1,
              2.4154981722455560e-1,
              5.1744260331489045e-2,
              1.3701998859367848e-2 },

            { // degree 5
              1.0,
              6.9315298010274962e-1,
              2.4014712313022102e-1,
              5.5855296413199085e-2,
              8.9477503096873079e-3,
              1.8968500441332026e-3 },

            { // degree 6
              1.0,
              6.9314698914837525e-1,
              2.4023013440952923e-1,
              5.5481276898206033e-2,
              9.6838443037086108e-3,
              1.2388324048515642e-3,
              2.1892283501756538e-4 },

            { // degree 7
              1.0,
              6.9314718588750690e-1,
              2.4022637363165700e-1,
              5.5505235570535660e-2,
              9.6136265387940512e-3,
              1.3429234504656051e-3,
              1.4299202757683815e-4,
              2.1662892777385423e-5 }

        }
    };

    constexpr std::array exp2EstimateMaxError{
        8.6071332055935e-2,  // degree 1
        3.8132476831059e-3,  // degree 2
        1.4694877755229e-4,  // degree 3
        4.7617792662269e-6,  // degree 4
        1.3162098788655e-7,  // degree 5
        3.1590552396211e-9,  // degree 6
        6.7157390759576e-11  // degree 7
    };

    /// 输入约束是[0,1]中的x。例如，3阶的估计值是
    /// float x; // in [0,1]
    /// float result = Exp2Estimate<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 7)
    NODISCARD T Exp2Estimate(T x);

    /// 输入x可以是任何实数。范围缩减用于在[0,1]中生成一个值y，调用Exp2Estimate(y)，然后将输出与适当的指数组合以获得近似值。例如，3阶的估计值是
    /// float x;  // x >= 0
    /// float result = Exp2EstimateReal<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 7)
    NODISCARD T Exp2EstimateReal(T x);

    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 7)
    NODISCARD constexpr T GetExp2EstimateMaxError()
    {
        return static_cast<T>(exp2EstimateMaxError[Degree - 1]);
    }
}

#endif  // MATHEMATICS_ESTIMATE_EXP2_ESTIMATE_H
