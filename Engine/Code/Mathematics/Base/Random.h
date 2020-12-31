///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/10/30 14:28)

#ifndef MATHEMATICS_BASE_RANDOM_H
#define MATHEMATICS_BASE_RANDOM_H

#include "Mathematics/MathematicsDll.h"

#include "Math.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Random final
    {
    public:
        static_assert(std::is_floating_point_v<Real>, "Real must be floating point.");

        using ClassType = Random<Real>;
        using Math = Math<Real>;

    public:
        // 产生范围在[0,1]的随机数。
        // 随机数生成器可以通过调用UnitRandom先设置一个正数的种子。
        [[nodiscard]] static Real UnitRandom(uint32_t seed = 0) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 产生范围在[-1,1]的随机数。
        // 随机数生成器可以通过调用UnitRandom先设置一个正数的种子。
        [[nodiscard]] static Real SymmetricRandom(uint32_t seed = 0) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 产生范围在[min,max]的随机数。
        // 随机数生成器可以通过调用UnitRandom先设置一个正数的种子。
        [[nodiscard]] static Real IntervalRandom(Real min, Real max, uint32_t seed = 0) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
    };

    using FloatRandom = Random<float>;
    using DoubleRandom = Random<double>;
}

#endif  // MATHEMATICS_BASE_RANDOM_H
