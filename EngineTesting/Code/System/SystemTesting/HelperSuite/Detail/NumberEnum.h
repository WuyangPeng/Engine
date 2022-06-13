///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 0:34)

#ifndef SYSTEM_TESTING_HELPER_SUITE_NUMBER_ENUM_H
#define SYSTEM_TESTING_HELPER_SUITE_NUMBER_ENUM_H

#include "System/Helper/ConfigMacro.h"

namespace System
{
    enum class Number : uint32_t
    {
        Zero = 0,
        One = 1,
        Two = 2,
        Three = 3,
        Four = 4,
        Five = 5,
        Six = 6,
        Seven = 7,
        Eight = 8,
        Nine = 9,
    };

    enum class SignedNumber
    {
        NegativeThree = -3,
        NegativeTwo = -2,
        NegativeOne = -1,
        Zero = 0,
        One = 1,
        Two = 2,
        Three = 3,
        Four = 4,
        Five = 5,
        Six = 6,
        Seven = 7,
        Eight = 8,
        Nine = 9,
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_NUMBER_ENUM_H
