///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/10/30 14:31)

#ifndef MATHEMATICS_BASE_BIT_HACKS_DETAIL_H
#define MATHEMATICS_BASE_BIT_HACKS_DETAIL_H

#include "BitHacks.h"
#include "Log2OfPowerOfTwoDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"

#include <type_traits>

// log2�Ŀ��������㷨
// ͨ����������powerOfTwo�����λ������log2(powerOfTwo)��ֵ��
template <typename T>
T Mathematics::BitHacks::Log2OfPowerOfTwo(T powerOfTwo)
{
    static_assert(std::is_integral_v<T>, "T must be integral.");
    MATHEMATICS_ASSERTION_3(0 < powerOfTwo, "ֵpowerOfTwo�������0");

    const Mathematics::Log2OfPowerOfTwo<T> log2OfPowerOfTwo{ powerOfTwo };

    return log2OfPowerOfTwo.GetLog2();
}

#endif  // MATHEMATICS_BASE_BIT_HACKS_DETAIL_H
