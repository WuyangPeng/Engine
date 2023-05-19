///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/11 11:31)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_MESSAGE_TYPE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_MESSAGE_TYPE_H

namespace Network
{
    enum class StringMessageField
    {
        UserName = 0,
        UserInfo,
        GuildName,

        Count,
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_MESSAGE_TYPE_H