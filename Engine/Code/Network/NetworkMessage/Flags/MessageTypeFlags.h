//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 9:52)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_FLAGS_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Network
{
    enum class VersionsCondition
    {
        Greater = 0,
        GreaterEequal = 1,
        Equality = 2,
        LessEequal = 3,
        Less = 4,
        Range = 5,  // [ ] ����
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
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_TYPE_FLAGS_H
