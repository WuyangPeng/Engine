///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/06 15:47)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <vector>

namespace Network
{
    template <typename E, typename T>
    requires(std::is_enum_v<E>)
    class MessageContainer final
    {
    public:
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
        NODISCARD int GetSize() const noexcept;

    private:
        MessageType message;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_H
