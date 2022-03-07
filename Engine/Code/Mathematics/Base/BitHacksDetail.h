///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/01/29 10:17)

#ifndef MATHEMATICS_BASE_BIT_HACKS_DETAIL_H
#define MATHEMATICS_BASE_BIT_HACKS_DETAIL_H

#include "BitHacks.h"
#include "Log2OfPowerOfTwoDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <type_traits>

// log2�Ŀ��������㷨
// ͨ����������powerOfTwo�����λ������log2(powerOfTwo)��ֵ��
template <typename T>
T Mathematics::BitHacks::Log2OfPowerOfTwo(T powerOfTwo)
{
    static_assert(std::is_integral_v<T>, "T must be integral.");

    if (powerOfTwo <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ֵpowerOfTwo�������0"s));
    }

    const Mathematics::Log2OfPowerOfTwo<T> log2OfPowerOfTwo{ powerOfTwo };

    return log2OfPowerOfTwo.GetLog2();
}

#endif  // MATHEMATICS_BASE_BIT_HACKS_DETAIL_H
