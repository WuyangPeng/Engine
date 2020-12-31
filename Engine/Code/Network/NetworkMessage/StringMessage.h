//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:43)

#ifndef NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageContainer.h"
#include "MessageInterface.h"

#include <vector>

namespace Network
{
    template <typename E>
    class StringMessage : public MessageInterface
    {
    public:
        static_assert(std::is_enum_v<E>, "E must be is enum.");

        using ClassType = StringMessage<E>;
        using ParentType = MessageInterface;
        using MessageContainer = MessageContainer<E, std::string>;
        using StringType = typename MessageContainer::MessageType;

    public:
        StringMessage(int64_t messageID, const StringType& stringType);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_DECLARE;
        NETWORK_STREAM_DECLARE(StringMessage);

        [[nodiscard]] std::string GetValue(E index) const;
        [[nodiscard]] int GetSize() const;

    private:
        MessageContainer m_String;
    };

    template <typename E>
    using StringMessageSharedPtr = std::shared_ptr<StringMessage<E>>;

    template <typename E>
    using ConstStringMessageSharedPtr = std::shared_ptr<const StringMessage<E>>;
}

#endif  // NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_H
