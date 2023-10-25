///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 10:22)

#ifndef MATHEMATICS_ESTIMATE_SQRT_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_SQRT_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

/// sqrt(x)的极小极大多项式近似。
/// 其中多项式 p(x)的次数为D，
/// 最小化了所有次数为D的多项式中的最大值{|sqrt(x) - p(x)| : x in [1,2]}。
namespace Mathematics
{
    constexpr std::array<std::array<double, 9>, 8> sqrtEstimateCoefficient{
        {

            { // degree 1
              +1.0,
              +4.1421356237309505e-1 },

            { // degree 2
              +1.0,
              +4.8563183076125260e-1,
              -7.1418268388157458e-2 },

            { // degree 3
              +1.0,
              +4.9750045320242231e-1,
              -1.0787308044477850e-1,
              +2.4586189615451115e-2 },

            { // degree 4
              +1.0,
              +4.9955939832918816e-1,
              -1.2024066151943025e-1,
              +4.5461507257698486e-2,
              -1.0566681694362146e-2 },

            { // degree 5
              +1.0,
              +4.9992197660031912e-1,
              -1.2378506719245053e-1,
              +5.6122776972699739e-2,
              -2.3128836281145482e-2,
              +5.0827122737047148e-3 },

            { // degree 6
              +1.0,
              +4.9998616695784914e-1,
              -1.2470733323278438e-1,
              +6.0388587356982271e-2,
              -3.1692053551807930e-2,
              +1.2856590305148075e-2,
              -2.6183954624343642e-3 },

            { // degree 7
              +1.0,
              +4.9999754817809228e-1,
              -1.2493243476353655e-1,
              +6.1859954146370910e-2,
              -3.6091595023208356e-2,
              +1.9483946523450868e-2,
              -7.5166134568007692e-3,
              +1.4127567687864939e-3 },

            { // degree 8
              +1.0,
              +4.9999956583056759e-1,
              -1.2498490369914350e-1,
              +6.2318494667579216e-2,
              -3.7982961896432244e-2,
              +2.3642612312869460e-2,
              -1.2529377587270574e-2,
              +4.5382426960713929e-3,
              -7.8810995273670414e-4 }

        }
    };

    constexpr std::array sqrtEstimateMaxError{
        1.7766952966369e-2,  // degree 1
        1.1795695163111e-3,  // degree 2
        1.1309620116485e-4,  // degree 3
        1.2741170151820e-5,  // degree 4
        1.5725569051384e-6,  // degree 5
        2.0584162152560e-7,  // degree 6
        2.8072338675856e-8,  // degree 7
        3.9468401880072e-9  // degree 8
    };

    /// 输入约束是[1,2]中的x。例如，3阶的估计值是
    /// float x; // in [1,2]
    /// float result = SqrtEstimate<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD T SqrtEstimate(T x);

    /// 输入约束是x >= 0。范围缩减用于在[0,1]中生成一个值y，调用SqrtEstimate(y)，然后将输出与适当的指数组合以获得近似值。例如，3阶的估计值是
    /// float x;  // x >= 0
    /// float result = SqrtEstimateReal<float, 3>(x);
    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD T SqrtEstimateReal(T x);

    template <typename T, int Degree>
    requires(1 <= Degree && Degree <= 8)
    NODISCARD constexpr T GetSqrtEstimateMaxError()
    {
        return static_cast<T>(sqrtEstimateMaxError[Degree - 1]);
    }
}

#endif  // MATHEMATICS_ESTIMATE_SQRT_ESTIMATE_H
