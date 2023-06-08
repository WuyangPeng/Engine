///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/30 15:00)

#ifndef MATHEMATICS_BASE_RANDOM_H
#define MATHEMATICS_BASE_RANDOM_H

#include "Mathematics/MathematicsDll.h"

#include "Math.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_floating_point_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Random final
    {
    public:
        using ClassType = Random<Real>;
        using Math = Math<Real>;

    public:
        // 产生范围在[0,1]的随机数。
        // 随机数生成器可以通过调用UnitRandom先设置一个正数的种子。
        NODISCARD static Real UnitRandom(uint32_t seed = 0) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 产生范围在[-1,1]的随机数。
        // 随机数生成器可以通过调用UnitRandom先设置一个正数的种子。
        NODISCARD static Real SymmetricRandom(uint32_t seed = 0) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // 产生范围在[min,max]的随机数。
        // 随机数生成器可以通过调用UnitRandom先设置一个正数的种子。
        NODISCARD static Real IntervalRandom(Real min, Real max, uint32_t seed = 0) noexcept(gAssert < 3 || gMathematicsAssert < 3);
    };

    using RandomF = Random<float>;
    using RandomD = Random<double>;
}

#endif  // MATHEMATICS_BASE_RANDOM_H
