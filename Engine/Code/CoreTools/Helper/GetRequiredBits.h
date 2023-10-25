///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/22 11:09)

#ifndef CORE_TOOLS_HELPER_GET_REQUIRED_BITS_H
#define CORE_TOOLS_HELPER_GET_REQUIRED_BITS_H

#include "UserMacro.h"

namespace CoreTools
{
    template <int Value, int Bits>
    struct GetRequiredBitsHelper
    {
        static_assert(0 <= Value);

        static constexpr auto result = GetRequiredBitsHelper<(Value >> 1), Bits + 1>::result;
    };

    template <int Bits>
    struct GetRequiredBitsHelper<0, Bits>
    {
        static constexpr auto result = Bits;
    };

    template <int Value>
    struct GetRequiredBits
    {
        static_assert(0 <= Value);

        static constexpr auto result = GetRequiredBitsHelper<Value, 0>::result;
    };
}

#endif  // CORE_TOOLS_HELPER_GET_REQUIRED_BITS_H
