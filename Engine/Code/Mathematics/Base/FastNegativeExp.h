///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/10/30 13:35)

#ifndef MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H
#define MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H

#include "Mathematics/MathematicsDll.h"

#include "Math.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FastNegativeExp final
    {
    public:
        static_assert(std::is_floating_point_v<Real>, "Real must be floating point.");

        using ClassType = FastNegativeExp<Real>;
        using Math = Math<Real>;

    public:
        // ���ٱƽ�exp(-x)������x�����ڷ�Χ[0,�����)

        // 1.0e-3���ȣ�float����1.0e-4���ȣ�double��
        [[nodiscard]] static Real FastNegativeExpMoreRoughCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-4����
        [[nodiscard]] static Real FastNegativeExpRoughCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-5����
        [[nodiscard]] static Real FastNegativeExpPreciseCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
        // 1.0e-6����
        [[nodiscard]] static Real FastNegativeExpMorePreciseCalculation(Real value) noexcept(g_Assert < 3 || g_MathematicsAssert < 3);
    };

    using FloatFastNegativeExp = FastNegativeExp<float>;
    using DoubleFastNegativeExp = FastNegativeExp<double>;
}

#endif  // MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H
