/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:19)

#ifndef NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageContainer.h"
#include "MessageInterface.h"

namespace Network
{
    template <typename E>
    requires(std::is_enum_v<E>)
    class StringMessage : public MessageInterface
    {
    public:
        using ClassType = StringMessage<E>;
        using ParentType = MessageInterface;

        using MessageContainer = MessageContainer<E, std::string>;
        using StringType = typename MessageContainer::MessageType;

    public:
        StringMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId, const StringType& message);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(StringMessage);

        NODISCARD std::string GetValue(E index) const;
        NODISCARD int GetSize() const noexcept;

    private:
        MessageContainer message;
    };

    template <typename E>
    using StringMessageSharedPtr = std::shared_ptr<StringMessage<E>>;

    template <typename E>
    using ConstStringMessageSharedPtr = std::shared_ptr<const StringMessage<E>>;
}

#endif  // NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_H
