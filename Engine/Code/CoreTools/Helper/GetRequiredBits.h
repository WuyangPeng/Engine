///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.1 (2021/07/29 16:09)

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
