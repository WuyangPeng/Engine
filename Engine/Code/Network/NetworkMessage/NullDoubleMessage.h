///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/05/06 11:02)

#ifndef NETWORK_NETWORK_MESSAGE_NULL_DOUBLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_NULL_DOUBLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE NullDoubleMessage final : public MessageInterface
    {
    public:
        using ClassType = NullDoubleMessage;
        using ParentType = MessageInterface;

    public:
        NullDoubleMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(NullDoubleMessage);
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(NullDoubleMessage);
}

#endif  // NETWORK_NETWORK_MESSAGE_NULL_DOUBLE_MESSAGE_H
