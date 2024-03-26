///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/19 16:38)

#ifndef MATHEMATICS_ESTIMATE_LOG2_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_LOG2_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/PragmaWarning.h"

#include <array>

/// 其中多项式 p(x)的次数为D，
/// 最小化了所有次数为D的多项式中的最大值{|log2(x) - p(x)| : x in [1,2]}。
namespace Mathematics
{
    constexpr std::array<std::array<double, 8>, 8> log2EstimateCoefficient{
        {

            { // degree 1
              +1.0 },

            { // degree 2
              +1.3465553856377803,
              -3.4655538563778032e-1 },

            { // degree 3
              +1.4228653756681227,
              -5.8208556916449616e-1,
              +1.5922019349637218e-1 },

            { // degree 4
              +1.4387257478171547,
              -6.7778401359918661e-1,
              +3.2118898377713379e-1,
              -8.2130717995088531e-2 },

            { // degree 5
              +1.4419170408633741,
              -7.0909645927612530e-1,
              +4.1560609399164150e-1,
              -1.9357573729558908e-1,
              +4.5149061716699634e-2 },

            { // degree 6
              +1.4425449435950917,
              -7.1814525675038965e-1,
              +4.5754919692564044e-1,
              -2.7790534462849337e-1,
              +1.2179791068763279e-1,
              -2.5841449829670182e-2 },

            { // degree 7
              +1.4426664401536078,
              -7.2055423726162360e-1,
              +4.7332419162501083e-1,
              -3.2514018752954144e-1,
              +1.9302965529095673e-1,
              -7.8534970641157997e-2,
              +1.5209108363023915e-2 },

            { // degree 8
              +1.4426896453621882,
              -7.2115893912535967e-1,
              +4.7861716616785088e-1,
              -3.4699935395019565e-1,
              +2.4114048765477492e-1,
              -1.3657398692885181e-1,
              +5.1421382871922106e-2,
              -9.1364020499895560e-3 }

        }
    };

    constexpr std::array log2EstimateMaxError{
        8.6071332055935e-2,  // degree 1
        7.6362868906659e-3,  // degree 2
        8.7902902652948e-4,  // degree 3
        1.1318551356388e-4,  // degree 4
        1.5521274483455e-5,  // degree 5
        2.2162052037978e-6,  // degree 6
        3.2546558681457e-7,  // degree 7
        4.8798286744756e-8  // degree 8
    };

    /// 输入约束是[1,2]中的x。例如，3阶的估计值是
    /// float x; // in [1,2]
    /// float result = Log2Estimate<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD T Log2Estimate(T x);

    /// 输入约束是x > 0。范围缩减用于在[1,2]中生成一个值y，调用Log2Estimate(y) ，然后将x的二进制科学表示中的二次幂指数相加。例如，3阶估计为
    /// float x;  // x > 0
    /// float result = Log2EstimateReal<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD T Log2EstimateReal(T x);

    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD constexpr T GetLog2EstimateMaxError()
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        return static_cast<T>(log2EstimateMaxError[Degree - 1]);

#include SYSTEM_WARNING_POP
    }
}

#endif  // MATHEMATICS_ESTIMATE_LOG2_ESTIMATE_H
