///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/06 14:54)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_JSON_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_JSON_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"

#include <string>

namespace Network
{
    template <typename T>
    class JsonMessage : public MessageInterface
    {
    public:
        using ClassType = JsonMessage<T>;
        using ParentType = MessageInterface;

    public:
        JsonMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId, const std::string& message);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(JsonMessage);

        NODISCARD T GetMessage() const;

    private:
        std::string message;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_JSON_MESSAGE_H
