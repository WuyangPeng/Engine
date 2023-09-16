///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:21)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TYPE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TYPE_H

namespace Network
{
    enum class IntegerMessageField
    {
        UserId = 0,
        Level,
        Exp,
        VipLevel,
        VipExp,

        Count,
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TYPE_H