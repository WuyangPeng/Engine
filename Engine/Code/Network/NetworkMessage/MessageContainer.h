//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 9:59)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <vector>

namespace Network
{
    template <typename E, typename T>
    class MessageContainer final
    {
    public:
        static_assert(std::is_enum_v<E>, "E must be is enum.");

        using ClassType = MessageContainer<E, T>;
        using MessageType = std::vector<T>;

    public:
        MessageContainer();
        explicit MessageContainer(const MessageType& messageType);

        CLASS_INVARIANT_DECLARE;

        void Load(const MessageSourceSharedPtr& source);
        void Save(const MessageTargetSharedPtr& target) const;
        [[nodiscard]] int GetStreamingSize() const;

        [[nodiscard]] T GetValue(E index) const;
        [[nodiscard]] int GetSize() const;

    private:
        MessageType m_Message;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_H
