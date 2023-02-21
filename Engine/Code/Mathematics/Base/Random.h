///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/01/28 16:19)

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
        // ������Χ��[0,1]���������
        // ���������������ͨ������UnitRandom������һ�����������ӡ�
        NODISCARD static Real UnitRandom(uint32_t seed = 0) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // ������Χ��[-1,1]���������
        // ���������������ͨ������UnitRandom������һ�����������ӡ�
        NODISCARD static Real SymmetricRandom(uint32_t seed = 0) noexcept(gAssert < 3 || gMathematicsAssert < 3);

        // ������Χ��[min,max]���������
        // ���������������ͨ������UnitRandom������һ�����������ӡ�
        NODISCARD static Real IntervalRandom(Real min, Real max, uint32_t seed = 0) noexcept(gAssert < 3 || gMathematicsAssert < 3);
    };

    using RandomF = Random<float>;
    using RandomD = Random<double>;
}

#endif  // MATHEMATICS_BASE_RANDOM_H
