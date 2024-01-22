/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:18)

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
