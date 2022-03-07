///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 15:38)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_H

#include "Network/NetworkDll.h"

#include "MessageContainer.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <vector>

namespace Network
{
    template <typename E, typename T>
    class MessageContainerGroup final
    {
    public:
        static_assert(std::is_enum_v<E>, "E must be is enum.");

        using ClassType = MessageContainerGroup<E, T>;
        using MessageType = std::vector<T>;
        using ContainerType = MessageContainer<E, T>;
        using StructureType = std::vector<MessageType>;
        using GroupType = std::vector<ContainerType>;
        using GroupConstIter = typename GroupType::const_iterator;

    public:
        MessageContainerGroup() noexcept;
        explicit MessageContainerGroup(const StructureType& group);

        CLASS_INVARIANT_DECLARE;

        void Load(MessageSource& source);
        void Save(MessageTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        NODISCARD const ContainerType GetValue(int index) const;
        NODISCARD int GetSize() const;

        NODISCARD GroupConstIter begin() const noexcept;
        NODISCARD GroupConstIter end() const noexcept;

    private:
        GroupType m_Group;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_H
