///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 15:37)

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
        MessageContainer() noexcept;
        explicit MessageContainer(const MessageType& messageType);

        CLASS_INVARIANT_DECLARE;

        void Load(MessageSource& source);
        void Save(MessageTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        NODISCARD T GetValue(E index) const;
        NODISCARD int GetSize() const;

    private:
        MessageType message;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_H
