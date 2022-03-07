///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/08 0:56)

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
