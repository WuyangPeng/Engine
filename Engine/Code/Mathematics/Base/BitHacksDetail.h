///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 09:55)

#ifndef MATHEMATICS_BASE_BIT_HACKS_DETAIL_H
#define MATHEMATICS_BASE_BIT_HACKS_DETAIL_H

#include "BitHacks.h"
#include "Log2OfPowerOfTwoDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename T>
requires std::is_integral_v<T> bool Mathematics::BitHacks::IsPowerOfTwo(T value)
{
    if (value < 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("ֵvalue�����ǷǸ�����"s))
    }

    return (0 < value) && ((value & (value - 1)) == 0);
}

#endif  // MATHEMATICS_BASE_BIT_HACKS_DETAIL_H
