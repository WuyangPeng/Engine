///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/11 11:31)

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