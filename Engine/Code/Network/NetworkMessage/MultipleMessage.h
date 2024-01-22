/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:16)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"
#include "MultipleMessageContainer.h"
#include "NetworkMessageInternalFwd.h"

namespace Network
{
    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    requires(std::is_enum_v<E>)
    class MultipleMessage : public MessageInterface
    {
    public:
        using ClassType = MultipleMessage<E, ByteType, Types...>;
        using ParentType = MessageInterface;

        using MessageType = MultipleMessageContainer<E, ByteType, Types...>;

    public:
        MultipleMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId, const MessageType& messageType);

        template <typename T, typename... OtherTypes>
        MultipleMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId, T value, OtherTypes&&... otherValue);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(MultipleMessage);

        template <E Index>
        NODISCARD auto GetValue() const
        {
            NETWORK_CLASS_IS_VALID_CONST_9;

            return message.template GetValue<Index>();
        }

        NODISCARD int GetSize() const;

    private:
        MessageType message;
    };

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    using MultipleMessageSharedPtr = std::shared_ptr<MultipleMessage<E, ByteType, Types...>>;

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    using ConstMultipleMessageSharedPtr = std::shared_ptr<const MultipleMessage<E, ByteType, Types...>>;
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_H
