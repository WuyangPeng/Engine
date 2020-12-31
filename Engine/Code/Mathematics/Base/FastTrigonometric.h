///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 13:51)

#ifndef MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H
#define MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H

#include "Mathematics/MathematicsDll.h"

#include "Math.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <type_traits>

namespace Mathematics
{
    // 使用快速近似算法的潜力，而不是调用标准的数学库函数。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FastTrigonometric final
    {
    public:
        static_assert(std::is_floating_point_v<Real>, "Real must be floating point.");

        using ClassType = FastTrigonometric<Real>;
        using Math = Math<Real>;

    public:
        // 采用多项式逼近三角函数和反三角函数的快速计算。速度起伏依靠处理器。

        // 输入必须在范围[0,pi/2]

        // 1.0e-3精度
        [[nodiscard]] static Real FastSinRoughCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-6精度（float）、1.0e-8精度（double）
        [[nodiscard]] static Real FastSinPreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7精度（float）、1.0e-10精度（double）
        [[nodiscard]] static Real FastSinMorePreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 输入必须在范围[0,pi/2]

        // 1.0e-2精度
        [[nodiscard]] static Real FastCosRoughCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7精度（float）、1.0e-8精度（double）
        [[nodiscard]] static Real FastCosPreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7精度（float）、1.0e-10精度（double）
        [[nodiscard]] static Real FastCosMorePreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 输入必须在范围[0,pi/4]

        // 1.0e-3精度
        [[nodiscard]] static Real FastTanRoughCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7精度
        [[nodiscard]] static Real FastTanPreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7精度（float）、1.0e-10精度（double）
        [[nodiscard]] static Real FastTanMorePreciseCalculation(Real angle) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 输入必须在范围[0,1]

        // 1.0e-4精度
        [[nodiscard]] static Real FastInvSinRoughCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-6精度（float）、1.0e-7精度（double）
        [[nodiscard]] static Real FastInvSinPreciseCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 输入必须在范围 [0,1]

        // 1.0e-4精度
        [[nodiscard]] static Real FastInvCosRoughCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-6精度（float）、1.0e-7精度（double）
        [[nodiscard]] static Real FastInvCosPreciseCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 输入必须在范围 [-1,1]

        // 1.0e-4精度
        [[nodiscard]] static Real FastInvTanRoughCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-7精度
        [[nodiscard]] static Real FastInvTanPreciseCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
    };

    using FloatFastTrigonometric = FastTrigonometric<float>;
    using DoubleFastTrigonometric = FastTrigonometric<double>;
}

#endif  // MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H
