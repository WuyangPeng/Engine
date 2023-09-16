///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:23)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_FLAGS_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Network
{
    enum class VersionsCondition
    {
        Greater = 0,
        GreaterEqual = 1,
        Equality = 2,
        LessEqual = 3,
        Less = 4,
        Range = 5,  // [ ] 区间
        Specific = 6,
        All = 7,
    };

    enum class MultipleMessageByteType
    {
        String = 0,
        Uint64 = 1,
        Int64 = 2,
        Uint32 = 3,
        Int32 = 4,
        Uint16 = 5,
        Int16 = 6,
        Uint8 = 7,
        Int8 = 8,
        Bool = 9,
        Float = 10,
        Double = 11,
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_FLAGS_H
