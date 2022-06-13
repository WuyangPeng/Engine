///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 18:19)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TYPE_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TYPE_H

namespace Network
{
    enum class IntegerMessageField
    {
        UserID = 0,
        Level,
        Exp,
        VipLevel,
        VipExp,

        Count,
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TYPE_H