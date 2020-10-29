//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 10:06)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_DOUBLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_DOUBLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "DoubleMessage.h"
#include "MultipleMessageContainer.h"

#include <vector>

namespace Network
{
    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleDoubleMessage : public DoubleMessage
    {
    public:
        static_assert(std::is_enum_v<E>, "E must be is enum.");

        using ClassType = MultipleDoubleMessage<E, ByteType, Types...>;
        using ParentType = DoubleMessage;
        using MessageType = MultipleMessageContainer<E, ByteType, Types...>;

    public:
        MultipleDoubleMessage(int64_t messageID, const MessageType& messageType);

        template <typename T, typename... OtherTypes>
        MultipleDoubleMessage(int64_t messageID, T value, OtherTypes... otherValue);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_DECLARE;
        NETWORK_STREAM_DECLARE(MultipleDoubleMessage);

        template <E index>
        [[nodiscard]] auto GetValue() const
        {
            NETWORK_CLASS_IS_VALID_CONST_9;

            return m_Message.GetValue<index>();
        }

        [[nodiscard]] int GetSize() const;

    private:
        MessageType m_Message;
    };

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    using MultipleDoubleMessageSharedPtr = std::shared_ptr<MultipleDoubleMessage<E, ByteType, Types...>>;

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    using ConstMultipleDoubleMessageSharedPtr = std::shared_ptr<const MultipleDoubleMessage<E, ByteType, Types...>>;
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_DOUBLE_MESSAGE_H
