//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:09)

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
        MultipleMessageContainerGroup();

        explicit MultipleMessageContainerGroup(const GroupType& group);

        CLASS_INVARIANT_DECLARE;

        void Load(const MessageSourceSharedPtr& source);
        void Save(const MessageTargetSharedPtr& target) const;
        [[nodiscard]] int GetStreamingSize() const;

        [[nodiscard]] int GetSize() const;

        [[nodiscard]] const MessageType GetValue(int index) const;

        [[nodiscard]] GroupConstIter begin() const;
        [[nodiscard]] GroupConstIter end() const;

    private:
        GroupType m_Group;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_H
