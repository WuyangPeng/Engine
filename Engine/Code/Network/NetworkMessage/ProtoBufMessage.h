///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/06 13:40)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_PROTO_BUF_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_PROTO_BUF_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"

#include <google/protobuf/message.h>

namespace Network
{
    template <typename T>
    requires(std::is_base_of_v<google::protobuf::Message, T>)
    class ProtoBufMessage : public MessageInterface
    {
    public:
        using ClassType = ProtoBufMessage<T>;
        using ParentType = MessageInterface;

    public:
        ProtoBufMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId, const T& message);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(ProtoBufMessage);

        NODISCARD T GetProtoBufMessage() const;

    private:
        int32_t length;
        T message;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_PROTO_BUF_MESSAGE_H
