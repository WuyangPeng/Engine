///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 09:51)

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
        // ���ٱƽ�exp(-x)������x�����ڷ�Χ[0,�����)

        // 1.0e-3���ȣ�float����1.0e-4���ȣ�double��
        NODISCARD static Real FastNegativeExpMoreRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-4����
        NODISCARD static Real FastNegativeExpRoughCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-5����
        NODISCARD static Real FastNegativeExpPreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
        // 1.0e-6����
        NODISCARD static Real FastNegativeExpMorePreciseCalculation(Real value) noexcept(gAssert < 3 || gMathematicsAssert < 3);
    };

    using FastNegativeExpF = FastNegativeExp<float>;
    using FastNegativeExpD = FastNegativeExp<double>;
}

#endif  // MATHEMATICS_BASE_FAST_NEGATIVE_EXP_H
