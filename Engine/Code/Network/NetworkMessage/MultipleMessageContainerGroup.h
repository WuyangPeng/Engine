///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 18:12)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_H

#include "Network/NetworkDll.h"

#include "MultipleMessageContainer.h"

namespace Network
{
    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageContainerGroup final
    {
    public:
        static_assert(std::is_enum_v<E>, "E must be is enum.");

        using ClassType = MultipleMessageContainerGroup<E, ByteType, Types...>;
        using MessageType = MultipleMessageContainer<E, ByteType, Types...>;
        using GroupType = std::vector<MessageType>;
        using GroupConstIter = typename GroupType::const_iterator;

    public:
        MultipleMessageContainerGroup() noexcept;

        explicit MultipleMessageContainerGroup(const GroupType& group);

        CLASS_INVARIANT_DECLARE;

        void Load(MessageSource& source);
        void Save(MessageTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        NODISCARD int GetSize() const;

        NODISCARD const MessageType GetValue(int index) const;

        NODISCARD GroupConstIter begin() const noexcept;
        NODISCARD GroupConstIter end() const noexcept;

    private:
        GroupType group;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_H
