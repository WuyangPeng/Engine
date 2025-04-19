///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 09:54)

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

        using MathType = Math<Real>;

    public:
        // ������Χ��[0,1]���������
        // ���������������ͨ������UnitRandom������һ�����������ӡ�
        NODISCARD static Real UnitRandom(uint32_t seed = 0);

        // ������Χ��[-1,1]���������
        // ���������������ͨ������UnitRandom������һ�����������ӡ�
        NODISCARD static Real SymmetricRandom(uint32_t seed = 0);

        // ������Χ��[min,max]���������
        // ���������������ͨ������UnitRandom������һ�����������ӡ�
        NODISCARD static Real IntervalRandom(Real min, Real max, uint32_t seed = 0);
    };

    using RandomF = Random<float>;
    using RandomD = Random<double>;
}

#endif  // MATHEMATICS_BASE_RANDOM_H
