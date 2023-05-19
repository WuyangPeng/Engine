///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 10:20)

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
        using SocketIdContainer = std::map<int64_t, BufferSendStreamContainerSharedPtr>;
        using SocketIdContainerConstIter = SocketIdContainer::const_iterator;

    public:
        BufferSendStreamMultiIndexContainer() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Insert(int64_t socketId, ACEHandleType handle, int bufferSize, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy);

        NODISCARD BufferSendStreamContainerSharedPtr GetBufferSendStreamContainerBySocketId(int64_t socketId);
        NODISCARD BufferSendStreamContainerSharedPtr GetBufferSendStreamContainerByHandle(ACEHandleType handle);

        void Erase(int64_t socketId);
        NODISCARD SocketIdContainerConstIter begin() const noexcept;
        NODISCARD SocketIdContainerConstIter end() const noexcept;

    private:
        using HandleIdContainer = std::map<ACEHandle, BufferSendStreamContainerWeakPtr>;

    private:
        SocketIdContainer socketIdContainer;
        HandleIdContainer handleIdContainer;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_MULTI_INDEX_CONTAINER_H
