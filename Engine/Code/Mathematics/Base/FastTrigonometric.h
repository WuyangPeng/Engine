///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/30 14:54)

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
    requires std::is_floating_point_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FastTrigonometric final
    {
    public:
        using ClassType = FastTrigonometric<Real>;
        using Math = Math<Real>;

    public:
        // 采用多项式逼近三角函数和反三角函数的快速计算。速度起伏依靠处理器。

        // 输入必须在范围[0,pi/2]

        // 1.0e-3精度
        NODISCARD static Real FastSinRoughCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-6精度（float）、1.0e-8精度（double）
        NODISCARD static Real FastSinPreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7精度（float）、1.0e-10精度（double）
        NODISCARD static Real FastSinMorePreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 输入必须在范围[0,pi/2]

        // 1.0e-2精度
        NODISCARD static Real FastCosRoughCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7精度（float）、1.0e-8精度（double）
        NODISCARD static Real FastCosPreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7精度（float）、1.0e-10精度（double）
        NODISCARD static Real FastCosMorePreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 输入必须在范围[0,pi/4]

        // 1.0e-3精度
        NODISCARD static Real FastTanRoughCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7精度
        NODISCARD static Real FastTanPreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7精度（float）、1.0e-10精度（double）
        NODISCARD static Real FastTanMorePreciseCalculation(Real angle) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 输入必须在范围[0,1]

        // 1.0e-4精度
        NODISCARD static Real FastInvSinRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-6精度（float）、1.0e-7精度（double）
        NODISCARD static Real FastInvSinPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 输入必须在范围 [0,1]

        // 1.0e-4精度
        NODISCARD static Real FastInvCosRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-6精度（float）、1.0e-7精度（double）
        NODISCARD static Real FastInvCosPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 输入必须在范围 [-1,1]

        // 1.0e-4精度
        NODISCARD static Real FastInvTanRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-7精度
        NODISCARD static Real FastInvTanPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
    };

    using FastTrigonometricF = FastTrigonometric<float>;
    using FastTrigonometricD = FastTrigonometric<double>;
}

#endif  // MATHEMATICS_BASE_FAST_TRIGONOMETRIC_H
