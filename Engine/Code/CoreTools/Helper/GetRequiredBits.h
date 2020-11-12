///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/07 18:55)

#ifndef CORE_TOOLS_HELPER_GET_REQUIRED_BITS_H
#define CORE_TOOLS_HELPER_GET_REQUIRED_BITS_H

#include "UserMacro.h"

namespace CoreTools
{
    template <int Value, int Bits>
    struct GetRequiredBitsHelper
    {
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
        static constexpr auto result = GetRequiredBitsHelper<Value, 0>::result;
    };
}

#endif  // CORE_TOOLS_HELPER_GET_REQUIRED_BITS_H
