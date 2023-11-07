///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 09:51)

#ifndef MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H
#define MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H

#include "Mathematics/MathematicsDll.h"

#include "Math.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_floating_point_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FastNegativeExp final
    {
    public:
        using ClassType = FastNegativeExp<Real>;

        using Math = Math<Real>;

    public:
        // 快速逼近exp(-x)。输入x必须在范围[0,无穷大)

        // 1.0e-3精度（float）、1.0e-4精度（double）
        NODISCARD static Real FastNegativeExpMoreRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-4精度
        NODISCARD static Real FastNegativeExpRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-5精度
        NODISCARD static Real FastNegativeExpPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-6精度
        NODISCARD static Real FastNegativeExpMorePreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
    };

    using FastNegativeExpF = FastNegativeExp<float>;
    using FastNegativeExpD = FastNegativeExp<double>;
}

#endif  // MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H
