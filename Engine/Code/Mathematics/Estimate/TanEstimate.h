/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:18)

#ifndef MATHEMATICS_ESTIMATE_TAN_ESTIMATE_H
#define MATHEMATICS_ESTIMATE_TAN_ESTIMATE_H

#include "Mathematics/MathematicsDll.h"

/// tan(x)的极小极大多项式近似。次数为D的多项式 p(x)只有奇数次幂项，要求具有线性项x，并且p(pi/4) = tan(pi/4) = 1。
/// 在上述约束条件下，最小化了所有次数为D的多项式中的最大值{|tan(x) - p(x)| : x in [-pi/4,pi/4]}。
namespace Mathematics
{
    constexpr std::array<std::array<double, 7>, 6> tanEstimateCoefficient{

        { { // degree 3
            1.0,
            4.4295926544736286e-1 },

          { // degree 5
            1.0,
            3.1401320403542421e-1,
            2.0903948109240345e-1 },

          { // degree 7
            1.0,
            3.3607213284422555e-1,
            1.1261037305184907e-1,
            9.8352099470524479e-2 },

          { // degree 9
            1.0,
            3.3299232843941784e-1,
            1.3747843432474838e-1,
            3.7696344813028304e-2,
            4.6097377279281204e-2 },

          { // degree 11
            1.0,
            3.3337224456224224e-1,
            1.3264516053824593e-1,
            5.8145237645931047e-2,
            1.0732193237572574e-2,
            2.1558456793513869e-2 },

          { // degree 13
            1.0,
            3.3332916426394554e-1,
            1.3343404625112498e-1,
            5.3104565343119248e-2,
            2.5355038312682154e-2,
            1.8253255966556026e-3,
            1.0069407176615641e-2 } }

    };

    constexpr std::array tanEstimateMaxError{
        1.1661892256205e-2,  // degree 3
        5.8431854390146e-4,  // degree 5
        3.5418688397793e-5,  // degree 7
        2.2988173248307e-6,  // degree 9
        1.5426258070939e-7,  // degree 11
        1.0550265105991e-8  // degree 13
    };

    /// 输入约束是[-pi/4,pi/4]中的x。例如，3阶的估计值是
    /// float x; // in [-pi/4,pi/4]
    /// float result = TanEstimate<float, 3>(x);
    template <typename T, int Degree>
    requires((Degree & 1) == 1 && 1 <= ((Degree - 1) / 2) && ((Degree - 1) / 2) <= 6)
    NODISCARD T TanEstimate(T x);

    /// 输入x可以是任何实数。范围缩小用于生成[-pi/2,pi/2]中的值y。如果|y| <= pi/4，则对多项式进行求值。
    /// 如果y在(pi/4,pi/2)中，则设置 z = y - pi/4并使用恒等式tan(y) = tan(z + pi/4) = [1 + tan(z)]/[1 - tan(z)]。
    /// 如果y在(-pi/2,-pi/4)中，则设置z = y + pi/4 并使用恒等式tan(y) = tan(z - pi/4) = -[1 - tan(z)]/[1 + tan(z)]。
    /// 在y接近pi/2时进行求值时要小心，因为tan(y) 变为无穷大。
    /// 例如，3度的估计值是
    template <typename T, int Degree>
    requires((Degree & 1) == 1 && 1 <= ((Degree - 1) / 2) && ((Degree - 1) / 2) <= 6)
    NODISCARD T TanEstimateReal(T x);

    template <typename T, int Degree>
    requires((Degree & 1) == 1 && 1 <= ((Degree - 1) / 2) && ((Degree - 1) / 2) <= 6)
    NODISCARD constexpr T GetTanEstimateMaxError()
    {
        return static_cast<T>(tanEstimateMaxError[(Degree - 3) / 2]);
    }
}

#endif  // MATHEMATICS_ESTIMATE_TAN_ESTIMATE_H
