//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 15:31)

#ifndef NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_MULTI_INDEX_CONTAINER_H
#define NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_MULTI_INDEX_CONTAINER_H

#include "Network/NetworkDll.h"

#include "BufferSendStreamContainer.h"
#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/NetworkMessage/BufferSendStream.h"

#include <map>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BufferSendStreamMultiIndexContainer final
    {
    public:
        using ClassType = BufferSendStreamMultiIndexContainer;
        using BufferSendStreamContainerSharedPtr = std::shared_ptr<BufferSendStreamContainer>;
        using BufferSendStreamContainerWeakPtr = std::weak_ptr<BufferSendStreamContainer>;
        using SocketIDContainer = std::map<uint64_t, BufferSendStreamContainerSharedPtr>;
        using SocketIDContainerConstIter = SocketIDContainer::const_iterator;

    public:
        BufferSendStreamMultiIndexContainer() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Insert(uint64_t socketID, ACEHandle handle, int bufferSize, ParserStrategy parserStrategy);

        [[nodiscard]] BufferSendStreamContainerSharedPtr GetBufferSendStreamContainerBySocketID(uint64_t socketID);
        [[nodiscard]] BufferSendStreamContainerSharedPtr GetBufferSendStreamContainerByHandle(ACEHandle handle);

        void Erase(uint64_t socketID);
        [[nodiscard]] SocketIDContainerConstIter begin() const noexcept;
        [[nodiscard]] SocketIDContainerConstIter end() const noexcept;

    private:
        using HandleIDContainer = std::map<ACEHandle, BufferSendStreamContainerWeakPtr>;

    private:
        SocketIDContainer m_SocketIDContainer;
        HandleIDContainer m_HandleIDContainer;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_MULTI_INDEX_CONTAINER_H
