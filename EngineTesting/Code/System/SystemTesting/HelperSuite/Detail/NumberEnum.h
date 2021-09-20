///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/09 17:25)

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
