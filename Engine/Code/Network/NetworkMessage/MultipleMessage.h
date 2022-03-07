///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 18:02)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"
#include "MultipleMessageContainer.h"
#include "NetworkMessageInternalFwd.h"

#include <vector>

namespace Network
{
    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessage : public MessageInterface
    {
    public:
        static_assert(std::is_enum_v<E>, "E must be is enum.");

        using ClassType = MultipleMessage<E, ByteType, Types...>;
        using ParentType = MessageInterface;
        using MessageType = MultipleMessageContainer<E, ByteType, Types...>;

    public:
        MultipleMessage(int64_t messageID, const MessageType& messageType);

        template <typename T, typename... OtherTypes>
        MultipleMessage(int64_t messageID, T value, OtherTypes&&... otherValue);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(MultipleMessage);

        template <E index>
        NODISCARD auto GetValue() const
        {
            NETWORK_CLASS_IS_VALID_CONST_9;

            return message.GetValue<index>();
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
