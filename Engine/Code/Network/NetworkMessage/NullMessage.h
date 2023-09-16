///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:30)

#ifndef NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE NullMessage final : public MessageInterface
    {
    public:
        using ClassType = NullMessage;
        using ParentType = MessageInterface;

    public:
        NullMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(NullMessage);
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(NullMessage);
}

#endif  // NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H
