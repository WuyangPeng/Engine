//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 10:00)

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
        MessageContainerGroup();
        explicit MessageContainerGroup(const StructureType& group);

        CLASS_INVARIANT_DECLARE;

        void Load(const MessageSourceSharedPtr& source);
        void Save(const MessageTargetSharedPtr& target) const;
        [[nodiscard]] int GetStreamingSize() const;

        [[nodiscard]] const ContainerType GetValue(int index) const;
        [[nodiscard]] int GetSize() const;

        [[nodiscard]] GroupConstIter begin() const;
        [[nodiscard]] GroupConstIter end() const;

    private:
        GroupType m_Group;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_H
