/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/28 11:02)

#ifndef CORE_TOOLS_HELPER_GET_REQUIRED_BITS_H
#define CORE_TOOLS_HELPER_GET_REQUIRED_BITS_H

#include "UserMacro.h"

namespace CoreTools
{
    template <uint64_t Value, int Bits>
    struct GetRequiredBitsHelper
    {
        static constexpr auto result = GetRequiredBitsHelper<(Value >> 1), Bits + 1>::result;
    };

    template <int Bits>
    struct GetRequiredBitsHelper<0, Bits>
    {
        static constexpr auto result = Bits;
    };

    template <uint64_t Value>
    struct GetRequiredBits
    {
        static constexpr auto result = GetRequiredBitsHelper<Value, 0>::result;
    };
}

#endif  // CORE_TOOLS_HELPER_GET_REQUIRED_BITS_H
